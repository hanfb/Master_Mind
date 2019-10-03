#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player
{
private:
	std::string playerName;
	int difficulty;
	int score;
	int numberOfWins;

public:
	// constructors
	Player();
	Player(std::string inputName, std::string inputDifficulty);
	// destructor
	~Player();
	// getters
	std::string getPlayerName();
	int getDifficulty();
	int getScore();
	int getNumberOfWins();
	// mutators
	void setNewName(std::string newName);
	void setNewScore(int newScore);
	void incrementNumberOfWins();
};

#endif

