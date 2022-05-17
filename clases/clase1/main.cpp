#include "cHello.h"

int main()
{
	//Hello h;
	//h.sayHello();
	
	Hello* h1 = new Hello(); // Instance a copy of Hello class
	h1->sayHello();
	cout << h1 << endl;

	Hello* h2 = new Hello();
	h2->message = "Get out!";
	h2->sayHello();

	delete h1;
	delete h2;
	
	return 0;
}