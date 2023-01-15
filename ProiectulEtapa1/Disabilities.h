#pragma once
#include<iostream>
#include "client.h"

using namespace std;
class Disabilities : public client
{
private:
	string problem;
	int severity;
public:
	Disabilities();
	Disabilities(char* first_name, char* last_name, int age, string category,string problem);
	Disabilities(const Disabilities& ds);
	Disabilities& operator=(const Disabilities& ds);
	friend ostream& operator<<(ostream& out, Disabilities d);
	friend istream& operator>>(istream& in, Disabilities& d);
	void print();
	void helpful_material(string material);
	/*virtual void print_special() = 0;*/
};