#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//TODO
//
//getters setters
//Copy constructor		--done
//Overload =			--done
//overload << >>
//Overload []  (+,-,* or /), ++ or -- (with the 2 forms)the cast operator (to any type) explicitly or implicitly
//			the negation operator !, a conditional operator (<.>,=<,>=), operator for testing equality between 2 objects ==

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------VENUE CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Venue {
	const int id;
	char* name;
	const int TotalCapacity;
	char Description[30];

public:
	// Default Constructor + Constructor with parameters
	Venue(const int id, const char* VenueName = "", const int TotalCapacity = 0, const char description[30] = "")
		: id(id), TotalCapacity(TotalCapacity) {
		this->name = new char[strlen(VenueName) + 1];
		strcpy(this->name, VenueName);
		strcpy(this->Description, description);
	}

	// Copy Constructor
	Venue(const Venue& o) : id(o.id), TotalCapacity(o.TotalCapacity) {
		if (o.name != nullptr) {
			this->name = new char[strlen(o.name) + 1];
			strcpy(this->name, o.name);
		}
		else {
			this->name = nullptr;
		}
		strcpy(this->Description, o.Description);
	}

	// Operator =
	Venue& operator=(const Venue& o) {
		if (this != &o) {
			if (this->name != nullptr) {
				delete[] this->name;
			}

			if (o.name != nullptr) {
				this->name = new char[strlen(o.name) + 1];
				strcpy(this->name, o.name);
			}
			else {
				this->name = nullptr;
			}
			strcpy(this->Description, o.Description);
		}
		return *this;
	}

	// Destructor
	~Venue() {
		if (this->name != nullptr) {
			delete[] this->name;
		}
	}

	//getters
	int getId() const {
		return this->id;
	}

	char* getName() const{
		if (this->name != nullptr) {
			char* copy = new char[strlen(this->name) + 1];
			strcpy(copy, this->name);
			return copy;
		}
		else
			return nullptr;
	}

	int getTotalCapacity() const {
		return this->TotalCapacity;
	}

	const char* getDescription() const {
		return this->Description;
	}

	// Setters
	void setName(const char* newName) {
		if (strlen(newName) <= 0) {
			throw "The venue must have a name of at least one Character";
		}
		else {
			if (this->name != nullptr) {
				delete[] this->name;
			}
			this->name = new char[strlen(newName) + 1];
			strcpy(this->name, newName);
		}
		}

	void setDescription(const char* newDescription) {
		if (strlen(newDescription) > 30) {
			throw "New Description is too large";
		}
		else
		{
			strcpy(this->Description, newDescription);
		}
		
	}
};




//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------TICKET CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
		for (int i=0; i < this->NrOfSeats; i++) {
			this->SeatsArray[i] = seatsarray[i];
		};
		

		if (TotalNrOfSeats + this->NrOfSeats < MAX_NR_OF_SEATS) {
			throw "Too Many Seats";
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats + this->NrOfSeats;
		};
	}

	//Copy Constructor
	Ticket(const Ticket& o) :id(o.id){
		if (o.EventName != nullptr) {
			this->EventName = new char[strlen(o.EventName) + 1];
			strcpy(this->EventName, o.EventName);
		}
		else this->EventName = nullptr;

		this->dateOfTicket = o.dateOfTicket;
		this->isValidated = o.isValidated;
		this->NrOfSeats = o.NrOfSeats;
		for (int i = 0; i < this->NrOfSeats; i++) {
			this->SeatsArray[i] = o.SeatsArray[i];
		};

		if (TotalNrOfSeats + this->NrOfSeats < MAX_NR_OF_SEATS) {
			throw "Too Many Seats";
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats + this->NrOfSeats;
		};
	}

	// Operator =
	Ticket& operator=(const Ticket& o) {
		if (this != &o) {
			if (this->EventName != nullptr) {
				delete[] EventName;
			}
			dateOfTicket = o.dateOfTicket;
			isValidated = o.isValidated;
			NrOfSeats = o.NrOfSeats;

			if (o.EventName != nullptr) {
				EventName = new char[strlen(o.EventName) + 1];
				strcpy(EventName, o.EventName);
			}
			else {
				EventName = nullptr;
			}

			for (int i = 0; i < NrOfSeats; i++) {
				SeatsArray[i] = o.SeatsArray[i];
			}

			if (TotalNrOfSeats + NrOfSeats > MAX_NR_OF_SEATS) {
				throw "Too Many Seats";
			}
			else {
				TotalNrOfSeats = TotalNrOfSeats + NrOfSeats;
			}
		}
		return *this;
	}

	//Destructor
	~Ticket() {
		if (this->EventName != nullptr) {
			delete[]this->EventName;
		}
	}

	// Getters
	int getId() const {
		return id;
	}

	char* getEventName() const {
		if (this->EventName != nullptr) {
			char* copy = new char[strlen(this->EventName) + 1];
			strcpy(copy, this->EventName);
			return copy;
		}
		else
			return nullptr;
	}

	string getDateOfTicket() const {
		return dateOfTicket;
	}

	bool getIsValidated() const {
		return isValidated;
	}

	int getNrOfSeats() const {
		return NrOfSeats;
	}

	const int* getSeatsArray() const {
		return SeatsArray;
	}

	// Setters
	void setEventName(const char* newName) {
		if (strlen(newName) <= 0) {
			throw "Event must have a name of at leas one Character";
		}
		else {
			if (EventName != nullptr) {
				delete[] EventName;
			}
			EventName = new char[strlen(newName) + 1];
			strcpy(EventName, newName);
		}
	}

	// Testing for valid dd/mm/yyyy format
	bool isDayMonthYear(const std::string& date) const {
		if (date.size() != 10) {
			return false;
		}

		if (isdigit(date[0]) && isdigit(date[1]) && date[2] == '/' &&
			isdigit(date[3]) && isdigit(date[4]) && date[5] == '/' &&
			isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9])) 
		{
			return true;
		}

		return false;
	}

	void setDateOfTicket(const std::string& newDate) {
		if (isDayMonthYear(newDate)) {
			dateOfTicket = newDate;
		}
		else {
			throw "Invalid date format. Use the format dd/mm/yyyy.";
		}
	}

	void setIsValidated(bool newIsValidated) {
		if (this->isValidated == newIsValidated) {
			throw "Ticket already has that value. Give it another True/Flase value";
		}
		isValidated = newIsValidated;
	}

	void setNrOfSeats(int newNrOfSeats) {
		if (newNrOfSeats + (TotalNrOfSeats - this->NrOfSeats) > MAX_NR_OF_SEATS)
		{
			throw "Giving NrOfSeats this Value would put it over the Maximum. Give it a smaller Value";
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats - this->NrOfSeats;
			NrOfSeats = newNrOfSeats;
			TotalNrOfSeats = TotalNrOfSeats + newNrOfSeats;
		}
	}

	void setSeatsArray(const int newSeatsArray[]) {
		for (int i = 0; i < sizeof(newSeatsArray); i++) {
			SeatsArray[i] = newSeatsArray[i];
		};
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
			throw "Too Many Artists";
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

	//Operator =
	Event& operator=(const Event& o) {
		if (this != &o) {
			if (this->Location != nullptr) {
				delete[] Location;
			}
			this->EventType = o.EventType;
			this->NrOfArtists = o.NrOfArtists;
			if (o.Location != nullptr) {
				Location = new char[strlen(o.Location) + 1];
				strcpy(Location, o.Location);
			}
			else {
				Location = nullptr;
			}
			for (int i = 0; i < NrOfArtists; i++) {
				ArtistsList[i] = o.ArtistsList[i];
			}
		}
		return *this;
	}

	//Destructor
	~Event() {
		if (this->Location != nullptr) {
			delete[] this->Location;
		}
	}
	
	// Getters
	Type getEventType() const {
		return EventType;
	}

	string getEventTypeAsString() const {
		switch (EventType) {
		case zero:
			return "zero";
		case concert:
			return "concert";
		case opera:
			return "opera";
		case theater:
			return "theater";
		case ballet:
			return "ballet";
		case movie:
			return "movie";
		default:
			return "Error";
		}
	}

	int getEventId() const {
		return EventId;
	}

	char* getLocation() const {
		if (this->Location != nullptr) {
			char* copy = new char[strlen(this->Location) + 1];
			strcpy(copy, this->Location);
			return copy;
		}
		else
			return nullptr;
	}

	int getNrOfArtists() const {
		return NrOfArtists;
	}

	const string* getArtistsList() const {
		return ArtistsList;
	}

	// Setters
	void setEventType(Type newEventType) {
		if (newEventType == zero) {
			throw "Event Type cannot be zero. Use a different value";
		}
		else {
			EventType = newEventType;
		}
	}

	void setLocation(const char* newLocation) {
		if (strlen(newLocation) <= 0) {
			throw "Location must have at least one character";
		}
		else {
			if (Location != nullptr) {
				delete[] Location;
			}
			Location = new char[strlen(newLocation) + 1];
			strcpy(Location, newLocation);
		}
	}

	void setNrOfArtists(int newNrOfArtists) {
		if (newNrOfArtists >= 10) {
			throw "Event can't have more than 10 artists. Make a different event objects and split the artists";
		}
		else {
			NrOfArtists = newNrOfArtists;
		}
	}

	void setArtistsList(const string newArray[]) {
		if (sizeof(newArray) >= 10) {
			throw "Event can't have more than 10 artists. Make a different event objects and split the artists";
		}
		else {
			for (int i = 0; i < sizeof(newArray); i++) {
				ArtistsList[i] = newArray[i];
			}
		}
	}

};


int main() {
	std::cout << "Hello!";

	
}