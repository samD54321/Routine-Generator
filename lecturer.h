#pragma once
#include "iostream"
#include "fstream"
#include "string"
#include "classroom.h"
#include "array"
class lecturer
{
public:
	bool freetime[6][8];
	std::string name;
	bool class1;

	bool class2;
	bool assignclass[6][8];


public:
	void readfile(std::string a);
	friend class classroom;

};

