#pragma once

#include "../libraries.h"

class Box : public QLabel
{
	Q_OBJECT

public:
	explicit Box(int x, int y, QWidget* parent = Q_NULLPTR);
	~Box();

private:
	int x_ = 0;
	int y_ = 0;

protected:
	void mouseReleaseEvent(QMouseEvent* event);

signals:
	void isClicked(int x, int y);
};
