#include "main.h"

int main() {
	srand(time(NULL));
	gameControl();

	system("pause");
	return 0;
}

void gameControl() {
	bool notEnd = true;
	int score = 0;
	std::vector<int> scoreVec;
	int row, column;
	std::string playAgain;
	printInfo();
	Player player = addPlayer();
	if (player.getPlayerName() == "QUITHASBEENENTERED") {
		return;
	}
	while (notEnd) {
		// calculate player's score on SPECFIC ROUND
		scoreVec.push_back(player.getScore());
		if (scoreVec.size() > 2) {
			scoreVec.pop_back();
			score = player.getScore() - scoreVec.back();
			scoreVec.push_back(player.getScore());
		}
		else {
			score = player.getScore();
		}
		player = determinePromotion(player);
		if (player.getPlayerName() == "QUITHASBEENENTERED") {
			break;
		}
		printPlayerInfo(player, score);
		Board board = initializeBoard(player);
		std::vector<int> code = generateCode(board);
		player = playerTurn(player, board, code);
		if (player.getPlayerName() == "QUITHASBEENENTERED") {
			break;
		}
		std::cout << "\n Would you like to play again? (y/n) ";
		std::cin >> playAgain;
		if (playAgain == "n") {
			std::cout << "Thanks for playing this torturous game" << std::endl;
			notEnd = false;
		}
		else if (playAgain == "quit") {
			notEnd = false;
		}
	}
}

void printInfo() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "            MasterMind :: Job Protection Simulator" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::string line;
	std::ifstream file;
	file.open("GameInfo.txt");
	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
	}
	else {
		std::cout << "File is not open\n" << std::endl;
	}
	file.close();
	std::cout << "\n";
	system("pause");
}

Player addPlayer() {
	std::string playerName;
	std::string difficulty;
	std::cout << "\nNow that you know what's going on and not a complete idiot:\n" << std::endl;
	std::cout << "Tell me your name: ";
	std::cin >> playerName;
	if (playerName == "quit") {
		Player empty;
		return  empty;
	}
	std::cout << "\nTell me what kind of job do you want (difficulty).\n[0] Easy, [1] Normal, [2] Alcoholism: ";
	std::cin >> difficulty;
	if (difficulty == "quit" ) {
		Player empty;
		return  empty;
	}
	if (stoi(difficulty) != 0 & stoi(difficulty) != 1 & stoi(difficulty) != 2) {
		std::cout << "\nPlease enter valid difficulty, your difficulty is now set as 1 (normal), please restart to reselect difficulty." << std::endl;
		difficulty = 1;
	}
	std::cout << "\nGood to see you're somewhat competent, break a leg!" << std::endl;
	return Player(playerName, stoi(difficulty));
}

void printPlayerInfo(Player player, int score) {
	std::string difficulty;
	if (player.getDifficulty() == 0) {
		difficulty = "easy";
	}
	else if (player.getDifficulty() == 1) {
		difficulty = "normal";
	}
	else {
		difficulty = "alcoholism";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "		Name:                   " << player.getPlayerName() << std::endl;
	std::cout << "		Difficulty:             " << difficulty << std::endl;
	std::cout << "		Cracked Codes:          " << player.getNumberOfWins() << std::endl;
	std::cout << "		Score:                  " << score << std::endl;
	std::cout << "		Total Score:            " << player.getScore() << std::endl;
	std::cout << "		Games until Promotion:  " << player.getGamesUntilPromotion() << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\n";
	system("pause");
}

Board initializeBoard(Player player) {
	int row, column;
	if (player.getDifficulty() == 0) {
		row = 10;
		column = 4;
	}
	else if (player.getDifficulty() == 1) {
		row = 12;
		column = 5;
	}
	else {
		row = 14;
		column = 6;
	}
	return Board(row, column);
}

std::vector<int> generateCode(Board board) {
	std::vector<int> code;
	for (int i = 0; i < board.getBoardSizeColumn(); i++) {
		if (board.getBoardSizeColumn() == 4) {
			code.push_back(rand() % 5);
		}
		else if (board.getBoardSizeColumn() == 5) {
			code.push_back(rand() % 7);
		}
		else if (board.getBoardSizeColumn() == 6) {
			code.push_back(rand() % 9);
		}
	}
	return code;
}

Player playerTurn(Player player, Board board, std::vector<int> code) {
	bool win = false;
	std::vector<std::vector<int>> table = board.getTable();
	std::vector<std::vector<int>> hintsRecords = board.getHints();
	int rowsUsed = 0;

	//gives the answer, remove before submit
	for (int i = 0; i < code.size(); i++) {
		std::cout << code[i];
	}
	std::cout << "\n";

	while (rowsUsed != board.getBoardSizeRow() & !win) {
		
		bool incorrectInput = true;
		
		printTable(board, rowsUsed);
		std::vector<int> userCode = computePlayerInput(board);
		if (userCode.size() == 1) {
			Player empty;
			return empty;
		}
		std::vector<int> hints = compareUserCode(userCode, code);
		
		board.setNewTable(userCode, rowsUsed);
		board.setNewHints(hints, rowsUsed);
		
		rowsUsed++;
		if (hints[0] == board.getBoardSizeColumn()) {
			win = true;
			player.incrementNumberOfWins();
			std::cout << "\nYou may have won, BUT YOU GET NO COOKIE" << std::endl;
		}
	}
	if (rowsUsed == board.getBoardSizeRow()) {
		std::cout << "\nYou lost your job, have you tried looking for jobs in Bosnia?" << std::endl;
	}
	player.setNewScore(calculateScore(rowsUsed, player, board));
	player.changeGamesUntilDemotion(win);
	player.changeGamesUntilPromotion(win);
	return player;
}

void printTable(Board board, int rowsUsed) {
	std::vector<std::vector<int>>table = board.getTable(); 
	std::vector<std::vector<int>>hints = board.getHints();
	for (int i = 0; i < rowsUsed; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			std::cout << table[i][j] << "\t";
		}
		for (int k = 0; k < hints[i][0]; k++) {
			std::cout << "o";
		}
		for (int l = 0; l < hints[i][1]; l++) {
			std::cout << "?";
		}
		std::cout << "\n";
	}
}

std::vector<int> compareUserCode(std::vector<int> userCode, std::vector<int>code) {
	std::vector<int> hints = { 0, 0 };
	bool alreadyExist = false;
	for (int i = 0; i < userCode.size(); i++) {
		// bool alreadyExist = false;
		if (userCode[i] == code[i]) {
			hints[0]++;
		}
		for (int j = 0; j < code.size(); j++) {

			if (userCode[i] == code[j] & !alreadyExist) {
				hints[1]++;
				alreadyExist = true;
			}
		}
	}
	hints[1] -= hints[0];
	return hints;
}

std::vector<int> computePlayerInput(Board board) {
	bool incorrectInput = true;
	std::string userCode;
	std::vector<int> userCodeVec;

	if (board.getBoardSizeColumn() == 4) {
		std::cout << "The code Elements: 0 1 2 3 4 5" << std::endl;
	}
	else if (board.getBoardSizeColumn() == 5) {
		std::cout << "The code Elements: 0 1 2 3 4 5 6 7" << std::endl;
	}
	else if (board.getBoardSizeColumn() == 6) {
		std::cout << "The code Elements: 0 1 2 3 4 5 6 7 8 9" << std::endl;
	}
	std::cout << "The code could be: ";
	std::cin >> userCode;
	if (userCode == "quit") {
		return std::vector<int> {0};
	}
	while (incorrectInput) {
		if (userCode == "quit") {
			return std::vector<int> {0};
		}
		if (userCode.size() != board.getBoardSizeColumn()) {
			std::cout << "\nPlease enter a valid option (e.g. '1234'): ";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> userCode;
		}
		else {
			incorrectInput = false;
		}
	}

	for (int i = 0; i < userCode.size(); i++) {
		char letter = userCode[i];
		userCodeVec.push_back(std::stoi(&letter));
	}

	return userCodeVec;
}

int calculateScore(int rowsUsed, Player player, Board board) {
	if (rowsUsed == board.getBoardSizeRow()) {
		return 0;
	}
	else {
		int unusedTurnsBonus = 10 * (board.getBoardSizeRow() - rowsUsed);
		int turnsTakenNegative = 5 * rowsUsed;
		int difficultyBonus = 10 * player.getDifficulty();
		return difficultyBonus + unusedTurnsBonus - turnsTakenNegative;
	}
}

Player determinePromotion(Player player) {
	std::string promoteInput;
	if (player.getGamesUntilDemotion() == 0 & player.getDifficulty() != 0) {
		std::cout << "you've been demoted for losing 5 games in a row" << std::endl;
		player.setNewDifficulty(0);
	}
	if (player.getGamesUntilPromotion() == 0 & player.getDifficulty() != 2) {
		std::cout << "Do you want to be promoted to a higher difficulty?(y/n) ";
		std::cin >> promoteInput;
		if (promoteInput == "quit") {
			Player empty;
			return empty;
		}
		if (promoteInput == "y") {
			std::cout << "Congratulations, you have been promoted, enjoy it while you can.\n" << std::endl;
			player.setNewDifficulty(1);
		}
		else if(promoteInput == "n") {
			std::cout << "Are you a psychopath to not want a promotion? Alright, you may continue.\n" << std::endl;
		}
		else {
			std::cout << "\nPlease enter a valid option.\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		player.resetGamesUntilPromotion();
		system("pause");
	}
	return player;
}