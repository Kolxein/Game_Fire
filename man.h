#ifndef MAN_H
#define MAN_H

#include "gameObject.h"
#include "point.h"
#include "size.h"


class Man : public GameObject
{
	public:
		Man();
		Man(const Point&, const Size&);
		char simbl = '*';
		void moveStep1();
		void moveStep2();
		void moveStep3();
		void moveDed();
};

#endif
