#include <iostream>
#include <bitset>

int decoder(int d)
{
    std::bitset<8> bits(d);
    bool d1 = bits[0];
    bool d2 = bits[1];
    bool d3 = bits[2];
    bool d4 = bits[3];
    bool d5 = bits[4];
    bool d6 = bits[5];
    bool d7 = bits[6];
    bool d8 = bits[7];

    bool A = (d1 + d2 + d6 + d8) % 2 == 1;
    bool B = (d2 + d3 + d4 + d8) % 2 == 1;
    bool C = (d2 + d4 + d5 + d6) % 2 == 1;
    bool D = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8) % 2 == 1;

    if (A && B && C && D) {
        std::cout << "Accepted\n";
    }
    else if (A && B && C && !D) {
        std::cout << "Error in p4, but accepted\n";
    }
    else if ((!A || !B || !C) && !D) {
        std::cout << "Single Error\n";
        if (!A && B && C) bits.flip(0);
        if (!A && !B && !C) bits.flip(1);
        if (A && !B && C) bits.flip(2);
        if (A && !B && !C) bits.flip(3);
        if (A && B && !C) bits.flip(4);
        if (!A && B && !C) bits.flip(5);
        if (!A && !B && !C) bits.flip(6);
        if (!A && !B && C) bits.flip(7);
    }
    else if (!A && !B && !C && D) {
        std::cout << "Double error, rejecting\n";
        return -1;
    }
    else {
        std::cout << "Unknown error condition\n";
        return -1;
    }

    int data = 0;
    data |= d2;
    data |= d4 << 1;
    data |= d6 << 2;
    data |= d8 << 3;

    return data;
}

int decode(short sh) {
    int first = sh >> 8;
    int second = sh & 0xFF;
    int res;

    int res1 = decoder(first);
    int res2 = decoder(second);

    if (res1 != -1 && res2 != -1) {
        res = res1 * 16 + res2;
    }
    return res;
}

