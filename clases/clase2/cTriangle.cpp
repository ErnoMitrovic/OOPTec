#include "cTriangle.h"

Triangle::Triangle() : Shape()
{
	vertices = new Point*[3];
	for(int i = 0; i < 3; i++)
	{
		vertices[i] = new Point();
	}
}

string Triangle::toString()
{
	string txt = "TRIANGLE:\n";
	txt += "CENTER: " + center->toString() + "\n";
	for(int i = 0; i < 3; i++)
	{
		txt += vertices[i]->toString() + "\n";		
	}
	return txt;
}

void Triangle::setVertex(int i, float x, float y, float z)
{
	vertices[i]->setValues(x, y, z);
}
