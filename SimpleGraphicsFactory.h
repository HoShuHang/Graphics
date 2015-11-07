#ifndef SIMPLEGRAPHICSFACTORY_H_INCLUDED
#define SIMPLEGRAPHICSFACTORY_H_INCLUDED
#include "GraphicsFactory.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"

class SimpleGraphicsFactory : public GraphicsFactory
{
public:
    Graphics * extractGraphicsFromOneLine(std::string & contents, int & level);
};

#endif // SIMPLEGRAPHICSFACTORY_H_INCLUDED
