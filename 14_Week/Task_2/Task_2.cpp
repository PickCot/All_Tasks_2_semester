
#include <iostream>
#include <string>
using namespace std;
class IPAddress
{
public:
    int ipAddress[4];
    IPAddress() {}
    IPAddress(int ipAddress[4])
    {
        for (int i = 0; i < 4; i++)
        {
            this->ipAddress[i] = ipAddress[i];
        }
    }
    void print()
    {
        cout << "Ip Adress: ";

            for(int i = 0; i < 4; i++)
            {
                cout << ipAddress[i] << ".";
            }
        cout << endl;
    }
};
class IPAddressChecked : public IPAddress
{
public:
    bool isCorrect;
    IPAddressChecked(){}
    IPAddressChecked(int ipAddress[4])
    {
        for (int i = 0; i < 4; i++)
        {
            this->ipAddress[i] = ipAddress[i];
            if (ipAddress[i] > 255 && ipAddress[i] < 0)
            {
                isCorrect = false;
            }
        }
    }
    void print()
    {
        IPAddress::print();
        cout << (isCorrect ? "Correct" : "Not Correct") << endl;

    }
};
int main() {

    int array1[4] = { 1, 2, 3, 4 };
    int array2[4] = { 999, 29, 29, 29 };
    int array3[4] = { 199, 29, 29, 29 };
    IPAddress ipad1(array1);
    IPAddressChecked ipad2(array2);
    IPAddressChecked ipad3(array3);

    ipad1.print();
    ipad2.print();
    ipad3.print();

    return 0;
}