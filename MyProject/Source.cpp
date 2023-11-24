#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//TODO
//getters setters
//Copy constructor
//Overload =
//overload << >>
// overload []  (+,-,* or /), ++ or -- (with the 2 forms)the cast operator (to any type) explicitly or implicitly
//the negation operator !, a conditional operator (<.>,=<,>=), operator for testing equality between 2 objects ==

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------VENUE CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Venue {
	const int id;
	char* name;
	const int TotalCapacity;
	char Description[30];
public:
	//Default Constructor + Constructor with parameters
	Venue(const int id, const char* VenueName = "", const int TotalCapacity = 0, const char description[30] = "") : id(id), TotalCapacity(TotalCapacity)
	{
		this->name = new char[strlen(VenueName) + 1];
		strcpy(this->name, VenueName);
		strcpy(this->Description, description);
	}

	//Copy Constructor
	Venue(const Venue& o) :id(o.id), TotalCapacity(o.TotalCapacity) {
		if (o.name != nullptr) {
			this->name = new char[strlen(o.name) + 1];
			strcpy(this->name, o.name);
		}
		else this->name = nullptr;
		strcpy(this->Description, o.Description);
	}

	//Destructor
	~Venue() {
		if (this->name != nullptr) {
			delete[]this->name;
		}
	}
};



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------TICKET CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class TooManySeatsException : public std::exception {
public:
	const char* what(){
		return "Error: Too many seats!";
	}
};

class Ticket {
	static int TotalNrOfSeats;
	char* EventName;
	static const int MAX_NR_OF_SEATS;
	const int id;
	string dateOfTicket;
	bool isValidated;
	int NrOfSeats;
	int SeatsArray[10];

public:
	//Default Constructor + w/ parameters
	Ticket(const int id = 0 ,string date = "", bool isValid = false, const char* name = "", int seatsarray[]={}) :id(id) {
		this->dateOfTicket = date;
		this->isValidated = isValid;
		strcpy(this->EventName, name);
		this->NrOfSeats = sizeof(seatsarray);
		for (int i; i < this->NrOfSeats; i++) {
			this->SeatsArray[i] = seatsarray[i];
		};
		

		if (TotalNrOfSeats + this->NrOfSeats < MAX_NR_OF_SEATS) {
			throw TooManySeatsException();
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats + this->NrOfSeats;
		};
	}

	//Destructor
	~Ticket() {
		if (this->EventName != nullptr) {
			delete[]this->EventName;
		}
	}
};

const int Ticket::MAX_NR_OF_SEATS = 300;
int Ticket::TotalNrOfSeats = 0;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------ATENDEE CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
enum Type {
	zero,
	concert,
	opera,
	theater,
	ballet,
	movie
};

class ToManyArtists : public std::exception {
public:
	const char* what() {
		return "Error: Too many artists!";
	}
};

class Event {
	Type EventType;
	const int EventId;
	char* Location;
	string ArtistsList[10];
	int NrOfArtists;

public:
	//Constructor With Parameters & Default Constructor
	Event(Type eventtype = zero, const char* location = "", string artistList[] = {}, int id=0): EventId(id) {
		this->EventType = eventtype;
		strcpy(this->Location, location);
		this->NrOfArtists = sizeof(artistList);
		if (NrOfArtists > 10) {
			throw ToManyArtists();
		}
		for (int i = 0; i < this->NrOfArtists; i++) {
			this->ArtistsList[i] = artistList[i];
		};
	};

	//Copy Constructor
	Event(const Event& o) : EventId(o.EventId) {
		if (o.Location != nullptr) {
			this->Location = new char[strlen(o.Location) + 1];
			strcpy(this->Location, o.Location);
		}
		else this->Location = nullptr;

		this->EventType = o.EventType;
		this->NrOfArtists = o.NrOfArtists;

		for (int i = 0;i < o.NrOfArtists;i++) {
			this->ArtistsList[i] = o.ArtistsList[i];
		}
	}

	//Destructor
	~Event() {
		if (this->Location != nullptr) {
			delete[] this->Location;
		}
	}
	
};


int main() {
	std::cout << "Hello!";

	
}