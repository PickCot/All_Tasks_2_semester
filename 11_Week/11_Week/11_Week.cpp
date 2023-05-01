#include <iostream>
using namespace std;
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void set(int id, int capacity, int reserved);
	void get();
	double percentage(int capacity, int reserved);
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	if (capacity < reserved)
	{
		cout << "Error";
	}
	else
	{
		double percentage = double(this->reserved) / this->capacity * 100;

		cout << "Flight " << this->id << " : " << this->reserved
		<< "/" << this->capacity << " (" << percentage << "%) seats taken";

	}
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	if (double(reserved) / capacity * 100 > 105)
	{
		cout << "";
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
	cout << "Id : "<< this->id << "Capacity : " << this->capacity << "Reserved : " << this->reserved;
}
double FlightBooking::percentage(int capacity, int reserved) {
	return reserved * 100 / capacity;
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
	booking.printStatus();
	return 0;
}