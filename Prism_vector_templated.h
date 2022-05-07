/*
Licence:

MIT License

Copyright (c) 2022 David Jogoo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once
//<iostream> is required
#include <iostream>
//uncomment this if you want to use divide by zero safeguard. Be warned this may cause inaccurate calculations if a division by zero occurs.  
//#define PV_DIVIDE_BY_ZERO_GUARD
//when debug is defined it allows extra warnings
//#define DEBUG
//uncomment to silence warnings when DEBUG is also defined.
//#define PV_SILENT


template<typename T = float, int COUNT = 3>
struct pVector {
public:
	//@param array that stores the vector 
	T data[COUNT]{};


	pVector() {};

	pVector(T Initial_value) {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = Initial_value;
		}
	};

	//operator section 
	pVector<T, COUNT> operator- (const float other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] - other_;
		}
		return out;
	};

	pVector<T, COUNT> operator+ (const float other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] + other_;
		}
		return out;
	};

	pVector<T, COUNT> operator* (const float other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] * other_;
		}
		return out;
	};

	pVector<T, COUNT> operator/ (const float other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] / other_;
		}
		return out;
	};

	pVector<T, COUNT>& operator= (const float other_) {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = other_;

		}
		return *this;
	};

	pVector<T, COUNT>& operator-- (int) {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = this->data[i] - 1;
		}
		return *this;
	};

	pVector<T, COUNT>& operator++ (int) {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = this->data[i] + 1;
		}
		return *this;
	};
	pVector<T, COUNT>& operator-- () {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = this->data[i] - 1;
		}
		return *this;
	};

	pVector<T, COUNT>& operator++ () {
		for (int i = 0; i < COUNT; i++) {
			this->data[i] = this->data[i] + 1;
		}
		return *this;
	};

	pVector<T, COUNT>& operator= (const pVector<T, COUNT>* other_) {
		memcpy(this, other_, sizeof(this->data));
		return *this;
	};

	pVector<T, COUNT> operator+ (const pVector<T, COUNT>& other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] + other_.data[i];
		}
		return out;
	};
	pVector<T, COUNT> operator- (const pVector<T, COUNT>& other_)const {
		pVector<T, COUNT> out;
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] - other_.data[i];
		}
		return out;
	};

#ifdef  PV_DIVIDE_BY_ZERO_GUARD
	//slower than normal but contains safeguard check to prevent division by 0 if a component is == to zero the division will be this->axis /1. 
	pVector < T, COUNT> operator/ (const pVector < T, COUNT> other_)const {
#ifdef DEBUG
#ifndef PV_SILENT
		try {
			for (int i=0; i < COUNT; i++) {
				if (other_.data[i] == 0) {
					throw "error";
					break;
				}
			}
		}
		catch (...) { std::cerr << " WARNING: division by zero occurred but will be augmented. \n"; }
#endif //PV_SILENT
#endif // DEBUG
		pVector < T, COUNT> out;
		for (int i=0; i < COUNT; i++) {
			out.data[i] = T(this->data[i] / (other_.data[i] + (other_.data[i] == 0)));
		}
		return out;
		};
#else 
	// division by zero can occur 
	pVector < T, COUNT> operator/ (const pVector < T, COUNT> other_)const {
		pVector < T, COUNT> out;
		for (int i =0; i < COUNT; i++) { out.data[i] = T(this->data[i] / other_.data[i]); }
		return out;
		};
#endif //  PV_DIVIDE_BY_ZERO_GUARD

	//easy printing to console 
	friend std::ostream& operator<<(std::ostream& os, const pVector<T, COUNT>& o)
	{
		for (int i = 0; i < COUNT; i++) {
			os << o.data[i];
		}
		return os;
	}
	

	//@return pointer to the first element in data
	T* start() {
		return &this->data[0];
	};
	//@return pointer to the last element in data
	T* end() {
		return &this->data[COUNT - 1];
	};
	//@return returns the number of elements in the data array 
	const int number_of_elements() { return COUNT; };


	// easy printing to streams, vector is formatted as [ x, y , z , ...]
	//@param the pVector<T, COUNT> vector to print , the stream to write too, can be std::cout or std::filestream for example. 
	static void print(pVector<T, COUNT>& vect, std::ostream& outStream = std::cout) {
		outStream << "[ ";
		for (int i = 0; i < COUNT; i++) {
			outStream << vect.data[i] << " ";
		}
		outStream << "]";
	};

	inline bool isNullVector()const {
		T sum = 0;
		for(int i = 0; i < COUNT; i++){
			sum += this->data[i];
		}
		return (sum == 0);
	};

	//@return the magnitude of the vector
	inline float magnitude()const {
		double sum = 0;
		for (int i = 0; i < COUNT; i++) {
			sum += pow(this->data[i], 2);
		}
		return float(sqrt(sum));
	};

	//divides each component by the magnitude of the vector 
	//@return a normalized vector, unless vector is a null vector in which case returns pVector<T,COUNT>(0,0,...)
	pVector<T,COUNT> normalize() const {
		pVector<T, COUNT> out;
		if (this->isNullVector()) {
			return out;
		}
		float mag = this->magnitude();
		for (int i = 0; i < COUNT; i++) {
			out.data[i] = this->data[i] / mag;
		}
		return out;
	};
	
};