/*
Example#02
#include<iostream>
using namespace std;

template<class Itemtype>
class Stack {

public:
	Stack();
	Stack(int max);
	~Stack();
	int IsEmpty() const;
	int IsFull() const;
	void Push(Itemtype newitem);
	void Pop(Itemtype& item);

private:
	int top;
	int maxStack;
	Itemtype* items;
};


template<class Itemtype>
Stack<Itemtype>::Stack()
{
	maxStack = 500;
	top = -1;
	items = new Itemtype[500];
}

template<class Itemtype>
Stack<Itemtype>::Stack(int max)
{
	maxStack = max;
	top = -1;
	items = new Itemtype[max];
}

template<class Itemtype>
Stack<Itemtype>::~Stack()
{
	delete[] items;
}

template<class Itemtype>
int Stack<Itemtype>::IsEmpty() const
{
	return (top == -1);
}

template<class Itemtype>
int Stack<Itemtype>::IsFull() const
{
	return (top == maxStack - 1);
}

template<class Itemtype>
void Stack<Itemtype>::Push(Itemtype newitem)
{
	if (IsFull())
	{
		cout << "Stack Overflow." << endl;
		exit(1);
	}
	top++;
	items[top] = newitem;
}

template<class Itemtype>
void Stack<Itemtype>::Pop(Itemtype& item)
{
	if (IsEmpty())
	{
		cout << "Stack Underflow." << endl;
		exit(1);
	}

	item = items[top];
	top--;
}

int main() {

	Stack<int> IntStack;
	Stack<float> FloatStack;
	int data;
	float val;

	IntStack.Push(35);
	FloatStack.Push(3.1415927);

	IntStack.Pop(data);
	cout << data << endl;

	FloatStack.Pop(val);
	cout << val << endl;

	return 0;
}*/


//Exercise 2.2 
//(a)

/*#include<iostream>
#include<string>
using namespace std;

class Stack {

public:
	Stack();
	Stack(int max);
	~Stack();
	int IsEmpty() const;
	int IsFull() const;
	void Validity(const std::string newitem);


private:
	int top;
	int maxStack;
	char* items;
};

Stack::Stack() {

	maxStack = 20;
	top = -1;
	items = new char[20];
}

Stack::Stack(int max)
{
	maxStack = max;
	top = -1;
	items = new char[max];
}

Stack::~Stack()
{
	delete[] items;
}


int Stack::IsEmpty() const
{
	return (top == -1);
}


int Stack::IsFull() const
{
	return (top == maxStack - 1);
}


void Stack::Validity(const std::string newitem)
{
	if (IsFull())
	{
		cout << "Stack Overflow." << endl;
		exit(1);
	}

	int i=0;

	for (i = 0; i < newitem.size(); i++) {


		if (newitem[i] == '(') {

			cout << newitem[i] << " at " << i << endl;
			top++;
			items[top] = newitem[i];
		}
	}


		if (IsEmpty())
		{
			cout << "Stack Underflow." << endl;
			exit(1);
		}

		else
		{

			for (i = 0; i < newitem.size(); i++) {

				if (newitem[i] == ')') {

					cout << newitem[i] << " at " << i << endl;

					char ch = items[top];
					top--;
				}
			}
		}

		if (IsEmpty()) {

			cout << "Expression is valid because stack is empty." << endl;
		}

		else {
			cout << "Expression is not valid because stack is not empty." << endl;
		}
}

int main() {

	Stack s1;
	string str = "(((A+B)*(C-D))";

	s1.Validity(str);


	return 0;
}*/
//-------Exercise 2.2
//---------(b)
/*#include <iostream>
#include<string>
using namespace std;

class Stack {
private:
	char* arr;
	int topIndex;
	int maxSize;

public:

	Stack() {
		maxSize = 100;
		arr = new char[maxSize];
		topIndex = -1;
	}


	Stack(int size) {
		maxSize = size;
		arr = new char[maxSize];
		topIndex = -1;
	}

	~Stack() {
		delete[] arr;
	}

	int IsEmpty() {
		return topIndex == -1;
	}

	int IsFull() {
		return topIndex == maxSize - 1;
	}

	void Push(char ch) {

		if (!IsFull()) {
			arr[++topIndex] = ch;
		}
	}

	char Pop() {
		if (!IsEmpty()) {
			return arr[topIndex--];
		}
		else{
			return '\0';
		}

	}

	char top() {
		return IsEmpty() ? '\0' : arr[topIndex];
	}
};


int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}


void check(string infix) {
	Stack s(infix.length());
	string postfix = "";

	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		if (c >= 'A' && c <= 'Z')
			postfix += c;
		else {
			while (!s.IsEmpty() && precedence(s.top()) >= precedence(c))
				postfix += s.Pop();
			s.Push(c);
		}
	}

	while (!s.IsEmpty())
		postfix += s.Pop();

	cout << "Postfix expression: " << postfix << endl;
}

int main() {
	string infix;
	cout << "Enter infix expression: ";
	getline(cin, infix) ;

	cin.ignore();

	check(infix);
	return 0;
}*/

//EXERCISE 2.2 (c)
/*
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	char* arr;
	int topIndex;
	int maxSize;

public:
	Stack() {
		maxSize = 100;
		arr = new char[maxSize];
		topIndex = -1;
	}

	Stack(int size) {
		maxSize = size;
		arr = new char[maxSize];
		topIndex = -1;
	}

	~Stack() {
		delete[] arr;
	}

	int IsEmpty() {
		return topIndex == -1;
	}

	int IsFull() {
		return topIndex == maxSize - 1;
	}

	void Push(char ch) {
		if (!IsFull()) {
			arr[++topIndex] = ch;
		}
	}

	char Pop() {
		if (!IsEmpty()) {
			return arr[topIndex--];
		}
		else {
			return '\0';
		}
	}

	char Top() {
		return IsEmpty() ? '\0' : arr[topIndex];
	}
};

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

void ConvertandEvaluate(string infix) {
	Stack s(infix.length());
	string postfix = "";

	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		if (isalnum(c)) {
			postfix += c;
		}
		else if (c == '(') {
			s.Push(c);
		}
		else if (c == ')') {
			while (!s.IsEmpty() && s.Top() != '(') {
				postfix += s.Pop();
			}
			if (!s.IsEmpty() && s.Top() == '(') {
				s.Pop();
			}
		}
		else {
			while (!s.IsEmpty() && precedence(s.Top()) >= precedence(c)) {
				postfix += s.Pop();
			}
			s.Push(c);
		}
	}

	while (!s.IsEmpty()) {
		postfix += s.Pop();
	}

	cout << "Postfix expression: " << postfix << endl;

	Stack e(postfix.size());

	for (int i = 0; i < postfix.size(); i++) {
		char ch = postfix[i];

		if (isdigit(ch)) {
			e.Push(ch - '0');
		}
		else {
			int oprd2 = e.Pop();
			int oprd1 = e.Pop();
			int res;
			if (ch == '+') {
				res = oprd1 + oprd2;
			}
			else if (ch == '-') {
				res = oprd1 - oprd2;
			}
			else if (ch == '/') {
				res = oprd1 / oprd2;
			}
			else if (ch == '*') {
				res = oprd1 * oprd2;
			}
			e.Push(res);
		}
	}

	int answer = e.Pop();
	cout << "Solution of the expression is given by: " << answer << endl;
}

int main() {
	string infix;
	cout << "Enter infix expression: ";
	getline(cin, infix);

	ConvertandEvaluate(infix);
	return 0;
}/*