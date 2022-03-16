#include <iostream>
#include <string>
#include <exception>
using namespace std;

class ChineseYear {
public:
	int year, gregorian;
	string strGregorian[12] = { "Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig" }; //生肖

	ChineseYear() {
		year = 2020; // 今年
		gregorian = 0; //鼠年
	};

	ChineseYear(int inYear) throw() {
		if (inYear < 1900) { //小過1900年
			throw WrongGregorianYear("Invalid Gregorian Year (must be >= 1900)");
		}
		year = inYear;
		gregorian = inYear - 2020; //input - 今年
		if (gregorian > 0) { //大過2020 
			gregorian = gregorian % 12;
		}
		else if (gregorian < 0) {//小過2020 
			gregorian = 12 + gregorian % 12; // +12
		}
	};

	ChineseYear(string inGregorian) throw() {
		int save = -1;
		for (int i = 0; i != 12; i++) {//for
			if (inGregorian == strGregorian[i]) {//有相同生肖
				save = i;
				break;
			}
		}
		if (save == -1) {
			throw WrongChineseYear("Invalid Chinese Year");//沒有相同生肖
		}
		gregorian = save; 
		year = 2020 - (12 - gregorian);
	};

	ChineseYear operator+=(int i) {//  cy1 += 1;
		this->year = this->year + i;
		this->gregorian = (this->gregorian + i) % 12;
		return *this;
	}

	friend ChineseYear operator+(ChineseYear cy, int i) { // cy2 + 3
		cy.year = cy.year + i;
		cy.gregorian = (cy.gregorian + i) % 12;
		return cy;
	}

	friend ChineseYear operator+(int i, ChineseYear cy) {// 5 + cy2
		cy.year = cy.year + i;
		cy.gregorian = (cy.gregorian + i) % 12;
		return cy;
	}

	friend ostream& operator<<(ostream& os, const ChineseYear& cy) {//
		os << cy.strGregorian[cy.gregorian] << " " << cy.year << "-" << cy.year + 1; // output format
		return os;
	}

	class WrongGregorianYear : public exception {//wrong生肖
	public:
		WrongGregorianYear(const string& msg) : _msg(msg) {}

		virtual const char* what() const noexcept override {
			return _msg.c_str();
		}

		string _msg;
	};

	class WrongChineseYear : public exception { //wrong年
	public:
		WrongChineseYear(const string& msg) : _msg(msg) {}

		virtual const char* what() const noexcept override {
			return _msg.c_str();
		}

		string _msg;
	};
};
#pragma once
