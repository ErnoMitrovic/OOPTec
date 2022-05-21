#include "cShape.h"

Shape::Shape()
{
	center = new Point();
}

Shape::Shape(float x, float y, float z)
{
	center = new Point(x, y, z);
}

string Shape::toString()
{
	string txt = "SHAPE:\n";
	txt += center->toString();
	return txt;
}
