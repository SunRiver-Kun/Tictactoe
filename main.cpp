#include <iostream>
#include"tictactoe.h"
using namespace std;
int main()
{
    cout<<"Please input 0~1 to choose human or machine to go first: ";
    int choice;
    cin>>choice;

    Tictactoe game;
    if(choice==0)
    {
        cout<<"Human go first"<<endl;
        while(true)
        {
            game.GoHuman();
            game.GoMachine();
            game.ReflashWindow();
        }
    }
    else
    {
        cout<<"Machine go first"<<endl;
        while(true)
        {
            game.GoMachine();
            game.ReflashWindow();
            game.GoHuman();
            game.ReflashWindow();
        }
    }
    return 0;
}
