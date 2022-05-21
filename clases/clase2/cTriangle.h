#pragma once
#include <iostream>
#include "../clase1/cPoint.h"
#include "cShape.h"
using namespace std;

class Triangle : protected Shape
{
private:
	Point** vertices;	// COMPOSITION

public:
	Triangle();
	string toString();
	void setVertex(int i, float x, float y, float z);
};
