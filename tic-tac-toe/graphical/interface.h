#pragma once

#include "../logical/board.h"
#include "box.h"

class Interface : public QMainWindow
{
	Q_OBJECT

public:
	explicit Interface(QWidget* parent = Q_NULLPTR);
	~Interface();

private:
	const int   horizontalDimensions_ = 3;
	const int   verticalDimensions_   = 3;
	const QFont font_                 = QFont("Arial", 50);

	QWidget*     boardWidget_ = Q_NULLPTR;
	QHBoxLayout* boardLayout_ = Q_NULLPTR;

	Board board_;

signals:

public slots:
	void displayNewBoard();
	void displayMove(const QString s, int x, int y);
};
