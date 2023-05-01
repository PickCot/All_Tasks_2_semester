#include <iostream>
#include <string>

using namespace std;
class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_ob_seats);
    bool cancelReservations(int number_ob_seats);
    int getId() { return id; }
    int getCapacity() { return capacity; }
    int getReserved() { return reserved; }
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking()
{
    id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) :
    id(id), capacity(capacity), reserved(reserved) {}

void FlightBooking::printStatus()
{
    std::cout << "Flight " << id << " : " << reserved << "/"
        << capacity << " (" << (100 * reserved) / capacity << "%) seats reserved";
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
    if (reserved + number_ob_seats <= capacity && reserved + number_ob_seats >= 0)
    {
        reserved += number_ob_seats;
        return true;
    }
    else
    {
        return false;
    }
}

bool FlightBooking::cancelReservations(int number_ob_seats)
{
    if (reserved - number_ob_seats >= 0)
    {
        reserved -= number_ob_seats;
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    FlightBooking booking[10];
    std::string command = "";
    while (command != "quit")
    {
        std::cout << "What would you like to do?: ";
        getline(cin, command);

        // split the command into parts
        // std::stringstream ss(command);
        std::string cmd;
        int id, cap, num;

        cin >> cmd;
        cin >> id;

        if (cmd == "create")
        {
            cin >> cap;
            if (id > 0 && id <= 10 && booking[id - 1].getId() == 0)
            {
                booking[id - 1] = FlightBooking(id, cap, 0);
                booking[id - 1].printStatus();
                std::cout << " has been created." << std::endl;
            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (cmd == "delete")
        {
            if (id > 0 && id <= 10 && booking[id - 1].getId() != 0)
            {
                booking[id - 1].printStatus();
                std::cout << " has been deleted." << std::endl;
                booking[id - 1] = FlightBooking();

            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (cmd == "add")
        {
            cin >> num;
            if (id > 0 && id <= 10 && booking[id - 1].getId() != 0 && booking[id - 1].reserveSeats(num))
            {
                std::cout << num << " seats have been reserved for Flight " << id << "." << std::endl;
                booking[id - 1].printStatus();
                cout << endl;
            }
            else
            {
                std::cout << "Cannot perform this operation." << std::endl;
            }
        }
        else if (cmd == "cancel")
        {
            cin >> num;
            if (id > 0 && id <= 10 && booking[id - 1].getId() != 0 && booking[id - 1].reserveSeats(-num))
            {
                std::cout << num << " seats have been canceled for Flight " << id << "." << std::endl;
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