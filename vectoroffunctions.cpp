/*
  Experimenting with vector of function pointers(handles)
  Applications ?
 */
 
 #include <iostream>
#include <vector>

#define VIA_EXECUTOR

using namespace std;

typedef void (*handler) (void);

vector <handler> tasklist;

void dothis(void)
{
    cout << __func__ << endl;
}

void dothat(void)
{
    cout << __func__ << endl;
}

void donothing(void)
{
    cout << __func__ << endl;
}

#ifdef VIA_EXECUTOR
void execute (vector<handler> &todolist)
{
    for(auto h = todolist.cbegin(); h != todolist.cend(); h++)
    {
        (*h)();
    }    
}
#endif

int main(int argc, char **argv)
{
    tasklist.push_back(dothis);
    tasklist.push_back(dothat);
    tasklist.push_back(donothing);
#ifndef VIA_EXECUTOR

    for(auto h = tasklist.cbegin(); h != tasklist.cend(); h++)
    {
        (*h)();
    }
#else
    // Use executor
    execute(tasklist);
#endif
    return 0;
}
