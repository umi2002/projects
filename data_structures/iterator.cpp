#include "iterator.h"

template <typename T>
iterator<T>::iterator(Node<T>* node) : currentNode_(node)
{ }

template <typename T>
Node<T>& iterator<T>::operator*()
{
	assert(currentNode_ != Node<T>::pastEnd_);
	return *currentNode_;
}

template <typename T>
Node<T>* iterator<T>::operator->()
{
	assert(currentNode_ != Node<T>::pastEnd_);
	return currentNode_;
}

template <typename T>
iterator<T>& iterator<T>::operator++()
{
	assert(currentNode_ != Node<T>::pastEnd_);
	currentNode_ = currentNode_->next_;
	return *this;
}

template <typename T>
iterator<T>& iterator<T>::operator--()
{
	assert(currentNode_ != Node<T>::pastEnd_);
	currentNode_ = currentNode_->previous_;
	return *this;
}
