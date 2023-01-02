#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
	unsigned size;
	T *arr;
public:
	Array() : size{ 0 }, arr{new T[size]}{}
	
	void input(int size) {
		this->size = size;
		T *arr1 = new T[size];
		for (int i = 0; i < size; i++) {
			cout << "enter " << i+1 << " " << "elements:" << endl;
			cin >> arr1[i];
		}
		arr = arr1;
	}
	void getMin() {
		T* arr2 = new T[size];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		for (int i = 0; i < size; i++) {
			if (arr2[0] > arr2[i]) {
				swap(arr2[0], arr2[i]);
			}
		}
		cout << "min value-> " <<arr2[0]<<endl;
		delete[] arr2;
	}
	void getMax() {
		T* arr2 = new T[size];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		for (int i = 0; i < size; i++) {
			if (arr2[0] < arr2[i]) {
				swap(arr2[0], arr2[i]);
			}
		}
		cout<<"max value-> "<< arr2[0] << endl;
		delete[] arr2;
	}

	void sort() {
		for (int i = 0; i < size - 1; i++){
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
	}
		
	}

	void set(int pos, T a) {
		arr[pos - 1] = a;
	}
	void show() {
		cout << "this mass-> ";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
			}
		cout << endl;
	}

};

