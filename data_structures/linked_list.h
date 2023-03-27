#pragma once

#include "iterator.h"
#include "node.h"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void append(T value);
	void insert(T value, iterator<T> position);
	void remove(iterator<T> position);
    iterator<T> find(T value);
	void print();

	iterator<T> begin();
	iterator<T> end();
	bool        isEmpty() const;

private:
	Node<T>* head_ = Node<T>::pastEnd_;
	Node<T>* tail_ = Node<T>::pastEnd_;
};
