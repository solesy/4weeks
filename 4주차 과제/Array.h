#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<algorithm>
#include<cassert>
#include<memory.h>
#include<cmath>
using namespace std;
template<typename T>
class Array {
protected:
	T* data; //배열
	int len; //배열의 크기
public:
	Array(int size) {
		if (size <= 0) {
			cout << "Array size error!" << endl;
			exit(1);
		}
		else {
			data = new T[size];
			len = size;
			for (int i = 0; i < len; ++i)
				data[i] = 0;
		}
	}
	~Array() {
		delete[] data;
		data = NULL;
	}

	//배열의 크기를 반환한다.
	int length() const {
		return len;
	}
	//return reference
	virtual T& operator[](int i) {
		static T tmp;
		if (i < len && i >= 0) return data[i];
		cout << "Array bound error!" << endl;
		return tmp;
	}
	//return data[i]
	T operator[](int i)const {
		if (i < len && i >= 0) return data[i];
		else {
			cout << "Array bound error!" << endl;
			return 0;
		}
	}
	void print() {
		cout << "[ ";
		for (int i = 0; i < len; ++i)
			cout << data[i] << " ";
		cout << "]" << endl;
	}
};

#endif
