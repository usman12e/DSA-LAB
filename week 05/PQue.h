#pragma once
#include<iostream>
#include"Que.h"
using namespace std;
template<class ItemType>
class PQue {

public:
	PQue();
	int IsFull() const;
	int IsEmpty() const;
	void Insert(ItemType newItem, int p);
	void Remove(ItemType& item);
private:
	Que <ItemType> pQ[10];
};

template<class ItemType>
PQue<ItemType>::PQue() {}

template<class ItemType>
int PQue<ItemType>::IsEmpty() const
{
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].IsEmpty()) {
			return false;
		}
		return true;
	}
}

template<class ItemType>
int PQue<ItemType>::IsFull() const
{
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].IsFull()) {
			return false;
		}
		return true;
	}
}

template<class ItemType>
void PQue<ItemType>::Insert(ItemType newItem,int p)
{
	if (p < 0 || p >= 10) {
		cout << "Invalid Prority." << endl;
		return;
	}
	pQ[p].Insert(newItem);
}

template<class ItemType>
void PQue<ItemType>::Remove(ItemType& item)
{
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].IsEmpty()) {
			pQ[i].Remove(item);
			return;
		}
	}
	cout << "Under Flow" << endl;
}


