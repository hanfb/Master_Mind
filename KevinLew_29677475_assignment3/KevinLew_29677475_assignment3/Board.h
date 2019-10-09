#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>

class Board
{
private:
	int BoardSizeRow;
	int BoardSizeColumn;
	std::vector<std::vector<int>> table;
	std::vector<std::vector<int>> Hints;

public:
	Board(int rowSize, int columnSize);
	~Board();
	// getters
	int getBoardSizeRow();
	int getBoardSizeColumn();
	std::vector<std::vector<int>> getTable();
	std::vector<std::vector<int>> getHints();

	// setters
	void setNewTable(std::vector<int> newTable, int rowNumber);
	void setNewBoardSizeRow(int newRow);
	void setNewBoardSizeColumn(int newColumn);
	void setNewHints(std::vector<int> newHints, int rowNumber);
};

#endif