#pragma once
#include<iostream>
#include "event.h"

using namespace std;
class Other_event : public event
{
private:
	string temperatura;
	int sev
public:
	Disabilities();
	Disabilities(char* first_name, char* last_name, int age, string category, string problem);
	Disabilities(const Disabilities& ds);
	Disabilities& operator=(const Disabilities& ds);
	friend ostream& operator<<(ostream& out, Disabilities d);
	friend istream& operator>>(istream& in, Disabilities& d);
	void print();
	void helpful_material(string material);
};