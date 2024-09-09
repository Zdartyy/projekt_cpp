#include "TicTacToe.h"
#include <iostream>

//konstruktor gry
TicTacToe::TicTacToe(Player *p1, Player *p2) : player1(p1), player2(p2), currentPlayer(p1)
{
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
}

//destruktor
TicTacToe::~TicTacToe()
{
    delete player1;
    delete player2;
}

//wyświetlanie planszy
void TicTacToe::displayBoard()
{
    for (const auto &row : board) //iterator
    {
        for (const auto &cell : row)
        {
            std::cout << (cell == ' ' ? '.' : cell) << " ";
        }
        std::cout << "\n";
    }
}

//funkcja do gry
void TicTacToe::playGame()
{
    while (true)
    {
        displayBoard();
        currentPlayer->makeMove(board); //polimorfizm

        if (checkWin(currentPlayer->getSymbol()))
        {
            displayBoard();
            std::cout << "Gracz " << currentPlayer->getSymbol() << " wygral!\n";
            break;
        }
        if (checkDraw())
        {
            displayBoard();
            std::cout << "Remis!\n";
            break;
        }
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
}

//sprawdzanie zwycięzcy
bool TicTacToe::checkWin(char symbol)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)    //sprawdzanie komorek w wierszu
            return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)    //sprawdzanie komorek w kolumnie
            return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)    //sprawdzanie komorek na przekątnej
        return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)    //sprawdzanie komorek na przekątnej
        return true;
    return false;
}

//sprawdzanie remisu
bool TicTacToe::checkDraw()
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

//wykonanie ruchu gracza z obsługą błędów
void HumanPlayer::makeMove(std::vector<std::vector<char>> &board)
{
    int x, y;
    bool validMove = false;

    while (!validMove)
    {
        try
        {
            std::cout << "Gracz " << symbol << ", podaj wspolrzedne (wiersz i kolumna): ";
            std::cin >> x >> y;

            if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ')
            {
                throw GameException();  //jeśli ruch jest niepoprawny to wyrzuca wyjątek
            }

            board[x][y] = symbol;   //jeśli ruch jest poprawny to aktualizuje planszę
            validMove = true;       //poprawny ruch
        }
        catch (const GameException &e) //wyjątki
        {
            std::cerr << e.what() << "\n";
        }
    }
}