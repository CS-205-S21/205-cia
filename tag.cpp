#include "tag.h"
#include <iostream>
using namespace std;
Tag::Tag(string n)
{
    name = n;
}
Tag::Tag(string n, string t)
{
    name = n;
    type = t;
}

string Tag::getName()
{
    return name;
}

string Tag::getType()
{
            return type;
        }
