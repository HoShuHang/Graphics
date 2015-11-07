#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED
#include "Graphics.h"
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include "SnapshotStack.h"
using namespace std;

class GraphicsFactory
{
public:
    Graphics * buildGraphicsFromFile(const char * fileName); /*implement the pseudo code */
    string fileContentsAsString(const char * fileName); /* implement line 1 of pseudo code */
    virtual Graphics * extractGraphicsFromOneLine(std::string & contents, int & level); /*implement line 3 */
    void compose (); /* implement lines 5, 6 as well as line 9 */
    vector<string> split(string str, char delimiter);
    vector<int> getParams(string str);
    string pureString(string str);
    int getLevel(string str);
    string getStackTrace();
    string getStackTraceBeforeLineFive();
    vector<Graphics *> getGraphicsStack();
    vector<int> getLevelStack();
    void setCurrentLevel(int c_level);
    void setPreLevel(int p_level);
    vector<Graphics *> graphicsStack;
    vector<int> levelStack;
protected:
    int current_level = 0, pre_level = 0;
private:
    stringstream stackTrace;
    stringstream stackTraceBeforeLineFive;
    void pushToStack(Graphics * g);
    void popStack();
    void traceStack();
};

#endif // GRAPHICSFACTORY_H_INCLUDED
