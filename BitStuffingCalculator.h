#pragma once

namespace bsc {
	class BitStuffingCalculator {
		char* _bits;
		int _bitSize;
		char* _flag;
		int _flagSize;

	private:
		bool isEmpty(char* c);

	public:
		BitStuffingCalculator(); // Constructor
		void setEmpty();
		void set(const char* bits, const char* flag);
		void getBitsBeforeStuffing(char* c);
		void getBitsAfterStuffing(char* c);
		void getBitsAfterFraming(char* c);
	};
}