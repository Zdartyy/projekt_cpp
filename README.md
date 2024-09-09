# projekt_cpp


Autor: Artur Tabor                                                                         Krakow 09.09.2024


* Zawartosc:


Katalog zawiera grę kółko krzyżyk w terminalu napisaną w jezyku C++:

I.  Program main.cpp implementuje grę w kółko i krzyżyk. Tworzy dwóch graczy jako obiekty
klasy HumanPlayer, a następnie tworzy obiekt gry TicTacToe z tymi graczami. Uruchamia grę 
za pomocą metody playGame. Obsługuje wyjątki, wyświetlając odpowiednie komunikaty błędów 
w przypadku wystąpienia problemów.

II. Program uruchamia grę, wyświetla planszę, pozwala graczom na wykonywanie ruchów, 
sprawdza warunki zwycięstwa lub remisu oraz obsługuje błędy związane z niepoprawnymi ruchami.

W Klasie TicTacToe:
-Konstruktor: Inicjalizuje grę, tworząc planszę 3x3 i przypisując graczy.
-Destruktor: Usuwa graczy, aby zwolnić pamięć.
-Metoda displayBoard: Wyświetla aktualny stan planszy.
-Metoda playGame: Zarządza przebiegiem gry, wywołując ruchy graczy, sprawdzając zwycięstwo
lub remis, i zmieniając aktualnego gracza.
-Metoda checkWin: Sprawdza, czy dany symbol (gracz) wygrał, analizując wiersze, kolumny i przekątne.
-Metoda checkDraw: Sprawdza, czy gra zakończyła się remisem, analizując, czy wszystkie komórki 
są zapełnione.

W Klasie HumanPlayer:
-Metoda makeMove: Pozwala graczowi wykonać ruch, sprawdzając poprawność współrzędnych i aktualizując
planszę. Obsługuje błędy za pomocą wyjątków.

III. Plik TicTacToe.h jest plikiem nagłówkowym, który zawiera deklaracje klas i funkcji
używanych w implementacji gry.

Klasa abstrakcyjna Player:
Deklaruje czysto wirtualne metody getSymbol i makeMove, które są zaimplementowane przez klasy dziedziczące.
Zawiera wirtualny destruktor.

Klasa HumanPlayer:
Dziedziczy po klasie Player.
Implementuje metody getSymbol i makeMove.
Posiada prywatne pole symbol oraz konstruktor inicjalizujący to pole.

Klasa TicTacToe:
Zawiera prywatne pola: plansza (board), wskaźniki do graczy (player1, player2, currentPlayer).
Deklaruje publiczne metody: konstruktor, destruktor, playGame, checkWin, checkDraw, displayBoard.

*WAŻNE*
W programie można podać współrzędne w zakresie od 0 do 2 dla zarówno wierszy, jak i kolumn. 
Po poleceniu by podać współrzędne gracza należy podac pierwszą współrzędną, wstawić znak spacji oraz następną
współrzędna 
Przykładowe poprawne współrzędne: 0 0; 2 1; 1 1; 0 2;



* Jak uruchomic program:
g++ -o tic_tac_toe main.cpp TicTacToe.cpp    kompiluje oraz tworzy plik .exe
.\tic_tac_toe.exe                            uruchamia grę

 
