/*	Name: Nathan Higley
    Date Modified: 1/29/2021
    Purpose: Use a class and loops to make a two-player Tic Tac Toe program.
    Compiler: MS VC++ 2019
*/
#include <iostream>
using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void ShowBoard();
    void XPlay();
    void OPlay();
    void PlayerMove(char player);
    char DetermineWinner(char player);

private:
    char GameBoard[3][3];
};

TicTacToe::TicTacToe() :
    GameBoard{ {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} } 
{}

void TicTacToe::ShowBoard()
{
    cout << endl << "Player 1 - X | Player 2 - O" << endl << endl;

    cout << "    |     |" << endl;
    cout << " " << GameBoard[0][0] << "  |  " << GameBoard[0][1] << "  |  " << GameBoard[0][2] << endl;

    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;

    cout << " " << GameBoard[1][0] << "  |  " << GameBoard[1][1] << "  |  " << GameBoard[1][2] << endl;

    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;

    cout << " " << GameBoard[2][0] << "  |  " << GameBoard[2][1] << "  |  " << GameBoard[2][2] << endl << endl;

}

void TicTacToe::XPlay() {
    PlayerMove('X');
}

void TicTacToe::OPlay() {
    PlayerMove('O');
}

void TicTacToe::PlayerMove(char player) {

    bool ValidMove = false;
    int playerR;
    int playerC;

    cout << player << " TURN" << endl << endl;

    while (ValidMove == false) {

        cout << "Select a Row" << endl;
        cin >> playerR;
        cout << "Select a Column" << endl;
        cin >> playerC;

        if ((playerR > 0 and playerR < 4) && (playerC > 0 and playerC < 4) && (GameBoard[(playerR - 1)][(playerC - 1)] == '*'))
        {
            GameBoard[(playerR - 1)][(playerC - 1)] = player;
            ValidMove = true;
        }
        else {
            cout << "Invalid Move!" << endl << endl;
        }
    }
}

char TicTacToe::DetermineWinner(char player)
{
    char WinCondition = 'n';

    //ROWS
    for (int c = 0; c < 3; c++)
    {
        if (GameBoard[c][0] == GameBoard[c][1] && GameBoard[c][1] == GameBoard[c][2] && GameBoard[c][2] != '*')
        {
            WinCondition = player;
        }
    }

    //COLUMNS
    for (int c = 0; c < 3; c++)
    {
        if (GameBoard[0][c] == GameBoard[1][c] && GameBoard[1][c] == GameBoard[2][c] && GameBoard[2][c] != '*')
        {
            WinCondition = player;
        }
    }

    //DIAGONALS
    if (GameBoard[0][0] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][2] && GameBoard[2][2] != '*')
    {
        WinCondition = player;
    }
    if (GameBoard[2][0] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[0][2] && GameBoard[0][2] != '*')
    {
        WinCondition = player;
    }

    //TIE
    //I desperately wanted to automate a check for * in every spot but couldn't figure out how to do that without prematurely calling a tie.
    if (GameBoard[0][0] != '*' && GameBoard[0][1] != '*' && GameBoard[0][2] != '*' && GameBoard[1][0] != '*' && GameBoard[1][1] != '*' && GameBoard[1][2] != '*' && GameBoard[2][0] != '*' && GameBoard[2][1] != '*' && GameBoard[2][2] != '*')
        {
            WinCondition = 't';
        }


    if (WinCondition == player)
    {
        ShowBoard();
        cout << endl << player << " Wins!" << endl;
    }
    else if (WinCondition == 't')
    {
        ShowBoard();
        cout << "Tie Game!" << endl;
    }

    return(WinCondition);
}

int main()
{
    bool play = true;
    int Turn = 0;
    char GameOver = 'n';
    char player;

    TicTacToe game;

    while (play == true)
    {
        while (GameOver == 'n')
        {
            if (GameOver == 'n')
            {
                Turn++;
            }
            else
            {
                play = false;
            }

            game.ShowBoard();

            if (Turn % 2) {
                player = 'X';
                game.XPlay();
            }
            else {
                player = 'O';
                game.OPlay();
            }
            GameOver = game.DetermineWinner(player);
        }
    }

    return(0);
}