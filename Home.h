#ifndef Home_H
#define Home_H
#pragma once

#include <iostream>
class Home
{
    int iHome;
    int NumbApartament;
    int MenCount;
    double TaxForHome;
public:
    Home();
    Home(int iH, int NumbA, int MenC, double TFH);
    ~Home();
    int get_iHome();
    int get_NumbApartament();
    int get_MenCount();
    double get_TaxForHome();
    void set_iHome(int iH);
    void set_MenCount(int MenC);
    void set_NumbApartament(int NumbA);
    void set_TaxForHome(double TFH);
    friend std::ostream& operator<<(std::ostream& output, Home& H);
};

#endif;
