#ifndef OBJ_H
#define OBJ_H
#include "Tank.h"
class ObjController
{
public:
	vector<base*> objs;
	ObjController() : objs() {

	}

	void addObj(base *obj) {
		objs.push_back(obj);
	}

	void update() {
		for (vector<base*>::iterator it = objs.begin(); it != objs.end();)
		{
			base *il = (*it);
			if (!il->destroyed) {
				il->update();
				for (vector<base*>::iterator jt = objs.begin(); jt != objs.end(); ++jt)
				{
					base *jl = (*jt);
					if (it != jt && !jl->destroyed && il->bnds.inBounds(&jl->bnds))
						il->collide(jl);
				}
				++it;
			}
			else {
				delete *(it);
				it = objs.erase(it);
			}
		}
		for (vector<base*>::iterator it = objs.begin(); it != objs.end(); ++it) {
			if (!(*it)->destroyed) { (*it)->draw(); }
		}
	}

	~ObjController()
	{
		for (vector<base*>::iterator it = objs.begin(); it != objs.end(); ++it) {
			delete *it;
		}
		objs.clear();
	}
};

#endif

