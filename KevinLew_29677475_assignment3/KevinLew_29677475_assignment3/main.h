#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include <fstream>
#include <ctime>

void printInfo();
Board initializeBoard(Player player);
void printPlayerInfo(Player player, int score);
Player addPlayer();
std::vector<int> generateCode(Board board);
void printTable(Board board, int rowsUsed);
Player playerTurn(Player player, Board board, std::vector<int> code);
std::vector<int> computePlayerInput(Board board);
std::vector<int> compareUserCode(std::vector<int> userCode, std::vector<int>code);
int calculateScore(int rowsUsed, Player player, Board board);
Player determinePromotion(Player player);
void gameControl();