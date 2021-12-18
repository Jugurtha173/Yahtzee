#pragma once

#include <iostream>

namespace Yahtzee {

	class de
	{
		unsigned int value;
		bool isHeld;

	public:
		de(unsigned int value) : value(value), isHeld(false) {};
		~de() = default;


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

	typedef std::shared_ptr<de> dePtr;

}



