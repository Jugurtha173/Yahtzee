// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include <iostream>

namespace Yahtzee {

	class de
	{
		unsigned int value;
	public:
		de(unsigned int value) : value(value){};
		~de() = default;

		bool operator==(unsigned int v) {return value == v;}
		unsigned int getValue() {return value;}
		void roll(int max, int min = 1);

		friend std::ostream& operator<<(std::ostream& out, const de& dice);

		friend class lancer;
	};

	std::ostream& operator<<(std::ostream& out, const de& dice);

	typedef std::shared_ptr<de> dePtr;
}
