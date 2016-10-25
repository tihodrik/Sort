#include "stdafx.h"
#include "MyArray.h"
#include "stdlib.h"
#include "fstream"
#include "iostream"
#include "map"

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
int  MyArray::GetMin() {
	int min = a[0];
	for (int i = 1; i < length; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int MyArray::GetMax() {
	int max = a[0];
	for (int i = 1; i < length; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

bool MyArray::IsFileEmpty(fstream& f) {
	f.seekg(0, ios::beg);

	if (f.peek() == EOF)
		return true;

	return false;
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

		// if (the element that has een chosen in the very begining is already minimal)
		// the condition is written in order to not change the element with itself
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
		// the biggest element is the last now
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
		// the smallest element is the first now
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

// Quick sorts
void MyArray::QuickSort(int left, int right) {
	int l = left, r = right;
	int mid = a[int((r + l) / 2)];
	while (l < r) {
		while (a[l] < mid)
			l++;
		while (a[r] > mid)
			r--;

		//swap
		if (l < r) {
			int tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;

			l++;
			r--;
		}
	}
	if (r > left)
		QuickSort(left, r);
	if (l + 1 < right)
		QuickSort(l + 1, right);
}

// Integer sorts
void MyArray::CountSort() {
	int min = GetMin(),
		max = GetMax(),
		offset = -1 * min;  // for situation when min != 0
	// each element of array can be got using the formula: i - offset

	int l = max + 1 - min;
	int* aux = new int[l];

	for (int i = 0; i < l; i++) {
		aux[i] = 0;
	}

	for (int i = 0; i < length; i++) {
		aux[a[i] + offset]++;
	}

	int i = 0;
	for (int j = 0; j < l; j++)
		for (int k = 0; k < aux[j]; k++)
			a[i++] = j - offset;

	delete[] aux;
}

// External sort
void MyArray::MergeSort(string path_f) {
	fstream f(path_f);

	if (!f)
		throw "Can't find a file";
	if (IsFileEmpty(f))
		throw "File is empty";

	fstream f1("file1.txt");
	fstream f2("file2.txt");

	map <string, fstream> streams;

	streams.insert(make_pair("file", f));
	streams.insert(make_pair("file1", f1));
	streams.insert(make_pair("file2", f2));

	char current, previous;

	while (true) {
		string current_file = "file1";

		streams["file"] >> previous;
		streams[current_file] << previous;

		while (streams["file"].peek() != EOF) {
			streams["file"] >> current;

			if (current < previous) {
				streams[current_file] << "`";

				if (current_file == "file1")
					current_file = "file2";
				else
					current_file = "file1";
			}

			streams[current_file] << current;
			previous = current;
		}

		streams[current_file] << "`";

		if (IsFileEmpty(f2)) {
			break;
		}

		MergeFiles(f, f1, f2);
	}
}

void MyArray::MergeFiles(fstream& f, fstream& f1, fstream& f2) {
	char current_f1, current_f2;

	while (f1.peek() != EOF || f2.peek() != EOF) {
		f1 >> current_f1;
		f2 >> current_f2;
		do {
			if (current_f1 <= current_f2) {
				f << current_f1;
				f1 >> current_f1;
			}
			else {
				f << current_f2;
				f2 >> current_f2;
			}
		} while (current_f1 != '`' && current_f2 != '`');

		// cur_f1 == `
		if (current_f1 == '`'){
			// cur_f1 == ` && cur_f2 !=	`
			if (current_f2 != '`') {
				do {
					f << current_f2;
					f2 >> current_f2;
				} while (current_f2 != '`');
			}
		}
		// cur_f1 != `
		else {
			// cur_f1 != ` && cur_f2 == `
			if (current_f2 == '`'){
				do {
					f << current_f2;
					f2 >> current_f2;
				} while (current_f2 != '`');
			}
		}
	}
}