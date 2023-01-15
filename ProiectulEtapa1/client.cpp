#include "client.h"
#include <string>
#include"Disabilities.h"
client::client()
{
	first_name = nullptr;
	last_name = nullptr;
	age = NULL;
	category = "N/A";
}
client::client(char* first_name, char* last_name, int age, string category)
{
	if (first_name != nullptr)
	{
		this->first_name = new char[strlen(first_name) + 1];
		strcpy_s(this->first_name, strlen(first_name) + 1, first_name);
	}
	else
	{
		this->first_name = nullptr;
	}
	if (last_name != nullptr)
	{
		this->last_name = new char[strlen(last_name) + 1];
		strcpy_s(this->last_name, strlen(last_name) + 1, last_name);
	}
	else
	{
		this->last_name = nullptr;
	}
	if (age > 5 && age <= 100)
	{
		this->age = age;
	}
	else
	{
		this->age = NULL;
	}
	const char* buffer = (category).c_str();
	if ((_stricmp(buffer, "student") == 0) || (_stricmp(buffer, "retired") == 0) || (_stricmp(buffer, "adult") == 0) || (_stricmp(buffer, "child") == 0) || (_stricmp(buffer, "pupil") == 0))
	{
		this->category = category;
	}
	else
	{
		this->category = "N/A";
	}
}
client::client(const client& c)
{
	if (c.first_name != nullptr)
	{
		this->first_name = new char[strlen(c.first_name) + 1];
		strcpy_s(this->first_name, strlen(c.first_name) + 1, c.first_name);
	}
	else
	{
		this->first_name = nullptr;
	}
	if (c.last_name != nullptr)
	{
		this->last_name = new char[strlen(c.last_name) + 1];
		strcpy_s(this->last_name, strlen(c.last_name) + 1, c.last_name);
	}
	else
	{
		this->last_name = nullptr;
	}
	if (c.age > 5 && c.age <= 100)
	{
		this->age = c.age;
	}
	else
	{
		this->age = NULL;
	}
	const char* buffer = (c.category).c_str();
	if ( (_stricmp(buffer, "student") == 0) || (_stricmp(buffer, "retired")==0) || (_stricmp(buffer, "adult")==0) || (_stricmp(buffer, "child")==0) || (_stricmp(buffer, "pupil") == 0))
	{
		this->category = c.category;
	}
	else
	{
		this->category = "N/A";
	}
}
client& client::operator=(const client& c)
{
	if (this != &c)
	{
		if (this->first_name != nullptr)
		{
			delete[] this->first_name;
		}
		if (c.first_name != nullptr)
		{
			this->first_name = new char[strlen(c.first_name) + 1];
			strcpy_s(this->first_name, strlen(c.first_name) + 1, c.first_name);
		}
		else
		{
			this->first_name = nullptr;
		}
		if (this->last_name != nullptr)
		{
			delete[] this->last_name;
		}
		if (c.last_name != nullptr)
		{
				this->last_name = new char[strlen(c.last_name) + 1];
				strcpy_s(this->last_name, strlen(c.last_name) + 1, c.last_name);
		}
		else
		{
			this->last_name = nullptr;
		}
		if (c.age > 5 && c.age <= 100)
		{
			this->age = c.age;
		}
		else
		{
			this->age = NULL;
		}
		const char* buffer = (c.category).c_str();
		if ((_stricmp(buffer, "student") == 0) || (_stricmp(buffer, "retired") == 0) || (_stricmp(buffer, "adult") == 0) || (_stricmp(buffer, "child") == 0) || (_stricmp(buffer, "pupil") == 0))
		{
			this->category = c.category;
		}
		else
		{
			this->category = "N/A";
		}
	}
	return *this;
}
void client::setFirstName(char* first_name)
{
	if (first_name != nullptr) 
	{
		delete[] this->first_name;
		this->first_name = new char[strlen(first_name) + 1];
		strcpy_s(this->first_name, strlen(first_name) + 1, first_name);
	}
}
char* client::getFirstName()
{
	if (this->first_name != nullptr)
	{
		char* copy = new char[strlen(first_name) + 1];
		strcpy_s(copy, strlen(first_name) + 1, this->first_name);
		return copy;
	}
	return nullptr;
}

void client::setLastName(char* last_name)
{
	if (last_name != nullptr)
	{
		delete[] this->last_name;
		this->last_name = new char[strlen(last_name) + 1];
		strcpy_s(this->last_name, strlen(last_name) + 1, last_name);
	}
}
char* client::getLastName()
{
	if (this->last_name != nullptr)
	{
		char* copy = new char[strlen(last_name) + 1];
		strcpy_s(copy, strlen(last_name) + 1, this->last_name);
		return copy;
	}
	return nullptr;
}

void client::setAge(int age)
{
	if (age > 5 && age <= 100)
	{
		this->age = age;
	}
}
int client::getAge()
{
	return this->age;
}

void client::setCategory(string category)
{
	const char* buffer = (category).c_str();
	if ((_stricmp(buffer, "student") == 0) || (_stricmp(buffer, "retired") == 0) || (_stricmp(buffer, "adult") == 0) || (_stricmp(buffer, "child") == 0) || (_stricmp(buffer, "pupil") == 0))
	{
		this->category = category;
	}
}

string client::getCategory()
{
	return category;
}

void client:: print()
{
	cout << "Other: The customer is expected at the show together with the identity document." << endl;
}
void Disabilities::print()
{
	cout << "Other: The client with dysfunctions will have free medical support and guidance throughout the event." << endl;
}
void client::helpful_material(string material)
{
	cout << "You have a special entrance so that there is as much convenience as possible!" << endl;
}
void Disabilities::helpful_material(string material)
{
	cout << "Your mobility aid: " << material << endl;
}
//void Disabilities::print_special()
//{
//	cout << "Ati selectat tipul de bilet pt o persoana cu nevoi speciale";
//}


int client::average_age_all_round(client* cl, int nr_clienti)
{
	double sum_age = 0;
	if (cl!=nullptr && nr_clienti > 0)
	{
		for (int i = 0; i < nr_clienti; i++)
		{
			sum_age = sum_age + cl[i].age;
		}
	}
	int round_age = sum_age / nr_clienti;
	return round_age;
}
int client::average_age_categoryStudent_round(client* cl, int nr_clienti,string category)
{
	if (category == "student")
	{
		double sum_age = 0;
		if (cl != nullptr && nr_clienti > 0)
		{
			for (int i = 0; i < nr_clienti; i++)
			{
				sum_age = sum_age + cl[i].age;
			}
		}
		int round_age= sum_age / nr_clienti;
		return round_age;
	}
}
bool client::operator <= (int restriction)
{
	string output;
	restriction = 18;
	if (this->age <= restriction-1)
	{
		return true; //minor;
	}
	return false; //adult
}
bool client::operator ==(int restriction)
{
	restriction = 18;
	if (this->age == 18)
	{
		return true; //Access allowed on the basis of a bulletin
	}
	return false; //Access allowed with parental consent
}

istream& operator>>(istream& in, client& c)
{
	cout << "First Name: ";
		delete[] c.first_name;
		string buffer1;
		in >> buffer1;
		c.first_name = new char[buffer1.length()+1];
		strcpy_s(c.first_name,buffer1.length()+1, buffer1.c_str());
	cout << endl;
	cout << "Last Name: ";
		delete[] c.last_name;
		string buffer2;
		in >> buffer2;
		c.last_name = new char[buffer2.length()+1];
		strcpy_s(c.last_name, buffer2.length()+1, buffer2.c_str());
	cout << endl;
	cout << "Age: ";
	in >> c.age;
	cout << endl;
	cout << "Category(lowercase letters only): ";
	in >> c.category;
	return in;
}

ostream& operator<<(ostream& out, client c)
{
		out << "First Name: " << c.first_name << endl;
		out << "Last Name: " << c.last_name << endl;
	out << "Age: " << c.age << endl;
	out << "Category: " << c.category << endl;
	return out;
}
	






	Disabilities::Disabilities()
	{
		problem = "N/A";
		severity = 0;
	}
	//calling the base constructor
	Disabilities::Disabilities(char* first_name, char* last_name, int age, string category,
		string problem) : client(first_name, last_name, age, category)
	{
		this->problem = problem;
		this->severity = 0;
	}

	//calling the base constructor in the case of the copy constructor
	Disabilities::Disabilities(const Disabilities& ds) : client(ds)
	{
		this->severity= ds.severity;
		this->problem = ds.problem;
	}
	Disabilities& Disabilities:: operator=(const Disabilities& ds)
	{
		if (this != &ds)
		{
			client::operator=(ds);
			this->severity = ds.severity;
			this->problem = ds.problem;
		}
		return *this;
	}

ostream& operator<<(ostream& out, Disabilities d)
{
	//out << (client)d << endl;
	out << "Problem: " << d.problem << endl;
	out << "Severity: " << d.severity << endl;
	return out;
}

istream& operator>>(istream& in, Disabilities& d)
{
	//in >> (client&)d;
	cout << "Problem: ";
	in >> d.problem;
	cout << "Severity: ";
	in >> d.severity;
	return in;
}



