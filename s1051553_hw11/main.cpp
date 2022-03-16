//
//  main.cpp
//  s1051553_hw11
//
//  Created by Ip Kinkwan on 1/6/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include <iostream>
//#include "ChineseYear.hpp".
#include "ChineseYear.h"
using namespace std;

int main()
{
	ChineseYear cy1 = ChineseYear("Tiger");

	ChineseYear cy2 = ChineseYear(2015);

	ChineseYear cy3;

	cout << "Trying the year of 1900" << endl;
	try
	{
		ChineseYear cy3 = ChineseYear(1899);

	}
	catch (ChineseYear::WrongGregorianYear& e)
	{
		cerr << e.what() << endl;
	}

	cout << "Trying the year of the Panda" << endl;
	try
	{
		ChineseYear cy3 = ChineseYear("Panda");
	}
	catch (ChineseYear::WrongChineseYear& e)
	{
		cerr << e.what() << endl;
	}

	cout << "cy1 = " << cy1 << ", cy2 = " << cy2 << ", cy3 = " << cy3 << endl;

	cy1 += 1;

	cout << "cy1 = " << cy1 << endl;

	cout << "cy2 + 3 = " << cy2 + 3 << endl;

	cout << "5 + cy2 = " << 5 + cy2 << endl;

	//Add
	system("pause");
}