#pragma once
#include <iostream>
#include <string>
#include "../clase1/cPoint.h"
using namespace std;

class Shape
{
protected:
	Point* center;
public:
	Shape();
	Shape(float x, float y, float z);
	string toString();
};