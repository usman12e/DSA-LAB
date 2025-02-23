#include<iostream>
#include<conio.h>

using namespace std;
/*int fact(int n) {
	if (n == 0) return 1;
	else
		return n * fact(n - 1);
}
int main()
{
	cout << fact(5);
	return 0;
}*/
////example 3.2:
//void rev() {
//	char ch;
//	cin.get(ch);
//	if (ch != '\n') {
//		rev();
//		cout.put(ch);
//	};
//}
//int main()
//{
//	rev();
//	_getch();
//	return 0;
//}
// example 3.3
//int power(int X, int N) {
//		if (N == 0)
//			return 1;
//	
//	else 
//		return power(X, N - 1) * X;
//}
//int main()
//{
//	int A, B;
//	A = 3;
//	B = 7;
//	cout << power(A, B);
//}
//Exercise 3.1
/*int power(int X, int N) {
	if (N == 0) {
		return 1;
	}
	else
	{
		return (power(X, N - 1) * X);
	}
}
int main()
{
	int x = 2;

	for (int i = 0; i <= 20; i++) {
	
		cout << x << "\t\t" << i << "\t\t" << power(x, i) << endl;
			}
}
*/
//example 3.4
//int Ackermann(int m, int n) {
//	if (m == 0)
//		return n + 1;
//	else if (m > 0 && n == 0)
//		return Ackermann(m - 1, 1);
//	else if (m > 0 && n > 0) {
//		return Ackermann(m - 1, Ackermann(m, n - 1));
//	}
//}Exercise 3.2
// //int Ackermann(int m, int n) {
//	if (m == 0)
//		return n + 1;
//	else if (m > 0 && n == 0)
//		return Ackermann(m - 1, 1);
//	else if (m > 0 && n > 0) {
//		return Ackermann(m - 1, Ackermann(m, n - 1));
//	}
//int main()
//{
//	cout << Ackermann(3, 4);
//	return 0;
//}
//Exercise 3.3:
//part a 
/*
int Print(int n)
{
	if (n == 0) {
		return 0;
}
	else {
		
		cout<< n;
		return Print(n - 1);
	}

}
int main() {
	int n;
	cout << "enter a number ";
	cin >> n;
	cout << Print(n);

}*/
//part b 
//int computebinomialccoefficient(int n, int k) {
//	if (n == k)
//		return 1;
//	else if (k == 0)
//		return 1;
//	else if (n > 1 && k > 0)
//		return computebinomialccoefficient(n - 1, k - 1) + computebinomialccoefficient(n - 1, k);
//}
////part c
//int Print(int n)
//{
//	if (n == 0) {
//		return 0;
//	}
//	else {
//
//		cout << n;
//		return Print(n - 1);
//	}
//
//}
//int computebinomialccoefficient(int n, int k) {
//	if (n == k)
//		return 1;
//	else if (k == 0)
//		return 1;
//	else if (n > 1 && k > 0)
//		return computebinomialccoefficient(n - 1, k - 1) + computebinomialccoefficient(n - 1, k);
//}
//bool isPrime(int n, int i = 2)
//{
//	if (n <= 2)
//		return (n == 2) ? true : false;
//	if (n % i == 0)
//		return false;
//	if (i * i > n)
//		return true;
//	return isPrime(n, i + 1);
//}
//int main() {
//	int num = 20;
//	int nB = 3 kB = 4
//	cout << isPrime(kB) << endl;
//	cout << "Binomial computation: " << computebinomialccoefficient(nB, kB);
//	Print(num);
//}