#include <iostream>
#include <string>

using namespace std;

class Member {
public:
    Member(int id, string name, int membership);
    Member();
    void printStatus();
    int getId() { return id; }
    int getMembership() { return membership; }
    string getName() { return name; }
    void extendMembership(int number_ob_seats);
    void cancelMembership();
private:
    int id;
    int membership;
    string name;
};

Member::Member()
{
    id = 0; membership = 0; name = "";
}

Member::Member(int id, string name, int membership)
{
    this->id = id;
    this->name = name;
    this->membership = membership;
}

void Member::printStatus()
{
    std::cout << "Member " << this->name << " with id " << this->id << " subscription valid for " << this->membership << " months";
}

void Member::extendMembership(int number_of_month)
{
    membership += number_of_month;
}

void Member::cancelMembership()
{
    membership = 0;
}
int main() {
    Member booking[10];
    std::string command = "";

    while (command != "quit")
    {
        std::cout << "What would you like to do?: ";
        cin >> command;

        int id, membership, num;
        string name;

        // cin >> cmd;
        cin >> id;

        if (command == "create")
        {
            cin >> name;
            if (id > 0 && id <= 10 && booking[id - 1].getId() == 0)
            {
                booking[id - 1] = Member(id, name, 0);
                booking[id - 1].printStatus();
                std::cout << " has been created." << std::endl;
            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (command == "delete")
        {
            if (id > 0 && id <= 10 && booking[id - 1].getId() != 0)
            {
                booking[id - 1].printStatus();
                std::cout << " has been deleted." << std::endl;
                booking[id - 1] = Member();

            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (command == "extend")
        {
            cin >> num;
            if (id > 0 && id <= 10 && booking[id - 1].getId() != 0)
            {
                booking[id - 1].extendMembership(num);
                std::cout << num << " months have been added for " << booking[id - 1].getName() << "." << std::endl;
                booking[id - 1].printStatus();
                cout << endl;
            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (command == "cancel")
        {
            if (id > 0 && id <= 10 && booking[id - 1].getId())
            {
                std::cout << "  Membership have been canceled for " << booking[id - 1].getId() << "." << std::endl;
                booking[id - 1].cancelMembership();
                booking[id - 1].printStatus();
                cout << endl;
            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else
        {
            std::cout << "Cannot perform this operation." << std::endl;
        }
    }

}