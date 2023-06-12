#pragma once

struct Quaternion {
private:

	//Store rotation in degrees
	float x, y, z;
public:
	Quaternion(float x, float y, float z);
	Quaternion();
	
	float getX();
	float getY();
	float getZ();
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void abs();
	void normalize();
	Quaternion operator-(Quaternion other);
	Quaternion operator+(Quaternion other);
	Quaternion operator*(Quaternion other);
	Quaternion operator/(Quaternion other);
	Quaternion operator+=(Quaternion other);
	Quaternion operator-=(Quaternion other);
	Quaternion operator*=(Quaternion other);
	Quaternion operator/=(Quaternion other);
	Quaternion operator%(Quaternion other);
	Quaternion operator%=(Quaternion other);
	static float degrees(float radiants);
	static float radiants(float degrees);
	
};