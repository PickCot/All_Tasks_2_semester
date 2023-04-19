#include <iostream>
#include <string>
using namespace std;
class ShopItemOrder
{
public:
    double totalPrice();
    ShopItemOrder(string name, int items, double price);
    void print();
    void set(string name, int items, double price);
    void get();
private:
    string name;
    double price;
    int itemsOrdered;
};
double ShopItemOrder::totalPrice()
{
    return this->itemsOrdered * this->price;
}
ShopItemOrder::ShopItemOrder(string name, int items, double price)
{
    set(name, items, price);
}
void ShopItemOrder::print()
{
    cout << "Consumer ordered " << this->itemsOrdered << " items of "
        << this->name << " for " << this->price << " dollars each." << endl
        << "The total sum is " << this->totalPrice() << endl;
}
void ShopItemOrder::set(string name, int items, double price)
{
    this->name = name;
    this->itemsOrdered = items;
    this->price = price;
}
void ShopItemOrder::get()
{
    cout << "Name: " << this->name << ", Price: "<< this->price << ", Items Ordered: " <<  this->itemsOrdered;
}
int main()
{
    ShopItemOrder sio = ShopItemOrder("Milk", 2, 4);
    sio.print();
    sio.set("Cola", 3, 1);
    sio.get();

    return 0;
}