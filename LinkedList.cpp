#ifndef __LIST_CPP
#define __LIST_CPP
#include <iostream>
#include <cstdlib>
#include <memory>
#include "LinkedList.h"
using namespace std;

// ##################################################    Constructor    ##################################################
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
	head = tail = nullptr;

	shared_ptr<ListItem<T>> current = otherLinkedList.head;
	while (current != nullptr) {
		insertAtTail(current->value);
		current = current->next;
	}
}

// ##################################################    Insert    ##################################################
template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(item);

	if (head == nullptr) {
		head = tail = newItem;
	}
	else {
		newItem->next = head;
		head->prev = newItem;
		head = newItem;
	}
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(item);
	if (tail == nullptr) {
		head = tail = newItem;
	}
	else {
		tail->next = newItem;
		newItem->prev = tail;
		tail = newItem;
	}
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
	shared_ptr<ListItem<T>> current = searchFor(afterWhat);

	if (current != nullptr) {
		shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(toInsert);
		newItem->next = current->next;
		newItem->prev = current;
		current->next = newItem;
		if (newItem->next != nullptr) {
			newItem->next->prev = newItem;
		}
		else {
			tail = newItem;
		}
	}
	else {
		cout << "\nValue not Found!" << endl;
	}
}

// ##################################################    Retrieve    ##################################################
template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getHead()
{
	return head;
}

template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::getTail()
{
	return tail;
}

template <class T>
shared_ptr<ListItem<T>> LinkedList<T>::searchFor(T item)
{
	shared_ptr<ListItem<T>> current = head;
	while (current != nullptr) {
		if (current->value == item) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

// ##################################################    Delete    ##################################################
template <class T>
void LinkedList<T>::deleteElement(T item)
{
	shared_ptr<ListItem<T>> current = searchFor(item);

	if (current != nullptr) {
		if (current->prev != nullptr) {
			current->prev->next = current->next;
		}
		else {
			head = current->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
		}
		if (current->next != nullptr) {
			current->next->prev = current->prev;
		}
		else {
			tail = current->prev;
			if (tail != nullptr) {
				tail->next = nullptr;
			}
			else {
				head = nullptr;
			}
		}
	}
	else {
		cout << "\nValue not Found!" << endl;
	}
}

template <class T>
void LinkedList<T>::deleteHead()
{
	if (head != nullptr) {
		if (head->next != nullptr) {
			head = head->next;
			head->prev = nullptr;
		}
		else {
			head = tail = nullptr;
		}
	}
}

template <class T>
void LinkedList<T>::deleteTail()
{
	if (tail != nullptr) {
		if (tail->prev != nullptr) {
			tail = tail->prev;
			tail->next = nullptr;
		}
		else {
			head = tail = nullptr;
		}
	}
}

// ##################################################    Utility    ##################################################
template <class T>
int LinkedList<T>::length()
{
	int length = 0;
	shared_ptr<ListItem<T>> current = head;
	while (current != nullptr) {
		current = current->next;
		length++;
	}
	return length;
}

template <class T>
void LinkedList<T>::display() {
	shared_ptr<ListItem<T>> current = head;
	cout << "\nHead ->    ";
	while (current != nullptr) {
		cout << current->value << "  ";
		current = current->next;
	}
	cout << "  <- Tail" << endl;
}

template <class T>
bool LinkedList<T>::isEmpty() {
	return head == nullptr;
}

#endif