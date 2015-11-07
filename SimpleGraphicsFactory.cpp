#include "SimpleGraphicsFactory.h"

Graphics * SimpleGraphicsFactory::extractGraphicsFromOneLine(std::string & contents, int & level)
{
    if(level != getLevel(contents)){
        pre_level = level;
    }
    level = getLevel(contents);
    vector<string> args_string = split(pureString(contents), ',');
    vector<int> args_int;
    int arg;
    for(int i = 0; i < args_string.size(); i++)
    {
        stringstream ss(args_string[i]);
        ss >> arg;
        args_int.push_back(arg);
    }
    Graphics *g;
    switch(contents[level * 2])
    {
    case 'C':
        if(contents[level * 2 + 1] == 'o'){
            g = new CompositeGraphics();
        }else
            g = new SimpleGraphics(new Circle(args_int[0], args_int[1], args_int[2]));
        break;
    case 'S':
        g = new SimpleGraphics(new Square(args_int[0], args_int[1], args_int[2]));
        break;
    case 'R':
        g = new SimpleGraphics(new Rectangle(args_int[0], args_int[1], args_int[2], args_int[3]));
        break;
    default:
        throw std::string("contents is error");
    }
    return g;
}
