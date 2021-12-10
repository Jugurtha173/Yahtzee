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
		unsigned int numberOfFaces = 6;
		unsigned int numberOfDices = 5;
		std::vector<std::shared_ptr<de>> dices;


		void sortDices();

	public:
		lancer();
		~lancer();

		std::vector<std::shared_ptr<de>>& getDices() { return dices; };
		std::vector<unsigned int> getDicesOccurences() const ;

		void rollAllDices();
		void rollDices(const std::vector<unsigned int>& indexes);
		void rollDicesByIndex(const std::vector<unsigned int>& indexes);
		

		void showDices() const ;

		friend class figure;

	};

}


