#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

// ########################################    Constructor    ########################################
template <class T>
Stack<T>::Stack() : list()
{}
    
template <class T>
Stack<T>::Stack(Stack<T>& otherStack) : list(otherStack.list)
{}

template <class T>
Stack<T>::~Stack()
{}

// ########################################    Operations    ########################################
template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    shared_ptr<ListItem<T>> head = list.getHead();
    if (head != nullptr) {
        return head->value;
    }
    return NULL;
}

template <class T>
T Stack<T>::pop()
{
    T temp = top();
    list.deleteHead();
    return temp;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    return list.isEmpty();
}

template <class T>
void Stack<T>::display() {
    list.display();
}

#endif
