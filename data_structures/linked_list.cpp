#include "linked_list.h"

template <typename T>
LinkedList<T>::LinkedList()
{ }

template <typename T>
LinkedList<T>::~LinkedList()
{
    for (iterator<T> it = begin(); it != end(); ++it)
    {
        delete it.currentNode_;
    }
    head_ = Node<T>::pastEnd_;
    tail_ = Node<T>::pastEnd_;
}

template <typename T>
void LinkedList<T>::append(T value)
{
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty())
	{
		head_ = newNode;
		tail_ = newNode;
	}
	else
	{
		tail_->next_       = newNode;
		newNode->previous_ = tail_;
		tail_              = newNode;
	}
}

template <typename T>
void LinkedList<T>::insert(T value, iterator<T> position)
{
	assert(find(position->value_) != iterator<T>(Node<T>::pastEnd_));

	Node<T>* newNode = new Node<T>(value);
	if (position == begin())
	{
		newNode->next_   = head_;
		head_->previous_ = newNode;
		head_            = newNode;
	}
	else if (position == end())
	{
		append(value);
	}
	else
	{
		newNode->next_     = position.currentNode_;
		newNode->previous_ = position.currentNode_->previous_;
		position.currentNode_->previous_->next_ = newNode;
		position.currentNode_->previous_        = newNode;
	}
}

template <typename T>
void LinkedList<T>::remove(iterator<T> position)
{
	assert(find(position->value_) != iterator<T>(Node<T>::pastEnd_));

	if (position == begin())
	{
		head_ = head_->next_;
		if (head_ != Node<T>::pastEnd_)
		{
			head_->previous_ = Node<T>::pastEnd_;
		}
	}
	else if (position == end())
	{
		tail_ = tail_->previous_;
		if (tail_ != Node<T>::pastEnd_)
		{
			tail_->next_ = Node<T>::pastEnd_;
		}
	}
	else
	{
		position.currentNode_->previous_->next_ = position.currentNode_->next_;
		position.currentNode_->next_->previous_ =
			position.currentNode_->previous_;
	}
	delete position.currentNode_;
}

template <typename T>
iterator<T> LinkedList<T>::find(T value)
{
	for (iterator<T> it = begin(); it != end(); ++it)
	{
		if (it->value_ == value)
		{
			return it;
		}
	}
	return iterator<T>(Node<T>::pastEnd_);
}

template <typename T>
void LinkedList<T>::print()
{ }

template <typename T>
iterator<T> LinkedList<T>::begin()
{
	return iterator<T>(head_);
}

template <typename T>
iterator<T> LinkedList<T>::end()
{
	return iterator<T>(tail_);
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return head_ == Node<T>::pastEnd_;
}
