#ifndef BNDS_H
#define BNDS_H

#include "Vector.h"

class V2Pos {
public:
	Vector2 pos; //позиция левого верхнего угла
	Vector2 size; //сдвиг до правого нижнего

	V2Pos(Vector2 _size, Vector2 _pos) {
		size = _size;
		pos = _pos;
	}

	int inBounds(Vector2 pos2, float radi) {
		return !((pos2.x + radi) > (pos.x+size.x) || (pos2.x - radi) < pos.x || (pos2.y + radi) > pos.y+size.y || (pos2.y - radi) < pos.y);
	}

	int inBounds(V2Pos *bnds) {
		return !(pos.y > (bnds->pos.y + bnds->size.y) || (pos.y + size.y) < bnds->pos.y || (pos.x + size.x) < bnds->pos.x || pos.x > (bnds->pos.x + bnds->size.x));
	}

	/*Vector2 deltaPos(Vector2 pos, float radi) {
        int posCheck = inBounds(pos, radi);
        Vector2 ret = Vector2(0,0);
        if((posCheck & 2) == 2) ret.x += (ruPos.x - (pos.x + radi))-3;
        else if((posCheck & 8) == 8) ret.x += (ldPos.x - (pos.x - radi))+3;

        if((posCheck & 4) == 4) ret.y += (ldPos.y - (pos.y + radi))-3;
        else if((posCheck & 16) == 16) ret.y += (ruPos.y - (pos.y - radi))+3;
        return ret;
	}*/

	V2Pos() {}
};

#endif