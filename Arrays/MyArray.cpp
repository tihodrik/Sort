#include "stdafx.h"
#include "MyArray.h"
#include "stdlib.h"


MyArray::MyArray(int length)
{
	a = new int[length];
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
		// ���� ������� �������
		if (a[i] < a[i - 1]) {

			// ��������� ������� �������
			int tmp = a[i];
			
			// ����� ����� ��� �������, ������� ������� ��� �������� �� 1 ������
			int j = i - 1;
			while (j != 0 && a[j] > tmp)
				a[j + 1] = a[j];

			// �������� ������� �������
			a[j] = tmp;
		}
	}
}