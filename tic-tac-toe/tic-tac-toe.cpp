#include "tic-tac-toe.h"
#include "interface.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Interface window;

    return app.exec();
}
