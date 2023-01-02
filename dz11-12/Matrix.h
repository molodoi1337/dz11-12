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

	void Min() {										//не знаю,затратней это или нет,в сравнении с пузырьковым методом,но решил попробывать.(наверное затратней)
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

	
	//коректно работает только при условии,когда в обоих векторах равное кол. элементов.Можно было бы сделать проверку,в каком из векторов меньше элементов->
	//->т на сколько и прибывить это кол через reserve(),и тогда бы оставшиеся элементы стали бы равны 0 ,но у меня не получилось.

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
		arr = a.arr;//эта часть нужна вот почему.В перегрузке << можно использовать только a.arr и поэтому я выполняю все действия с a.arr ,но возвратить у меня получилось только arr,вот я и приравниваю arr к a.arr
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

