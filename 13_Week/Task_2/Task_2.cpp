/*
#include <iostream>
#include <string>
#include <vector> // For std::vector
using namespace std;

class Fraction {

public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}




// implement Fraction methods
int main(void) {
    int num, den;
    cin >> num >> den;
    Fraction fraction(num, den);

    // parse input and get numerator and denominator
    // 
    cout << fraction.toString() << " is " fraction.toDouble() in decimal << endl;
    return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() {
    int whole = numerator / denominator;
    int remainder = abs(numerator) % denominator;
    string sign = (numerator < 0 || denominator < 0) ? "-" : "";
    denominator = denominator < 0 ? denominator * -1 : denominator;

    if (whole == 0) {
        if (remainder == 0) {
            return "0";
        }
        return sign + to_string(abs(numerator)) + "/" + to_string(denominator);
    }
    else {
        if (remainder == 0) {
            return sign + to_string(whole);
        }
        return sign + to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return (double)numerator / denominator;
}

int main(void) {
    int num, den;
    std::string input = "";
    getline(cin, input);
    size_t pos = input.find('/');

    if (pos != std::string::npos) {
        num = stoi(input.substr(0, pos));
        den = stoi(input.substr(pos + 1));
        Fraction fraction(num, den);
        cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    }
    else {
        cout << "Invalid input." << endl;
    }
    return 0;
}