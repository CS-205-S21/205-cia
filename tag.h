#ifndef TAG_H
#define TAG_H
#include <iostream>
#include <string>
using namespace std;
class Tag
{
public:
    Tag(string n);
    Tag(string n, string t);
    string getName();
    string getType();
private:
    string name;
    string type;

};

#endif // TAG_H
