#include "Player.h"

Player::Player()
{
	playerName = "QUITHASBEENENTERED";
	difficulty = 1;
	score = 0;
	numberOfWins = 0;
	gamesUntilPromotion = 5;
	gamesUntilDemotion = 5;
}

Player::Player(std::string inputName, int inputDifficulty) {
	playerName = inputName;
	difficulty = inputDifficulty;
	score = 0;
	numberOfWins = 0;
	gamesUntilPromotion = 5;
	gamesUntilDemotion = 5;
}

Player::~Player()
{
}

// getters
std::string Player::getPlayerName() { return playerName; }
int Player::getDifficulty() { return difficulty; }
int Player::getScore() { return score; }
int Player::getNumberOfWins() { return numberOfWins; }
int Player::getGamesUntilPromotion() { return gamesUntilPromotion; }
int Player::getGamesUntilDemotion() { return gamesUntilDemotion; }

// mutators
void Player::setNewName(std::string newName) {
	if (newName.size() > 0) {
		playerName = newName;
	}
}
void Player::setNewScore(int newScore) {
	score += newScore;
}
void Player::setNewDifficulty(int direction) {
	if (direction == 1) {
		difficulty++;
	}
	else {
		difficulty--;
	}
}
void Player::incrementNumberOfWins() {
	numberOfWins += 1;
}
void Player::changeGamesUntilPromotion(bool win) {
	if (win) {
		gamesUntilPromotion--;
	}
	else {
		gamesUntilPromotion = 5;
	}
}
void Player::resetGamesUntilPromotion() {
	gamesUntilPromotion = 5;
}
void Player::changeGamesUntilDemotion(bool win) {
	if (!win) {
		gamesUntilDemotion--;
	}
	else {
		gamesUntilDemotion = 5;
	}
}