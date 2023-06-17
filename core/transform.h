#pragma once
#include "vector3.h"
#include "quaternion.h"
#include <vector>
struct Transform {

	//Variables
	Transform* parent = nullptr;
	Vector3 localVector;
	Quaternion localRotation;
	std::vector<Transform *> childs;

	//Contructors
	Transform();
	Transform(Vector3 v);
	Transform(Vector3 v, Quaternion rotation);
	Transform(double x, double y, double z);
	Transform(double x, double y, double z, Quaternion rotation);
	
	//Functions
	Quaternion angleTo(Vector3 other);
	Quaternion angleFrom(Vector3 other);
	Quaternion getGlobalRotation();
	Quaternion getLocalRotation();
	Vector3 getGlobalVector3();
	Vector3 getLocalVector3();
	bool hasParent();
	bool isFacing(Vector3 point, float fov);
	bool isFacing(Vector3 point);
	Transform* getParent();
	void setRotation(Quaternion r);
	void setParent(Transform p);
	void setParent(Transform* p);
};