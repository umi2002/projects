#pragma once

#include "node.h"

#include <cassert>

template <typename T>
class iterator
{
public:
	iterator(Node<T>* node = Node<T>::pastEnd_);

	Node<T>&  operator*();
	Node<T>*  operator->();
	iterator& operator++();
	iterator& operator--();
	bool      operator==(const iterator& other) const = default;

private:
	Node<T>* currentNode_;
};
