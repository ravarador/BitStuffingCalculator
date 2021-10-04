// BitStuffingCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>

#include "BitStuffingCalculator.h" 

using namespace std;
using namespace bsc;

int main()
{
    BitStuffingCalculator bCalc;
    bCalc.set("011111101111110", "01111110");

    char* bitsBeforeStuffing = nullptr;
    bitsBeforeStuffing = new char[20];

    bCalc.getBitsBeforeStuffing(bitsBeforeStuffing);

    cout << "Before Stuffing: " << bitsBeforeStuffing << endl;
}