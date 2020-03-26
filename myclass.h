#pragma once
#include"iostream"
#include"fstream"
using namespace std;
struct csub {
	string name;
	int subdepartcode;
	int labno;
	int classno;
};

class myclass
{
public:
	string Timetable[6][8];

	string classname;
	int nsub;//no. of sub
	csub* subject;
public:
	void readfile(string a);
	void showfile();

};

