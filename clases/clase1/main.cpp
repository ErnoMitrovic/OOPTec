#include "cHello.h"
#include "cPoint.hpp"

void pt1(){
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
}

int main()
{
  Point * p1 = new Point(-3.5f, 6.f, -0.37f), * p2 = new Point(0.5f, 7.8f, -1.f);
  cout << p1 -> toString() << endl << p2 -> toString() << endl;

  cout << "Distance: " << p1 -> distance(p2) << endl;
	return 0;
}