#pragma once

template <typename T>
class Node
{
public:
	Node(T value);

private:
	inline static constexpr Node* pastEnd_ = nullptr;

	T     value_;
	Node* next_     = pastEnd_;
	Node* previous_ = pastEnd_;
};
