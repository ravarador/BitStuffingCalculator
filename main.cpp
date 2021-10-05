// BitStuffingCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>

#include "BitStuffingCalculator.h" 

using namespace std;
using namespace bsc;

int main()
{
    const char* bits = "011111101111110";
    const char* flag = "01111110";

    int bitsSize = strlen(bits) + 1;
    int flagSize = strlen(flag) + 1;

    BitStuffingCalculator bCalc;
    bCalc.set(bits, flag);

    char* bitsBeforeStuffing = nullptr;
    char* bitsAfterStuffing = nullptr;
    char* bitsAfterFraming = nullptr;

    bitsBeforeStuffing = new char[bitsSize];
    bitsAfterStuffing = new char[bitsSize];
    bitsAfterFraming = new char[bitsSize + (flagSize * 2)];

    bCalc.getBitsBeforeStuffing(bitsBeforeStuffing);
    bCalc.getBitsAfterStuffing(bitsAfterStuffing);
    bCalc.getBitsAfterFraming(bitsAfterFraming);

    cout << "Before Stuffing: " << bitsBeforeStuffing << endl;
    cout << "After Stuffing: " << bitsAfterStuffing << endl;
    cout << "After Framing: " << bitsAfterFraming << endl;
}