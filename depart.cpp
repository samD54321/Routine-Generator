#include "Depart.h"
#include "teach.h"
#include"iomanip"
void Depart::readfile(std::string a) {


    std::ifstream myfile;
    myfile.open(a);

    if (myfile.is_open())
    {

        myfile >> nteach;
        int c = nteach;
        tclass = new dclass[nteach];
        while (!myfile.eof() && c--)
        {
            myfile >> tclass[c].teacherid;
            myfile >> tclass[c].subject;
            myfile >> tclass[c].classs;
            myfile >> tclass[c].classno;
            myfile >> tclass[c].labno;

        }
    }
    else std::cout << "Unable to open file(invalid path entered)";
}
void Depart::Showfile() {
    for (int i = 0; i < nteach; i++) {
        std::cout << std::setw(20) << tclass[i].teacherid << std::setw(20) << tclass[i].subject << "\t" << std::setw(20) << tclass[i].classs << "\t" << std::setw(20) << tclass[i].classno << "\t" << std::setw(20) << tclass[i].labno << std::endl;

    }

}
