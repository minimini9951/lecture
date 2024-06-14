#ifndef CSD1130_COLLISION_H_
#define CSD1130_COLLISION_H_

#include "CProcessing.h"

/**************************************************************************/
/*!

	*/
/**************************************************************************/

struct AABB
{
	CP_Vector min;
	CP_Vector max;
	float width;
	float height;
	int count;
};

int CollisionIntersection_RectRect(const struct AABB* aabb1, const struct AABB* aabb2);

struct AABB intersection(const struct AABB* aabb1, const struct AABB* aabb2);

#endif // CSD1130_COLLISION_H_