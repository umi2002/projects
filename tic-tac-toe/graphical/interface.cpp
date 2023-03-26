#include "interface.h"

Interface::Interface(QWidget* parent)
    : QMainWindow(parent)
{
    QObject::connect(&board_, SIGNAL(madeNewBoard()), this, SLOT(displayNewBoard()));
    QObject::connect(&board_, SIGNAL(madeMove(const QString, int, int)), this, SLOT(displayMove(const QString, int, int)));
    this->board_.makeNewBoard();
}

Interface::~Interface() {}

void Interface::displayNewBoard()
{
    boardWidget_ = new QWidget(this);
    boardLayout_ = new QHBoxLayout();
    boardWidget_->setLayout(boardLayout_);
    this->setCentralWidget(boardWidget_);

    for (int i : iter::range(board_.board_.size()))
    {
        QVBoxLayout* columnLayout_ = new QVBoxLayout();
        boardLayout_->addLayout(columnLayout_);

        for (int j : iter::range(board_.board_[i].size()))
        {
            Box* box = new Box(i, j);
            box->setText(" ");
            box->setAlignment(Qt::AlignCenter);
            box->setFont(font_);
            box->setStyleSheet(
                "QLabel {\
                color : black;\
                background-color : white;\
                border: 1px solid black;\
                }"
                );
            QObject::connect(box, SIGNAL(isClicked(int, int)), &board_, SLOT(makeMove(int, int)));
            columnLayout_->addWidget(box);
        }
    }
    this->show();
}

void Interface::displayMove(const QString s, int x, int y)
{
    dynamic_cast<Box*>(
            boardLayout_
            ->itemAt(x)
            ->layout()
            ->itemAt(y)
            ->widget())
            ->setText(s);
} 
