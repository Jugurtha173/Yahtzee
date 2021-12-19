// Jugurtha ASMA && Hylia BOUDAHBA

#include "pch.h"

#include "../Yahtzee/partie.cpp"
#include "../Yahtzee/lancer.cpp"
#include "../Yahtzee/de.cpp"
#include "../Yahtzee/joueur.cpp"
#include "../Yahtzee/IA.cpp"
#include "../Yahtzee/figure.cpp"
#include "../Yahtzee/figureInferieur.cpp"
#include "../Yahtzee/figureSuperieur.cpp"

using namespace Yahtzee;

partie game;
lancerPtr roll = game.getLancer();

TEST(TestGame, TestNumberOfPlayers) {
	int defaultNumPlayers = 2;
	ASSERT_EQ(defaultNumPlayers, game.getPlayers().size());
}

TEST(TestPlayer, TestAddPlayer) {
	// creation d'un joueur
	std::string playerName = "TestPlayer";
	joueurPtr player = std::make_shared<joueur>(playerName, game.getLancer());
	ASSERT_EQ(playerName, player->getName());

	// comparaison du nombre de joueurs
	size_t numPlayersBefore = game.getPlayers().size();
	game.addPlayer(player);
	size_t numPlayersAfter = game.getPlayers().size();
	ASSERT_GT(numPlayersAfter, numPlayersBefore);
}

// un de qu'on a pas choisis de relancer, doit garder la meme valeur
TEST(TestDice, TestRollDices) {
	// la valeur du premier de avant le lance
	unsigned int diceValueBefore = roll->getDices().at(0)->getValue();
	
	// ne pas relancer le premier de 
	roll->rollDicesByIndex({2, 4, 5});

	// la valeur du premier de apres le lance
	unsigned int diceValueAfter = roll->getDices().at(0)->getValue();
	
	ASSERT_EQ(diceValueAfter, diceValueBefore);
}

// un joueur ne peut choisir qu'un figure disponible
TEST(TestFigure, TestChooseFigure) {
	// IA
	joueurPtr IA = game.getPlayers().at(1);
	std::vector<figurePtr> figures = IA->getFigures();
	figurePtr figureToChoose = figures.at(0);
	unsigned int totalPointsBefore = IA->getTotalPoints();

	// touttes les figures ont deja ete choisis (sauf la premiere)
	for (int i = 1; i < figures.size(); ++i) {
		figures.at(i)->setChoose();
	}

	// IA ne choisira que la figure disponible
	figurePtr choosedFigure = IA->chooseFigure();
	ASSERT_EQ(choosedFigure, figureToChoose);

	// plus ou autant de points qu'avant
	unsigned int totalPointsAfter= IA->getTotalPoints();
	ASSERT_GE(totalPointsAfter, totalPointsBefore);
}

TEST(TestPlayer, TestPlayerPoints) {
	// IA
	joueurPtr IA = game.getPlayers().at(1);
	unsigned int totalPointsBefore = IA->getTotalPoints();

	figurePtr choosedFigure = IA->chooseFigure();

	// plus ou autant de points qu'avant
	unsigned int totalPointsAfter= IA->getTotalPoints();

	ASSERT_GE(totalPointsAfter, totalPointsBefore);
}

