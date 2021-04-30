#pragma once


#include "common.hpp"
#include "natives.hpp"
#include "Math.hpp"




#include <math.h>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>


float degToRad(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}

Hash $(std::string str) {
	return GAMEPLAY::GET_HASH_KEY(&str[0u]);
}

Vector3 coordsOf(Entity entity) {
	return ENTITY::GET_ENTITY_COORDS(entity, 1);
}

float distanceBetween(Vector3 A, Vector3 B) {
	return GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

int rndInt(int start, int end) {
	return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(start, end);
}

Vector3 rot_to_direction(Vector3* rot) {
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

Vector3 add(Vector3* vectorA, Vector3* vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 SUBVEc(Vector3* vectorA, Vector3* vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x -= vectorB->x;
	result.y -= vectorB->y;
	result.z -= vectorB->z;
	return result;
}


Vector3 multiply(Vector3* vector, float x) {
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float get_distance(Vector3* pointA, Vector3* pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float get_vector_length(Vector3* vector) {
	double x = (double)vector->x;
	double y = (double)vector->y;
	double z = (double)vector->z;
	return(float)sqrt(x * x + y * y + z * z);
}

//From Menyoo-------------------Below--------------------
Vector3 operator + (Vector3 const& left, Vector3 const& right)
{
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator - (Vector3 const& left, Vector3 const& right)
{
	return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3 operator - (Vector3 const& value)
{
	return Vector3(-value.x, -value.y, -value.z);
}

Vector3 operator * (Vector3 const& left, Vector3 const& right)
{
	return Vector3(left.x * right.x, left.y * right.y, left.z * right.z);
}

Vector3 operator * (Vector3 const& value, float const& scale)
{
	return Vector3(value.x * scale, value.y * scale, value.z * scale);
}

Vector3 operator * (float const& scale, Vector3 const& value)
{
	return Vector3(value.x * scale, value.y * scale, value.z * scale);
}

Vector3 operator *= (Vector3& value, float const& scale)
{
	value.x *= scale;
	value.y *= scale;
	value.z *= scale;
	return value;
}

Vector3 operator / (Vector3 const& left, Vector3 const& right)
{
	return Vector3(left.x / right.x, left.y / right.y, left.z / right.z);
}

Vector3 operator / (Vector3 const& value, float const& scale)
{
	return Vector3(value.x / scale, value.y / scale, value.z / scale);
}

Vector3 operator /= (Vector3& value, float const& scale)
{
	value.x /= scale;
	value.y /= scale;
	value.z /= scale;
	return value;
}