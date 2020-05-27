#include "Home.h"

Home::Home() 
{
    iHome = NumbApartament = MenCount = TaxForHome = 0;
}

Home::Home(int iH, int NumbA, int MenC, double TFH) 
{
    iHome = iH;
    NumbApartament = NumbA;
    MenCount = MenC;
    TaxForHome = TFH;
}

void Home::set_iHome(int iH) 
{
    iHome = iH;
}
void Home::set_NumbApartament(int NumbA) 
{
    NumbApartament = NumbA;
}
void Home::set_MenCount(int MenC) 
{
    MenCount = MenC;
}
void Home::set_TaxForHome(double TFH)
{
    TaxForHome = TFH;
}


int Home::get_iHome() 
{
    return iHome;
}
int Home::get_NumbApartament() 
{
    return NumbApartament;
}
int Home::get_MenCount() 
{
    return MenCount;
}
double Home::get_TaxForHome() 
{
    return TaxForHome;
}

std::ostream& operator<<(std::ostream& out, Home& H) 
{
    out << "Home{" <<
        "number = " << H.get_iHome() << "," <<
        "number Of apartments = " << H.get_NumbApartament() << "," <<
        "number Of residents = " << H.get_MenCount() << "," <<
        "size of tax = " << H.get_TaxForHome() << "}";
    return out;
}

Home::~Home()
{
}