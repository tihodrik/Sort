// Arrays.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "MyArray.h"
#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	MyArray A(10);

	cout << "Init array\n";
	for (int i = 0; i < A.GetLength(); i++)
		cout << A[i] << "\t";

	cout << "\n\n";
	A.ShellSort();

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