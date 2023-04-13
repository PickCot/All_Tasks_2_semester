#include <iostream>
#include <string>
using namespace std;
class ShopItemOrder
{
public:
    string name;
    double price;
    int itemsOrdered;
    double totalPrice();
    ShopItemOrder(string name, int items, double price);
};
double ShopItemOrder::totalPrice()
{
    return this->itemsOrdered * this->price;
}
ShopItemOrder::ShopItemOrder(string name, int items, double price)
{
    this->name = name;
    this->itemsOrdered = items;
    this->price = price;
}
void print(ShopItemOrder* sio)
{
    cout << "Consumer ordered " << sio->itemsOrdered << " items of "
        << sio->name << " for " << sio->price << " dollars each." << endl
        << "The total sum is " << sio->totalPrice();
}
int main()
{
    ShopItemOrder sio = ShopItemOrder("Milk", 2, 4);
    print(&sio);

    return 0;
}