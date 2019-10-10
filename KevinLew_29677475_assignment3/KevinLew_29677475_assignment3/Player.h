#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <algorithm>

class Player
{
private:
	std::string playerName;
	int difficulty;
	int score;
	int numberOfWins;
	int gamesUntilPromotion;
	int gamesUntilDemotion;

public:
	// constructors
	Player();
	Player(std::string inputName, int inputDifficulty);
	// destructor
	~Player();
	// getters
	std::string getPlayerName();
	int getDifficulty();
	int getScore();
	int getNumberOfWins();
	int getGamesUntilPromotion();
	int getGamesUntilDemotion();
	// mutators
	void setNewName(std::string newName);
	void setNewScore(int newScore);
	void setNewDifficulty(int direction);
	void incrementNumberOfWins();
	void changeGamesUntilPromotion(bool win);
	void resetGamesUntilPromotion();
	void changeGamesUntilDemotion(bool win);
};
#endif

