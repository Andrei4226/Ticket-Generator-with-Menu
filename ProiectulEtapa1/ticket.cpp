#include "ticket.h"
#include "event.h"

int ticket::express = 4;
float ticket::priceStandard = 100;
float ticket::priceVip = 250;
int ticket::ticketsStandardSell = 0;
int ticket::ticketsVipSell = 0;
ticket::ticket()
{
	ID = pow(express, 2) * express/2 - express; //hard expression because the id should not be guessed
	express = express + 2;
	place = nullptr;
	area = "N/A";
	nrRow = 0;
	nrColumn = 0;
	price = 0;
}
ticket::ticket(int nrRow, int nrColumn,float price, string area)
{
	const char* buffer = (area).c_str();
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0) 
	{
		this->price = ticket::priceStandard;
	}
	else
	{
		this->price = 0;
	}
	this->ID = pow(express, 2) * express / 2 - express;
	this->express = this->express + 2;

	if (nrRow <= c.getnrMaxRows() && nrColumn <= c.getnrMaxColumns() && nrRow>0 && nrColumn>0)
	{
		this->nrRow = nrRow;
		this->nrColumn = nrColumn;
		this->place = new int*[c.getnrMaxRows()];
		for (int i = 0; i < c.getnrMaxRows(); i++) 
		{
			this->place[i] = new int[c.getnrMaxColumns()];
		}
		this->place[nrRow][nrColumn] = ID;
		if (strcmp(buffer, "Vip") == 0)
		{
			ticketsVipSell++;
		}
		if (strcmp(buffer, "Standard") == 0)
		{
			ticketsStandardSell++;
		}
	}
	else {
		
		this->nrRow = NULL;
		this->nrColumn = NULL;
		this->place = nullptr;
	}
	this->area = area;
}


ticket::ticket(const ticket& tic)
{
	const char* buffer = (tic.area).c_str();
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0)
	{
		this->price = ticket::priceStandard;
	}
	else
	{
		this->price = 0;
	}
	this->ID = tic.express;
	this->express = tic.express + 2;

	if (tic.nrRow > 0 && tic.nrRow<=c.getnrMaxRows() && tic.nrColumn > 0 && tic.nrColumn<=c.getnrMaxColumns())
	{
		this->nrRow = tic.nrRow;
		this->nrColumn = tic.nrColumn;
		this->place = new int* [c.getnrMaxRows()];
		for (int i = 0; i < c.getnrMaxRows(); i++)
		{
			this->place[i] = new int[c.getnrMaxColumns()];
		}
		this->place[tic.nrRow][tic.nrColumn] = ID;
	}
	else {

		this->nrRow = NULL;
		this->nrColumn = NULL;
		this->place = nullptr;
	}
	this->area = tic.area;
}

ticket& ticket::operator=(const ticket& tic) 
{
	if (this != &tic)
	{
		const char* buffer = (tic.area).c_str();
		if (strcmp(buffer, "Vip") == 0) {
			this->price = ticket::priceVip;
		}
		else if (strcmp(buffer, "Standard") == 0)
		{
			this->price = ticket::priceStandard;
		}
		else
		{
			this->price = 0;
		}
		this->ID = tic.express;
		this->express = tic.express + 2;
		if (place != nullptr)
		{
			for (int i = 0; i < c.getnrMaxRows(); i++)
			{
				delete[] place[i];
			}
			delete[] place;
			place = nullptr;
		}
		if (tic.nrRow > 0 && tic.nrRow <= c.getnrMaxRows() && tic.nrColumn > 0 && tic.nrColumn <= c.getnrMaxColumns())
		{
			this->nrRow = tic.nrRow;
			this->nrColumn = tic.nrColumn;
			this->place = new int* [c.getnrMaxRows()];
			for (int i = 0; i < c.getnrMaxRows(); i++)
			{
				this->place[i] = new int[c.getnrMaxColumns()];
			}
			this->place[tic.nrRow][tic.nrColumn] = ID;
		}
		else {

			this->nrRow = NULL;
			this->nrColumn = NULL;
			this->place = nullptr;
		}
		this->area = tic.area;
	}
	return *this;
}

ticket::~ticket()
{
	if (place != NULL) {
		for (int i = 0; i < c.getnrMaxRows(); i++) {
			delete[] place[i];
		}
		delete[] place;
		place = nullptr;
	}
}

int ticket::getID()
{
	return ID;
}

int ticket::getRow() 
{
	return nrRow;
}
void ticket::setRow(int row)
{
	if (row <= c.getnrMaxRows())
	{
		this->nrRow = row;
	}
}

void ticket::setColumn(int column)
{
	if (column <= c.getnrMaxColumns())
	{
		this->nrColumn = column;
	}
}
int ticket::getColumn() 
{
	return nrColumn;
}

int ticket::getpriceStandard()
{
	return ticket::priceStandard;
}
void ticket::setpriceStandard(int priceStandard)
{
	this->priceStandard = priceStandard;
}

int ticket::getpriceVip()
{
	return ticket::priceVip;
}
void ticket::setpriceVip(int priceVip)
{
	this->priceVip = priceVip;
}
int ticket::getPriceTicket()
{
	return this->price;
}

void ticket::setPriceTicket(string area)
{
	const char* buffer = (area.c_str());
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0)
	{
		this->price = ticket::priceStandard;
	}
}

int ticket::getArea(int nrRand, int nrColoana) 
{
	if (nrRand >= 0 && nrColoana >= 0 && nrRand <= c.getnrMaxRows() && nrColoana <= c.getnrMaxColumns()) 
	{
		return place[nrRand][nrColoana];
	}
	return -1;
}

void ticket::setArea(string area)
{
	const char* buffer = (area.c_str());
	if (strcmp(buffer, "Vip") == 0)
	{
		this->area = area;
	}
}
string ticket::setArea()
{
	return this->area;
}
istream& operator>>(istream& in, ticket& tic) 
{
	cout << "Area: ";
	in >> tic.area;
	cout << endl;
	cout << "Column: ";
	in >> tic.nrColumn;
	cout << endl;
	cout << "Column: ";
	in >> tic.nrRow;
	cout << endl;
	return in;
}
ticket ticket::operator*(int price) 
{
	ticket copie = *this;
	copie.priceStandard = copie.priceStandard * price;
	return copie;
}
ticket operator+(int price, ticket tic) 
{
	tic.priceStandard = tic.priceStandard + price;
	return tic;
}
float ticket::sum_price_tickets_areaVip_sell()
{
	float sum = 0;
	sum = sum + (priceVip * ticketsVipSell);
	return sum;
}
float ticket::sum_price_tickets_areaStandard_sell()
{
	float sum = 0;
	sum = sum + (priceStandard * ticketsStandardSell);
	return sum;
}
ticket ticket::operator-(int price)
{
	ticket copie = *this;
	if(price<= copie.priceVip/2)
	copie.priceVip = copie.priceVip - price;
	return copie;
}

ostream& operator<<(ostream& out, ticket tic) 
{
	out << "Your area: ";
	const char* buffer = (tic.area.c_str());
	if (strcmp(buffer, "Vip") == 0 || strcmp(buffer, "Standard") == 0)
	{
		out << tic.area;
	}
	out << endl;
	out << "Price of ticket VIP: ";
	out << tic.priceVip;
	out << endl;
	out << "Price of ticket Standard: ";
	out << tic.priceStandard;
	if (tic.ID != 0)
	{
		out << "ID: " << tic.ID;
	}
	out << endl;
	out << "Column: ";
	out << tic.nrColumn;
	out << endl;
	out << "Row: ";
	out << tic.nrRow;
	return out;
}