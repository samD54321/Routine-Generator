#include "classroom.h"
#include"array"

void classroom::sortschedule(lecturer* l, int s) {
	std::string cr = "class";
	bool z;
	cr += std::to_string(s);


	if (cr == "class1") {}
	for (int i = 0; i < 8; i++) {
		if (cr == "class1") { z = l[i].class1; }
		if (cr == "class2") { z = l[i].class2; }
		if (z) {
			for (int day = 0; day < 6; day++) {
				for (int period = 0; period < 8; period++) {
					if (l[i].freetime[day][period] == true && TT[day][period].empty()) {

						TT[day][period] = l[i].name;
						l[i].freetime[day][period] = false;
						l[i].assignclass[day][period] = true;
						break;

					}
				}

			}

		}
	}

}
void classroom::printtable()
{
	for (int day = 0; day < 6; day++)
	{
		std::cout << "\n DAY " << day + 1 << " ";
		for (int period = 0; period < 8; period++)
		{
			std::cout << TT[day][period] << std::setw(20);
		}
	}

}