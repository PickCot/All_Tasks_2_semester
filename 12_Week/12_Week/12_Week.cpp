#include <iostream>
#include <string>
using namespace std;
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void set(int id, int capacity, int reserved);
	void get();
	double percentage(int capacity, int reserved);
	void add(int ticket);
	void cancel(int ticket);
	static void quit();
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	if (this->capacity < this->reserved || this->capacity < 0)
	{
		quit();
	}
	else
	{

		cout << "Flight " << this->id << " : " << this->reserved
			<< "/" << this->capacity << " (" << percentage(this->capacity, this->reserved) << "%) seats taken";

	}
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	if (double(reserved) / capacity * 100 > 105)
	{
		quit();
	}
	else
	{
		if (reserved < 0)
		{
			reserved = 0;
		}

		set(id, capacity, reserved);
	}
}
void FlightBooking::set(int inputId, int InputCapacity, int inputReserved)
{
	this->id = inputId;
	this->capacity = InputCapacity;
	this->reserved = inputReserved;
}
void FlightBooking::get()
{
	cout << "Id : " << this->id << "Capacity : " << this->capacity << "Reserved : " << this->reserved;
}
double FlightBooking::percentage(int capacity, int reserved) {
	return reserved * 100 / capacity;
}
void FlightBooking::add(int tickets)
{
	this->reserved += tickets;
}
void FlightBooking::cancel(int tickets)
{
	if (reserved > tickets)
	{
		this->reserved -= tickets;
	}
	else
	{
		quit();
	}
}
void FlightBooking::quit()
{
	cout << "Cannot perform this operation\n";
}


int main()
{
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	std::string command = "";
	int num = 0;

	while (command != "quit")
	{
		booking.printStatus();
		std::cout << "What would you like to do?: ";
		getline(cin, command);

		if (command == "add")
		{
			cin >> num;
			booking.add(num);
		}
		else if (command == "cancel")
		{
			cin >> num;
			booking.cancel(num);
		}
	}
	return 0;
}