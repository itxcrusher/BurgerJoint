/*
#include "../../../Production/Crusher.h"
#include "./LinkedList.h"
#include "./LinkedList.cpp"
#include "./stack.h"
#include "./stack.cpp"
#include "./Queue.h"
#include "./Queue.cpp"

int main() {
    // ########################################    Linked List    ########################################
	heading("LinkedList Test");
	/*
	cout << "\nDefault Constructor..." << endl;
	LinkedList<int> list;

	cout << "\nInsert..." << endl;
	list.insertAtHead(12);
	list.insertAfter(7, 12);
	list.insertAtTail(2);
	list.insertAtHead(1);
	list.insertAfter(4, 2);
	list.insertAtTail(9);
	list.display();

	cout << "\nGet Items..." << endl;
	cout << "Head: " << list.getHead()->value << endl;
	cout << "Tail: " << list.getTail()->value << endl;

	cout << "\nCopy Constructor..." << endl;
	LinkedList<int> listB(list);

	cout << "\nDelete..." << endl;
	list.deleteHead();
	list.deleteTail();
	list.deleteElement(7);
	list.display();

	cout << "\nLength: " << list.length() << endl;

	listB.display();
	
	// ########################################    Stack    ########################################
	heading("Stack Test");

    ##############################################################################################################################################################

    heading("Linked List Testing");
    LinkedList<int> originalList;
    originalList.insertAtTail(1);
    originalList.insertAtTail(2);
    originalList.insertAtTail(3);

    cout << "Original List: ";
    originalList.display();

    LinkedList<int> deepCopyList(originalList);

    cout << "Deep Copy List: ";
    deepCopyList.display();

    // Modify the original list and verify that the deep copy is independent
    originalList.insertAtTail(4);

    cout << "Original List after modification: ";
    originalList.display();

    cout << "Deep Copy List remains unchanged: ";
    deepCopyList.display();
    
    heading("Stack Testing");
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack: ";
    stack.display();

    stack.pop();
    std::cout << "Stack after pop: ";
    stack.display();

    std::cout << "Peek at the top of the stack: " << stack.top() << "\n";

    heading("Queue Testing");
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Queue: ";
    queue.display();

    queue.dequeue();
    std::cout << "Queue after dequeue: ";
    queue.display();

    std::cout << "Front element of the queue: " << queue.front() << "\n";

    return 0;
}
*/