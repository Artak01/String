#include <iostream>
#include "string.h"

int main() {
    // Test your string class here

    const char* sample = "Hello";
    String str1(sample);  // Constructor with parameters
    std::cout << "str2: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    String str2 = str1;  // Copy constructor
    std::cout << "str3: " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    String str3 = std::move(str2);  // Move constructor
    std::cout << "str4: " << str3.c_str() << ", Size: " << str3.size() << std::endl;

    String str4;
    str4 = str3;  // Copy assignment operator
    std::cout << "str5: " << str4.c_str() << ", Size: " << str4.size() << std::endl;

    String str5;
    str5 = std::move(str4);  // Move assignment operator
    std::cout << "str6: " << str5.c_str() << ", Size: " << str5.size() << std::endl;

    str5.append(" World!");  // Append function
    std::cout << "str6 after append: " << str5.c_str() << ", Size: " << str5.size() << std::endl;

    std::cout << "Character at position 4: " << str5.at(4) << std::endl;

    std::cout << "Front character: " << str5.front() << std::endl;
    std::cout << "Back character: " << str5.back() << std::endl;

    std::cout << "Is str6 empty? " << (str5.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
