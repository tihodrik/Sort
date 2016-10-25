// Arrays.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyArray.h"
#include "iostream"
#include "string"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	MyArray A;

	/*cout << "Init array\n";
	for (int i = 0; i < A.GetLength(); i++)
		cout << A[i] << "\t";

	cout << "\n\n";*/
	try {
		A.MergeSort("f.txt");
	}
	catch (char* message) {
		cout << message << endl;
	}


	/*cout << "\n\n";
	cout << "Sorted array\n";
	for (int i = 0; i < A.GetLength(); i++)
		cout << A[i] << "\t";*/

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