#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>

//klasa abstrakcyjna
class Player
{
public:
    virtual char getSymbol() const = 0;
    virtual void makeMove(std::vector<std::vector<char>> &board) = 0;
    virtual ~Player() = default;
};

//klasa dziedzicząca po klasie Player
class HumanPlayer : public Player
{
private:
    char symbol;

public:
    HumanPlayer(char s) : symbol(s) {}
    char getSymbol() const override { return symbol; }
    void makeMove(std::vector<std::vector<char>> &board) override;
};

//klasa TicTacToe
class TicTacToe
{
private:
    std::vector<std::vector<char>> board;
    Player *player1;
    Player *player2;
    Player *currentPlayer;

public:
    //konstruktor
    TicTacToe(Player *p1, Player *p2);

    //destruktor
    ~TicTacToe();

    //funkcja do gry
    void playGame();

    //sprawdzanie zwycięzcy
    bool checkWin(char symbol);

    //sprawdzanie remisu
    bool checkDraw();

    //wyświetlanie planszy
    void displayBoard();
};

//wyjątek gry
class GameException : public std::exception
{
public:
    //przeciazenie metody what
    const char *what() const noexcept override
    {
        return "Nieprawidlowy ruch!";
    }
};

#endif //TICTACTOE_H