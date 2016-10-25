// Arrays.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyArray.h"
#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	MyArray A(6);

	cout << "Init array\n";
	for (int i = 0; i < A.GetLength(); i++)
		cout << A[i] << "\t";

	cout << "\n\n";
	A.QuickSort(0, A.GetLength() -1);

	cout << "\n\n";
	cout << "Sorted array\n";
	for (int i = 0; i < A.GetLength(); i++)
		cout << A[i] << "\t";

	return 0;
}
//cout << "\n\n";
//for (int k = 0; k < step; k++) {
//	cout << "group: " << k << "\n";
//	cout << "elements (after): ";
//	for (int i = k; i < length; i += step)
//		cout << a[i] << "\t";
//	cout << "\n\n";
//}