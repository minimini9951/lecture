#include "Collision.h"

/*!



	*/
/**************************************************************************/

int CollisionIntersection_RectRect(const struct AABB* aabb1, const struct AABB* aabb2)
{
	if (aabb1->min.x > aabb2->max.x || aabb2->min.x > aabb1->max.x || aabb1->max.y < aabb2->min.y || aabb2->max.y < aabb1->min.y)
		return 0;
	else
		return 1;
}

struct AABB intersection(const struct AABB* aabb1, const struct AABB* aabb2)
{
	struct AABB aabb3;

	if (aabb1->max.x >= aabb2->max.x)
	{
		aabb3.width = aabb2->max.x - aabb1->min.x;
		aabb3.min.x = aabb1->min.x;
		if (aabb1->min.x <= aabb2->min.x)
		{
			aabb3.width = aabb2->width;
			aabb3.min.x = aabb2->min.x;
		}
	}

	else
	{
		aabb3.width = aabb1->max.x - aabb2->min.x;
		aabb3.min.x = aabb2->min.x;
		if (aabb2->min.x <= aabb1->min.x)
		{
			aabb3.width = aabb1->width;
			aabb3.min.x = aabb1->min.x;
		}
	}
	if (aabb1->max.y >= aabb2->max.y)
	{
		aabb3.height = aabb2->max.y - aabb1->min.y;
		aabb3.min.y = aabb2->min.y;
		if (aabb1->min.y <= aabb2->min.y)
		{
			aabb3.height = aabb2->height;
			aabb3.min.y = aabb1->min.y;
		}
		return aabb3;
	}
	else
	{
		aabb3.height = aabb1->max.y - aabb2->min.y;
		aabb3.min.y = aabb1->min.y;
		if (aabb2->min.y <= aabb1->min.y)
		{
			aabb3.height = aabb1->height;
			aabb3.min.y = aabb2->min.y;
		}
		return aabb3;
	}
}