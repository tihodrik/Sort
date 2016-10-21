#include "stdafx.h"
#include "MyArray.h"
#include "stdlib.h"
#include "iostream"

using namespace std;


MyArray::MyArray(int length)
{
	this->length = length;
	a = new int[length];
	SetArray();
}
MyArray::MyArray(MyArray &obj) {
	length = obj.length;
	a = new int[length];
	for (int i = 0; i < length; i++)
		a[i] = obj.a[i];
}
MyArray::~MyArray()
{
	delete[] a;
	length = 0;
}

void MyArray::SetArray() {
	for (int i = 0; i < length; i++)
		a[i] = rand() % 100;
}
int MyArray::GetLength() {
	return length;
}

int& MyArray::operator[](int index) {
	return a[index];
}

// Basic sorts
void MyArray::BubbleSort() {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (a[j] > a[j + 1]){
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void MyArray::InsertionSort() {
	for (int i = 1; i < length; i++) {
		// If wrong order found
		if (a[i] < a[i - 1]) {

			// Write current element
			int tmp = a[i];

			// Search place to insert. Move all elemets to the right
			int j = i - 1;
			while (j >= 0 && a[j] >= tmp) {
				a[j + 1] = a[j];
				j--;
			}

			// Insert curret element: a[j] < tmp,
			// so insert tmp to (j+1)th position
			a[j + 1] = tmp;
		}
	}
}
void MyArray::SelectionSort() {
	int minIndex;

	for (int i = 0; i < length - 1; i++) {
		minIndex = i;

		for (int j = i + 1; j < length; j++) {
			if (a[j] < a[minIndex])
				minIndex = j;
		}

		if (minIndex != i) {
			int tmp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = tmp;
		}
	}
}

// Sorts, that are based on basic sorts
void MyArray::ShakerSort() {
	int left = 0, right = length - 1;
	bool sortable = true;
	while (left < right && sortable) {
		sortable = false;

		// towards
		for (int i = 0; i < right; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
				sortable = true;
			}
		}
		right--;

		// backward
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				sortable = true;
			}
		}
		left++;
	}
}

void MyArray::ShellSort() {
	// step == number of groups
	for (int step = length / 2; step > 0; step /= 2) {
		// Inserton sort
		for (int k = 0; k < step; k++) {
			cout << "group: " << k << "\n";
			cout << "elements (before): ";
			for (int i = k; i < length; i += step)
				cout << a[i] << "\t";
			cout << "\n\n";
			for (int i = k + step; i < length; i += step) {
				// If wrong order found
				if (a[i - step] > a[i]) {

					// Write current element
					int tmp = a[i];

					// Search place to insert. Move all elemets to the right
					int j = i - step;
					while (j >= k && a[j] > tmp) {
						a[j + step] = a[j];
						j -= step;
					}

					a[j + step] = tmp;
				}
			}
			cout << "group: " << k << "\n";
			cout << "elements (after): ";
			for (int i = k; i < length; i += step)
				cout << a[i] << "\t";
			cout << "\n\n";
		}
	}
}

void MyArray::CombSort() {
	for (int step = int(length / 1.3); step > 0; step = int(step / 1.3)) {
		if (step == 9 || step == 10)
			step = 11;

		// Bubble sort for each group
		for (int k = 0; k < step; k++) {
			bool sorted = false;
			for (int i = k; i + step < length && !sorted; i += step) {
				for (int j = k; j + step < length - i; j += step) {
					if (a[j] > a[j + step]){
						int tmp = a[j];
						a[j] = a[j + step];
						a[j + step] = tmp;
					}
					else
						sorted = true;
				}
			}
		}
	}
}

//// Quick sorts
//void MyArray::QuickSort(int left, int right) {
//	int l = left, r = right;
//	int m = (int)((r + l) / 2);
//	while (l <= m) {
//		while (a[l] < a[m] && l < m)
//			l++;
//		while (a[r] > a[m] && r > m)
//			r--;
//
//		//swap
//		if (a[l] > a[r]) {
//			int tmp = a[l];
//			a[l] = a[r];
//			a[r] = tmp;
//
//			l++;
//			r--;
//		}
//	}
//	if (l > left)
//		QuickSort()
//
//}