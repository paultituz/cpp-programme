#include "iostream"
#include "string"
#include "person.h"
#pragma warning(disable:4996)
using namespace std;

	// constructor
	person::person(char const* nm , int ae ) 
	{
		name = new char[ strlen( nm ) + 1 ];
		strcpy( name, nm );//copy
		age = ae;
	}

	// copy constructor
	person::person( person& m ) 
	{
		age = m.age;
		name = new char[ strlen( m.name ) + 1 ];
		strcpy( name, m.name );// member functions
	}

	// destructor
	person::~person()
	{
		delete [] name;//clear
	}

	// assignment operator
	person& person::operator=(person& m)
	{
		age = m.age;

		delete[]name;//clear
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name); //copy
		return *this;
	}

	// member functions
	void person::setName(char const* nm ) 
	{
		delete[]name;//clear
		name = new char[strlen(nm) + 1];
		strcpy(name, nm);// member functions
	}

	void person::setAge(int ae) 
	{
		age = ae;
	}

	string person::getName() 
	{
		return name;
	}

	int person::getAge()
	{
		return age;
	}

