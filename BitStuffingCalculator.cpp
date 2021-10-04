#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

#include "BitStuffingCalculator.h"

using namespace std;

namespace bsc {
	BitStuffingCalculator::BitStuffingCalculator() {
	};

	void BitStuffingCalculator::set(const char* bits, const char* flag) {
		_bits = new char[strlen(bits) + 1];
		_flag = new char[strlen(flag) + 1];

		if (_bits == nullptr) {
			cout << "Failed to initialize bits. " << endl;
			return;
		}

		if (_flag == nullptr) {
			cout << "Failed to initialize flag. " << endl;
			return;
		}

		strcpy(_bits, bits);
		strcpy(_flag, flag);
	};

	void BitStuffingCalculator::setEmpty() {
		_bits = nullptr;
		_flag = nullptr;
	};

	void BitStuffingCalculator::getBitsBeforeStuffing(char* c) {
		if (isEmpty(_bits)) {
			cout << "No bits found. " << endl;
		}
		else {
			strcpy(c, _bits);
		}
	};

	void BitStuffingCalculator::getBitsAfterStuffing(char* c) {
		char* stuffedBits = nullptr;
		stuffedBits = new char[strlen(_bits) + 1];

		if (isEmpty(_bits)) {
			cout << "No bits found. " << endl;
		}
		else {
			int c = 0;
			for (int i = 0; i < strlen(_bits); i++) {
				if (c == 5) {
					stuffedBits[i] = 0;
					--i;
					c = 0;
				}
				else {
					stuffedBits[i] = _bits[i];

					if (_bits[i] == 1) {
						c++;
					}
					else {
						c = 0;
					}
				}
			}
		}
	}
	/*void getBitsAfterFraming() {

	}*/

	bool BitStuffingCalculator::isEmpty(char* c) {
		if (c == nullptr)
			return true;
		return false;
	}
}