#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void display (queue<string>pl)
{
    while(!pl.empty())
    {
    cout<<pl.front()<<"\n";
    pl.pop();
    }    
}

int main()
{
    queue <string> pl;
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout<<"Initial Stack: "<<endl;
    display (pl);
    pl.pop();
    pl.pop();
    cout<<"\n"<<"Final Stack: " <<endl;
    display (pl);
    return 0;
}

