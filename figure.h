#pragma once

#include <string>
#include <iostream>
#include "lancer.h"

namespace Yahtzee {

	class figure
	{
	protected:
		std::string name;
		unsigned int currentPoints = 0; // la valeur des points a ganger a chaque lance
		unsigned int playerPoints = -1; // si le joueur a choisi la figure, la valeur est stocke ici 
		bool used = false; // si le joueur a choisi la figure, on ne peut plus la reutiliser

	public:
		figure(const std::string& name) : name(name) {};
		virtual ~figure() {};

		bool isUsed() { return used; };
		virtual unsigned int eval(lancer* roll) = 0;

		friend std::ostream& operator<<(std::ostream& out, const figure& figure) {
			return out << (figure.playerPoints == -1 ? "_" : std::to_string(figure.playerPoints)) ;
		};

		friend class partie;
		friend class joueur;
	};

}


