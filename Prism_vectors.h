/*Prism Vectors:
Prism Vectors are bare bones 2d and 3d vector structs.
Containing a minimal set of overrides and functions to allow for simple vector manipulation.
common operators are supported +-*= as well as incrementors++ and decrementors--
division is also supported, along with optional safeguards and reporting.
other functions include:
magnitude
distanceTo
dot and cross products 
normalization
null vector checking 
*/
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
//uncomment this if you want to use divide by zero safeguard. Be warned this may cause inaccurate calculations if a division by zero occurs.  
//#define PV_DIVIDE_BY_ZERO_GUARD
//when debug is defined it allows extra warnings
//#define DEBUG
//uncomment to silence warnings when DEBUG is also defined.
//#define PV_SILENT


struct pV2d {
	//@param vector components  
	float x = 0, y = 0;

	// copy the vector to a new destination using memcpy 
	//@param the pointer to an array with space for 3 floats 
	void copyTo(float* copyTo_ptr) {
		memcpy(copyTo_ptr, this, (sizeof(float) * 2));
	};
	//@return the magnitude of the vector
	inline float magnitude()const {
		return float(sqrt(pow(this->x, 2) + pow(this->y, 2)));
	};
	//find the distance from this vector to another 
	//@param vector you wish to find the distance to
	//@return the distance from this vector to another 
	inline float distanceTo(const pV2d& vect_)const {
		return float(sqrt(pow((this->x - vect_.x), 2) + pow((this->y - vect_.y), 2)));
	};

	//@param Another vector you wish to find the dot product with. 
	//@return The dot product between this vector and the one given in the parameters.  
	inline float dotProduct(const pV2d& vect_)const{
		return float((this->x * vect_.x)+(this->y * vect_.y));
	};

	//Although only taking a 2d vector this function treats the cross product as though it is 
	//a 3d vector with each z component = 0. 
	//@param Another 2d vector you wish to cross with this one.
	//@return A sudo z component scalar. 
	inline float crossProduct(const pV2d& vect_)const {		
		return float((this->x * vect_.y)-(this->y * vect_.x));
	};
	//divides each component by the magnitude of the vector 
	//@return a normalized vector, unless vector is a null vector in which case returns (0,0)
	pV2d normalize() const {
		if (this->isNullVector()) {
			return pV2d(0, 0);
		}
		float mag = this->magnitude();
		return pV2d(this->x / mag, this->y / mag);
	};

	//@return true if the vector is a null vector (0,0) 
	inline bool isNullVector()const{
		return (double(this->x + this->y)==0);
	};

	//operator overrides 
	pV2d& operator = (pV2d other_) {
		this->x = other_.x;
		this->y = other_.y;
		return *this;
	};
	pV2d operator + (const pV2d other_)const {
		pV2d out;
		out.x = this->x + other_.x;
		out.y = this->y + other_.y;
		return out;
	};
	pV2d operator* (const pV2d other_)const {
		pV2d out;
		out.x = float(this->x * other_.x);
		out.y = float(this->y * other_.y);
		return out;
	};

#ifdef PV_DIVIDE_BY_ZERO_GUARD
	//slower than normal but contains safeguard check to prevent division by 0 if a component is == to zero the division will be this->axis /1. 
	pV2d operator/ (const pV2d other_)const {
#ifdef DEBUG
#ifndef PV_SILENT
		try {
			if (other_.x == 0 || other_.y == 0) {
				throw "error";
			}
		}
		catch (...) { std::cerr << " WARNING: pv2D division by zero occurred but will be augmented. \n"; }
#endif //PV_SILENT
#endif // DEBUG
		pV2d out;
		out.x = float(this->x / (other_.x + (other_.x == 0)));
		out.y = float(this->y / (other_.y + (other_.y == 0)));
		return out;
	};
#else
	//may allow division by 0 
	pV2d operator/ (const pV2d other_)const {
		pV2d out;
		out.x = float(this->x / other_.x);
		out.y = float(this->y / other_.y);
		return out;
	};
#endif // PV_DIVIDE_BY_ZERO_GAURD

	pV2d operator - (const pV2d other_)const {
		pV2d out;
		out.x = this->x - other_.x;
		out.y = this->y - other_.y;
		return out;
	};

	pV2d& operator = (const double other_) {
		this->x = float(other_);
		this->y = float(other_);
		return *this;
	};
	pV2d operator* (const double other_)const {
		pV2d out;
		out.x = float(this->x * other_);
		out.y = float(this->y * other_);
		return out;
	};

	pV2d operator/ (const double other_)const {
		pV2d out;
		out.x = float(this->x / other_);
		out.y = float(this->y / other_);
		return out;
	};
	pV2d operator- (const double other_)const {
		pV2d out;
		out.x = this->x - float(other_);
		out.y = this->y - float(other_);
		return out;
	};
	pV2d operator+ (const double other_)const {
		pV2d out;
		out.x = this->x + float(other_);
		out.y = this->y + float(other_);
		return out;
	};
	pV2d& operator++ () {
		this->x += 1;
		this->y += 1;
		return *this;
	};
	pV2d& operator-- () {
		this->x -= 1;
		this->y -= 1;
		return *this;
	};

	//easy printing to console 
	friend std::ostream& operator<<(std::ostream& os, const pV2d& o)
	{
		os << " [" << o.x << " , " << o.y << "] ";
		return os;
	}
};
struct pV3d {
	//@param vector component  
	float x = 0, y = 0, z = 0;

	// copy the vector to a new destination using memcpy 
	//@param the pointer to an array with space for 3 floats 
	void copyTo(float* copyTo_ptr) {
		memcpy(copyTo_ptr, this, (sizeof(float) * 3));
	};

	//@return the magnitude of the vector 
	inline float magnitude()const {
		return float(sqrt(pow(this->x, 2) + pow(this->y, 2)) + pow(this->z, 2));
	};
	//find the distance from this vector to another 
	//@param vector you wish to find the distance to
	//@return the distance from this vector to another 
	inline float distanceTo(pV3d& vect_)const {
		return float(sqrt(pow((this->x - vect_.x), 2) + pow((this->y - vect_.y), 2)) + pow((this->z - vect_.z), 2));
	};

	//@param Another vector you wish to find the dot product with. 
	//@return The dot product between this vector and the one given in the paramerters.  
	inline float dotProduct(const pV3d& vect_)const {
		return float((this->x * vect_.x) + (this->y * vect_.y)+ (this->z * vect_.z));
	};

	//Although only taking a 2d vector this function treats the cross product as though it is 
	//a 3d vector with each z component = 0. 
	//@param Another 2d vector you wish to cross with this one.
	//@return A sudo z component scalar. 
	inline pV3d crossProduct(const pV3d& vect_)const {
		return pV3d(
			((this->y * vect_.z) - (this->z * vect_.y)),
			((this->z * vect_.x) - (this->x * vect_.z)),
			((this->x * vect_.y) - (this->y * vect_.x))
					);
	};

	//@return true if the vector is a null vector (0,0,0) 
	inline bool isNullVector()const {
		return ((this->x + this->y + this->z) == 0);
	};

	//divides each component by the magnitude of the vector 
	//@return a normalized vector , unless original vector was a null vector, then returns (0,0,0)
	pV3d normalize() const {
		if (this->isNullVector()) {
			return pV3d(0, 0, 0);
		}
		float mag = this->magnitude();
		return pV3d(this->x / mag, this->y / mag, this->z / mag);
	};

	//operator overrides ///////////////////////////////////////////////////////

	pV3d& operator = (pV3d other_) {
		this->x = float(other_.x);
		this->y = float(other_.y);
		this->z = float(other_.z);
		return *this;
	};
	pV3d operator * (const pV3d other_)const {
		pV3d out;
		out.x = this->x * other_.x;
		out.y = this->y * other_.y;
		out.z = this->z * other_.z;
		return out;
	};

#ifdef PV_DIVIDE_BY_ZERO_GUARD
	//slower than normal but contains safeguard check to prevent division by 0 if a component is == to zero the division will be this->axis /1. 
	pV3d operator/ (const pV3d other_)const {
#ifdef DEBUG  
#ifndef PV_SILENT
		try {
			if (other_.x == 0 || other_.y == 0 || other_.z == 0) {
				throw "error";
			}
		}
		catch (...) { std::cerr << " WARNING: pv3D division by zero occurred but will be augmented. \n"; }
#endif // PV_SILENT 
#endif // DEBUG
		pV3d out;
		out.x = float(this->x / (other_.x + (other_.x == 0)));
		out.y = float(this->y / (other_.y + (other_.y == 0)));
		out.z = float(this->z / (other_.z + (other_.z == 0)));
		return out;
	};
#else
	//may allow division by 0 
	pV3d operator/ (const pV3d other_)const {
		pV3d out;
		out.x = float(this->x / other_.x);
		out.y = float(this->y / other_.y);
		out.z = float(this->z / other_.z);
		return out;
	};
#endif // PV_DIVIDE_BY_ZERO_GAURD


	pV3d operator + (const pV3d other_)const {
		pV3d out;
		out.x = this->x + other_.x;
		out.y = this->y + other_.y;
		out.z = this->z + other_.z;
		return out;
	};
	pV3d operator - (const pV3d other_)const {
		pV3d out;
		out.x = this->x - other_.x;
		out.y = this->y - other_.y;
		out.z = this->z - other_.z;
		return out;
	};
	pV3d& operator = (pV2d other_) {
		this->x = float(other_.x);
		this->y = float(other_.y);
		return *this;
	};

	pV3d& operator = (double other_) {
		this->x = float(other_);
		this->y = float(other_);
		this->z = float(other_);
		return *this;
	};
	pV3d operator* (const double other_)const {
		pV3d out;
		out.x = float(this->x * other_);
		out.y = float(this->y * other_);
		out.z = float(this->z * other_);
		return out;
	};
	pV3d operator/ (const double other_)const {
		pV3d out;
		out.x = float(this->x / other_);
		out.y = float(this->y / other_);
		out.z = float(this->z / other_);
		return *this;
	};
	pV3d operator- (const double other_)const {
		pV3d out;
		out.x = float(this->x - other_);
		out.y = float(this->y - other_);
		out.z = float(this->z - other_);
		return out;
	};
	pV3d operator+ (const double other_)const {
		pV3d out;
		out.x = float(this->x + other_);
		out.y = float(this->y + other_);
		out.z = float(this->z + other_);
		return out;
	};
	pV3d& operator++ () {
		this->x += 1;
		this->y += 1;
		this->z += 1;
		return *this;
	};
	pV3d& operator-- () {
		this->x -= 1;
		this->y -= 1;
		this->z -= 1;
		return *this;
	};

	//easy printing to console 
	friend std::ostream& operator<<(std::ostream& os, const pV3d& o)
	{
		os << " [" << o.x << " , " << o.y << " , " << o.z << "] ";
		return os;
	}

	//operator overrides ///////////////////////////////////////////////////////
};