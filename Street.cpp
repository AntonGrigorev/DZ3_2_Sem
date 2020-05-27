#include "Street.h"

Street::Street() 
{
    Name_Street = "Zero";
    Homes_num = NumberStreet = HumanCount = 0;
}

Street::Street(std::string NameS, int NumS, int HomeN, int HC)
{
    Name_Street = NameS;
    NumberStreet = NumS;
    Homes_num = HomeN;
    HumanCount = HC;
}

Street::Street(std::string NameS, int NumS)
{
    Name_Street = NameS;
    NumberStreet = NumS;
}

Street::~Street()
{
}

void Street::set_NameStreet(std::string NameStr) 
{ 
    Name_Street = NameStr;
}
void Street::set_HomeNum() 
{
    Homes_num = homes.size();
}
void Street::set_NumbStreet(int NumSt) 
{ 
    NumberStreet = NumSt; 
}
void Street::set_HumanCount() 
{ 
    int count = 0;
    for (std::list<Home>::iterator it = homes.begin(); it != homes.end(); it++) {
        count += it->get_MenCount();
    }
    HumanCount = count;
}
void Street::set_Income()
{
    double tax = 0;
    for (std::list<Home>::iterator it = homes.begin(); it != homes.end(); it++) {
        tax += it->get_TaxForHome();
    }
    Income = tax;
}


std::string Street::get_NameStreet() 
{ 
    return Name_Street;
}
int Street::get_HomesNum() 
{ 
    return Homes_num;
}
int Street::get_NumbStreet() 
{
    return NumberStreet;
}
int Street::get_HumanCount() 
{ 
    return HumanCount;
}
double Street::get_Income()
{
    return Income;
}

void Street::add(Home& house)
{
    homes.push_back(house);
}

void Street::del()
{
    if (homes.empty()) {
        std::cout << "List is empty";
        return;
    }
    homes.pop_back();
    set_HumanCount();
    set_HomeNum();
    set_Income();
}

void Street::print_homes()
{
    for (auto it = homes.begin(); it != homes.end(); it++) {
        std::cout << *it;
        std::cout << std::endl;
    }
}

Street Street::operator+(Home& H)
{
    add(H);
    set_HumanCount();
    set_HomeNum();
    set_Income();
    return *this;
}

Street Street::operator+(Street& Str)
{
    homes.insert(homes.end(), Str.homes.begin(), Str.homes.end());
    set_HumanCount();
    set_HomeNum();
    set_Income();
    return *this;
}

Street Street::operator=(Street& Str)
{
    Name_Street = Str.get_NameStreet();
    NumberStreet = Str.get_NumbStreet();
    HumanCount = Str.get_HumanCount();
    Homes_num = Str.get_HomesNum();
    Income = Str.get_Income();
    for (std::list<Home>::iterator it = Str.homes.begin(); it != Str.homes.end(); it++) {
        homes.push_back(*(it));
    }
    return *this;
}

Street Street::operator/(int num) //деление улицы пополам
{
    num = 2;
    Street tmp("Ulitza Pobedy", NumberStreet + 1, Homes_num / 2, HumanCount);
    std::list<Home>::iterator it = homes.begin();
    advance(it, homes.size() / 2);
    for (it; it != homes.end(); it++) {
        tmp.homes.push_back(*(it));
    }
    std::list<Home>::iterator it2 = homes.begin();
    advance(it2,  homes.size() / 2);
    homes.erase(it2, homes.end());
    set_HumanCount();
    set_HomeNum();
    set_Income();
    tmp.set_HumanCount();
    tmp.set_HomeNum();
    tmp.set_Income();
    return tmp;
}

//DZ3

std::ostream& operator<<(std::ostream& out, Street& Str)
{
    out << "Street{" <<
        "number = " << Str.get_NumbStreet() << "," <<
        "name of street = " << Str.get_NameStreet() << "," <<
        "number of homes = " << Str.get_HomesNum() << "," <<
        "number of humans = " << Str.get_HumanCount() << "," <<
        "total income = " << Str.get_Income() <<"}";
    out << std::endl;

    for (std::list<Home>::iterator it = Str.homes.begin(); it != Str.homes.end(); it++) {
        out << *(it) << std::endl;
    }
    return out;
}

Home Street::search(double taxsearch)
{
    std::list<Home>::iterator found = std::find_if(homes.begin(), homes.end(),
        [&](Home& a) {return a.get_TaxForHome() == taxsearch; });
    if (found != homes.end()) {
        return *(found);
    }
    else {
        Home empty;
        return empty;
    }
}

void Street::redact(double newtax, int index)
{
    std::list<Home>::iterator it = homes.begin();
    std::advance(it, index - 1);
    it->set_TaxForHome(newtax);
    set_Income();
}

void Street::delobj(int index1)
{
    if (homes.empty()) {
        std::cout << "List is empty";
        return;
    }
    std::list<Home>::iterator it = homes.begin();
    std::advance(it, index1 - 1);
    homes.erase(it);
    set_HumanCount();
    set_HomeNum();
    set_Income();
}

std::ofstream& operator<<(std::ofstream& outf, Street& Str)
{
    for (std::list<Home>::iterator it = Str.homes.begin(); it != Str.homes.end(); it++) 
    {
        outf << it->get_iHome() << std::endl;
        outf << it->get_NumbApartament() << std::endl;
        outf << it->get_MenCount() << std::endl;
        outf << it->get_TaxForHome() << std::endl;
    }
    return outf;
}

std::ifstream& operator>>(std::ifstream& inf, Street& Str)
{
    int par1 = 0, par2 = 0, par3 = 0; double par4 = 0;
    while (inf ) {
         inf >> par1; inf >> par2; inf >> par3; inf >> par4;
         if (!inf)
             break;
         Home obj(par1, par2, par3, par4);
         Str.add(obj);
    }
    Str.set_HumanCount();
    Str.set_HomeNum();
    Str.set_Income();
    return inf;
}

void Street::sortind()
{
    homes.sort([](Home& a, Home& b) { return a.get_iHome() < b.get_iHome(); });
}

void Street::sortmen()
{
    homes.sort([](Home& a, Home& b) { return a.get_MenCount() < b.get_MenCount(); });
}

unsigned int Street::size()
{
    return homes.size();
}

