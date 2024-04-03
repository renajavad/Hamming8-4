#include <gtest/gtest.h>
#include "code.cpp"
#include "decode.cpp"

TEST(CodeTest1, Value) {
    std::bitset<16> res = code(255);
    EXPECT_EQ(res.to_string(), "1110101011101010");
}

TEST(CodeTest2, Value) {
    std::bitset<16> res = code(85);
    EXPECT_EQ(res.to_string(), "0111001101110011");
}

TEST(DecodeTest, Decode) {
    short sh1 = 0b1101011011101101;
    int int1 = -1;
    EXPECT_EQ(decode(sh1), int1);

    short sh2 = 0b1100011011101101;
    int int2 = 158;
    EXPECT_EQ(decode(sh2), int2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
