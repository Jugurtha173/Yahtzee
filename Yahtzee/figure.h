// Jugurtha ASMA && Hylia BOUDAHBA

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
		virtual ~figure() = default;

		const std::string getName();
		bool isUsed();
		void setChoose();

		virtual unsigned int eval(const std::vector<unsigned int>& dicesOccurences) = 0;

		friend std::ostream& operator<<(std::ostream& out, const figure& figure);
		bool operator<=(const figure& figure);

		friend class partie;
		friend class joueur;
	};

	std::ostream& operator<<(std::ostream& out, const figure& figure);

	typedef std::shared_ptr<figure> figurePtr;
}
