#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

#include "BitStuffingCalculator.h"

using namespace std;

namespace bsc {
	BitStuffingCalculator::BitStuffingCalculator() {
		_bitSize = 0;
		_flagSize = 0;
	};

	void BitStuffingCalculator::set(const char* bits, const char* flag) {
		_bitSize = strlen(bits);
		_bits = new char[_bitSize];

		_flagSize = strlen(flag);
		_flag = new char[_flagSize];

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
		stuffedBits = new char[_bitSize];

		if (isEmpty(_bits)) {
			cout << "No bits found. " << endl;
		}
		else {
			int c = 0, j = 0, extraBits = 0;
			for (int i = 0; i < strlen(_bits); i++) {
				if (c == 5) {
					stuffedBits[j] = '0';
					--i;
					c = 0;
					extraBits++;
				}
				else {
					stuffedBits[j] = _bits[i];

					if (_bits[i] == '1') {
						c++;
					}
					else {
						c = 0;
					}
				}

				j++;
			}

			stuffedBits[_bitSize + extraBits] = '\0';
		}
		
		strcpy(c, stuffedBits);
	}
	void BitStuffingCalculator::getBitsAfterFraming(char* c) {
		char* bitsAfterStuffing = nullptr;
		bitsAfterStuffing = new char[_bitSize];

		getBitsAfterStuffing(bitsAfterStuffing);

		char* bitsAfterFraming = nullptr;
		bitsAfterFraming = new char[_bitSize + (_flagSize * 2)];

		int j = 0; // Index to be used for bitsAfterFraming

		// Add first flag
		for (int i = 0; i < _flagSize; i++) {
			bitsAfterFraming[i] = _flag[i];
			j++;
		}

		// Add bitsAfterStuffing to bitsAfterFraming
		for (int i = 0; i < strlen(bitsAfterStuffing); i++) {
			bitsAfterFraming[j] = bitsAfterStuffing[i];
			j++;
		}

		// Add last flag
		for (int i = 0; i < _flagSize; i++) {
			bitsAfterFraming[j] = _flag[i];
			j++;
		}

		bitsAfterFraming[j] = '\0';
		strcpy(c, bitsAfterFraming);
	}

	bool BitStuffingCalculator::isEmpty(char* c) {
		if (c == nullptr)
			return true;
		return false;
	}
}