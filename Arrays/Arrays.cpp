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

void PrintSorts();
void PrintArray(MyArray& arr);
MyArray Create();
long GetTime(clock_t);

//СОРТИРОВКИ
void Selection(MyArray * array);
void Insertion(MyArray * array);
void Bubble(MyArray * array);
void Shaker(MyArray * array);
void Shell(MyArray * array);
void Comb(MyArray * array);
void Count(MyArray * array);
void Quick(MyArray * array);

typedef void(*SORT)(MyArray*);

int _tmain(int argc, _TCHAR* argv[])
{
	int answer;
	//bool silent_mode = true;
	clock_t time;
	MyArray A = Create();

	map <int, SORT> sort;
	sort.insert(make_pair(1, Selection));
	sort.insert(make_pair(2, Insertion));
	sort.insert(make_pair(3, Bubble));
	sort.insert(make_pair(4, Shaker));
	sort.insert(make_pair(5, Shell));
	sort.insert(make_pair(6, Comb));
	sort.insert(make_pair(7, Quick));
	sort.insert(make_pair(8, Count));

	while (true) {
		MyArray B(A);

		fflush(stdin);

		PrintSorts();

		cout << "Answer: ";
		answer = _getch() - '0';

		if (answer > 0 && answer < 9){
			system("cls");
			fflush(stdin);

			cout << "Would you like to look at the init array? (y/any other)";
			if (_getch() == 'y'){
				PrintArray(B);
				_getch();
			}

			time = clock();
			sort[answer](&B);
			cout << "\nTime: " << GetTime(time) << " ticks\n\n";

			cout << "Would you like to look at the result array? (y/any other)";
			if (_getch() == 'y'){
				PrintArray(B);
				_getch();
			}
		}
		if (!answer) {
			return 0;
		}
	}
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

void PrintSorts() {
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

		<< "0 - to exit\n\n";
}
MyArray Create() {
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
void PrintArray(MyArray& a) {
	cout << "\n\nBEGIN\n\n";
	for (int i = 0; i < a.GetLength(); i++)
		cout << a[i] << "\t";

	cout << "\nEND\n\n";
}

void Selection(MyArray * array) {
	array->SelectionSort();
}
void Insertion(MyArray * array) {
	array->InsertionSort();
}
void Bubble(MyArray * array) {
	array->BubbleSort();
}
void Shaker(MyArray * array) {
	array->ShakerSort();
}
void Shell(MyArray * array) {
	array->ShellSort();
}
void Comb(MyArray * array) {
	array->CombSort();
}
void Count(MyArray * array) {
	array->CountSort();
}
void Quick(MyArray * array) {
	array->QuickSort(0, array->GetLength() - 1);
}