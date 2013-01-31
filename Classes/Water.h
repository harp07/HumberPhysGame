#include <math.h>
#include "cocos2d.h"
#include "Particle.h"
#include "Vector2.h"

using namespace cocos2d;

#define WATERCOLUMNS 201
#define PI 3.1415

class Water {
	struct WaterColumn {
		float TargetHeight;
		float Height;
		float Speed;

		void Update(float dampening, float tension){
			float x = TargetHeight - Height;
			Speed += tension * x - Speed * dampening;
			Height += Speed;
		}
	};
public:
	WaterColumn *columns[201];
	float rand;
	float Tension;
	float Dampening;
	float Spread;

	CCSpriteBatchNode spriteBatch;
	CCTexture2D ParticleTexture;
	std::list<Particle> particles;

	Water(CCTexture2D particleTexture);
	float GetHeight(float x);
	void UpdateParticle(Particle *particle);
	void Update();
	void DrawToRenderTargets();
	void Draw();
	CCSize winSize;

private:
	float Scale(float sWidth){
		return sWidth / WATERCOLUMNS - 1.0f;
	}
	float GetAngle(Vector2 vector){
		return (float)atan2(vector.Y, vector.X);
	}

	/*void CreateParticle(Vector2 pos, Vector2 velocity)
		{
			particles.insert(
		}*/

	Vector2 FromPolar(float angle, float magnitude)
	{
		Vector2 mag = Vector2((float)cos(angle),(float)sin(angle));

		return mag * magnitude;
	}

	float GetRandomFloat(float min, float max)
	{
		return (float)rand * (max - min) + min;
	}

	Vector2 GetRandomVector2(float maxLength)
	{
		return FromPolar(GetRandomFloat(PI, PI), GetRandomFloat(0, maxLength));
	}

};