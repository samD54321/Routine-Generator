#pragma once
#include"iostream"
#include"fstream"

struct teac {
	int teacherid;
	std::string name;
	bool FT[6][8];
	std::string Timetable[6][8];
};
class teach
{
public:

	teac* teacin;
	void showfile();
	void readfile(std::string a);
};

