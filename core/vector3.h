#pragma once
struct Vector3 {
private:
	double x, y, z;
	
public:
	Vector3(double x, double y, double z);
	Vector3();
	Vector3(double x, double y);
	Vector3 operator-(Vector3 other);
	Vector3 operator+(Vector3 other);
	Vector3 operator*(Vector3 other);
	Vector3 operator/(Vector3 other);
	Vector3 operator+=(Vector3 other);
	Vector3 operator-=(Vector3 other);
	Vector3 operator*=(Vector3 other);
	Vector3 operator/=(Vector3 other);
	
	double distance(Vector3 other);
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	

	static Vector3 normalize(Vector3 vec3);
};