#include <Windows.h>
#include <iostream>
#include "Array.h"
#include <vector>
#include "Matrix.h"
using namespace std;

int main()
{
	//Array<int>arr;
	Matrix mx;
	mx.Input_keyboard();
	Matrix mx2;
	mx2.Input_keyboard();
	Matrix mx3 = mx + mx2;
	cout << mx3;


}

