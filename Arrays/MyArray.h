#pragma once
class MyArray
{
public:
	MyArray(int length);
	~MyArray();

	void GetLength();
	
	// Basic sorts
	void SelectionSort();
	void InsertionSort();
	void BubbleSort();

	// Sorts, that are based on basic sorts
	void ShakerSort();
	void ShellSort();
	void CombSort(); // Сортировка прочесыванием

	// Quick sorts
	void QuickSort();
	void MergeSort();
	void HeapSort(); // Пирамидальная сортировка

	// Integer sorts
	void CountSort();
	void BlockSort();
	void RadixSort(); // Распределяющая сортировка = поразрядная сортировка

	// 3rd course sorts
	void TreeSorts();

private:
	int* a;
	int length;
};

