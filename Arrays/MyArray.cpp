#include "stdafx.h"
#include "MyArray.h"
#include "stdlib.h"


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
		}
	}
}