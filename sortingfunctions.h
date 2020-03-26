#pragma once
#include "myclass.h"
#include"Depart.h"
#include"teach.h"
#include "iomanip"
#include"iostream"
#include "cstring"
#include"fstream"


std::string daysofweek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };




void findteacherswithlab(myclass& c1, Depart d1, teach& t1)

{
    string assigned[10];
    int alreadydonesub = 0;
    int z, k;

    for (int i = 0; i < d1.Depart::nteach; i++)
    {
        bool haha = 0;
        if (c1.classname == d1.tclass[i].classs)
        {
            if (d1.tclass[i].labno != 0)
            {//check if their is lab
                for (int j = 0; j < d1.Depart::nteach; j++)//Check for each teacher
                {
                    if (d1.tclass[i].subject == d1.tclass[j].subject && i != j && d1.tclass[j].labno != 0)//check the two teacher for lab
                    {
                        for (int l = 0; l < 6; l++) {
                            if (d1.tclass[i].subject == assigned[l])  haha = 1;

                        }
                        if (haha == 0)
                        {


                            for (k = 0; k < d1.Depart::nteach; k++)
                            {
                                if (t1.teacin[k].teacherid == d1.tclass[i].teacherid || t1.teacin[k].teacherid == d1.tclass[j].teacherid)//goes to teacher obj
                                {
                                    if (t1.teacin[k].teacherid == d1.tclass[i].teacherid)
                                    {
                                        for (z = k; z < d1.Depart::nteach; z++)
                                        {
                                            if (t1.teacin[z].teacherid == d1.tclass[j].teacherid) break;
                                        }

                                    }
                                    if (t1.teacin[k].teacherid == d1.tclass[j].teacherid)
                                    {
                                        for (z = k; z < d1.Depart::nteach; z++)
                                        {
                                            if (t1.teacin[z].teacherid == d1.tclass[i].teacherid) break;
                                        }

                                    }

                                    if (z != (d1.Depart::nteach))
                                    {
                                        for (int day = 0; day < 6; day++)
                                        {
                                            for (int period = 0; period < (9 - d1.tclass[i].labno); period++)
                                            {
                                                if ((t1.teacin[k].FT[day][period]) && (t1.teacin[k].FT[day][period + d1.tclass[i].labno - 1]) && (t1.teacin[k].FT[day][period + d1.tclass[i].labno - 2]))//check if teacher is free 
                                                {
                                                    if ((t1.teacin[z].FT[day][period]) && (t1.teacin[z].FT[day][period + d1.tclass[i].labno - 1]) && (t1.teacin[z].FT[day][period + d1.tclass[i].labno - 2]))
                                                    {

                                                        if (c1.Timetable[day][period].empty() && c1.Timetable[day][period + d1.tclass[i].labno - 1].empty() && c1.Timetable[day][period + d1.tclass[i].labno - 2].empty())
                                                        {
                                                            assigned[alreadydonesub] = d1.tclass[i].subject;
                                                            alreadydonesub++;
                                                            c1.Timetable[day][period + d1.tclass[i].labno - 1] = c1.Timetable[day][period + d1.tclass[i].labno - 2] = c1.Timetable[day][period] = t1.teacin[k].name + " " + t1.teacin[z].name + " " + "lab " + d1.tclass[i].subject;
                                                            t1.teacin[z].Timetable[day][period + d1.tclass[i].labno - 1] = t1.teacin[z].Timetable[day][period + d1.tclass[i].labno - 2] = t1.teacin[z].Timetable[day][period] = c1.classname + " " + d1.tclass[i].subject;
                                                            t1.teacin[k].Timetable[day][period + d1.tclass[i].labno - 1] = t1.teacin[k].Timetable[day][period + d1.tclass[i].labno - 2] = t1.teacin[k].Timetable[day][period] = c1.classname + " " + d1.tclass[i].subject;
                                                            t1.teacin[k].FT[day][period + d1.tclass[i].labno - 1] = t1.teacin[k].FT[day][period + d1.tclass[i].labno - 2] = t1.teacin[k].FT[day][period] = 0;
                                                            t1.teacin[z].FT[day][period + d1.tclass[i].labno - 1] = t1.teacin[z].FT[day][period + d1.tclass[i].labno - 2] = t1.teacin[z].FT[day][period] = 0;
                                                            day = 7;
                                                            period = -1;                                                                                                                                                                      period = 9;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }




}


void printclasstable(myclass c1) {
    cout << "\n     ";
    for (int money = 1; money < 9; money++) {
        cout << setw(19) << "Period" << money;
    }
    for (int day = 0; day < 6; day++)
    {
        cout << "\n" << daysofweek[day] << "  ";
        for (int period = 0; period < 8; period++)
        {
            if (c1.Timetable[day][period].empty()) cout << setw(20) << "-";
            else cout << setw(20) << c1.Timetable[day][period];
        }
    }
    cout << "\n \n ";
}

void printteachertable(teac t1) {
    cout << "     ";
    for (int money = 1; money < 9; money++) {
        cout << setw(20) << money;
    }
    for (int day = 0; day < 6; day++)
    {
        cout << "\n" << daysofweek[day] << "  ";
        for (int period = 0; period < 8; period++)
        {
            cout << setw(20) << t1.Timetable[day][period];
        }
    }
    cout << "\n \n";
}


void find2lectureclass(myclass& c1, Depart d1, teach& t1) {
    for (int i = 0; i < d1.Depart::nteach; i++)
    {

        if (c1.classname == d1.tclass[i].classs)
        {
            int flag;

            if (d1.tclass[i].classno != 0) {
                for (int j = 0; j < d1.nteach; j++)//Check for each teacher
                {
                    if (d1.tclass[i].teacherid == t1.teacin[j].teacherid)
                    {
                        do
                        {
                            flag = d1.tclass[i].classno;
                            if (d1.tclass[i].classno > 1)
                            {
                                for (int day = 0; day < 6; day++)
                                {
                                    for (int period = 0; period < 7; period++)
                                    {
                                        if (d1.tclass[i].classno > 1) {
                                            if ((t1.teacin[j].FT[day][period]) && (t1.teacin[j].FT[day][period + 1]))//check if teacher is free 
                                            {
                                                if (((c1.Timetable[day][period]).empty()) && ((c1.Timetable[day][period + 1]).empty())) {

                                                    c1.Timetable[day][period] = c1.Timetable[day][period + 1] = t1.teacin[j].name;
                                                    d1.tclass[i].classno = d1.tclass[i].classno - 2;
                                                    t1.teacin[j].FT[day][period] = t1.teacin[j].FT[day][period + 1] = false;
                                                    break;

                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } while (d1.tclass[i].classno != flag);
                    }
                }
            }
        }
    }
}

void find1lectureclass(myclass& c1, Depart d1, teach& t1) {
    for (int i = 0; i < d1.Depart::nteach; i++)
    {
        int checker = d1.tclass[i].teacherid;
        if (c1.classname == d1.tclass[i].classs)
        {
            if (c1.classname == d1.tclass[i].classs)
            {
                int flag;
                if (d1.tclass[i].classno != 0)
                {
                    for (int j = 0; j < d1.Depart::nteach; j++)//Check for each teacher
                    {
                        if (d1.tclass[i].teacherid == t1.teacin[j].teacherid) {
                            do {
                                flag = d1.tclass[i].classno;
                                if (d1.tclass[i].classno) {
                                    for (int day = 0; day < 6; day++)
                                    {
                                        for (int period = 0; period < 8; period++)
                                        {
                                            if (d1.tclass[i].classno > 0)
                                            {
                                                if (t1.teacin[j].FT[day][period]) //check if teacher is free 
                                                {
                                                    if ((c1.Timetable[day][period]).empty())
                                                    {

                                                        if ((c1.Timetable[day][period + 1]) != (t1.teacin[j].name))
                                                        {
                                                            if ((c1.Timetable[day][period - 1] != t1.teacin[j].name))
                                                            {
                                                                c1.Timetable[day][period] = t1.teacin[j].name;
                                                                d1.tclass[i].classno -= 1;
                                                                break;
                                                            }
                                                        }

                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } while (d1.tclass[i].classno != flag);

                        }
                    }
                }
            }
        }

    }
}



/*void double_touch(Depart d1, teach t1, myclass c1) {

    for (int i = 0; i < d1.Depart::nteach; i++)
    {
        if (d1.tclass[i].classno != 0) {
            for (int j = 0; j < d1.Depart::nteach; j++)//Check for each teacher
            {
                if (d1.tclass[i].teacherid == t1.teacin[j].teacherid) {
                    std::string flag;
                    for (int day = 0; day < 6; day++)
                    {
                        for (int period = 0; period < 8; period++)
                        {

                            if (t1.teacin[j].FT[day][period]) //check if teacher is free
                            {

                                c1.Timetable[day][period] = flag;

                                for (int tname = 0; tname < d1.Depart::nteach; tname++)
                                {

                                }

                            }
                        }

                    }
                }
            }

        }

    }
}



void tandhatan(teach t1,Depart d1,myclass c1,int j,string flag) {




}*/