#pragma once

#include <ostream>

namespace Yahtzee {

	class de
	{
		unsigned int value;
		bool isHeld;

	public:
		de(unsigned int value) : value(value), isHeld(false) {};
		~de() {};


		bool operator==(unsigned int v) {return value == v;}
		unsigned int getValue() {return value;}
		void roll(int max, int min = 1);

		friend std::ostream& operator<<(std::ostream& out, const de& dice) {
			return out 
				<< "[" << dice.value 
				<< "] " << (dice.isHeld ? "(Held)" : "");
		};
		friend class lancer;
	};

}



