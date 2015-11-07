#include "GraphicsFactory.h"
#include <fstream>
using namespace std;

Graphics * GraphicsFactory::buildGraphicsFromFile(const char * fileName)
{
    string contents = fileContentsAsString(fileName);
    std::stringstream ss(contents);
    string line;
    while(getline(ss, line))
    {
        Graphics *g = extractGraphicsFromOneLine(line, current_level);
        stack<Graphics *> composites;
        if(current_level < pre_level)
            compose();
        pushToStack(g);
        traceStack();
    }
    stackTraceBeforeLineFive << stackTrace.str();
    while(graphicsStack.size() > 1)
        compose();
    traceStack();
    return graphicsStack.back();
}

string GraphicsFactory::fileContentsAsString(const char * fileName)
{
    string contents, line;
    ifstream file(fileName);
    if(!file)
        throw string("File does not exist.");
    if(file.is_open())
    {
        while(getline(file, line))
        {
            contents += line + '\n';
        }
        file.close();
    }
    else
        throw string("Unable to open file.");
    return contents;
}

Graphics * GraphicsFactory::extractGraphicsFromOneLine(std::string & contents, int & level)
{
}

vector<Graphics *> GraphicsFactory::getGraphicsStack()
{
    return graphicsStack;
}

vector<int> GraphicsFactory::getLevelStack()
{
    return levelStack;
}

void GraphicsFactory::setCurrentLevel(int c_level)
{
    current_level = c_level;
}

void GraphicsFactory::setPreLevel(int p_level)
{
    pre_level = p_level;
}

void GraphicsFactory::compose ()
{
    int level = levelStack.back();
    stack<Graphics *> composites;
    while(levelStack.back() == level)
    {
        composites.push(graphicsStack.back());
        popStack();
        pre_level = levelStack.back();
    }
    Graphics *compositeGraphic = graphicsStack.back();
    while(composites.size() > 0)
    {
        compositeGraphic -> add(composites.top());
        composites.pop();
    }
}

void GraphicsFactory::pushToStack(Graphics * g)
{
    graphicsStack.push_back(g);
    levelStack.push_back(current_level);
}

void GraphicsFactory::popStack()
{
    graphicsStack.pop_back();
    levelStack.pop_back();
}

void GraphicsFactory::traceStack()
{
    stackTrace << '\n';
    for(int i = 0; i < graphicsStack.size(); i++)
    {
        stackTrace << levelStack[i] << ", " << graphicsStack[i]->trace() << '\n';
    }
}

string GraphicsFactory::getStackTrace()
{
    return stackTrace.str();
}

string GraphicsFactory::getStackTraceBeforeLineFive()
{
    return stackTraceBeforeLineFive.str();
}

vector<string> GraphicsFactory::split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string line;
    while(getline(ss, line, delimiter))
        internal.push_back(line);
    return internal;
}

string GraphicsFactory::pureString(string str)
{
    int index_of_l_brackets = str.find('(');
    int index_of_r_brackets = str.find(')');
    str.erase(0, index_of_l_brackets + 1);
    str.erase(str.size() - 1, 1);
    return str;
}

int GraphicsFactory::getLevel(string str)
{
    int level = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i]!=' ')
        {
            level = i / 2;
            break;
        }
    }
    return level;
}
