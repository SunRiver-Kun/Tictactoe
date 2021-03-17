#include<windows.h>
#include"tictactoe.h"
Tictactoe::Tictactoe()
{
    for(int i=0;i<10;++i)
        tiles[i] ='\0';
    count_down = 0;
    result = "";
}
bool Tictactoe::IsFinish()
{
    // horizontal
    for(int i=0;i<=6;i+=3)
    {
        if(tiles[i]==tiles[i+1] && tiles[i]==tiles[i+2] && tiles[i]!='\0')
        {
            result = tiles[i]==HUMAN ? "human" : "machine";
            return true;
        }
    }
    // vertical
    for(int i=0;i<=2;++i)
    {
        if(tiles[i]==tiles[i+3] && tiles[i]==tiles[i+6] && tiles[i]!='\0')
        {
            result = tiles[i]==HUMAN ? "human" : "machine";
            return true;
        }
    }
    // main diagonal
    if(tiles[0]==tiles[4] && tiles[0]==tiles[8] && tiles[0]!='\0' )
    {
        {
            result = tiles[0]==HUMAN ? "human" : "machine";
            return true;
        }
    }
    // deputy diagonal
    if(tiles[2]==tiles[4] && tiles[2]==tiles[6] && tiles[2]!='\0')
    {
        result = tiles[2]==HUMAN ? "human" : "machine";
        return true;
    }
    // no empty
    if(count_down>=9)
    {
        result = "equal";
        return true;
    }
    return false;
}
bool Tictactoe::IsEmpty(int order)
{
    if(order<1 || order>9) {return false;}
    if( tiles[order-1]=='\0')
        return true;
    else
        return false;
}  //1~9
string Tictactoe::GetResult()
{
    if(!IsFinish()){return "Game isn't finish.";}
    if(result=="human")
        return "!!! Human win !!!";
    else if(result=="machine")
        return "!!! Machine win !!!";
    else
        return "--- A dead heat ---";
}
void Tictactoe::PrintTiles()
{
    for(int i=0;i<=6;i+=3)
        cout<<tiles[i]<<" | "<<tiles[i+1]<<" | "<<tiles[i+2]<<endl;
}
void Tictactoe::ReflashWindow()
{
    system("cls");
    PrintTiles();
}
void Tictactoe::GoHuman()
{
    cout<<"Please input your choice 1~9: ";
    int order;
    cin>>order;
    while( (order<1 || order>9 ) || (!IsEmpty(order)))
    {
        cout<<"Input wrong!"<<endl<<"please choose your choice again 1~9: ";
        cin>>order;
    }
    tiles[order-1] = HUMAN;
    ++count_down;
    if(IsFinish())
    {
        ReflashWindow();
        cout<<GetResult()<<endl;
        exit(0);
    }
}

void Tictactoe::GoMachine()
{

    int score = -2000;
    int bestorder = -1;

    for(int i=1;i<=9;++i)  // order 1~9
    {
        if(IsEmpty(i))
        {
            tiles[i-1] = MACHINE;
            ++count_down;

            int temp = minimax(true,0);
            if(temp>score)
            {
                score = temp;
                bestorder = i;
            }

            tiles[i-1] = '\0';
            --count_down;
        }
    }

    if(bestorder<1){cout<<"GoMachine is wrong!!!"<<endl;return;}
    tiles[bestorder-1] = MACHINE;
    ++count_down;

    if(IsFinish())
    {
        ReflashWindow();
        cout<<GetResult()<<endl;
        exit(0);
    }
}
int Tictactoe::minimax(bool IsHuman,int depth)
{
    // machine find max score && human find min score
    if(IsFinish())
    {
        if(result=="human")
        {
            return -10+depth;
        }
        else if(result=="machine")
        {
            return 10-depth;
        }
        else
        {
            return -depth;
        }
    }

    if(IsHuman)
    {
        int best = 1000;

        for(int i=1;i<=9;++i) // order 1~9
        {
            if(IsEmpty(i))
            {
                tiles[i-1] = HUMAN;
                ++count_down;

                best = min(best,minimax(false,depth+1));

                tiles[i-1] = '\0';
                --count_down;
            }
        }

        return best;
    }
    else
    {
        int best = -1000;

        for(int i=1;i<=9;++i) // order 1~9
        {
            if(IsEmpty(i))
            {
                tiles[i-1] = MACHINE;
                ++count_down;

                best = max(best,minimax(true,depth+1));

                tiles[i-1] = '\0';
                --count_down;
            }
        }

        return best;
    }
}
