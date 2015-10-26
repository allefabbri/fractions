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

#include "fractions_class.hpp"

int main(){
	std::cout << "---- FRACTIONS CLASS ----" << std::endl;

	fractions q1(21,28), q2(150,90);

	std::cout << "Print\n\tq1 = " << q1 << " = " << q1.toStr() << " = " << q1.toLatex() << 
					  "\t\tq2 = " << q2 << " = " << q2.toStr() << " = " << q2.toLatex() << std::endl;
	std::cout << "Casting\n\tq1 = " << q1 << " ~ " << (int) q1  << " ~ " << (float) q1 << " ~ " << (double) q1 << 
					  "\t\tq2 = " << q2 << " ~ " << (int) q2  << " ~ " << (float) q2 << " ~ " << (double) q2 << std::endl;

	int a = 6;
	std::cout << "Inversion\n\t1/q1 = " << q1.inv() << "\t\t1/q2 = " << q2.inv() << std::endl;
	std::cout << "Scalar commutative product\n\ta q1 = " << a << " * " << q1 << " = " << a*q1 << " = " << q1*a << 
				"\n\ta q2 = " << a << " * " << q2 << " = " << a*q2 << " = " << q2*a << std::endl;

	fractions sum;
	sum += (q1 + q2);
	std::cout << "Sum\n\tq1 + q2 = " << q1 << " + " << q2 << " = " << q1+q2 << " = " << sum <<  std::endl;
	fractions diff;
	diff -= (q2 - q1);
	std::cout << "Difference\n\tq1 - q2 = " << q1 << " - " << q2 << " = " << q1-q2 << " = " << diff <<  std::endl;
	fractions prod(1,1);
	prod *= (q1 * q2);
	std::cout << "Product\n\tq1 * q2 = " << q1 << " * " << q2 << " = " << q1*q2 << " = " << prod <<  std::endl;
	fractions quot(1,1);
	quot /= (q2 / q1);
	std::cout << "Quotient\n\tq1 / q2 = " << q1 << " / " << q2 << " = " << q1/q2 << " = " << quot <<  std::endl;

	fractions sum_int;
	sum_int += (a + q1);
	std::cout << "\nSum Int\n\ta + q1 = " << a << " + " << q1 << " = " << a+q1 << " = " << q1+a << " = " << sum_int <<  std::endl;
	fractions diff_int;
	diff_int -= (q1 - a);
	std::cout << "Diff Int\n\ta - q1 = " << a << " - " << q1 << " = " << a-q1 << " = " << -1*(q1-a) << " = " << diff_int <<  std::endl;
	fractions quot_int(1,1);
	quot_int /= (q1 / a);
	std::cout << "Quotient Int\n\ta / q1 = " << a << " / " << q1 << " = " << a/q1 << " = " << 1/(q1/a) << " = " << quot_int <<  std::endl;	

	return 0;
}
