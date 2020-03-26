#include "teach.h"
#include "iomanip"
void teach::showfile() {
	for (int i = 0; i < 10; i++) {
		std::cout << std::setw(6) << teacin[i].name << std::setw(6) << teacin[i].teacherid << std::endl;
		for (int day = 0; day < 6; day++) {
			for (int period = 0; period < 8; period++) {
				std::cout << teacin[i].FT[day][period];
			}
			std::cout << std::endl;
		}

	}

}
void teach::readfile(std::string a) {
	int z;
	std::ifstream myfile;
	myfile.open(a);
	if (myfile.is_open())
	{
		myfile >> z;
		teacin = new teac[z];
		while (!myfile.eof()) {
			for (int i = 0; i < z; i++) {
				myfile >> teacin[i].teacherid;
				myfile >> teacin[i].name;
				for (int day = 0; day < 6; day++) {
					for (int period = 0; period < 8; period++) {
						myfile >> teacin[i].FT[day][period];
					}
				}
			}

		}
	}
	else std::cout << "Unable to open file(invalid path entered)";
}

