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
}

MyArray::MyArray()
{
	length = 0;
}
MyArray::MyArray(const MyArray& object) {
	length = object.length;
	a = new int[length];
	for (int i = 0; i < length; i++)
		a[i] = object.a[i];
}
MyArray::~MyArray()
{
	if (length != 0) {
		delete[] a;
		length = 0;
	}
}

void MyArray::SetArray() {
	for (int i = 0; i < length; i++)
		a[i] = rand() % 100;
}

void MyArray::SetArray(int arr[]) {
	for (int i = 0; i < length; i++)
		a[i] = arr[i];
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

void MyArray::operator()(const MyArray& object) {
	delete[] a;

	length = object.length;
	a = new int[length];
	for (int i = 0; i < length; i++)
		a[i] = object.a[i];
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
void MyArray::InsertionSort() { // modify
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
void MyArray::SelectionSort() { // modified
	int minIndex, maxIndex;
	int left, right;

	for (left = 0, right = length - 1; left < right;) {
		minIndex = maxIndex = left;

		for (int i = left + 1; i < right + 1; i++) {
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		// if (the element that has been chosen in the very begining is already minimal)
		// the condition is written in order to not change the element with itself
		if (minIndex != left){
			int tmp = a[minIndex];
			a[minIndex] = a[left];
			a[left] = tmp;

			if (maxIndex == left)
				maxIndex = minIndex;
		}
		left++;

		if (maxIndex != right) {
			int tmp = a[maxIndex];
			a[maxIndex] = a[right];
			a[right] = tmp;
		}
		right--;
	}
}

// Sorts, that are based on basic sorts
void MyArray::ShakerSort() { //modify
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
	while (l <= r) {
		while (a[l] < mid)
			l++;
		while (a[r] > mid)
			r--;

		//swap
		if (l <= r) {
			if (l < r){
				int tmp = a[l];
				a[l] = a[r];
				a[r] = tmp;
			}

			l++;
			r--;
		}
	}
	if (r > left)
		QuickSort(left, r);
	if (l < right)
		QuickSort(l, right);
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

//External sort
//void MyArray::OpenStreams(string path_f, map<string, fstream*>& streams) {
//	fstream f(path_f);
//	fstream f1("file1.txt");
//	fstream f2("file2.txt");
//
//	map <string, fstream*> streams;
//
//	streams.insert(make_pair("file", &f));
//	streams.insert(make_pair("file1", &f1));
//	streams.insert(make_pair("file2", &f2));
//}
//
//void MyArray::CloseStreams(map<string, fstream*>& streams) {
//	for each (pair <string, fstream*> st in streams) {
//		st.second->close();
//	}
//}

bool MyArray::EndRange(fstream& stream) {
	char symbol;
	stream.seekg(1, ios_base::cur);

	symbol = char(stream.peek());

	stream.seekg(-1, ios_base::cur);

	if (symbol == '`') {
		return true;
	}
	return false;
}

void MyArray::MergeSort(string path_f) { // protection of not opened files
	int current, previous;

	while (true) {
		fstream f(path_f, ios::in);
		fstream f1("file1.txt", ios::out, ios::trunc);
		fstream f2("file2.txt", ios::out, ios::trunc);

		map <string, fstream*> streams;

		streams.insert(make_pair("file", &f));
		streams.insert(make_pair("file1", &f1));
		streams.insert(make_pair("file2", &f2));

		for each (pair<string, fstream*> st in streams) {
			if (!(st.second->is_open()))
				throw "Can't open a file";
		}

		string current_file = "file1";

		*streams["file"] >> previous;
		*streams[current_file] << previous << " ";

		while ((*streams["file"]).peek() != EOF) {
			*streams["file"] >> current;

			if (current < previous) {
				*streams[current_file] << "` ";

				if (current_file == "file1")
					current_file = "file2";
				else
					current_file = "file1";
			}

			*streams[current_file] << current << " ";
			previous = current;
		}

		*streams[current_file] << "` ";

		streams["file"]->close();
		streams["file1"]->close();
		streams["file2"]->close();

		f2.open("file2.txt", ios::in);
		if (IsFileEmpty(*streams["file2"])) {
			break;
		}

		f.open(path_f, ios::out);
		f1.open("file1.txt", ios::in);

		MergeFiles(f, f1, f2);

		streams["file"]->close();
		streams["file1"]->close();
		streams["file2"]->close();
	}
	remove("file1.txt");
	remove("file2.txt");
}

void MyArray::MergeFiles(fstream& f, fstream& f1, fstream& f2) {
	int current_f1, current_f2;
	bool written_f1, written_f2;

	while (f1.peek() != EOF && f2.peek() != EOF) {
		// begining of the new range
		f1 >> current_f1;
		written_f1 = false;

		f2 >> current_f2;
		written_f2 = false;

		while (true) {
			if (current_f1 <= current_f2) {
				f << current_f1 << " ";
				written_f1 = true;
				if (EndRange(f1)) {
					break;
				}
				f1 >> current_f1;
				written_f1 = false;
			}
			else {
				f << current_f2 << " ";
				written_f2 = true;
				if (EndRange(f2)) {
					break;
				}
				f2 >> current_f2;
				written_f2 = false;
			}
		}

		// write if exists smt to write (for current range) 
		// notice if f1 or f2 is written or not - optional

		if (!written_f2) {
			while (true) {
				f << current_f2 << " ";
				if (EndRange(f2))
					break;
				f2 >> current_f2;
			}
		}

		if (!written_f1) {
			while (true) {
				f << current_f1 << " ";
				if (EndRange(f1))
					break;
				f1 >> current_f1;
			}
		}


		// and go to the next range
		f1.seekg(3, ios_base::cur);
		f2.seekg(3, ios_base::cur);
	}

	if (f1.peek() != EOF) {
		while (f1.peek() != EOF){
			while (true) {
				f << current_f1 << " ";
				if (EndRange(f1))
					break;
				f1 >> current_f1;
			}
			f1.seekg(3, ios_base::cur); // skip " ` "
		}
	}

	if (f2.peek() != EOF) {
		while (f2.peek() != EOF){
			while (true) {
				f << current_f2 << " ";
				if (EndRange(f2))
					break;
				f2 >> current_f2;
			}
			f2.seekg(3, ios_base::cur); // skip " ` "
		}
	}
}

