//
//  Polynomial.h
//  s1051553_hw4
//
//  Created by Ip Kinkwan on 31/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#ifndef POLYOMIAL_H
#define POLYOMIAL_H

#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
	friend ostream& operator<<( ostream &out, const Polynomial &poly1 );
	friend istream& operator>>( istream &in, Polynomial &poly1 );

public:
	Polynomial(int sizenum);
	Polynomial operator+( Polynomial &poly2 );
	Polynomial operator-( Polynomial &poly2 );

private:
	vector< int > num;
};

#endif