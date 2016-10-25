#pragma once
class MyArray
{
public:
	MyArray(int length);
	MyArray(MyArray&);
	~MyArray();

	void SetArray();
	int GetLength();
	int GetMin();
	int GetMax();

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

private:
	int* a;
	int length;
};