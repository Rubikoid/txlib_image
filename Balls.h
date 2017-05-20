#ifndef BALLS_H
#define BALLS_H

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include "TXgrap.h"
#include "Bounds.h"

using namespace std;

class base {
public:
	V2Pos bnds;
	bool destroyed;

	base(V2Pos _bnds) {
		bnds = _bnds;
		destroyed = false;
	}

	base() { }

	virtual void update() { }

	virtual void draw() { }

	virtual void collide(base *with) { }
};

class shot : public base {
public:
	float radi;
	double destF;
	COLORREF color;

	shot(V2Pos bnds, float r, double dst, COLORREF colr = RGB(255, 255, 255)) : base(bnds) {
		color = colr;
		radi = r;
		destF = dst;
	}

	shot() : base() {}

	void update() {
		bnds.pos.x += sin(destF*M_PI / 180.0) * 8;
		bnds.pos.y -= cos(destF*M_PI / 180.0) * 8;
	}

	void draw() {
		txSetFillColour(color);
		txSetColor(color, 1);
		txCircle(bnds.pos.x, bnds.pos.y, radi);
		resetCol();
	}

	void collide(base *with) { }
};

#endif
