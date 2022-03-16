//
//  main.cpp
//  s1051553_hw4
//
//  Created by Ip Kinkwan on 31/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include "Polynomial.h"
using namespace std;

int main(int argc, const char *argv[])
{
	Polynomial p(3);
	Polynomial q(4);
	Polynomial m(5);

	cout << "Please input all coefficients of polynomial p" << endl;
	cin >> p;
	cout << "Please input all coefficients of  polynomial q" << endl;
	cin >> q;

	cout << p + q;
	cout << p - q;

	m = p + q;
	cout << m;

	Polynomial n(p + q);
	cout << n;

	system("pause");
	return 0;
}