#include "print_ip.h"

#include "gtest/gtest.h"

#include <sstream>


TEST(PrintIPTest, IntegralChar) {
    std::ostringstream os;

    print_ip(char(-1), os);

    ASSERT_EQ(os.str(), "255\n");
}


TEST(PrintIPTest, IntegralShort) {
    std::ostringstream os;

    print_ip(short(0), os);

    ASSERT_EQ(os.str(), "0.0\n");
}


TEST(PrintIPTest, IntegralInt) {
    std::ostringstream os;

    print_ip(int(2130706433), os);

    ASSERT_EQ(os.str(), "127.0.0.1\n");
}


TEST(PrintIPTest, IntegralLong) {
    std::ostringstream os;

    print_ip(long(8875824491850138409), os);

    ASSERT_EQ(os.str(), "123.45.67.89.101.112.131.41\n");
}


TEST(PrintIPTest, String) {
    std::ostringstream os;

    print_ip(std::string("trololo"), os);

    ASSERT_EQ(os.str(), "trololo\n");
}


TEST(PrintIPTest, ContainerList) {
    std::ostringstream os;

    print_ip(std::list<int>({0, 1, 2, 3}), os);

    ASSERT_EQ(os.str(), "0.1.2.3\n");
}


TEST(PrintIPTest, ContainerVector) {
    std::ostringstream os;

    print_ip(std::vector<int>({0, 1, 2, 3}), os);

    ASSERT_EQ(os.str(), "0.1.2.3\n");
}



