#ifndef GRAPHICHANDLER_H
#define GRAPHICHANDLER_H

#include <stdlib.h>
#include <time.h>
#include <iostream>

class GraphicHandler
{
public:
    GraphicHandler();
    void randomColors();
    int getColor1();
    int getColor2();
    int getColor3();
private:
    int color1;
    int color2;
    int color3;
};

#endif // GRAPHICHANDLER_H
