//
//  Polynomial.cpp
//  s1051553_hw4
//
//  Created by Ip Kinkwan on 31/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include "Polynomial.h"

Polynomial::Polynomial( int sizenum )
{
	num.resize( sizenum ); //set the size of run
}

ostream& operator<<( ostream &out, const Polynomial &poly1 )
{
	for ( int i = 0; i < poly1.num.size(); i++ ) {
		if ( i != 0 ) 
			out << " + "; // output format
		out << poly1.num[ i ] << " * X^" << i; // output format
	}
	out << endl;
	return out;
}

istream& operator>>( istream &in, Polynomial &poly1 )
{
	for ( int i = 0; i < poly1.num.size(); i++ )
		in >> poly1.num[ i ];//input
	return in;
}

Polynomial Polynomial::operator + ( Polynomial &poly2 )
{
	int i, j; 
	if ( poly2.num.size() > num.size() ){ //Specific size
		i = poly2.num.size();
		j = num.size();

		Polynomial temp( i );
		for (i = i - 1; i >= 0; i--)
			temp.num[ i ] = poly2.num[ i ];

		for (j = j - 1; j >= 0; j--)
			temp.num[ j ] = temp.num[ j ] + num[ j ];//add
		return temp;
	}
	else {
		i = num.size();
		j = poly2.num.size();

		Polynomial temp( i );
		for (i = i - 1; i >= 0; i--)
			temp.num[ i ] = num[ i ];

		for (j = j - 1; j >= 0; j--)
			temp.num[ j ] = temp.num[ j ] + poly2.num[ j ];//add
		return temp;
	}
}

Polynomial Polynomial::operator - (Polynomial &poly2)
{
	int i, j; 
	if (poly2.num.size() > num.size()) {
		i = poly2.num.size();
		j = num.size();

		Polynomial temp(i);
		for (i = i - 1; i >= 0; i--)
			temp.num[i] = poly2.num[i];

		for (j = j - 1; j >= 0; j--)
			temp.num[j] = temp.num[j] - num[j];
		return temp;
	}
	else {
		i = num.size();
		j = poly2.num.size();

		Polynomial temp(i);
		for (i = i - 1; i >= 0; i--)
			temp.num[i] = num[i];

		for (j =j - 1; j >= 0; j--)
			temp.num[j] = temp.num[j] - poly2.num[j];
		return temp;
	}
}