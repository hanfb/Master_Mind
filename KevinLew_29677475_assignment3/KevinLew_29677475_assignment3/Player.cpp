#include "Player.h"

Player::Player()
{
	playerName = "BOB";
	difficulty = 1;
	score = 0;
	numberOfWins = 0;
}

Player::Player(std::string inputName, std::string inputDifficulty) {
	playerName = inputName;
	if (inputDifficulty == "Job's Done") {
		difficulty = 0;
	}
	else if(inputDifficulty == "Jobs") {
		difficulty = 1;
	}
	else if (inputDifficulty == "Alcoholism") {
		difficulty = 2;
	}
	else {
		std::cout << "\nPlease enter valid input, the difficulty is set to normal for now" << std::endl;
		difficulty = 1;
	}
	score = 0;
	numberOfWins = 0;
}

Player::~Player()
{
}

// getters
std::string Player::getPlayerName() { return playerName; }
int Player::getDifficulty() { return difficulty; }
int Player::getScore() { return score; }
int Player::getNumberOfWins() { return numberOfWins; }

// mutators
void Player::setNewName(std::string newName) {
	if (newName.length > 0) {
		playerName = newName;
	}
}
void Player::setNewScore(int newScore) {
	score += newScore;
}
void Player::incrementNumberOfWins() {
	numberOfWins += 1;
}
