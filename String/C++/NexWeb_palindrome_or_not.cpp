#include <iostream>

int main()
{
    std::string s;

    std::cout << "Please enter a string: ";
    std::cin >> s;

    if (s == std::string(s.rbegin(), s.rend())) {
        std::cout << s << " is a palindrome.\n";
    }
    else {
        std::cout << s << " is a not a palindrome.\n";
    }

    return 0;
}
