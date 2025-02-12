/*#include"iostream"
#include<math.h>
using namespace std;

class Complex {

private:
	float re;
	float im;

public:

	Complex() { re = 0.0; im = 0.0; }
	Complex(float r, float i) { re = r; im = i; }
	~Complex() {};

	float Real() { return re; }
	float Imag() { return im; }


	Complex operator*(Complex other) {
		Complex temp(0, 0);
		temp.re = re * other.re - im * other.im;
		temp.im = re * other.im + im * other.re;
		return temp;
	}

};
int main() {

	Complex a(5, 8);
	//Complex* b = new Complex(5.0);
	Complex c(6, 2);
	Complex d;

	cout << "a real= " << a.Real() << "   a imaginary= " << a.Imag() << endl;
	cout << "c real= " << c.Real() << "   c imaginary= " << c.Imag() << endl;

	d = a * c;


	return 0;
}*/




/*#include<iostream>
using namespace std;
template <class T>
T GetMax(T a, T b) {
	T result;
	result = (a > b) ? a : b;
	return result;
}

int main() {

	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax<int>(i, j);
	n = GetMax<long>(l, m);

	cout << k << endl;
	cout << n << endl;

	return 0;
}*/

/*#include<iostream>
using namespace std;
template <class T>
class mypair
{
	T a, b;
public:
	mypair(T first,T second)
	{
		a = first;
		b = second;
	}

	T getmax();
	T getmin();
};

template <class T>
T mypair<T>::getmax()
{
	T retval;
	retval = (a > b) ? a : b;
	return retval;
}

template <class T>
T mypair<T>::getmin()
{
	T min;
	min = (a < b) ? a : b;
	return min;
}

int main() {
	mypair<int>myobject(150, 75);
	mypair<float>myobj(150, 75);
	cout <<"Maximum number = "<< myobject.getmax() << endl;
	cout <<"Minimum number = "<< myobj.getmin() << endl;
	return 0;
}*/




/*#include<iostream>
using namespace std;
template <class T,int N>
class mysequence
{
	T memblock[N];
public:
	void setmember(int x, T value);
	T getmember(int x);
	T getmax(int x);
	T getmin(int x);
};
template<class T,int N>
void mysequence<T,N>::setmember(int x, T value)
{
	return memblock[x] = value;
}

template <class T,int N>
T mysequence<T, N>::getmember (int x)
{
	return memblock[x];
}

template <class T, int N>
T mysequence<T, N>::getmin(int x)
{
	T min = memblock[0];
	for (int i = 0, i < N, i++) {
	if (min > memblock[i]) {
		min = memblock[i];
	}
	}

	return min;
}
template <class T, int N>
T mysequence<T, N>::getmax(int x)
{
	T max = memblock[0];
	for (int i = 0, i < N, i++) {
		if (max < memblock[i]) {
			max = memblock[i];
		}
	}
	return max;
}
int main() {

	mysequence<int, 5>myints;
	mysequence<double, 5>myfloats;

	myints.setmember(0, 100);
	myfloats.setmember(3, 3.1416);

	cout << myints.getmember(0) << endl;
	cout << myfloats.getmember(3) << endl;

	return 0;
}
/* 


/*#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(void) {

	ofstream outfile;
	outfile.open("fout.txt");

	ifstream inFile("fin.txt");

	string ch;
	int sentenceCount = 0;
	int wordCount = 0;
	int characterCount = 0;

	while (getline(inFile,ch))
	{
		outfile << ch <<endl;
		sentenceCount++;

	}

	bool inWord = false;

	for (int i = 0; i < ch.size(); i++) {
		char character = ch[i]; 

		if (isspace(character)) {
			
			if (inWord) {
				wordCount++;
				inWord = false;
			}
		}
		else {
			
			inWord = true;
		}
	}

	
	if (inWord) {
		wordCount++;
	}

	characterCount += ch.size();

	outfile << "\nSentence count = " << sentenceCount << endl;
	outfile << "\nWord count = " << wordCount << endl;
	outfile << "\nCharacter count = " << characterCount << endl;

	inFile.close();
	outfile.close();

	return 0;
}*/

/*#include<iostream>
#include<string>
using namespace std;

class House {

	string Owner;
	string Address;
	int Bedrooms;
	float Price;
public:
	House() {
		Owner="";
		Address="";
		Bedrooms = 0;
		Price = 0.0;
	}

	void input() {

		cin.ignore();

		cout << "Enter Owner's name: ";
		getline(cin, Owner);
		

		cout << "Enter Address: ";
		getline(cin, Address);



		cout << "Enter number of bedrooms: ";
		cin >> Bedrooms;

		cout << "Enter Price: ";
		cin >> Price;
	}

	void display() {

		cout << "Owner's name: "<<Owner<<endl;

		cout << "Address: "<<Address<<endl;

		cout << "Enter number of bedrooms: "<< Bedrooms<<endl;

		cout << "Price: "<<Price<<endl;
	}
};

int main() {

	int const a = 100;
	House available[a];

	bool choice = true;
	int j = 0;
	while (choice) {
		
		char ch;
		cout << "Do you want to enter data for the available house (Y/N)?";
		cin >> ch;

		if(ch =='Y') {
			available[j].input(); 
			j++;
		}
		
		else {
			choice = false;

			if (j >0 ) {
				for (int i = 0; i < j; i++) {

					available[i].display();
					cout << endl;
				}
			}

		}
	}
	

	

	return 0;
}*/


/*
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student {
private:
	char name[30]; 
	int grades[10];
	float average; 

public:
	
	void setName(const char* studentName) {
		strncpy_s(name, studentName, 29);
		name[29] = '\0'; 
	}

	
	void setGrades(int studentGrades[], int numGrades) {
		for (int i = 0; i < numGrades; i++) {
			grades[i] = studentGrades[i];
		}
	}

	
	void calculateAverage(int numGrades) {
		float sum = 0;
		for (int i = 0; i < numGrades; i++) {
			sum += grades[i];
		}
		average = sum / numGrades;
	}

	
	float getAverage() const {
		return average;
	}

	
	const char* getName() const {
		return name;
	}

	
	void display(int numGrades) const {
		cout << left << setw(20) << name << " | ";
		for (int i = 0; i < numGrades; i++) {
			cout << setw(5) << grades[i] << " ";
		}
		cout << " | " << setw(6) << fixed << setprecision(2) << average << endl;
	}
};

int main() {
	
	char filename[100];
	cout << "Enter the filename: ";
	cin >> filename;

	
	ifstream infile(filename);
	if (!infile) {
		cerr << "Error: Could not open file!" << endl;
		return 1;
	}

	
	int numStudents, numGrades;
	infile >> numStudents >> numGrades;

	
	Student students[100]; 

	
	for (int i = 0; i < numStudents; i++) {
		char name[30];
		infile >> name;
		students[i].setName(name);

		int grades[10]; 
		for (int j = 0; j < numGrades; j++) {
			infile >> grades[j];
		}
		students[i].setGrades(grades, numGrades);
		students[i].calculateAverage(numGrades);
	}

	
	cout << "\nStudent Data:\n";
	cout << left << setw(20) << "Name" << " | Grades       | Average\n";
	cout << "--------------------------------------------\n";
	for (int i = 0; i < numStudents; i++) {
		students[i].display(numGrades);
	}

	
	float classAverage = 0;
	for (int i = 0; i < numStudents; i++) {
		classAverage += students[i].getAverage();
	}
	classAverage /= numStudents;
	cout << "\nClass Average: " << fixed << setprecision(2) << classAverage << endl;

	
	float highestAverage = students[0].getAverage();
	float lowestAverage = students[0].getAverage();
	for (int i = 1; i < numStudents; i++) {
		if (students[i].getAverage() > highestAverage) {
			highestAverage = students[i].getAverage();
		}
		if (students[i].getAverage() < lowestAverage) {
			lowestAverage = students[i].getAverage();
		}
	}
	cout << "Highest Average: " << highestAverage << endl;
	cout << "Lowest Average: " << lowestAverage << endl;

	
	cout << "\nStudents with average grade less than the class average:\n";
	for (int i = 0; i < numStudents; i++) {
		if (students[i].getAverage() < classAverage) {
			cout << students[i].getAverage() << " - " << students[i].getName() << endl;
		}
	}

	
	infile.close();

	return 0;
}
/*