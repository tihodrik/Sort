#pragma once
#include "string"
#include "fstream"
#include "iostream"

using namespace std;
class MyArray
{
public:
	MyArray(int length);
	MyArray(const MyArray& object);
	MyArray();
	~MyArray();

	void SetArray();
	void SetArray(int []);
	int GetLength();
	int GetMin();
	int GetMax();

	int& operator[](int index);
	void operator()(const MyArray& object);
	
	// Basic sorts
	void SelectionSort();	// modified
	void InsertionSort();	// modified
	void BubbleSort();		// modified

	// Sorts, that are based on basic sorts
	void ShakerSort();
	void ShellSort();
	void CombSort();

	// Quick sort
	void QuickSort(int left, int right);

	// Integer sorts
	void CountSort();

	// External sort
	bool EndRange(fstream& stream);
	bool IsFileEmpty(fstream& f);
	bool IsFileEnd(fstream& f);

	void MergeSort(string path_f);
	void MergeFiles(fstream& f, fstream& f1, fstream& f2);
	

private:
	int* a;
	int length;
};