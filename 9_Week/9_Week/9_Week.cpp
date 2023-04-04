#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string text;
    std::cout << "Enter some text: ";
    std::getline(std::cin, text);
    const std::string separators{ "=," };
    std::vector<std::string> words;
    size_t start{ text.find_first_not_of(separators) };
    while (start != std::string::npos)
    {
        size_t end = text.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = text.length();        
        words.push_back(text.substr(start, end - start)); 
        start = text.find_first_not_of(separators, end + 1);
    }
  
    std::cout << "\nText contains " << words.size() << " words:" << std::endl;

    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }
    std::cout << "Dear " + words[1] + ", we were happy to take care of your " + words[3] + " while you were away. Please call our pet hotel again if you need help with your " + words[3] + "!";
}