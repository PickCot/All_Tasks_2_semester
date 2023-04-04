#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string password;
    std::cout << "Enter some text: ";
    std::getline(std::cin, password);
    if (password.size() == 8)  // check 1
    {
        const std::string separators{ "QWERTYUIOPASDFGHJKLZXCVBNM" };
        const std::string separators2{ "qwertyuiopasdfghjklzxcvbnm" };
        const std::string separators3{ "1234567890" };
        const std::string separators4{ "~`!@#$%^&*()_+-=,./<>?[]{}|" };

        size_t end = password.find_first_of(separators);
        if (end == std::string::npos)   // check 2
        {
            std::cout << "Password must have at least one upper-case letter";
        }
        else
        {
            size_t end = password.find_first_of(separators2);
            if (end == std::string::npos)   // check 3
            {
                std::cout << "Password must have at least one lower-case letter";
            }
            else
            {
                size_t end = password.find_first_of(separators3);
                if (end == std::string::npos)   // check 4
                {
                    std::cout << "Password must have at least one digit";
                }
                else
                {
                    size_t end = password.find_first_of(separators4);
                    if (end == std::string::npos)   // check 5
                    {
                        std::cout << "Password must have at least one specialcharacter";
                    }
                    else
                    {
                        std::cout << "The password is valid";
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Password must be eight characters long";
    }


}