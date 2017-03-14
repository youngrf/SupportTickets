// SupportTickets.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#define MAX_ENTRY		100

static int currentTicketID = 0;

class Ticket
{
private: //data members
	int TicketID;
	string IssueStatus;
	string IssueType;
	string IssuePriority;
	string CallerName;
	string IssueDescription;
	int NumberOfUsers;


public: //member functions
	Ticket();  //constructor
	void CaptureTicket();
	void ShowTicket();
	void CloseTicket();

};

Ticket::Ticket()
{
	TicketID = -1;
	NumberOfUsers = 0;
	IssueStatus = "";
	IssueType = "";
	IssuePriority = "";
	CallerName = "";
	IssueDescription = "";
}

void Ticket::CaptureTicket()
{

	TicketID = currentTicketID;

	cout << "What is the name of the Caller? " << endl;
	cin.clear();
	getline(cin, CallerName);
	cin.clear();
	getline(cin, CallerName);


	cout << "Issue Type? S=Server A=Application C=aCcess" << endl;
	cin.clear();
	getline(cin, IssueType);
	
		if (IssueType == "A" || IssueType == "a")
		{
			IssueType = "Application";
		}
		else if (IssueType == "S" || IssueType == "s")
		{
			IssueType = "Server";
		}
		else if (IssueType == "C" || IssueType == "c")
		{
			IssueType = "Access";
		}

	cout << "Description of Issue?" << endl;
	cin.clear();
	getline(cin, IssueDescription);

	cout << "How many users impacted?" << endl;
	while (!(cin >> NumberOfUsers))
	{
			cout << "Must be a number " << endl;  //Input error check
			cin.clear();
			cin.ignore(100, '\n');
			//cin.clear();
			//cin >> NumberOfUsers;
	}
	IssueStatus = "OPEN";

	if (NumberOfUsers >= 50)
		IssuePriority = "High";
	else if (NumberOfUsers >= 10 && NumberOfUsers < 50)
		IssuePriority = "MED";
	else IssuePriority = "LOW";



	cout << "Your ticket ID is " << TicketID << endl;
}

void Ticket::ShowTicket() //Prints out ticket
{

	cout << "Ticket ID: " << TicketID << endl;
	cout << " NumberOfUsers = " << NumberOfUsers << endl;
	cout << " IssueStatus = " << IssueStatus << endl;
	cout << " IssueType = " << IssueType << endl;
	cout << " IssuePriority = " << IssuePriority << endl;
	cout << " CallerName = " << CallerName << endl;
	cout << " IssueDescription = " << IssueDescription << endl;
}

void Ticket::CloseTicket() //Closes ticket 
{

	IssueStatus = "CLOSED";

	cout << endl << " Ticket # " << TicketID << " has been closed." << endl;
}



//void init_ticket_array(char * Tickets);
//static int Ticket_index = 0;


int main(int argc, char *argv[])
{
	int		i;
	char inputChar = ' ';
	//char Tickets[MAX_ENTRY];


	Ticket myTicket[MAX_ENTRY]; //Creates array of 100 objects called myTicket

	while (inputChar != 'N' && inputChar != 'n') //Loop to create tickets
	{

		cout << "-------------------------------------------" << endl;
		cout << endl << "Would you like to open a ticket? Enter Y or N" << endl;
		cin >> inputChar;

		if (inputChar == 'N' || inputChar == 'n')
		{
			cout << "User entered no. No tickets were opened " << endl;
		}
		else if (inputChar == 'Y' || inputChar == 'y')
		{

			myTicket[currentTicketID].CaptureTicket(); //Calls CaptureTicket function for index currentTicketID
													   //myTicket[currentTicketID].ShowTicket(); //Calls ShowTicket function for index currentTicketID
			currentTicketID++;
		}
		else
		{
			cout << "Invalid option.  Please try again..." << endl; // Input error check
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
		}
	}



	cout << "--------------------" << endl;
	cout << "Ticket Listing" << endl;
	cout << "--------------------" << endl;
	for (i = 0; i<currentTicketID; i++) // Prints all tickets created
	{
		myTicket[i].ShowTicket();
		cout << "--------------------" << endl;
		cout << "--------------------" << endl;
	}

	myTicket[0].CloseTicket(); // Calls CloseTicket function

	

	return(0);
}

