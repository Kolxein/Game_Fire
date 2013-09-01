//
//  main.cpp
//  test
//
//  Created by cody on 9/1/13.
//  Copyright (c) 2013 cody. All rights reserved.
//

#include <iostream>

using namespace std;

class Vector
{
public:
	int x;
	int y;

	Vector(int a, int b)
		: x(a)
		, y(b)
	{
	}
	Vector operator-(const Vector& rhs)
		{
			return Vector(x - rhs.x, y - rhs.y);
		}

	Vector operator+(const Vector& rhs)
	{
		return Vector(x + rhs.x, y + rhs.y);
	}

	bool Compare(const Vector& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator==(const Vector& rhs)
	{
		return Compare(rhs);
	}
};


int main(int argc, const char * argv[])
{
	Vector v1(0, 1);
	Vector v2(1, 0);

	// insert code here...
	cout << "v1: {" << v1.x << ", " << v1.y << "}" << endl;
	cout << "v2: {" << v2.x << ", " << v2.y << "}" << endl;

	Vector v3 = v1 + v2; // v1.operator+(v2);
	cout << "v3: {" << v3.x << ", " << v3.y << "}" << endl;

	if (v1 == v3)
	{
		cout << "v1 == v3" << endl;
	}
	else
	{
		cout << "v1 != v3" << endl;
	}

	Vector v4 = v1 - v2;
	cout << "v4: {" << v4.x << ", " << v4.y << "}" << endl;

    return 0;
}

