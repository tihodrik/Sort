#include "stdafx.h"
#include "MyArray.h"
#include "stdlib.h"


MyArray::MyArray(int length)
{
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

void MyArray::BubbleSort() {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (a[j] < a[j + 1]){
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void MyArray::InsertionSort() {
	for (int i = 1; i < length; i++) {
		// Если порядок нарушен
		if (a[i] < a[i - 1]) {

			// Запомнить текущий элемент
			int tmp = a[i];
			
			// Найти место для вставки, попутно сдвигая все элементы на 1 вправо
			int j = i - 1;
			while (j != 0 && a[j] > tmp)
				a[j + 1] = a[j];

			// Вставить текущий элемент
			a[j] = tmp;
		}
	}
}

void MyArray::SelectionSort() {
	int minIndex;

	for (int i = 0; i < length - 1; i++) {
		minIndex = a[i];

		for (int j = i + 1; j < length; j++)
			if (a[j] < a[minIndex])
				minIndex = j;

		if (minIndex != i) {
			int tmp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = tmp;
		}
	}
}