#ifndef PET_H
#define PET_H
#include <vector>
#include <iostream>
#include <tag.h>
using namespace std;

class Pet
{

public:
    Pet(string n);
    Pet(string n, vector<Tag> tagList);
    string getName();
    vector<Tag> getTags();
    void showPetProfile();
private:
    string name;
    vector<Tag> tags;
};

#endif // PET_H
