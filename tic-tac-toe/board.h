#pragma once

#include "tic-tac-toe.h"
#include "interface.h"
#include "box.h"

class Board : public QObject
{
    Q_OBJECT
public:
    Board();
    ~Board();
    void makeNewBoard();
    std::vector<std::vector<int>> board_;

private:
    const int horizontalDimensions_ = 3;
    const int verticalDimensions_ = 3;

    bool turn_ = true;

signals:
    void madeNewBoard();
    void madeMove(const QString s, int x, int y);

public slots:
    void makeMove(int x, int y);

};
