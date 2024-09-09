#include "TicTacToe.h"
#include <iostream>

int main()
{
    try
    {
        Player *player1 = new HumanPlayer('X');
        Player *player2 = new HumanPlayer('O');

        TicTacToe game(player1, player2);
        game.playGame();
    }
    catch (const GameException &e)
    {
        std::cerr << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Wystapil nieoczekiwany blad\n";
    }

    return 0;
}