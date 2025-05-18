#pragma once
#include<iostream>
using namespace std;
template <class ItemType >
class Que {

public:

	Que();
	Que(int max);
	~Que();

	int IsFuLL() const;
	int IsEmpty() const;
	void Insert(ItemType newItem);
	void Remove(ItemType& item);

private:

	int front;
	int rear;
	int maxQue;
	int count;
	ItemType* items;

};

template<class ItemType>
Que<ItemType>::Que()
{

	maxQue = 501;
	front = 0;
	rear = 0;
	count = 0;
	items = new ItemType[maxQue];

}

template<class ItemType>
Que<ItemType>::Que(int max)
{
	maxQue = max + 1;
	front = 0;
	rear = 0;
	count = 0;
	items = new ItemType[maxQue];
}

template<class ItemType>
Que<ItemType>::~Que()
{
	delete[] items;
}


template<class ItemType>
int Que<ItemType>::IsEmpty() const
{
	return (count == 0);
}


template<class ItemType>
int Que<ItemType>::IsFuLL() const
{
	return (count == maxQue);
}


template<class ItemType>
void Que<ItemType>::Insert(ItemType newItem)
{
	if (IsFuLL()) {
		cout << "Over Flow";
	}

	else
	{
		items[rear] = newItem;
		rear = (rear + 1) % maxQue;
		++count;
	}
}

template<class ItemType>
void Que<ItemType>::Remove(ItemType& item)
{
	if (IsEmpty()) {
		cout << "Under Flow";
	}
	else
	{
		item = items[front];
		front = (front + 1) % maxQue;
		--count;
	}
}






