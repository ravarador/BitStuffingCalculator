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

		void set(char* bits, char* flag);
		void getBitsBeforeStuffing();
		void getBitsAfterStuffing();
		void getBitsAfterFraming();
	};
}