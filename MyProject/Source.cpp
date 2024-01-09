#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------VENUE CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Venue {
	const int id;
	char* name;
	const int TotalCapacity;
	char Description[30];

public:
	// Default Constructor + Constructor with parameters --------------------------------------------------------------------------------------------------------------------------------------
	Venue(const int id, const char* VenueName = "", const int TotalCapacity = 0, const char description[30] = "")
		: id(id), TotalCapacity(TotalCapacity) {
		this->name = new char[strlen(VenueName) + 1];
		strcpy(this->name, VenueName);
		strcpy(this->Description, description);
	}

	// Copy Constructor --------------------------------------------------------------------------------------------------------------------------------------
	Venue(const Venue& o) : id(o.id), TotalCapacity(o.TotalCapacity) {
		if (o.name != nullptr) {
			delete[]o.name;
			this->name = new char[strlen(o.name) + 1];
			strcpy(this->name, o.name);
		}
		else {
			this->name = nullptr;
		}
		strcpy(this->Description, o.Description);
	}

	// Operator = --------------------------------------------------------------------------------------------------------------------------------------
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

	// Destructor --------------------------------------------------------------------------------------------------------------------------------------
	~Venue() {
		if (this->name != nullptr) {
			delete[] this->name;
		}
	}
	//Display --------------------------------------------------------------------------------------------------------------------------------------
	
	void displayAttributes(){
		cout << "Venue ID: " << getId() << endl
			<< "Venue Name: " << getName() << endl
			<< "Total Capacity: " << getTotalCapacity() << endl
			<< "Description: " << getDescription() << endl;
	}

	void oneLineDisplay() {
		cout<<"This Venue has the id "<<getId()<<", the Name "<<getName() << ",the total capacity: " << getTotalCapacity() <<" and the description: " << getDescription() << endl;
	}

	// Getters --------------------------------------------------------------------------------------------------------------------------------------
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

	const int& getTotalCapacity() const {
		return this->TotalCapacity;
	}

	const char* getDescription() const {
		return this->Description;
	}

	// Setters --------------------------------------------------------------------------------------------------------------------------------------
	void setName(const char* newName) {
		if (newName == nullptr || strlen(newName) == 0) {
			printf( "The venue must have a name of at least one Character");
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
			printf( "New Description is too large");
		}
		else
		{
			strcpy(this->Description, newDescription);
		}
		
	}

	// Operators ----------------------------------------------------------------------------------------------------------------------------------
	
	const char& operator[](int index) const {
		if (index < 0 || index >= sizeof(Description)) {
			printf("Index out of range");
		}
		return Description[index];
	}

	Venue operator+(const Venue& other) const {
		Venue resultVenue = *this;

		char* combinedName = new char[strlen(name) + strlen(other.name) + 1];
		strcpy(combinedName, name);
		strcat(combinedName, other.name);
		resultVenue.setName(combinedName);
		delete[] combinedName;

		return resultVenue;
	}

	operator int() const {
		int copy = this->getTotalCapacity();
		return copy;
	}

	bool operator<(const Venue& other) const {
		return this->TotalCapacity < other.TotalCapacity;
	}

	bool operator>(const Venue& other) const {
		return this->TotalCapacity > other.TotalCapacity;
	}

	bool operator==(const Venue& other) const {
		return(this->TotalCapacity == other.TotalCapacity) &&
			(strcmp(this->name, other.name) == 0) &&
			(strcmp(this->Description, other.Description) == 0);
	}

};

// Overload <<
ostream& operator<<(ostream& os, const Venue& venue) {
	os << "Venue ID: " << venue.getId() << endl
		<< "Venue Name: " << venue.getName() << endl
		<< "Total Capacity: " << venue.getTotalCapacity() << endl
		<< "Description: " << venue.getDescription() << endl;
	return os;
}

// Overload >>
istream& operator>>(istream& is, Venue& venue) {
	char name[100], description[30];

	cout << "Enter Venue Name: ";
	is.getline(name, 100);
	venue.setName(name);

	cout << "Enter Description: ";
	is.getline(description, 30);
	venue.setDescription(description);

	return is;
}


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
	//Default Constructor + w/ parameters ---------------------------------------------------------------------------------------------------------------------
	Ticket(int id = 0, string date = "", bool isValid = false, const char* name = "", vector<int> seatsarray = {}) :id(id) {
		if (seatsarray.size() == 0) {
			printf("Empty seats array");
		}
		this->dateOfTicket = date;
		this->isValidated = isValid;
		this->EventName = new char[strlen(name) + 1];
		strcpy(this->EventName, name);
		this->NrOfSeats = seatsarray.size();
		for (int i=0; i < this->NrOfSeats; i++) {
			this->SeatsArray[i] = seatsarray[i];
		};
		
		if (TotalNrOfSeats + this->NrOfSeats >= MAX_NR_OF_SEATS) {
			printf("Too Many Seats");
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats + this->NrOfSeats;
		};
	}

	//Copy Constructor --------------------------------------------------------------------------------------------------------------------------------------
	Ticket(const Ticket& o) :id(o.id){
		if (o.EventName != nullptr) {
			delete[]o.EventName;
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

		if (TotalNrOfSeats + this->NrOfSeats > MAX_NR_OF_SEATS) {
			printf( "Too Many Seats");
		}
		else {
			TotalNrOfSeats = TotalNrOfSeats + this->NrOfSeats;
		};
	}

	// Operator = --------------------------------------------------------------------------------------------------------------------------------------
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
				printf( "Too Many Seats");
			}
			else {
				TotalNrOfSeats = TotalNrOfSeats + NrOfSeats;
			}
		}
		return *this;
	}

	//Destructor --------------------------------------------------------------------------------------------------------------------------------------
	~Ticket() {
		TotalNrOfSeats -= NrOfSeats;
		if (this->EventName != nullptr) {
			delete[] this->EventName;
		}
	}

	//Display --------------------------------------------------------------------------------------------------------------------------------------

	void displayAttributes() {
		cout << "Ticket ID: " << getId() << endl
			<< "Event Name: " << getEventName() << endl
			<< "Date of Ticket: " << getDateOfTicket() << endl
			<< "Is Validated: " << (CheckValidation() ? "Yes" : "No") << endl
			<< "Number of Seats: " << getNrOfSeats() << endl
			<< "Seats Array: ";

		const int* seatsArray = getSeatsArray();
		for (int i = 0; i < getNrOfSeats(); ++i) {
			cout << seatsArray[i] << " ";
		}

		cout <<endl;
	}

	void oneLineDisplay() const {
		cout << "This Ticket has the id " << getId() << ", the Event Name " << getEventName()
			<< ", the Date of Ticket: " << getDateOfTicket() << ", Is Validated: " << (CheckValidation() ? "Yes" : "No")
			<< ", Number of Seats: " << getNrOfSeats() << ", Seats Array: ";

		const int* seatsArray = getSeatsArray();
		for (int i = 0; i < getNrOfSeats(); ++i) {
			cout << seatsArray[i] << " ";
		}

		cout << endl;
	}

	// Getters --------------------------------------------------------------------------------------------------------------------------------------
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

	bool CheckValidation() const {
		return isValidated;
	}

	int getNrOfSeats() const {
		return NrOfSeats;
	}

	const int* getSeatsArray() const {
		return SeatsArray;
	}

	// Setters --------------------------------------------------------------------------------------------------------------------------------------
	void setEventName(const char* newName) {
		if (strlen(newName) <= 0) {
			printf( "Event must have a name of at leas one Character");
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
	bool isDayMonthYear(const string& date) const {
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

	void setDateOfTicket(const string& newDate) {
		if (isDayMonthYear(newDate)) {
			dateOfTicket = newDate;
		}
		else {
			printf( "Invalid date format. Use the format dd/mm/yyyy.");
		}
	}

	void setValidation (bool newIsValidated) {
		if (this->isValidated == newIsValidated) {
			printf( "Ticket already has that value. Give it another True/Flase value");
		}
		isValidated = newIsValidated;
	}

	void setNrOfSeats(int newNrOfSeats) {
		if (newNrOfSeats + (TotalNrOfSeats - this->NrOfSeats) > MAX_NR_OF_SEATS)
		{
			printf( "Giving NrOfSeats this Value would put it over the Maximum. Give it a smaller Value");
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

	//Operators
	const int& operator[](int index) const {
		if (index < 0 || index >= NrOfSeats) {
			printf("Index out of range");
		}
		return SeatsArray[index];
	}

	Ticket operator+(const Ticket& other) const {
		Ticket resultTicket = *this;
		if (this->NrOfSeats + other.NrOfSeats >= 10 || this->dateOfTicket != other.dateOfTicket) {
			printf( "These Tickets cannot be combined because theire Nr seats would exceed 10 or they are in different dates");
		}
		else {
			resultTicket.EventName = new char[strlen(EventName) + strlen(other.EventName) + 1];
			strcpy(resultTicket.EventName, EventName);
			strcat(resultTicket.EventName, other.EventName);

			for (int i = 0; i < this->NrOfSeats + other.NrOfSeats;i++) {
				if (i <= this->NrOfSeats)
					resultTicket.SeatsArray[i] = this->SeatsArray[i];
				else
					resultTicket.SeatsArray[i] = other.SeatsArray[i];
			}

			resultTicket.NrOfSeats = this->NrOfSeats + other.NrOfSeats;

			return resultTicket;
		}
	}

	operator bool() const {
		bool copy = CheckValidation();
		return isValidated;
	}

	bool operator<(const Ticket& other) const {
		return this->NrOfSeats < other.NrOfSeats;
	}

	bool operator>(const Ticket& other) const {
		return this->NrOfSeats > other.NrOfSeats;
	}

	bool operator!() const {
		return !isValidated;
	}

	bool operator==(const Ticket& other) const {
		bool flagTest=true;
		if (NrOfSeats != other.NrOfSeats) flagTest = false;
		else {
			for (int i = 0;i < NrOfSeats;i++) {
				if (SeatsArray[i] != other.SeatsArray[i])
				{
					flagTest = false;
					i = NrOfSeats;
				}
			}
		}
		return (dateOfTicket == other.dateOfTicket) &&
			(isValidated == other.isValidated) &&
			(strcmp(EventName, other.EventName) == 0) && flagTest;
	}
};

const int Ticket::MAX_NR_OF_SEATS = 300;
int Ticket::TotalNrOfSeats = 0;

//Overload <<
ostream& operator<<(ostream& os, const Ticket& ticket) {
	os << "Ticket ID: " << ticket.getId() << endl
		<< "Event Name: " << ticket.getEventName() << endl
		<< "Date of Ticket: " << ticket.getDateOfTicket() << endl
		<< "Is Validated: ";
	if (ticket.CheckValidation() == true) os << "Yes";
	else os << "No" << endl;
	os << "Number of Seats: " << ticket.getNrOfSeats() << endl
		<< "Seats Array: ";

	const int* seatsArray = ticket.getSeatsArray();
	for (int i = 0; i < ticket.getNrOfSeats(); ++i) {
		os << seatsArray[i] << " ";
	}

	os << endl;
	return os;
}

// Overload >> 
istream& operator>>(istream& is, Ticket& ticket) {
	int nrOfSeats;
	char eventName[100];
	string dateOfTicket;
	bool isValidated;
	int seatsArray[10];


	cout << "Enter Event Name: ";
	is.getline(eventName, 100);
	ticket.setEventName(eventName);

	cout << "Enter Date of Ticket (dd/mm/yyyy): ";
	is >> dateOfTicket;
	ticket.setDateOfTicket(dateOfTicket);

	cout << "Is Validated (1 for Yes, 0 for No): ";
	is >> isValidated;
	ticket.setValidation(isValidated);

	cout << "Enter Number of Seats (between 1 and 10): ";
	is >> nrOfSeats;
	ticket.setNrOfSeats(nrOfSeats);

	cout << "Enter Seats Array: ";
	for (int i = 0; i < nrOfSeats; i++) {
		is >> seatsArray[i];
	}
	ticket.setSeatsArray(seatsArray);

	return is;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------EVENT CLASS----------------------------------------------------------------------------------------------------------------------------------------------------------------
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
	//Constructor With Parameters & Default Constructor --------------------------------------------------------------------------------------------------------
	Event(Type eventtype = zero, const char* location = "", vector<string> artistList = {}, int id=0): EventId(id) {
		this->EventType = eventtype;
		this->Location = new char[strlen(location)+1];
		strcpy(this->Location, location);
		this->NrOfArtists = artistList.size();
		if (NrOfArtists > 10) {
			printf( "Too Many Artists");
		}
		for (int i = 0; i < this->NrOfArtists; i++) {
			this->ArtistsList[i] = artistList[i];
		};
	};

	Event(Type eventtype = zero, const char* location = "", const string artistList[] = {}, int artistListSize = 0, int id = 0) : EventId(id) {
		this->EventType = eventtype;
		this->Location = new char[strlen(location) + 1];
		strcpy(this->Location, location);
		this->NrOfArtists = artistListSize;

		if (NrOfArtists > 10) {
			printf( "Too Many Artists");
		}

		for (int i = 0; i < NrOfArtists; ++i) {
			this->ArtistsList[i] = artistList[i];
		}
	}


	//Copy Constructor --------------------------------------------------------------------------------------------------------------------------------------
	Event(const Event& o) : EventId(o.EventId) {
		if (o.Location != nullptr) {
			delete[]o.Location;
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

	//Operator = --------------------------------------------------------------------------------------------------------------------------------------
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

	//Destructor--------------------------------------------------------------------------------------------------------------------------------------
	~Event() {
		if (this->Location != nullptr) {
			delete[] this->Location;
		}
	}
	// Display --------------------------------------------------------------------------------------------------------------------------------------
	void displayAttributes() const {
		cout << "Event ID: " << getEventId() << endl
			<< "Event Type: " << getEventTypeAsString() << endl
			<< "Location: " << getLocation() << endl
			<< "Number of Artists: " << getNrOfArtists() << endl
			<< "Artists List: ";

		const string* artistsList = getArtistsList();
		for (int i = 0; i < getNrOfArtists(); ++i) {
			cout << artistsList[i] << " ";
		}

		cout << endl;
	}

	void oneLineDisplay() const {
		cout << "This Event has the id " << getEventId() << ", the Event Type: " << getEventTypeAsString()
			<< ", the Location: " << getLocation() << ", Number of Artists: " << getNrOfArtists()
			<< ", Artists List: ";

		const string* artistsList = getArtistsList();
		for (int i = 0; i < getNrOfArtists(); ++i) {
			cout << artistsList[i] << " ";
		}

		cout << endl;
	}
	// Getters --------------------------------------------------------------------------------------------------------------------------------------
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

	// Setters --------------------------------------------------------------------------------------------------------------------------------------
	void setEventType(Type newEventType) {
		if (newEventType == zero) {
			printf( "Event Type cannot be zero. Use a different value");
		}
		else {
			EventType = newEventType;
		}
	}

	void setLocation(const char* newLocation) {
		if (strlen(newLocation) <= 0) {
			printf( "Location must have at least one character");
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
			printf( "Event can't have more than 10 artists. Make a different event objects and split the artists");
		}
		else {
			NrOfArtists = newNrOfArtists;
		}
	}

	void setArtistsList(const string newArray[]) {
		if (sizeof(newArray) >= 10) {
			printf( "Event can't have more than 10 artists. Make a different event objects and split the artists");
		}
		else {
			for (int i = 0; i < sizeof(newArray); i++) {
				ArtistsList[i] = newArray[i];
			}
		}
	}

	// Operators--------------------------------------------------------------------------------------------------------------------------------------
	const string& operator[](int index) const {
		if (index < 0 || index >= NrOfArtists) {
			printf( "Index out of range");
		}
		return ArtistsList[index];
	}

	Event operator+(const Event& other) const {
		Event resultEvent = *this;
		if (this->NrOfArtists + other.NrOfArtists >= 10) {
			printf( "These Events cannot be combined because theire Nr of artists would exceed 10");
		}
		else {
			resultEvent.Location = new char[strlen(Location) + strlen(other.Location) + 1];
			strcpy(resultEvent.Location, Location);
			strcat(resultEvent.Location, other.Location);

			for (int i = 0; i < this->NrOfArtists + other.NrOfArtists;i++) {
				if (i <= this->NrOfArtists)
					resultEvent.ArtistsList[i] = this->ArtistsList[i];
				else
					resultEvent.ArtistsList[i] = other.ArtistsList[i];
			}

			resultEvent.NrOfArtists = this->NrOfArtists + other.NrOfArtists;
				
			return resultEvent;
		}
	}

	operator Type() const{
		Type copy = getEventType();
		return copy;
	}

	bool operator<(const Event& other) const {
		return this->NrOfArtists < other.NrOfArtists;
	}

	bool operator>(const Event& other) const {
		return this->NrOfArtists > other.NrOfArtists;
	}

	bool operator==(const Event& other) const {
		bool flagTest = true;
		if (NrOfArtists != other.NrOfArtists) flagTest = false;
		else {
			for (int i = 0;i < NrOfArtists;i++) {
				if (ArtistsList[i] != other.ArtistsList[i])
				{
					flagTest = false;
					i = NrOfArtists;
				}
			}
		}
		return (EventType == other.EventType) &&
			(EventId == other.EventId) &&
			(strcmp(Location, other.Location) == 0) && flagTest;
	}
};

// Overload <<
ostream& operator<<(ostream& os, const Event& event) {
	os << "Event ID: " << event.getEventId() << endl
		<< "Event Type: " << event.getEventTypeAsString() << endl
		<< "Location: " << event.getLocation() << endl
		<< "Number of Artists: " << event.getNrOfArtists() << endl
		<< "Artists List: ";

	const string* artistsList = event.getArtistsList();
	for (int i = 0; i < event.getNrOfArtists(); ++i) {
		os << artistsList[i] << " ";
	}

	os << endl;
	return os;
}

// Overload >>
istream& operator>>(istream& is, Event& event) {
	int nrOfArtists;
	char location[100];
	string artistsList[10];

	int eventType;
	cout << "Enter event type (0 for zero,1 for concert,2 for opera,3 for theater,4 for ballet,5 for movie";
	is >> eventType;
	switch (eventType) {
	case 0:
		event.setEventType(zero);
	case 1:
		event.setEventType(concert);
	case 2:
		event.setEventType(opera);
	case 3:
		event.setEventType(theater);
	case 4:
		event.setEventType(ballet);
	case 5:
		event.setEventType(movie);
	}

	cout << "Enter Location: ";
	is.getline(location, 100);
	event.setLocation(location);

	cout << "Enter Number of Artists: ";
	is >> nrOfArtists;
	event.setNrOfArtists(nrOfArtists);

	cout << "Enter Artists List: ";
	for (int i = 0; i < nrOfArtists; ++i) {
		is >> artistsList[i];
	}
	event.setArtistsList(artistsList);

	return is;
}

int main() {

	Venue venue1(1, "Venue1", 100, "Description1");
	Venue venue2(2, "Venue2", 150, "Description2");

	venue1.oneLineDisplay();
	venue2.oneLineDisplay();

	vector<int> seatsArray = { 1, 2, 3 };
	Ticket ticket1(1, "01/01/2023", true, "Event1", seatsArray);
	ticket1.oneLineDisplay();

	Ticket ticket2(2, "02/01/2023", false, "Event2", { 4, 5, 6 });

	ticket2.oneLineDisplay();

	vector<string> ArtistList1 = { "Artist1", "Artist2" };
	Event event1(concert, "Location1", ArtistList1, 1);
	Event event2(opera, "Location2", { "Artist3", "Artist4" }, 2);

	event1.oneLineDisplay();
	event2.oneLineDisplay();

	return 0;
}