#pragma once
Hash $(std::string str);
int rndInt(int start, int end);
float distanceBetween(Vector3 A, Vector3 B);
float degToRad(float degs);
float get_distance(Vector3* pointA, Vector3* pointB);
float get_vector_length(Vector3* vector);
Vector3 rot_to_direction(Vector3* rot);
Vector3 add(Vector3* vectorA, Vector3* vectorB);
Vector3 multiply(Vector3* vector, float x);
Vector3 coordsOf(Entity entity);
Vector3 operator + (Vector3 const& left, Vector3 const& right);
Vector3 operator - (Vector3 const& left, Vector3 const& right);
Vector3 operator - (Vector3 const& value);
Vector3 operator * (Vector3 const& left, Vector3 const& right);
Vector3 operator * (Vector3 const& value, float const& scale);
Vector3 operator * (float const& scale, Vector3 const& value);
Vector3 operator *= (Vector3& value, float const& scale);
Vector3 operator / (Vector3 const& left, Vector3 const& right);
Vector3 operator / (Vector3 const& value, float const& scale);
Vector3 operator /= (Vector3& value, float const& scale);