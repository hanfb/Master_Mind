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

public:
	Board();
	~Board();
	// getters
	int getBoardSizeRow();
	int getBoardSizeColumn();
	std::vector<std::vector<int>> getTable();

	// setters
	void setNewTable();
	void setNewBoardSizeRow();
	void setNewBoardSizeColumn();
};

#endif