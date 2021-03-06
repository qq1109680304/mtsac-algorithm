#ifndef RUNTIMEEXCEPTIONS_H
#define RUNTIMEEXCEPTIONS_H
// Modified for CSCI 220 Fall 13
// Updated Fall 21

#include <exception>

using namespace std;

class RuntimeException : public exception 
{
public:
	RuntimeException(const char *err) : exception() {}
};

class NonexistentElement : public RuntimeException
{
public:
	NonexistentElement(const char *err) : RuntimeException(err) {}
};

class BoundaryViolation : public RuntimeException 
{
public:
	BoundaryViolation(const char *err) : RuntimeException(err) {}
};
#endif