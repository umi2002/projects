#include "board.h"

Board::Board() : QObject() {};

Board::~Board() {};

void Board::makeNewBoard()
{
    board_.clear(); // clear the existing board if any
    board_.resize(horizontalDimensions_, std::vector<int>(verticalDimensions_, 0));
    emit madeNewBoard();
}

void Board::makeMove(int x, int y)
{
    if (board_[x][y] == 0)
    {
        board_[x][y] = turn_ ? 1 : -1;
        const QString s = turn_ ? "X" : "O";
        turn_ = !turn_;
        emit madeMove(s, x, y);
    }
}
