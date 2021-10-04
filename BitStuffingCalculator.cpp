#include <string.h>
#include <iostream>

#include "BitStuffingCalculator.h"

using namespace std;

namespace bsc {
	BitStuffingCalculator::BitStuffingCalculator() {

	};

	void BitStuffingCalculator::set(char* bits, char* flag) {
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

		_bits = bits;
		_flag = flag;
	};

	void BitStuffingCalculator::setEmpty() {
		_bits = nullptr;
		_flag = nullptr;
	};

	void getBitsBeforeStuffing();
	void getBitsAfterStuffing();
	void getBitsAfterFraming();
}