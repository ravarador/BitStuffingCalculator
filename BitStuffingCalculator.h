#pragma once

namespace bsc {
	class BitStuffingCalculator {
		char* _bits;
		char* _flag;

	private:
		
		void setEmpty();
		bool isEmpty(char* c);

	public:
		BitStuffingCalculator(); // Constructor

		void set(const char* bits, const char* flag);
		void getBitsBeforeStuffing(char* c);
		void getBitsAfterStuffing(char* c);
		//void getBitsAfterFraming();
	};
}