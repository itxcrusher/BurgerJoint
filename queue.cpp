#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

// ########################################    Constructor    ########################################
template <class T>
Queue<T>::Queue() : list()
{}

template <class T>
Queue<T>::Queue(Queue<T>& otherQueue) : list(otherQueue.list)
{}

template <class T>
Queue<T>::~Queue()
{}

// ########################################    Operations    ########################################
template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
	shared_ptr<ListItem<T>> head = list.getHead();
	if (head != nullptr) {
		return head->value;
	}
	return NULL;
}

template <class T>
T Queue<T>::dequeue()
{
	T temp = front();
	list.deleteHead();
	return temp;
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
	return list.isEmpty();
}

template <class T>
void Queue<T>::display() {
	list.display();
}

#endif