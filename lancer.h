#pragma once


#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "de.h"
#include <iostream>


namespace Yahtzee {

	class lancer
	{
		unsigned int numberOfFaces = 6;
		unsigned int numberOfDices = 5;
		std::vector<dePtr> dices;


		void sortDices();

	public:
		lancer();
		~lancer() = default;

		std::vector<dePtr>& getDices() { return dices; };
		std::vector<unsigned int> getDicesOccurences() const ;

		void rollAllDices();
		void rollDices(const std::vector<unsigned int>& indexes);
		void rollDicesByIndex(const std::vector<unsigned int>& indexes);
		

		void showDices() const ;

		friend class figure;

	};

	typedef std::shared_ptr<lancer> lancerPtr;

}


