// Arrays.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyArray.h"
#include "iostream"
#include "string"
#include "map"
#include "ctime"
#include "conio.h"

using namespace std;

void PrintMenu();
void PrintArray(MyArray& a, char* text, char agreement);

MyArray Create();
long GetTime(clock_t);

//СОРТИРОВКИ
void SelectionWrapper(MyArray * array);
void InsertionWrapper(MyArray * array);
void BubbleWrapper(MyArray * array);
void ShakerWrapper(MyArray * array);
void ShellWrapper(MyArray * array);
void CombWrapper(MyArray * array);
void CountWrapper(MyArray * array);
void QuickWrapper(MyArray * array);

typedef void(*SORT)(MyArray*);
bool silent_mode = false;

int _tmain(int argc, _TCHAR* argv[])
{
	int answer;
	clock_t time;
	MyArray A = Create();

	map <int, SORT> sort;
	sort.insert(make_pair(1, SelectionWrapper));
	sort.insert(make_pair(2, InsertionWrapper));
	sort.insert(make_pair(3, BubbleWrapper));
	sort.insert(make_pair(4, ShakerWrapper));
	sort.insert(make_pair(5, ShellWrapper));
	sort.insert(make_pair(6, CombWrapper));
	sort.insert(make_pair(7, QuickWrapper));
	sort.insert(make_pair(8, CountWrapper));

	while (true) {
		PrintMenu();

		cout << "Answer: ";
		cin >> answer;

		if (answer > 0 && answer < 9){
			MyArray B(A);
			system("cls");

			if (!silent_mode) {
				PrintArray(B, "Would you like to look at the init array? (y/any other) ", 'y');
			}
	
			time = clock();
			sort[answer](&B);
			
			cout << "\nTime: " << GetTime(time) << " ticks\n\n";
			_getch();

			if (!silent_mode){
				PrintArray(B, "Would you like to look at the result array? (y/any other) ", 'y');
			}
		}
		if (!answer) {
			return 0;
		}
		if (answer == 10) {
			A(Create());
		}
	}

	/*MyArray A(1);

	A.MergeSort("file.txt");*/
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

void PrintMenu() {
	system("cls");
	cout << "Enter:\n\n"
		<< "1 - SelectionSort\n"
		<< "2 - InsertionSort\n"
		<< "3 - BubbleSort\n\n"
		<< "4 - ShakerSort\n"
		<< "5 - ShellSort\n"
		<< "6 - CombSort\n"
		<< "7 - QuickSort\n"
		<< "8 - CountSort\n\n"

		<< "10 - to renew array\n"
		<< "0 - to exit\n\n";
}
MyArray Create() {
	system("cls");

	int length;
	bool randomly;

	cout << "Would you like to enter elements randomly? (y/n) ";
	
	if (_getch() == 'y')
		randomly = true;
	else
		randomly = false;

	system("cls");
	fflush(stdin);

	cout << "Enter length: ";
	cin >> length;

	if (length > 100)
		silent_mode = true;
	else
		silent_mode = true;

	MyArray array(length);

	if (randomly)
		array.SetArray();
	else {
		int* a = new int[length];
		for (int i = 0; i < length; i++){
			cout << "Enter element a[" << i << "]: ";
			cin >> a[i];
		}
		array.SetArray(a);
	}

	return array;
}
long GetTime(clock_t time) {
	return clock() - time;
}
void PrintArray(MyArray& a, char* text, char agreement) {
	fflush(stdin);

	cout << text;
	if (_getch() == agreement) {

		cout << "\n\nBEGIN\n\n";
		for (int i = 0; i < a.GetLength(); i++)
			cout << a[i] << "\t";

		cout << "\nEND\n\n";

		_getch();
	}
}

void SelectionWrapper(MyArray * array) {
	array->SelectionSort();
}
void InsertionWrapper(MyArray * array) {
	array->InsertionSort();
}
void BubbleWrapper(MyArray * array) {
	array->BubbleSort();
}
void ShakerWrapper(MyArray * array) {
	array->ShakerSort();
}
void ShellWrapper(MyArray * array) {
	array->ShellSort();
}
void CombWrapper(MyArray * array) {
	array->CombSort();
}
void CountWrapper(MyArray * array) {
	array->CountSort();
}
void QuickWrapper(MyArray * array) {
	array->QuickSort(0, array->GetLength() - 1);
}