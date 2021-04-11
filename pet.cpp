#include "pet.h"
#include <iostream>
using namespace std;
Pet::Pet(string n)
{
    name = n;
}
Pet::Pet(string n, vector<Tag> tagList)
{
    name = n;
    tags = tagList; //a pointer sin???
}
string Pet::getName()
{
    return name;
}
vector<Tag> Pet::getTags()
{
    return tags;
}

void Pet::showPetProfile()
{
    /**
    //Makeshift. Later method will loop through all categories of tags without
    //us entering it manually
    cout << name << endl;
    string species;
    vector<string> misc = new vector<string>;
    for (int i = 0; i < tags.size(); i++)
    {
        if (tags.at(i).type.compare("species") == 0)
        {
            species = tags.at(i).name;
        }
        if (tags.at(i).type.compare("misc") == 0)
        {
            misc.push_back(tags.at(i).name);
        }
    }
    cout << "species: " << species;
    cout << "misc: " << misc;
    */
}
