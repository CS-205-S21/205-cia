#include <iostream>
#include <vector>
#include "tag.h"
#include "pet.h"
using namespace std;

//Not sure where to put this, doesn't fit in main
void addPet()
{
    string petName;
    cout << "Enter pet's name: ";
    cin << petName << endln;
    string species;
    cout << "Enter pet's species: ";
    cin << species << endln;
    bool done = false;
    vector<Tag> tags;
    while (!done)
    {
        string misc;
        cout <<"Enter miscellaneous tags, or type 'end' to stop: ";
        cin  << misc << endl;
        if (misc.compare("end") == 0)
        {
            done = true;
        }
        else
        {
            tags.push_back(misc);
        }
    }
    Pet p = new Pet(name, tags);
    cout << "All done!" << endl;
}
int main()
{
    cout << "Hello World!" << endl;
    vector<Tag> tags = new vector<Tag>;
    Tag tag1 = new Tag("dog");
    tags->push_back(tag1);
    Tag* tag2 = new Tag("good with kids")
    tags->push_back(tag2);
    Tag* tag3 = new Tag("likes hikes");
    tags->push_back(tag3);
    Pet* Fido = new Pet("Fido",tags);
    cout << "We have a pet named " << Fido->getName() << endl;
    cout << "Here are his tags: " << Fido->getTags() << endl;
    return 0;
}
