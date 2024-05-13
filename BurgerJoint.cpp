#ifndef BurgerJoint_CPP
#define BurgerJoint_CPP
#include "BurgerJoint.h"

/*
    Helper function to tell whether the 
    given string is a number or not 
*/
bool isNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if( !(isdigit((unsigned char)str[i])) )
        {
            return false;
        }
        
    }

    return true;
}


/*
    Constructor:
    1. Load topping priority from topping_priority.txt into
       topping_priority attribute
    2. Load every customers' unsorted toppings form 
       assembly line - load data from assembly.txt 
       into customers queue
    
    For you convenience this has been done!
*/
BurgerJoint::BurgerJoint()
{
   
    ifstream fin("topping_priority.txt");

    string line;

    int count = 0;

    while (getline (fin, line)) 
    {

        topping_priority[count] = line;
        count++;

    }

    //saving number of toppings
    number_of_toppings = count;

    fin.close();
    
    //loading customers' unsorted toppings from assembly line
    fin.open("assembly.txt");


    bool first_line = true;

    int total_customers;
    int cust_id;

    LinkedList<string> lines;

    //reading all lines
    while(getline (fin, line))
    {
        lines.insertAtTail(line);
    }

    fin.close();

    shared_ptr<ListItem<string>> ptr = lines.getHead();

    ptr = lines.getHead();

    //adding customers with correct id and toppings into
    //customers queue
    while(ptr != NULL)
    {
        line = ptr->value;
        if(first_line)
        {
            //noting down total customers
            total_customers = stoi(line);
            first_line = false;
            ptr = ptr -> next;
        }

        else
        {
            //noting down customer id
            cust_id = stoi(line);

            ptr = ptr->next;

            shared_ptr<customer> new_cust(new customer);
            new_cust->id = cust_id;

            //noting down customer unsorted toppings
            while(ptr != NULL)
            {  
                line = ptr->value;
                if(isNumber(ptr->value))
                {
                    break;
                }
                new_cust->order.push(line);
                ptr = ptr->next;
            }

            //enqueuing customer
            customers.enqueue(new_cust);
        }
        
    }

}


/*
    Function to fetch priority of a topping.
    Matches prioirity from topping_priority list.
*/
int BurgerJoint::getPriority(string item)
{
    for (int i = 0; i < number_of_toppings; i++) {
        if (item == topping_priority[i]) {
            return i + 1;
        }
    }
    return -1;
}

//destructor
BurgerJoint::~BurgerJoint()
{}

/*
    You have two stacks:
    1. unsorted_toppings
    2. temp_stack

    You have one variable:
    1. temp

    DONOT CREATE ANYMORE VARIABLES OR DATASTRUCTURES IN THIS FUNCTION

    Use the above mentioned variable and datastructures to sort the
    unsorted_toppings stack.
    You need to sort it according to "topping_priority"
*/
void BurgerJoint::assemble(Stack<string> &unsorted_toppings)
{
    Stack<string> temp_Stack;
    string temp;

    while (!unsorted_toppings.isEmpty()) {
        temp = unsorted_toppings.pop();
        while (!temp_Stack.isEmpty() && getPriority(temp_Stack.top()) > getPriority(temp)) {
            unsorted_toppings.push(temp_Stack.pop());
        }
        temp_Stack.push(temp);
    }
    while (!temp_Stack.isEmpty()) {
        unsorted_toppings.push(temp_Stack.pop());
    }
}


/*
    Generate an output file similar to assembly.txt.
    The toppings need to be in a sorted order in this file.
    Moreover, every customer needs to hace the correct toppings.

    NAME THE OUTPUT TEXT FILE takeaway.txt
*/
void BurgerJoint::generateOutput()
{
    shared_ptr<customer> current;

    ofstream outputFile("takeaway.txt");
    if (outputFile.is_open()) {
        outputFile << customers.length() << endl;
        while (!customers.isEmpty()) {
            current = customers.dequeue();
            outputFile << current->id << endl;
            while (!current->order.isEmpty()) {
                outputFile << current->order.pop() << endl;
            }
        }
        outputFile.close();
        cout << "\n'takeaway.txt' File generated successfully!" << endl;
    }
    else {
        cout << "\nError opening the 'takeaway.txt' File!" << endl;
    }
}

void BurgerJoint::takeawayCounter()
{
    int totalCustomers = customers.length();
    shared_ptr<customer> current;

    for (int i = 0; i < totalCustomers; i++) {
        current = customers.dequeue();
        assemble(current->order);
        customers.enqueue(current);
    }
    generateOutput();
}

#endif