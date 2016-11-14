#include "graphichandler.h"

GraphicHandler::GraphicHandler()
{
    srand(time(NULL));
    this->color1=rand()%255;
    this->color2=rand()%255;
    this->color3=rand()%255;
}

void GraphicHandler::randomColors(){
    this->color1=rand()%255;
    this->color2=rand()%255;
    this->color3=rand()%255;
}

int GraphicHandler::getColor1(){
    return this->color1;
}

int GraphicHandler::getColor2(){
    return this->color2;
}

int GraphicHandler::getColor3(){
    return this->color3;
}

