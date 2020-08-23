#include "print_ip.h"

#include "gtest/gtest.h"

#include <iostream>
#include <sstream>


TEST(PrintIPTest, IntegralChar) {
    std::ostringstream os;
    
    print_ip(char(-1), os);
    
    ASSERT_EQ(os.str(), "255");
}




