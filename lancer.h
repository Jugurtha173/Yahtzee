#pragma once


#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "de.h"

namespace Yahtzee {

	class lancer
	{

		std::vector<de*> dices;

	public:
		lancer();
		~lancer();

		void rollDices();
		void holdDicesByIndex(const std::vector<unsigned int>& indexes, bool hold = true); // hold ba default
		void unholdDicesByIndex(const std::vector<unsigned int>& indexes);
		void unholdAll();

		void showDices() const ;

		friend class figure;

	};

}


