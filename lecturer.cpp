#include "lecturer.h"
#include "myclass.h"
#include "Depart.h"

void lecturer::readfile(std::string a) {

    char table[6][8];
    std::string line;
    std::ifstream myfile;
    myfile.open(a);

    if (myfile.is_open())
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                myfile >> table[i][j];
                if (table[i][j] == '1')
                    freetime[i][j] = true;
                else if (table[i][j] == '0')
                    freetime[i][j] = false;
            }
        }
        while (!myfile.eof())
        {
            myfile >> name;
            myfile >> class1;
            myfile >> class2;

        }
    }
    else std::cout << "Unable to open file(invalid path entered)";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            assignclass[i][j] = 0;
        }

    }

}

/*int main() {
    lecturer l[8];
    for (int i = 0; i < 8; i++)
    {
        std::string filename = std::to_string(i + 1);
        l[i].readfile("C:\\Users\\Sgr45\\Downloads\\l" + filename + ".txt");
    }
    classroom c1,c2;
    c1.sortschedule(l,1);
    c1.printtable();
    std::cout << "\n\n\n\n\n\n\n";
    c2.sortschedule(l, 2);
    c2.printtable();

    return 0;
}*/




