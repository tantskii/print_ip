#include <iostream>
#include <sstream>
#include "print_ip.h"

int main() {
    print_ip(char(-1), std::cout);
    print_ip(short(0), std::cout);
    print_ip(2130706433, std::cout);
    print_ip(long(8875824491850138409), std::cout);
    print_ip(std::string("trololo"), std::cout);
    print_ip(std::vector<int>({0, 1, 2, 3}), std::cout);
    print_ip(std::list<int>({0, 1, 2, 3}), std::cout);

    return 0;
}
