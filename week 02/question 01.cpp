#include<iostream>
#include"stack.h"
#include"stack2.h"
#include<string>
using namespace std;
int main() {
/*	Stack s;
	int s1=0;
	int Item;
	for (int i = 0; i < 20; i++) {
		s.push(i);
	}
	s.peek(s1);
	cout << endl;
	for (int i = 0; i < 20; i++) {
		s.pop(Item);
		cout << Item << endl;
	}
	return 0;*/
	char c;
	Stack s;
	string input;
	cin >> input;
	s.reverse(input);
}
