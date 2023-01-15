
#include <iostream>
#include<string>
#include "event.h"
#include<fstream>
#include "date.h"
#include "client.h"
#include "ticket.h"
#include "Disabilities.h"
#include<cstring>;
#include<stdlib.h>;
#include "otherEvent.h"
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
 ofstream f("file.bin", ios::out | ios::binary);
 int alege;
 int start_program = 0;
 while(start_program==0)
 {
 cout << "1.Menu" << endl;
 cout << "2.Txt" << endl;
 cout << "Option: ";
 cin >> alege;
		if(alege==1)
		{
			start_program = 1;
		string name_even1 = "MovieOne";
		string locationMovie1 = "AFI Cotroceni";
		char* location = new char[locationMovie1.length() + 1];
		strcpy_s(location, locationMovie1.length() + 1, locationMovie1.c_str());
		event Movie(name_even1, location);
		Movie.setName_event("MovieOne");
		Movie.setLocation(location);
		Movie.setnrMaxTickets(100);
		cout << endl;
	
		date date_Movie;
		int* start_Movie = new int[3];
		start_Movie[0] = 15;
		start_Movie[1] = 18;
		start_Movie[2] = 22;
		date_Movie.setYear(2022);
		date_Movie.setMonth(3);
		date_Movie.setDay(20);
		date_Movie.setLengthStartTime(3);
		date_Movie.setStartTime(start_Movie, 3);
	
	
		string name_even2 = "TheatricalPiece";
		string TheatricalName = "ACT Theatre";
		char* location2 = new char[TheatricalName.length() + 1];
		strcpy_s(location2, TheatricalName.length() + 1, TheatricalName.c_str());
		event Theatrical(name_even2, location2);
		Theatrical.setName_event("TheatricalPiece");
		Theatrical.setLocation(location2);
		Theatrical.setnrMaxTickets(100);
		cout << endl;
	
		date date_Theatrical;
		int* start_Theatrical = new int[4];
		start_Theatrical[0] = 15;
		start_Theatrical[1] = 17;
		start_Theatrical[2] = 19;
		start_Theatrical[3] = 21;
		date_Theatrical.setYear(2022);
		date_Theatrical.setMonth(8);
		date_Theatrical.setDay(10);
		date_Theatrical.setLengthStartTime(4);
		date_Theatrical.setStartTime(start_Theatrical, 4);
	
	
	
		string name_even3 = "Football_Match";
		string MatchName = "ArenaNationala";
		char* location3 = new char[MatchName.length() + 1];
		strcpy_s(location3, MatchName.length() + 1, MatchName.c_str());
		event Match(name_even3, location3);
		Match.setName_event("Football_Match");
		Match.setLocation(location3);
		Match.setnrMaxTickets(100);
		cout << endl;
	
		date date_Match;
		int* start_Match = new int[2];
		start_Match[0] = 15;
		start_Match[1] = 21;
		date_Match.setYear(2022);
		date_Match.setMonth(10);
		date_Match.setDay(13);
		date_Match.setLengthStartTime(2);
		date_Match.setStartTime(start_Theatrical, 2);
		int bufferix = 0;
		int ticketssellVip = 1;
		int ticketssellStandard = 1;
		cout << "Welcome!";
		cout << endl;
		int start = 1;
		while (start == 1)
		{
			int option1;
			cout << "Choose one of the events below:" << endl;
			cout << "1." << Movie.getName_event() << endl;
			cout << "2." << Theatrical.getName_event() << endl;
			cout << "3." << Match.getName_event() << endl;
			cout << "4. Exit" << endl;
			cout << "Chosen option: ";
			int option2;
			cin >> option2;
			if (option2 == 4)
			{
				f.close();
				exit(0);
			}
			int ok = 1;
			if (option2 == 1)
			{
				int checker_virtual = 0;
				int** place = new int* [10];
				for (int i = 0; i < 10; i++)
				{
					place[i] = new int[10];
				}
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						place[i][j] = 0;
				int nr = 0;
				while (ok == 1)
				{
					cout << "Choose the desired option:" << endl;
					cout << "1. Event details" << endl;
					cout << "2. Ticket reservation" << endl;
					cout << "3. Number of tickets available" << endl;
					cout << "4. Total number of tickets" << endl;
					cout << "5. Total number of tickets sold" << endl;
					cout << "6. View matrix places" << endl;
					cout << "7. Verification your ID" << endl;
					cout << "8. Lottery" << endl;
					cout << "9. Exit" << endl;
					int buffer_2 = 1;
					while (buffer_2 == 1)
					{
						int buffer_1 = 0;
						cout << "My option: ";
						cin >> option1;
						for (int i = 1; i <= 9; i++)
						{
							if (option1 == i)
							{
								buffer_1= 1;
							}
						}
						if (buffer_1 == 0)
						{
							cout << "Please try again.";
							cout << endl;
	
						}
						if (buffer_1 == 1)
						{
							buffer_2 = 0;
						}
					}
					if (option1 == 9)
					{
						exit(0);
					}
					if (option1 == 1)
					{
						cout << "Name:";
						cout << Movie.getName_event();
						cout << endl;
						cout << "Location:";
						cout << Movie.getLocation();
						cout << endl;
						cout << "Maximum number of tickets:";
						cout << Movie.getnrMaxTickets();
						cout << endl;
						cout << "The current number of tickets left:";
						cout << Movie.the_current_number_tickets_left();
						cout << endl;
						cout << "Year:";
						cout << date_Movie.getYear();
						cout << endl;
						cout << "Mouth:";
						cout << date_Movie.getMonth();
						cout << endl;
						cout << "Day:";
						cout << date_Movie.getDay();
						cout << endl;
						otherEvent* o = NULL;
						o = &Movie;
						cout << endl;
						o->print_temp();
						cout << endl;
						cout << "Available hours:";
						for (int j = 0; j < date_Movie.getLengthStartTime(); j++)
						{
							cout << date_Movie.getStartTime()[j];
							if (j == date_Movie.getLengthStartTime() - 1)
							{
								cout << ".";
							}
							else
							{
								cout << ", ";
							}
						}
						cout << endl;
						if (Movie.operator<(10) == true)
						{
							cout << "Hurry up!!there are only 10 tickets left." << endl;
						}
						else
						{
							cout << "There are enough tickets for the moment!" << endl;
						}
						cout << date_Movie.FirstHalfOrSecondHalf(date_Movie.getDay());
						cout << endl;
						cout << date_Movie.Season(date_Movie.getMonth());
						cout << endl;
					}
					int ok1 = 0;
					
					while (ok1 == 0)
					{
						int allowed = 1;
						if (option1 == 2)
						{
							client person_1;
							cin >> person_1;
							cout << person_1;
							if (person_1.operator<=(18) == true)
							{
								cout << "About: minor." << endl;
							}
							else
							{
								cout << "About: major." << endl;
								cout << "Access allowed on the basis of a card ID." << endl;
							}
							if (person_1.operator<=(18) != true)
							{
								cout << "Status: Allowed." << endl;
							}
							else
							{
								cout << "Status: Not allowed." << endl;
								allowed = 0;
							}
							if (allowed == 1)
							{
								cout << endl << endl;
								ticket person1;
								cin >> person1;
								cout << person1;
								int check;
								cout << endl;
								cout << "Do you have a serious health problem/disability?" << endl;
								cout << "Press the '1' key if you have one" << endl;
								cout << "Press any key if you haven't one" << endl;
								cout << endl;
								checker_virtual = 0;
								cout << "My option: ";
								cin >> check;
								if (check == 1)
								{
									checker_virtual = 1;
									Disabilities person_1;
									cin >> person_1;
									cout << endl << person_1;
									cout << "Do you have a mobility device? " << endl;
									cout << "Press the '1' key if you have one" << endl;
									int mobility;
									cin >> mobility;
									if (mobility == 1)
									{
										cout << "Your support: " << endl;
										string material;
										cin >> material;
										client* personProb1;
										Disabilities problemTwo;
										personProb1 = &problemTwo;
										personProb1->helpful_material(material);
									}
								}
								cout << endl;
								cout << endl << endl;
								cout << "Options:";
								cout << endl;
								cout << "1.Buy";
								cout << endl;
								cout << "2.Exit";
								cout << endl;
								cout << "Your option: ";
								int choise;
								cin >> choise;
								if (choise == 2)
								{
									ok1 = 1;
								}
								if (choise == 1)
								{
									bufferix = 0;
									int buffer_verification = 0;
	
									ticket bilet1(person1.getRow(), person1.getColumn(), person1.getPriceTicket(), person1.getArea(), place);
									int verificationPlace = 0;
									for (int i = 0; i < 10; i++)
									{
										for (int j = 0; j < 10; j++)
										{
											if (place[bilet1.getRow()][bilet1.getColumn()]==0)
											{
											  verificationPlace = 1;
												
												bufferix = 1;
											}
										}
									}
									if (verificationPlace == 1)
									{
										cout << "The place is valid!" << endl;
									}
									if (bufferix == 1)
									{

										bilet1.setID(bilet1.getRow(), bilet1.getColumn(), place);
										cout << "Ticket sold!" << endl;
										if (bilet1.getArea() == "standard")
										{
											ticket::setticketsStandardSell(ticketssellStandard);
											ticketssellStandard++;
										}
										if (bilet1.getArea() == "vip")
										{
											ticket::setticketsVipSell(ticketssellVip);
											ticketssellVip++;
											
										}
										
										f.write(reinterpret_cast<char*>(&bilet1), sizeof(bilet1));
										

										ticket::setticketsSell(ticket::getticketsStandardSell(), ticket::getticketsVipSell());
										cout << endl;
										cout << "ID: " << place[bilet1.getRow()][bilet1.getColumn()] << endl;
										cout << "Ticket validation:";
										cout << endl;
										for (int i = 0; i < 10; i++)
										{
											for (int j = 0; j < 10; j++)
											{
												if (place[i][j] != 0)
												{
													buffer_verification = 1;
													nr = 1;
												}
											}
										}
										if (nr == 1)
										{
											cout << "The ticket is valid" << endl;
										}
									}
									if (buffer_verification == 0 && nr!=1)
									{
										cout << "The ticket is invalid" << endl;
										nr = 0;
									}
									cout << endl;
									ok1 = 1;
								}
								ok1 = 1;
	
							}
						}
						ok1 = 1;
					}
					if (option1 == 3)
					{
							cout << endl << Movie.getnrMaxTickets() - ticket::getticketsSell() << endl;
	
					}
					if (option1 == 4)
					{
						cout << endl<<Movie.getnrMaxTickets() << endl;
					}
					if (option1 == 5)
					{
						cout << endl;
						cout << ticket::getticketsSell() << endl;
					}
					if (option1 == 6)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								cout << place[i][j] << " ";
							}
							cout << endl;
						}
					}
					if (option1 == 7)
					{
						int buffer_ID = 0;
						int ID1;
						cout << endl;
						cout << "Write your ID: ";
						cin >> ID1;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (place[i][j] == ID1)
								{
									buffer_ID = 1;
								}
							}
						}
						cout << endl;
						if (buffer_ID==1)
						{
							cout << "Yes, you have a valid ticket. We are waiting for you at the event!!" << endl;
							if (checker_virtual == 1)
							{
								if (checker_virtual == 1)
								{
									client* personProb1;
									Disabilities problemTwo;
									personProb1 = &problemTwo;
									personProb1->print();
								}
							}
						}
						else
						{
							cout << "The ticket does not exist :( ." << endl;
						}
					}
					if (option1 == 8)
					{
						cout << endl;
						cout << "List of ticket IDs purchased so far: " << endl;
						for (auto number : Movie.getVect())
						{
							cout << number << endl;
						}
						cout << "Your ID: ";
						int id_win;
						cin >> id_win;
						cout << endl;
						int id_verif = 0;
						for (int number : Movie.getVect())
						{
							if (id_win == number)
								id_verif = 1;
						}
						if (id_verif == 1)
						{
							cout << "The ID is valid." << endl;
						}
						else
						{
							cout << "Buy a ticket and come back to participate in the lottery!";
						}
						int position_won = 0;
						for (int i = 0; i < size(Movie.getVect()); i++)
						{
							if (((rand() % size(Movie.getVect()) == i)))
							{
								position_won = 1;
							}
						}
						cout << "The winning ID is: " << Movie.getElemVect(rand() % size(Movie.getVect())) << endl;
							if (id_win == Movie.getElemVect(rand() % size(Movie.getVect())))
							{
								cout << "You won!" << endl;
							}
							else
							{
							cout << "Better luck next time!" << endl;
							}

					}
				}
			}
			
	
	
	
	
	
	
	
	
	
	
		
			if (option2 == 2)
			{
				int checker_virtual2 = 0;
				int** place_t = new int* [10];
				for (int i = 0; i < 10; i++)
				{
					place_t[i] = new int[10];
				}
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						place_t[i][j] = 0;
				int nr = 0;
				while (ok == 1)
				{
					cout << "Choose the desired option:" << endl;
					cout << "1. Event details" << endl;
					cout << "2. Ticket reservation" << endl;
					cout << "3. Number of tickets available" << endl;
					cout << "4. Total number of tickets" << endl;
					cout << "5. Total number of tickets sold" << endl;
					cout << "6. View matrix places" << endl;
					cout << "7. Verification your ID" << endl;
					cout << "8. Lottery" << endl;
					cout << "9. Exit" << endl;
					int buffer_3 = 1;
					while (buffer_3 == 1)
					{
						int buffer_4 = 0;
						cout << "My option: ";
						cin >> option1;
						for (int i = 1; i <= 9; i++)
						{
							if (option1 == i)
							{
								buffer_4 = 1;
							}
						}
						if (buffer_4 == 0)
						{
							cout << "Please try again.";
							cout << endl;
	
						}
						if (buffer_4 == 1)
						{
							buffer_3 = 0;
						}
					}
					if (option1 == 9)
					{
						exit(0);
					}
					if (option1 == 1)
					{
						cout << "Name:";
						cout << Theatrical.getName_event();
						cout << endl;
						cout << "Location:";
						cout << Theatrical.getLocation();
						cout << endl;
						cout << "Maximum number of tickets:";
						cout << Theatrical.getnrMaxTickets();
						cout << endl;
						cout << "The current number of tickets left:";
						cout << Theatrical.the_current_number_tickets_left();
						cout << endl;
						cout << "Year:";
						cout << date_Theatrical.getYear();
						cout << endl;
						cout << "Mouth:";
						cout << date_Theatrical.getMonth();
						cout << endl;
						cout << "Day:";
						cout << date_Theatrical.getDay();
						cout << endl;
						otherEvent* o = NULL;
						o = &Theatrical;
						cout << endl;
						o->print_temp();
						cout << "Available hours:";
						for (int j = 0; j < date_Theatrical.getLengthStartTime(); j++)
						{
							cout << date_Theatrical.getStartTime()[j];
							if (j == date_Theatrical.getLengthStartTime() - 1)
							{
								cout << ".";
							}
							else
							{
								cout << ", ";
							}
						}
						cout << endl;
						if (Theatrical.operator<(10) == true)
						{
							cout << "hurry up!!there are only 10 tickets left" << endl;
						}
						else
						{
							cout << "There are enough tickets for the moment!" << endl;
						}
						cout << date_Theatrical.FirstHalfOrSecondHalf(date_Theatrical.getDay());
						cout << endl;
						cout << date_Theatrical.Season(date_Theatrical.getMonth());
						cout << endl;
					}
					int ok4 = 0;
	
					while (ok4 == 0)
					{
						int allowed2 = 1;
						if (option1 == 2)
						{
							client person_2;
							cin >> person_2;
							cout << person_2;
							int check2;
							cout << endl;
							cout << "Do you have a serious health problem/disability?" << endl;
							cout << "Press the '1' key if you have one" << endl;
							cout << "Press any key if you haven't one" << endl;
							cout << endl;
							cout << "My option: ";
							cin >> check2;
							if (check2 == 1)
							{
								int mobility = 1;
								if (mobility == 1)
								{
									cout << "Your support: " << endl;
									string material;
									cin >> material;
									client* personProb3;
									Disabilities problemThree;
									personProb3 = &problemThree;
									personProb3->helpful_material(material);
								}
								checker_virtual2 = 1;
								Disabilities person_2;
								cin >> person_2;
								cout << endl << person_2;
							}
							if (person_2.operator<=(18) == true)
							{
								cout << "About: minor." << endl;
							}
							else
							{
								cout << "About: major." << endl;
								cout << "Access allowed on the basis of a card ID." << endl;
							}
							if (person_2.operator<=(18) != true)
							{
								cout << "Status: Allowed." << endl;
							}
							else
							{
								cout << "Status: Not allowed." << endl;
								allowed2 = 0;
							}
							if (allowed2 == 1)
							{
								cout << endl << endl;
								ticket person2;
								cin >> person2;
								cout << endl;
								cout << person2;
	
								cout << endl << endl;
								cout << "Options:";
								cout << endl;
								cout << "1.Buy";
								cout << endl;
								cout << "2.Exit";
								cout << endl;
								cout << "Your option: ";
								int choise2;
								cin >> choise2;
								if (choise2 == 2)
								{
									ok4 = 1;
								}
								if (choise2 == 1)
								{
									bufferix = 0;
									int buffer_verification2 = 0;
	
									ticket bilet2(person2.getRow(), person2.getColumn(), person2.getPriceTicket(), person2.getArea(), place_t);
									int verificationPlace = 0;
									for (int i = 0; i < 10; i++)
									{
										for (int j = 0; j < 10; j++)
										{
											if (place_t[bilet2.getRow()][bilet2.getColumn()] == 0)
											{
												int verificationPlace = 1;
	
												bufferix = 1;
											}
										}
									}
									if (verificationPlace == 1)
									{
										cout << "The place is valid!" << endl;
									} 
									if (bufferix == 1)
									{
										bilet2.setID(bilet2.getRow(), bilet2.getColumn(), place_t);
										cout << "Ticket sold!";
										Theatrical.addElement(place_t[bilet2.getRow()][bilet2.getColumn()]);
										if (bilet2.getArea() == "standard")
										{
											ticket::setticketsStandardSell(ticketssellStandard);
											ticketssellStandard++;
										}
										if (bilet2.getArea() == "vip")
										{
											ticket::setticketsVipSell(ticketssellVip);
											ticketssellVip++;

										}
										f.write(reinterpret_cast<char*>(&bilet2), sizeof(bilet2));
										ticket::setticketsSell(ticket::getticketsStandardSell(), ticket::getticketsVipSell());
										cout << endl;
										cout << "Ticket validation:";
										cout << endl;
										cout << "ID: " << place_t[bilet2.getRow()][bilet2.getColumn()] << endl;
										cout << "Ticket validation:";
										cout << endl;
										for (int i = 0; i < 10; i++)
										{
											for (int j = 0; j < 10; j++)
											{
												if (place_t[i][j] != 0)
												{
													buffer_verification2 = 1;
													nr = 1;
												}
											}
										}
										if (nr == 1)
										{
											cout << "The ticket is valid" << endl;
										}
									}
									if (buffer_verification2 == 0 && nr!=1)
									{
										cout << "The ticket is invalid" << endl;
										nr = 0;
									}
									cout << endl;
									ok4 = 1;
								}
								ok4 = 1;
	
							}
						}
						ok4 = 1;
					}
					if (option1 == 3)
					{
						cout << endl << Theatrical.getnrMaxTickets() - ticket::getticketsSell() << endl;

					}
					if (option1 == 4)
					{
						cout << endl << Theatrical.getnrMaxTickets() << endl;
					}
					if (option1 == 5)
					{
						cout << endl;
						cout << ticket::getticketsSell() << endl;
					}
					if (option1 == 6)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								cout << place_t[i][j] << " ";
							}
							cout << endl;
						}
					}
					if (option1 == 7)
					{
						int buffer_ID2 = 0;
						int ID2;
						cout << endl;
						cout << "Write your ID: ";
						cin >> ID2;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (place_t[i][j] == ID2)
								{
									buffer_ID2 = 1;
								}
							}
						}
						cout << endl;
						if (buffer_ID2 == 1)
						{
							cout << "Yes, you have a valid ticket. We are waiting for you at the event!!" << endl;
							if (checker_virtual2 == 1)
							{
								client* personProb3;
								Disabilities problemThree;
								personProb3 = &problemThree;
								personProb3->print();
							}
						}
						else
						{
							cout << "The ticket does not exist :( ." << endl;
						}
					}
					if (option1 == 8)
					{
						cout << endl;
						cout << "List of ticket IDs purchased so far: " << endl;
						for (auto number : Theatrical.getVect())
						{
							cout << number << endl;
						}
						cout << "Your ID: ";
						int id_win;
						cin >> id_win;
						cout << endl;
						int id_verif = 0;
						for (int number : Theatrical.getVect())
						{
							if (id_win == number)
								id_verif = 1;
						}
						if (id_verif == 1)
						{
							cout << "The ID is valid." << endl;
						}
						else
						{
							cout << "Buy a ticket and come back to participate in the lottery!";
						}
						int position_won = 0;
						for (int i = 0;i<size(Theatrical.getVect());i++)
						{
							if (((rand() % size(Theatrical.getVect()) == i)))
							{
								position_won = 1;
							}
						}
						cout << "The winning ID is: " << Theatrical.getElemVect(rand() % size(Theatrical.getVect())) << endl;

								if (id_win == Theatrical.getElemVect(rand() % size(Theatrical.getVect())))
								{
									cout << "You won!" << endl;
								}
								else
								{
								cout << "Better luck next time!" << endl;
								}
						
					}
				}
			}
	
	
	
	
	
	
	
	
	
	
			if (option2 == 3)
			{
				int checker_virtual = 0;
				int** place_m = new int* [10];
				for (int i = 0; i < 10; i++)
				{
					place_m[i] = new int[10];
				}
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						place_m[i][j] = 0;
				int nr = 0;
				while (ok == 1)
				{
					cout << endl;
					cout << "Choose the desired option:" << endl;
					cout << "1. Event details" << endl;
					cout << "2. Ticket reservation" << endl;
					cout << "3. Number of tickets available" << endl;
					cout << "4. Total number of tickets" << endl;
					cout << "5. Total number of tickets sold" << endl;
					cout << "6. View matrix places" << endl;
					cout << "7. Verification your ID" << endl;
					cout << "8. Lottery" << endl;
					cout << "9. Exit" << endl;
					//7
					int buffer_7 = 1;
					while (buffer_7 == 1)
					{
						int buffer_8 = 0;
						cout << "My option: ";
						cin >> option1;
						for (int i = 1; i <= 9; i++)
						{
							if (option1 == i)
							{
								buffer_8 = 1;
							}
						}
						if (buffer_8 == 0)
						{
							cout << "Please try again.";
							cout << endl;
	
						}
						if (buffer_8 == 1)
						{
							buffer_7 = 0;
						}
					}
					if (option1 == 9)
					{
						exit(0);
					}
					if (option1 == 1)
					{
						cout << "Name:";
						cout << Match.getName_event();
						cout << endl;
						cout << "Location:";
						cout << Match.getLocation();
						cout << endl;
						cout << "Maximum number of tickets:";
						cout << Match.getnrMaxTickets();
						cout << endl;
						cout << "The current number of tickets left:";
						cout << Match.the_current_number_tickets_left();
						cout << endl;
						cout << "Year:";
						cout << date_Match.getYear();
						cout << endl;
						cout << "Mouth:";
						cout << date_Match.getMonth();
						cout << endl;
						cout << "Day:";
						cout << date_Match.getDay();
						cout << endl;
						otherEvent* o = NULL;
						o = &Match;
						cout << endl;
						o->print_temp();
						cout << endl;
						cout << "Available hours:";
						for (int j = 0; j < date_Match.getLengthStartTime(); j++)
						{
							cout << date_Match.getStartTime()[j];
							if (j == date_Match.getLengthStartTime() - 1)
							{
								cout << ".";
							}
							else
							{
								cout << ", ";
							}
						}
						cout << endl;
						if (Match.operator<(10) == true)
						{
							cout << "Hurry up!!there are only 10 tickets left." << endl;
						}
						else
						{
							cout << "There are enough tickets for the moment!" << endl;
						}
						cout << date_Match.FirstHalfOrSecondHalf(date_Match.getDay());
						cout << endl;
						cout << date_Match.Season(date_Match.getMonth());
						cout << endl;
					}
					int ok6 = 0;
	
					while (ok6 == 0)
					{
						int allowed3 = 1;
						if (option1 == 2)
						{
							client person_3;
							cin >> person_3;
							int check3;
							cout << endl;
							cout << "Do you have a serious health problem/disability?" << endl;
							cout << "Press the '1' key if you have one" << endl;
							cout << "Press any key if you haven't one" << endl;
							cout << endl;
							cout << "My option: ";
							cin >> check3;
							checker_virtual = 0;
							if (check3 == 1)
							{
								int mobility = 1;
								if (mobility == 1)
								{
									cout << "Your support: " << endl;
									string material;
									cin >> material;
									client* personProb;
									Disabilities problemOne;
									personProb = &problemOne;
									personProb->helpful_material(material);
								}
								checker_virtual = 1;
								Disabilities person_3;
								cin >> person_3;
								cout << endl << person_3;
							}
							cout << person_3;
							if (person_3.operator<=(18) == true)
							{
								cout << "About: minor." << endl;
							}
							else
							{
								cout << "About: major." << endl;
								cout << "Access allowed on the basis of a card ID." << endl;
							}
							if (person_3.operator<=(18) != true)
							{
								cout << "Status: Allowed." << endl;
							}
							else
							{
								cout << "Status: Not allowed." << endl;
								allowed3 = 0;
							}
							if (allowed3 == 1)
							{
								cout << endl << endl;
								ticket person3;
								cin >> person3;
								cout << endl;
								cout << person3;
								cout << endl << endl;
								cout << "Options:";
								cout << endl;
								cout << "1.Buy";
								cout << endl;
								cout << "2.Exit";
								cout << endl;
								cout << "Your option: ";
								int choise3;
								cin >> choise3;
								if (choise3 == 2)
								{
									ok6 = 1;
								}
								if (choise3 == 1)
								{
									bufferix == 0;
									int buffer_verification3 = 0;
	
									ticket bilet3(person3.getRow(), person3.getColumn(), person3.getPriceTicket(), person3.getArea(), place_m);
									int verificationPlace = 0;
									for (int i = 0; i < 10; i++)
									{
										for (int j = 0; j < 10; j++)
										{
											if (place_m[bilet3.getRow()][bilet3.getColumn()] == 0)
											{
											
											 verificationPlace = 1;
												bufferix = 1;
											}
										}
									}
									if (verificationPlace == 1)
									{
										cout << "The place is valid!" << endl;
									}
									if (bufferix == 1)
									{ 
										bilet3.setID(bilet3.getRow(), bilet3.getColumn(), place_m);
										cout << "The ticket is valid" << endl;
										if (bilet3.getArea() == "standard")
										{
											ticket::setticketsStandardSell(ticketssellStandard);
											ticketssellStandard++;
										}
										if (bilet3.getArea() == "vip")
										{
											ticket::setticketsVipSell(ticketssellVip);
											ticketssellVip++;

										}
										f.write(reinterpret_cast<char*>(&bilet3), sizeof(bilet3));
										ticket::setticketsSell(ticket::getticketsStandardSell(), ticket::getticketsVipSell());
										cout << endl;
										cout << "ID: " << place_m[bilet3.getRow()][bilet3.getColumn()] << endl;
										cout << "Ticket validation:";
										cout << endl;
										for (int i = 0; i < 10; i++)
										{
											for (int j = 0; j < 10; j++)
											{
												if (place_m[i][j] != 0)
												{
													buffer_verification3 = 1;
													nr = 1;
												}
											}
										}
										if (nr == 1)
										{
											cout << "The ticket is invalid" << endl;
										}
									}
									if (buffer_verification3 == 0 && nr!=1)
									{
										cout << "The ticket is invalid" << endl;
										nr = 0;
									}
									cout << endl;
									ok6 = 1;
								}
								ok6 = 1;
	
							}
						}
						ok6 = 1;
					}
					if (option1 == 3)
					{
						cout << endl << Match.getnrMaxTickets() - ticket::getticketsSell() << endl;

					}
					if (option1 == 4)
					{
						cout << endl << Match.getnrMaxTickets() << endl;
					}
					if (option1 == 5)
					{
						cout << endl;
						cout << ticket::getticketsSell() << endl;
					}
					if (option1 == 6)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								cout << place_m[i][j] << " ";
							}
							cout << endl;
						}
					}
					if (option1 == 7)
					{
						int buffer_ID3 = 0;
						int ID3;
						cout << endl;
						cout << "Write your ID: ";
						cin >> ID3;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (place_m[i][j] == ID3)
								{
									buffer_ID3 = 1;
								}
							}
						}
						cout << endl;
						if (buffer_ID3 == 1)
						{
							cout << "Yes, you have a valid ticket. We are waiting for you at the event!!" << endl;
							if (checker_virtual == 1)
							{
								client* personProb;
								Disabilities problemOne;
								personProb = &problemOne;
								personProb->print();
								cout << endl;
								
							}
						}
						else
						{
							cout << "The ticket does not exist :( ." << endl;
						}
					}
					if (option1 == 8)
					{
						cout << endl;
						cout << "List of ticket IDs purchased so far: " << endl;
						for (auto number : Match.getVect())
						{
							cout << number << endl;
						}
						cout << "Your ID: ";
						int id_win;
						cin >> id_win;
						cout << endl;
						int id_verif = 0;
						for (int number : Match.getVect())
						{
							if (id_win == number)
								id_verif = 1;
						}
						if (id_verif == 1)
						{
							cout << "The ID is valid." << endl;
						}
						else
						{
							cout << "Buy a ticket and come back to participate in the lottery!";
						}
						int position_won = 0;
						for (int i = 0; i < size(Match.getVect()); i++)
						{
							if (((rand() % size(Match.getVect()) == i)))
							{
								position_won = 1;
							}
						}
						cout << "The winning ID is: " << Match.getElemVect(rand() % size(Match.getVect())) << endl;
							if (id_win == Match.getElemVect(rand() % size(Match.getVect())))
							{
								cout << "You won!" << endl;
							}
							else
							{
							cout << "Better luck next time!" << endl;
							}

					}
				}
			}
	
	
		}
		
	}
	else if (alege == 2)
	{
	start_program = 1;
	ifstream h;
	h.open("file.txt", ios::in);
	string name_of_event;
	vector<string>VectNames;
	for (int i = 1; i <= 2; i++)
	{
		getline(h, name_of_event);
		VectNames.push_back(name_of_event);
	}
	cout << "The event name was taken from the file." << endl;
	cout << "The location of the event was taken from the file." << endl;
	string name_txt = VectNames[0]; //1
	string locationMovietxt = VectNames[1]; //2
	char* location_txt = new char[locationMovietxt.length() + 1];
	strcpy_s(location_txt, locationMovietxt.length() + 1, locationMovietxt.c_str());
	event event_txt(name_txt, location_txt);
	event_txt.setName_event(VectNames[0]);
	event_txt.setLocation(location_txt);
	event_txt.setnrMaxTickets(100);
	cout << endl;
	cout << "How many times a day does the event take place?" << endl;
	cout << "My option: ";
	int option1;
	cin >> option1;
	date date_event;
	int* start_event = new int[option1];
	cout << endl << "What time do you want the event to take place?" << endl;
	for (int j = 0; j < option1; j++)
	{
		cout << "Write " << j << " " << endl;
		cin >> start_event[j];
		cout << endl;
	}
	cout << "Year: ";
	int year;
	cin >> year;
	date_event.setYear(year);
	cout << endl;
	cout << "Month: ";
	int month;
	cin >> month;
	date_event.setMonth(month);
	cout << "Day: ";
	int day;
	cin >> day;
	date_event.setDay(day);
	cout << endl;
	date_event.setLengthStartTime(option1);
	date_event.setStartTime(start_event, option1);




	int bufferix = 0;
	int ticketssellVip = 1;
	int ticketssellStandard = 1;
	cout << "Welcome!";
	cout << endl;
	int start = 1;
	while (start == 1)
	{
		int ok = 1;
		int checker_virtual = 0;
		int** place = new int* [10];
		for (int i = 0; i < 10; i++)
		{
			place[i] = new int[10];
		}
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				place[i][j] = 0;
		int nr = 0;
		while (ok == 1)
		{
			cout << "Choose the desired option:" << endl;
			cout << "1. Event details" << endl;
			cout << "2. Ticket reservation" << endl;
			cout << "3. Number of tickets available" << endl;
			cout << "4. Total number of tickets" << endl;
			cout << "5. Total number of tickets sold" << endl;
			cout << "6. View matrix places" << endl;
			cout << "7. Verification your ID" << endl;
			cout << "8. Lottery" << endl;
			cout << "9. Exit" << endl;
			int buffer_2 = 1;
			while (buffer_2 == 1)
			{
				int buffer_1 = 0;
				cout << "My option: ";
				cin >> option1;
				for (int i = 1; i <= 9; i++)
				{
					if (option1 == i)
					{
						buffer_1 = 1;
					}
				}
				if (buffer_1 == 0)
				{
					cout << "Please try again.";
					cout << endl;

				}
				if (buffer_1 == 1)
				{
					buffer_2 = 0;
				}
			}
			if (option1 == 9)
			{
				exit(0);
			}
			if (option1 == 1)
			{
				cout << "Name:";
				cout << event_txt.getName_event();
				cout << endl;
				cout << "Location:";
				cout << event_txt.getLocation();
				cout << endl;
				cout << "Maximum number of tickets:";
				cout << event_txt.getnrMaxTickets();
				cout << endl;
				cout << "The current number of tickets left:";
				cout << event_txt.the_current_number_tickets_left();
				cout << endl;
				cout << "Year:";
				cout << date_event.getYear();
				cout << endl;
				cout << "Mouth:";
				cout << date_event.getMonth();
				cout << endl;
				cout << "Day:";
				cout << date_event.getDay();
				cout << endl;
				otherEvent* o = NULL;
				o = &event_txt;
				cout << endl;
				o->print_temp();
				cout << endl;
				cout << "Available hours:";
				for (int j = 0; j < date_event.getLengthStartTime(); j++)
				{
					cout << date_event.getStartTime()[j];
					if (j == date_event.getLengthStartTime() - 1)
					{
						cout << ".";
					}
					else
					{
						cout << ", ";
					}
				}
				cout << endl;
				if (event_txt.operator<(10) == true)
				{
					cout << "Hurry up!!there are only 10 tickets left." << endl;
				}
				else
				{
					cout << "There are enough tickets for the moment!" << endl;
				}
				cout << date_event.FirstHalfOrSecondHalf(date_event.getDay());
				cout << endl;
				cout << date_event.Season(date_event.getMonth());
				cout << endl;
			}
			int ok1 = 0;

			while (ok1 == 0)
			{
				int allowed = 1;
				if (option1 == 2)
				{
					client person_1;
					cin >> person_1;
					cout << person_1;
					if (person_1.operator<=(18) == true)
					{
						cout << "About: minor." << endl;
					}
					else
					{
						cout << "About: major." << endl;
						cout << "Access allowed on the basis of a card ID." << endl;
					}
					if (person_1.operator<=(18) != true)
					{
						cout << "Status: Allowed." << endl;
					}
					else
					{
						cout << "Status: Not allowed." << endl;
						allowed = 0;
					}
					if (allowed == 1)
					{
						cout << endl << endl;
						ticket person1;
						cin >> person1;
						cout << person1;
						int check;
						cout << endl;
						cout << "Do you have a serious health problem/disability?" << endl;
						cout << "Press the '1' key if you have one" << endl;
						cout << "Press any key if you haven't one" << endl;
						cout << endl;
						checker_virtual = 0;
						cout << "My option: ";
						cin >> check;
						if (check == 1)
						{
							checker_virtual = 1;
							Disabilities person_1;
							cin >> person_1;
							cout << endl << person_1;
							cout << "Do you have a mobility device? " << endl;
							cout << "Press the '1' key if you have one" << endl;
							int mobility;
							cin >> mobility;
							if (mobility == 1)
							{
								cout << "Your support: " << endl;
								string material;
								cin >> material;
								client* personProb1;
								Disabilities problemTwo;
								personProb1 = &problemTwo;
								personProb1->helpful_material(material);
							}
						}
						cout << endl;
						cout << endl << endl;
						cout << "Options:";
						cout << endl;
						cout << "1.Buy";
						cout << endl;
						cout << "2.Exit";
						cout << endl;
						cout << "Your option: ";
						int choise;
						cin >> choise;
						if (choise == 2)
						{
							ok1 = 1;
						}
						if (choise == 1)
						{
							bufferix = 0;
							int buffer_verification = 0;

							ticket bilet1(person1.getRow(), person1.getColumn(), person1.getPriceTicket(), person1.getArea(), place);
							int verificationPlace = 0;
							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if (place[bilet1.getRow()][bilet1.getColumn()] == 0)
									{
										verificationPlace = 1;

										bufferix = 1;
									}
								}
							}
							if (verificationPlace == 1)
							{
								cout << "The place is valid!" << endl;
							}
							if (bufferix == 1)
							{

								bilet1.setID(bilet1.getRow(), bilet1.getColumn(), place);
								cout << "Ticket sold!" << endl;
								if (bilet1.getArea() == "standard")
								{
									ticket::setticketsStandardSell(ticketssellStandard);
									ticketssellStandard++;
								}
								if (bilet1.getArea() == "vip")
								{
									ticket::setticketsVipSell(ticketssellVip);
									ticketssellVip++;

								}

								/*p.write(reinterpret_cast<char*>(&bilet1), sizeof(bilet1));*/


								ticket::setticketsSell(ticket::getticketsStandardSell(), ticket::getticketsVipSell());
								cout << endl;
								cout << "ID: " << place[bilet1.getRow()][bilet1.getColumn()] << endl;
								cout << "Ticket validation:";
								cout << endl;
								for (int i = 0; i < 10; i++)
								{
									for (int j = 0; j < 10; j++)
									{
										if (place[i][j] != 0)
										{
											buffer_verification = 1;
											nr = 1;
										}
									}
								}
								if (nr == 1)
								{
									cout << "The ticket is valid" << endl;
								}
							}
							if (buffer_verification == 0 && nr!=1)
							{
								cout << "The ticket is invalid" << endl;
								nr = 0;
							}
							cout << endl;
							ok1 = 1;
						}
						ok1 = 1;

					}
				}
				ok1 = 1;
			}
			if (option1 == 3)
			{
				cout << endl << event_txt.getnrMaxTickets() - ticket::getticketsSell() << endl;

			}
			if (option1 == 4)
			{
				cout << endl << event_txt.getnrMaxTickets() << endl;
			}
			if (option1 == 5)
			{
				cout << endl;
				cout << ticket::getticketsSell() << endl;
			}
			if (option1 == 6)
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						cout << place[i][j] << " ";
					}
					cout << endl;
				}
			}
			if (option1 == 7)
			{
				int buffer_ID = 0;
				int ID1;
				cout << endl;
				cout << "Write your ID: ";
				cin >> ID1;
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (place[i][j] == ID1)
						{
							buffer_ID = 1;
						}
					}
				}
				cout << endl;
				if (buffer_ID == 1)
				{
					cout << "Yes, you have a valid ticket. We are waiting for you at the event!!" << endl;
					if (checker_virtual == 1)
					{
						if (checker_virtual == 1)
						{
							client* personProb1;
							Disabilities problemTwo;
							personProb1 = &problemTwo;
							personProb1->print();
						}
					}
				}
				else
				{
					cout << "The ticket does not exist :( ." << endl;
				}
			}
			if (option1 == 8)
			{
				cout << endl;
				cout << "List of ticket IDs purchased so far: " << endl;
				for (auto number : event_txt.getVect())
				{
					cout << number << endl;
				}
				cout << "Your ID: ";
				int id_win;
				cin >> id_win;
				cout << endl;
				int id_verif = 0;
				for (int number : event_txt.getVect())
				{
					if (id_win == number)
						id_verif = 1;
				}
				if (id_verif == 1)
				{
					cout << "The ID is valid." << endl;
				}
				else
				{
					cout << "Buy a ticket and come back to participate in the lottery!";
				}
				int position_won = 0;
				for (int i = 0; i < size(event_txt.getVect()); i++)
				{
					if (((rand() % size(event_txt.getVect()) == i)))
					{
						position_won = 1;
					}
				}
				cout << "The winning ID is: " << event_txt.getElemVect(rand() % size(event_txt.getVect())) << endl;
					if (id_win == event_txt.getElemVect(rand() % size(event_txt.getVect())))
					{
						cout << "You won!" << endl;
					}
					else
					{
					cout << "Better luck next time!" << endl;
					}

			}
		}
	}
	h.close();
	}
	f.close();
	if((alege!=1)|| (alege!=2))
	{
		cout << "Invalid, try again" << endl;
	}
}
}





