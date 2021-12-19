// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include <vector>
#include "joueur.h"
#include "IA.h"
#include "lancer.h"
#include "figure.h"
#include "figuresJeu.h"

namespace Yahtzee {

	class partie
	{
		std::vector<joueurPtr> players;
		unsigned int numberPlayers;
		lancerPtr roll;

	public:

		partie(int numberPlayers = 2);
		~partie() = default;

		void initPlayers();
		void launch();

		std::vector<joueurPtr> getPlayers() const;
		lancerPtr getLancer() const;
		void addPlayer(const joueurPtr player);

		void showTable() const;
		void showScores();

		void separate(int allSize) const;
	};
}
