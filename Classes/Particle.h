#include <cocos2d.h>
#include "Vector2.h"

class Particle {
public:
	Vector2 Position;
	Vector2 Velocity;
	float Orientation;
	Particle(Vector2 position,Vector2 velocity, float orientation){
		Position = position;
		Velocity = velocity;
		Orientation = orientation;
	}
};