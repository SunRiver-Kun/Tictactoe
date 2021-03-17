#pragma once
#include<iostream>
#include<string>
#define HUMAN 'X'
#define MACHINE 'O'
using namespace std;
class Tictactoe
{
public:
    Tictactoe();
    string GetResult();  // make sure use "if( IsFinish() )" before your get the result
    void ReflashWindow();
    void GoHuman();
    void GoMachine();
private:
    char tiles[10];
    size_t count_down;
    string result;

    bool IsFinish();  // !!!  will change the result at the same time !!!  
    bool IsEmpty(int order);  //1~9
    void PrintTiles();
    int minimax(bool IsHuman,int depth);
};
