#include <iostream>
#include <string>
using namespace std;

class Venue {
	const char* name;
	const int TotalCapacity;
public:
	Venue(const char* VenueName = nullptr, const int TotalCapacity = 0) :name(VenueName), TotalCapacity(TotalCapacity) 
	{}
};

class Ticket {
	static int TotalNrOfTickets;
	char* EventName;
	static const int MAX_NR_OF_TICKETS = 300;
	const int id;
	string dateOfTicket;
	bool isValidated;
public:
	Ticket(const int id = 0 ,string date = "", bool isValid = false, const char* name = ""):id(id) {
		this->dateOfTicket = date;
		this->isValidated = isValid;
		strcpy(this->EventName, name);
	}
};

class Atendee{
	char* atendeeName;
	int age;

public:
	Atendee(const char* name ="", int age=0) {
		strcpy(this->atendeeName, name);
		this->age = age;
	}
};


int main() {
	std::cout << "Hello!";
}