#pragma once
#include "iostream"
#include "fstream"
#include "string"
#include "lecturer.h"
#include"iomanip"
class classroom
{
public:
	std::string TT[6][8];
	bool hasclass;
	friend class lecturer;
public:
	void sortschedule(lecturer* l, int s);
	void printtable();
};

