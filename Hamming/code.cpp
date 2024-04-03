#include <iostream>
#include <bitset>

std::bitset<8> hamming84(std::bitset<4> d) {
    bool d1 = d[0], d2 = d[1], d3 = d[2], d4 = d[3];
    bool p1, p2, p3, p4;

    p1 =  (d1 + d3 + d4 + 1) % 2;
    p2 =  (d1 + d2 + d4 + 1) % 2;
    p3 =  (d1 + d2 + d3 + 1) % 2;
    p4 =  (1 + p1 + d1 + p2 + d2 + p3 + d3 + d4) % 2;

    std::bitset<8> coded_res;
    coded_res[0] = p1;
    coded_res[1] = d1;
    coded_res[2] = p2;
    coded_res[3] = d2;
    coded_res[4] = p3;
    coded_res[5] = d3;
    coded_res[6] = p4;
    coded_res[7] = d4;

    return coded_res;
}

std::bitset<16> code(int i) {
    std::bitset<8> bits(i);

    std::bitset<4> first(bits.to_string().substr(0, 4));
    std::bitset<4> second(bits.to_string().substr(4, 4));

    std::bitset<8> res1 = hamming84(first);
    std::bitset<8> res2 = hamming84(second);

    std::bitset<16> res = (res1.to_ulong() << 8) | res2.to_ulong();

    return res;
}
