#pragma once
#include<iostream>
#include<fstream>
struct dclass {
	int teacherid;
	std::string  subject;
	std::string classs;
	int classno;
	int labno;


};
class Depart
{
public:
	int nteach;
	dclass* tclass;
	void readfile(std::string a);
	void Showfile();
};

