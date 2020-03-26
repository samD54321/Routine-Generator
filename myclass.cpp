#include "myclass.h"
#include"iomanip"


void myclass::readfile(string a) {


    std::ifstream myfile;
    myfile.open(a);

    if (myfile.is_open())
    {
        myfile >> classname;
        myfile >> nsub;
        int c = nsub;
        subject = new csub[nsub];
        while (!myfile.eof() && c--)
        {
            myfile >> subject[c].name;
            myfile >> subject[c].subdepartcode;
            myfile >> subject[c].classno;
            myfile >> subject[c].labno;

        }
    }
    else std::cout << "Unable to open file(invalid path entered)";
}
void myclass::showfile() {
    cout << classname;
    for (int i = 0; i < nsub; i++) {
        cout << subject[i].name << "\t" << std::setw(20) << subject[i].subdepartcode << "\t" << std::setw(20) << subject[i].classno << "\t" << std::setw(20) << subject[i].labno << endl;
    }
}
