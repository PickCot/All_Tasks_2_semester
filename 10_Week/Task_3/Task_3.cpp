#include <iostream>
#include <string>
using namespace std;
class AdHocSquare
{
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
};
AdHocSquare::AdHocSquare(double side)
{
    set_side(side);
}
double AdHocSquare::get_area()
{
    double  area;
    if (this->side < 0)
    {
        area = 0;
    }
    else
    {
        area = this->side * this->side;
    }
    return area;
}
void AdHocSquare::set_side(double side)
{
    this->side = side;
}
class LazySquare
{
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
    double area;
    bool side_changed;
};
LazySquare::LazySquare(double side)
{
    set_side(side);
}
double LazySquare::get_area()
{
    if (this->side_changed)
    {
        if (this->side < 0)
        {
            this->area = 0;
        }
        else
        {
            this->area = this->side * this->side;
        }
        return this->area;
    }
    else
    {
        return this->area;
    }

}
void LazySquare::set_side(double side)
{
    if (this->side == side)
    {
        this->side_changed = false;
    }
    else
    {
        this->side = side;
        this->side_changed = true;
    }
}
int main()
{
    AdHocSquare s(4);
    cout << s.get_area() << endl;
    s.set_side(2.0);
    cout << s.get_area() << endl;
    s.set_side(-33.0);
    cout << s.get_area() << endl;

    LazySquare ls(4);
    cout << ls.get_area() << endl;

    cout << ls.get_area() << endl;

    ls.set_side(2.0);
    cout << ls.get_area() << endl;
    ls.set_side(-33.0);
    cout << ls.get_area() << endl;

    return 0;
}