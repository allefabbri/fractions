// Copyright 2015, Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

#include <iostream>
#include <cstdlib>			// for exit()
#include <sstream>
#include <vector>			// for randomizers

class fractions{
private:
	int num, den;
// Great Common Divisor Euclid's algorithm, to reduce the fraction
	int gcd(int a, int b){
		if( a <= 0 || b <= 0 ) return -1;
		while( a != b ){
			if( a > b )
				a -= b;
			else
				b -= a;
		}
		return a;
	}
public:
// Void constructor
	fractions(){
		num = 0;
		den = 1;
	}
// Safe explicit constructor
	fractions(int n, int d){
		if ( d==0 ) {
			std::cerr << "Zero denominator..." << std::endl;
			exit(1);
		} else if ( n==0 ) {
			num=n;
			den=1;
		} else {
			int sign=1;
			if (n < 0) {
				sign *= -1;
			    n *= -1;
			}
			if (d < 0) {
				sign *= -1;
				d *= -1;
			}
		int tmp = gcd(n, d);
		num = n/tmp*sign;
		den = d/tmp;
		}
	}
// Safe accessing methods
	void setNum(int n){
		fractions temp(n , den);
		num = temp.num;
		den = temp.den;
	}
	void setDen(int d){
		if ( d==0 ) {
			std::cerr << "Can't set denominator to zero." << std::endl;
			return;
		} else {
			fractions temp(num , d);
			num = temp.num;
			den = temp.den;			
		}
	}
	int getNum() const { return num; }			// the const key is needed in order to overload operators in 
	int getDen() const { return den; }			// safe mode by passing const parameters to them
	fractions inv() const {
		if( num == 0 ){
			std::cout  << "Cannot invert zero." << std::endl;
			exit(2);
		} else {
			return fractions(den,num);
		}
	}
	std::string toStr() const {
		std::stringstream ss;
	    if ( den == 1) {
	        ss << num;
	    } else {
	        ss << num << "/" << den ;
	    }
	    return ss.str();
	}
	std::string toLatex() {
		std::stringstream ss;
	    if ( den == 1) {
	        ss << num;
	    } else {
	        ss << " \\frac{" << num << "}{" << den << "} ";
	    }
	    return ss.str();
	}
// Casting overload
	operator int()    { return (num)/den; }
	operator float()  { return ((float)num)/den; }
	operator double() { return ((double)num)/den; }
};

//// Arithmetic Operators overload
//// NOTE: they are implemented out of class definition 
//// using safe const arguments which enforce the presence
//// of the key const in some class members

// Scalar (abelian) multiplication and assignment
fractions operator * (const fractions& q1, const int& a) {
	return fractions(q1.getNum()*a, q1.getDen());
}
fractions operator * (const int& a , const fractions& q1){
	return q1*a;
}

// Sum
fractions operator + (const fractions& q1, const fractions& q2) {
	fractions temp( q1.getNum()*q2.getDen()+q2.getNum()*q1.getDen() , q1.getDen()*q2.getDen() );
	return temp;
}
fractions operator += ( fractions& q1, const fractions& q2) {  
	fractions temp( q1.getNum()*q2.getDen()+q2.getNum()*q1.getDen() , q1.getDen()*q2.getDen() );
	q1 = temp;		// here to show how to write this explicitly
	return q1;		// see below for more elegant solution
}

// Difference
fractions operator - (const fractions& q1, const fractions& q2) {
	return q1+(-1)*q2;
}
fractions operator -= ( fractions& q1, const fractions& q2) {
	q1 += (-1)*q2;
	return q1;
}

// Product
fractions operator * (const fractions& q1, const fractions& q2) {
	fractions temp( q1.getNum()*q2.getNum() , q1.getDen()*q2.getDen() );
	return temp;
}
fractions operator *= ( fractions& q1, const fractions& q2) {
	q1 = q1*q2;
	return q1;
}

// Division
fractions operator / (const fractions& q1, const fractions& q2) {
	return q1*q2.inv();
}
fractions operator /= ( fractions& q1, const fractions& q2) {
	q1 = q1/q2;
	return q1;
}

//// Abellian arithmetic with int
// Sum
fractions operator + (const fractions& q1, const int& a) {
	fractions temp( a,1 );
	return q1+temp;
}
fractions operator + (const int& a, const fractions& q1) {
	return q1+a;
}
fractions operator += ( fractions& q1, const int& a) {  
	fractions temp( a,1 );
	q1 = q1 + temp;
	return q1;
}
// Difference
fractions operator - (const fractions& q1, const int& a) {
	fractions temp( a,1 );
	return q1-temp;
}
fractions operator - (const int& a, const fractions& q1) {
	return -1*(q1-a);
}
fractions operator -= ( fractions& q1, const int& a) {  
	fractions temp( a,1 );
	q1 = q1 - temp;
	return q1;
}
// Division
fractions operator / (const fractions& q1, const int& a) {
	fractions temp(  a,1 );
	return q1/temp;
}
fractions operator / (const int& a, const fractions& q1) {
	fractions temp = q1/a;	
	return temp.inv();
}
fractions operator /= ( fractions& q1, const int& a) {  
	q1 = q1 / a;
	return q1;
}


// OStream overload
std::ostream& operator<<(std::ostream &ost, const fractions &q) {
	ost << q.toStr();
    return ost;
}


// Random fractions generator
std::vector<int> nums={1,3,5,7,9};
std::vector<int> dens={4,6,8,10,12};

fractions random_(){
    int i_num, i_den;
    fractions temp;
    i_den = rand() % dens.size();
    i_num = rand() % nums.size();
    temp = fractions(nums[i_num],dens[i_den]);
    return temp;
}

fractions random_g1(){
    int i_num, i_den;
    fractions temp;
    i_den = rand() % (dens.size()-1);
    i_num = rand() % (nums.size()-i_den) + i_den;
    temp = fractions(nums[i_num],dens[i_den]);
    return temp;
}

fractions random_l1(){
    int i_num, i_den;
    fractions temp;
    i_num = rand() % (nums.size()-1);
    i_den = rand() % (dens.size()-i_num) + i_num;
    temp = fractions(nums[i_num],dens[i_den]);
    return temp;
}
