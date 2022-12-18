#pragma once
#include<iostream>
#include "event.h"

using namespace std;
class ticket
{
private:

	float price;
	float ID;
    int** place;
	int nrRow;
	int nrColumn;
	string area;
	static float priceStandard;
	static float priceVip;
	static int express;
	event c;
	static int ticketsStandardSell;
	static int ticketsVipSell;
public:
	ticket();
	ticket(int nrRow, int nrColumn, float price, string area);
	ticket(const ticket& tic);
	ticket& operator=(const ticket& ticket);
	~ticket();
	int getID();
	int getRow();
	void setColumn(int column);
	int getColumn();
	void setRow(int row);
	int getpriceStandard();
	void setpriceStandard(int priceStandard);
	int getpriceVip();
	void setpriceVip(int priceVip);
	int getPriceTicket();
	void setPriceTicket(string area);
	int getArea(int nrRand, int nrColoana);
	void setArea(string area);
	string setArea();
	friend istream& operator>>(istream& in, ticket& tic);
	friend ostream& operator<<(ostream& out, ticket tic);
	ticket operator*(int price);
	friend ticket operator+(int price, ticket tic);
	ticket operator-(int price);
	float sum_price_tickets_areaVip_sell();
	float sum_price_tickets_areaStandard_sell();
};

