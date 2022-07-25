#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cout << "Enter an integer: ";
	cin >> a;
	cout << "Enter another integer: ";
	cin >> b;

	int* ptrA = &a;
	int* ptrB = &b;

	cout << *ptrA << endl;
	cout << *ptrB << endl;
}