#pragma once
#include "string"
#include "fstream"
#include "iostream"

using namespace std;
class MyArray
{
public:
	MyArray(int length);
	MyArray(MyArray&);
	MyArray();
	~MyArray();

	void SetArray();
	int GetLength();
	int GetMin();
	int GetMax();
	bool IsFileEmpty(fstream& f);

	int& operator[](int index);
	
	// Basic sorts
	void SelectionSort();
	void InsertionSort();
	void BubbleSort();

	// Sorts, that are based on basic sorts
	void ShakerSort();
	void ShellSort();
	void CombSort();

	// Quick sort
	void QuickSort(int left, int right);

	// Integer sorts
	void CountSort();

	// External sort
	void MergeSort(string path_f);
	//void MergeFiles(fstream& f, fstream& f1, fstream& f2);

private:
	int* a;
	int length;
};