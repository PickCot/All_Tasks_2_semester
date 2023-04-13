#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;
    string profession;
};
void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old and their profession is " << person->profession << endl;
}

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.profession = "carpenter";
    cout << "Meet " << person.name << endl;
    print(&person);

    return 0;
}