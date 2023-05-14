#include <iostream>
using namespace std;
class Parent
{
public:
    virtual void draw(){}
};
class StarTree : public Parent
{
    void draw()
    {
        cout << " /\u005C " << endl;
        cout << "/**\u005C" << endl;
    }
};
class RegularTree : public Parent
{
    void draw()
    {
        cout << " /\u005C " << endl;
        cout << "//\u005C\u005C" << endl;
    }
};
class PlusTree : public Parent
{
    void draw()
    {
        cout << " /\u005C " << endl;
        cout << "/++\u005C" << endl;
    }
};
int main() {
    Parent* table[3];

    StarTree startree1;
    table[0] = &startree1;

    RegularTree regulartree1;
    table[1] = &regulartree1;

    PlusTree plustree1;
    table[2] = &plustree1;

    for (int i = 0; i < 3; i++)
    {
        cout << "Drawing " << i + 1 << endl;
        table[i]->draw();
        cout << endl;
    }

    return 0;
}