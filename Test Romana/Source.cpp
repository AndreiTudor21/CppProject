#include <iostream>
using namespace std;

class Sejur {
	const int id;
	char destinatie[30];
	float pretBaza;
	int nrExcursiiOptionale;
	int* pretExcursie;

public:
	Sejur(int ID): id(ID){};
};

int main() {
	int hhhh = 12;
	Sejur a(hhhh);
}
