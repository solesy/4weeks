#ifndef GROWABLEARRAY_H
#define GROWABLEARRAY_H

#include"Array.h"
template<typename T>
class GrowableArray :public Array<T> {
public:
	GrowableArray(int _size) :Array<T>(_size) {}
	~GrowableArray() {
		delete[] this->data;
		this->data = NULL;
	}
private:
	void REALLOC() {
		T* temp = new T[2 * this->len];
		int i;
		for (i = 0; i < this->len; ++i)
			temp[i] = this->data[i];
		for (; i < 2 * this->len; ++i)
			temp[i] = 0;
		delete[] this->data;
		this->data = temp;
		this->len = 2 * this->len;
	}
public:
	T& operator[](int i) {
		while (i >= this->len)
			REALLOC();
		return Array<T>::operator[](i);
	}
};

#endif
