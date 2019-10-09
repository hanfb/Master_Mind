#include "Board.h"

Board::Board(int rowSize, int columnSize)
{
	std::vector<std::vector<int>> initializeTable(rowSize, std::vector<int>(columnSize));
	std::vector<std::vector<int>> initializeHints(rowSize, std::vector<int>(2));
	BoardSizeRow = rowSize;
	BoardSizeColumn = columnSize;
	table = initializeTable;
	Hints = initializeHints;
}

Board::~Board()
{
}

int Board::getBoardSizeRow() { return BoardSizeRow; }

int Board::getBoardSizeColumn() { return BoardSizeColumn; }

std::vector<std::vector<int>> Board::getHints() { return Hints; }

std::vector<std::vector<int>> Board::getTable() { return table; }

void Board::setNewTable(std::vector<int> newTable, int rowNumber) {
	table[rowNumber] = newTable;
}

void Board::setNewHints(std::vector<int> newHints, int rowNumber) {
	Hints[rowNumber] = newHints;
}

void Board::setNewBoardSizeRow(int newRow) { BoardSizeRow = newRow; }

void Board::setNewBoardSizeColumn(int newColumn) { BoardSizeColumn = newColumn; }