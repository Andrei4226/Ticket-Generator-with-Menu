#include <iostream>
#include "event.h"
#include "date.h"
#include "client.h"
#include "ticket.h"
using namespace std;
int main()
{
	cout << "Welcome!";
	string name_even;
	cout << "Enter the name of the event: ";
	cin >> name_even;
	cout << endl;
	cout << "Enter the location: ";
	string location2;
	char* location = new char[location2.length()+1];
	cin >> location2;
	strcpy_s(location, location2.length()+1, location2.c_str());
	cout << endl;
	event a(name_even, location);
	a.setLocation(location);
	cout << a.getLocation();
	event b(a);
	event c = a;

	string location3;
	char* new_location = new char[location3.length() + 1];
	cin >> location3;
	strcpy_s(new_location, location3.length() + 1, location3.c_str());
	cout << endl;
	c.setLocation(new_location);
	cout << c.getLocation() << endl;
	c.setName_event("Circ");
	cout << c.getName_event() << endl;
	c.setnrMaxTickets(200);
	cout << c.getnrMaxTickets() << endl;
	cout << c.getnrMaxRows() << endl;
	cout << c.getnrMaxColumns() << endl;
	cout << c.the_current_number_tickets_left() << endl;
	cout << c.the_number_tickets_sold() << endl;
	if (c.check() == true)
	{
		cout << "The number of tickets is eqal with columns * rows";
		cout << endl;
	}
	else
	{
		cout << "The number of tickets is not eqal with columns * rows";
		cout << endl;
	}
	if (c.operator<(10) < 10)
	{
		cout << "hurry up!!there are only 10 tickets left" << endl;
	}
	else
	{
		cout << "There are enough tickets!" << endl;
	}
	cin >> c;
	cout << endl;
	cout << c;
	cout << endl;
	int* v = new int[1];
	for (int i = 0; i < 1; i++)
	{
		cin >> v[i]; //hour 16
	}
	date d(2022, 5, 13, v, 1);
	date dat(d);
	date datele = dat;
	datele.setYear(2023);
	cout << datele.getYear() << endl;
	datele.setMonth(10);
	cout << datele.getMonth() << endl;
	datele.setDay(5);
	cout << datele.getDay() << endl;
	datele.setLengthStartTime(3);
	cout << datele.getLengthStartTime() << endl;
	datele.setStartTime(v, 1);
	cout << datele.getStartTime() << endl;
	cout << datele.operator[](0) << endl;
	if (datele.operator!() == true)
	{
		cout << "Length start time is valid" << endl;
	}
	else
	{
		cout <<"Length start time is not valid" << endl;
	}
	cout << datele.FirstHalfOrSecondHalf(5) << endl;
	cout << datele.Season(10) << endl;
	cin >> dat;
	cout << dat;
	cout << endl;

	char* ex = new char[100];
	cin >> ex;
	char* exe = new char[100];
	cin >> exe;
	client cl(ex, exe, 15, "student");
	client c3(cl);
	client c5 = cl;
	char* name1 = new char[100];
	cin >> name1;
	char* name2 = new char[100];
	cin >> name2;
	cl.setFirstName(name1);
	cout << cl.getFirstName() << endl;
	cl.setLastName(name2);
	cout << cl.getLastName() << endl;
	cl.setAge(22);
	cout << cl.getAge() << endl;
	cl.setCategory("pupil");
	cout << cl.getCategory() << endl;
	cin >> cl;
	cout << cl;
	cout << endl;
	client* clem = new client[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> clem[i];
	}
	cout << cl.average_age_all_round(clem,3) << endl;
	cout << cl.average_age_categoryStudent_round(clem, 3, "student") << endl;
	if (cl.operator<=(18) == true)
	{
		cout << "minor" << endl;
	}
	else
	{
		cout << "major" << endl;
	}
	if (cl.operator==(18) == true)
	{
		cout << "Access allowed on the basis of a bulletin" << endl;
	}
	else
	{
		cout << "Not allowed" << endl;
	}
	cin >> cl;
	cout << cl << endl;

	ticket ti(1, 2, 100, "Vip");
	ticket tip = ti;
	ticket tipar(ti);
	cout << tip.getID() << endl;
	tip.setRow(10);
	cout << tip.getRow() << endl;
	tip.setColumn(10);
	cout << tip.getColumn() << endl;
	tip.setArea("Standard");
	cout << tip.getArea(1,1);
	tip.setpriceStandard(100);
	cout << tip.getpriceStandard() << endl;
	tip.setpriceVip(250);
	cout << tip.getpriceVip();
	tip.setPriceTicket("Standard");
	cout << tip.getPriceTicket();
	cout << tip.sum_price_tickets_areaStandard_sell() << endl;
	cout << tip.sum_price_tickets_areaVip_sell() << endl;
	cin >> ti;
	cout << ti;

	//cout << "Do you want a ticket?";
	//cout << "1 = Yes" << endl;
	//cout << "2 = No" << endl;
	//int i;
	//cin >> i;
	//if (i == 1 || i == 2)
	//{
	//	switch (i)
	//	{
	//	case 1:
	//	{
	//	//metoda;
	//		break;
	//	}
	//	case 2:
	//	{
	//		cout << "All right!" << endl;
	//		break;
	//	}
	//	}
	//}
	//else
	//{
	//	cout << "Error";
	//}
}

