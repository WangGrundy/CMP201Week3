#pragma once

#include <vector>
#include <string>

template <class T> 
class Node
{
public:
	Node(T n)
	{
		data = n;
		next = nullptr;
		prev = nullptr;
	}

	T data;
	Node* next;
	Node* prev;
};

template <class T> 
class LinkedList
{
public:
	Node<T>* head;

	LinkedList();
	LinkedList(T n);
	~LinkedList();

	void Insert(T n);
	void Remove(T n);
	Node<T>* Get(int index);
	void Reverse();
	int Size();
	std::vector<T> ToVector();
	Node<T>* GetTail();
	std::string ToString();

};


