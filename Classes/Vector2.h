#pragma once

class Vector2{
public:
	float X,Y;

	Vector2(){
		X = 0;
		Y = 0;
	}

	Vector2(float x, float y){
		X = x;
		Y = y;
	}

	Vector2 operator+=(const Vector2 vect){
		X += vect.X;
		Y += vect.Y;
		return *this;
	}

	Vector2 operator*(float num){
		X *= num;
		Y *= num;
		return *this;
	}
};