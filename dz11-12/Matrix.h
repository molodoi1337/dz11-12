#pragma once
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Matrix
{
	vector<int> arr;

public:

	Matrix(){}

	void Clear() {
		arr.clear();
	}
	
	void Input_keyboard() {
		Clear();
		int size;
		cout << "how many elements do you want to fill in?" << endl; cin >> size;
		arr.reserve(size);
		for (int i{ 0 }; i < size; i++) {
			cout << "enter " << i + 1 << " " << "elements"<<endl;
			int temp; cin >> temp;
			arr.push_back(temp);
		}
	}

	void Input_random() {
		
		srand(time(0));
		int size;
		cout << "how many elements do you want to fill in?" << endl; cin >> size;
		arr.reserve(size);
		for (int i{ 0 }; i < size; i++) {
			arr.push_back(rand() % 101);
		}
	}

	void Show() {
		for (int num : arr) {
			cout << num << " ";
		}
		cout << endl;
		
	}

	void Sort() {
		sort(arr.begin(), arr.end());
	}

	void Min() {										//�� ����,��������� ��� ��� ���,� ��������� � ����������� �������,�� ����� �����������.(�������� ���������)
		vector<int> temp = arr;
		sort(temp.begin(), temp.end());
		cout << "min-> " << temp.at(0) << endl;
		temp.clear();
	}

	void Max() {
		vector<int> temp = arr;
		sort(temp.begin(), temp.end());
		cout << "max-> " << temp.at(arr.size()-1)<<endl;
		temp.clear();
	}

	
	//�������� �������� ������ ��� �������,����� � ����� �������� ������ ���. ���������.����� ���� �� ������� ��������,� ����� �� �������� ������ ���������->
	//->� �� ������� � ��������� ��� ��� ����� reserve(),� ����� �� ���������� �������� ����� �� ����� 0 ,�� � ���� �� ����������.

	Matrix operator+(Matrix& a) {
		/*
		if (arr.size() != a.arr.size()) {
			if (arr.size() > a.arr.size()) {
				int size = arr.size() - a.arr.size();
				a.arr.reserve(size);
			}
			else if (arr.size() < a.arr.size()) {
				int size = a.arr.size() - arr.size();
				arr.reserve(size);
			}
		}
*/

		for (int i{ 0 }; i < a.arr.size(); i++) {
			a.arr.at(i) = arr.at(i) + a.arr.at(i);
		}
		arr = a.arr;//��� ����� ����� ��� ������.� ���������� << ����� ������������ ������ a.arr � ������� � �������� ��� �������� � a.arr ,�� ���������� � ���� ���������� ������ arr,��� � � ����������� arr � a.arr
		return *this;
	}

	Matrix operator-(Matrix& a) {
		for (int i{ 0 }; i < a.arr.size(); i++) {
			a.arr.at(i) = arr.at(i) - a.arr.at(i);
		}
		arr = a.arr;
		return *this;
	}

	Matrix operator*(Matrix& a) {
		for (int i{ 0 }; i < a.arr.size(); i++) {
			a.arr.at(i) = arr.at(i) * a.arr.at(i);
		}
		arr = a.arr;
		return *this;
	}

	Matrix operator/(Matrix& a) {
		for (int i{ 0 }; i < a.arr.size(); i++) {
			a.arr.at(i) = arr.at(i) / a.arr.at(i);
		}
		arr = a.arr;
		return *this;
	}


	friend ostream& operator<<(ostream& outstream, Matrix& a) {
		for (int i{ 0 }; i < a.arr.size(); i++) {
			outstream << a.arr.at(i)<<" ";
		}
		return outstream;
	}

};

