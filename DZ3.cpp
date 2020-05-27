#include <iostream>
#include <string>
#include "Home.h"
#include "Street.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[])
{
    std::string name; //1)
    int snum;
    cout << "Street name and number?" << endl;
    cin >> name;
    cin >> snum;
    Street str(name, snum);
    int numb;
    cout << "How many houses?" << endl;
    cin >> numb;
    int par1, par2, par3; double par4;
    for (int i = 0; i < numb; i++) {
        cout << i+1 << ")" << "Home number?" << endl;
        cin >> par1;
        cout << "Number of apartaments?" << endl;
        cin >> par2;
        cout << "Men count?" << endl;
        cin >> par3;
        cout << "Tax size?" << endl;
        cin >> par4;
        Home obj(par1, par2, par3, par4);
        str.add(obj);
    }
    str.set_HumanCount();
    str.set_HomeNum();
    str.set_Income();
    
    double taxsearch;   //2)
    cout << "Size of tax to search?" << endl;
    cin >> taxsearch;
    Home src = str.search(taxsearch);
    if (src.get_iHome() != 0)
        cout << src << endl;
    else
        cout << "Not found" << endl;

    cout << "Position of house to redact?" << " (Total amount:" << " " <<  //3)
        numb << ")" << endl;
    int index;
    cin >> index;
    cout << "New size of tax?" << endl;
    int newtax;
    cin >> newtax;
    str.redact(newtax, index);

    cout << "Position of house to delete?" << " (Total amount:" << " " <<  //4)
        str.size() << ")" << endl;
    int index1;
    cin >> index1;
    str.delobj(index1);

    std::ofstream outf("File.txt");    //5
    outf << str;
    outf.close();

    std::ifstream inf("File.txt");   //6
    Street str1("Leninskaya", 2);
    inf >> str1;
    inf.close();

    cout << "Choose sort parameter:" << " press 1 to sort by home number or " << //7
        "press 2 to sort by men count " << endl;
    int button;
    cin >> button;
    switch (button) {
    case 1:
        str.sortind();
        break;
    case 2:
        str.sortmen();
        break;
    }
     
    cout << str << endl;   //8
    cout << str1 << endl;
    system("pause");
    return 0;
}