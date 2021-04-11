#include <iostream>
#include <vector>
#include "tag.h"
#include "pet.h"
#include <iostream>
#include "helper.h"
#include <QDir>
using namespace std;
//Not sure where to put this, doesn't fit in main

int main()
{
    bool done = false;
    Helper h("/home/browni/205-CIA/adoption.db");
    while (!done)
    {
        cout <<"Pets:" << endl;
        h.showPets();
        string in;
        cout << "Type 'add' to add a pet, the name of a pet to search, or 'end' to end ";
        cin >> in;
        if (in.compare("end") == 0)
        {
            done = true;
        }
        else if (in.compare("add") == 0)
        {
            h.addPet();
            continue;
        }
        else
        {
            h.search(in);
        }
    }
    return 0;
}
