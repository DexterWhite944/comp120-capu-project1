# Tic-Tac-Toe vs. Computer in C

## Description

This project creates a simple Tic-Tac-Toe game in C where the user plays against the computer. The game uses a 3x3 board with squares numbered from 0 to 8. The user plays as O and always goes first, while the computer plays as X and chooses random moves.

The program demonstrates basic concepts in C programming, including:

- Using arrays to store and display the game board
- Using functions to organize the code
- Using loops and conditional statements
- Using `rand()` to generate random computer moves
- Using `bool` variables to check game conditions
- Checking for invalid inputs and detecting wins or draws

## Code Overview

These are the functions used in the project:

- `init_board()` – Sets all nine squares to empty.
- `display_board()` – Displays the game board and numbers for empty squares.
- `is_winner()` – Checks if a player has won the game.
- `other_player()` – Switches between player O and player X.
- `get_human_move()` – Asks the user to choose an empty square.
- `get_computer_move()` – Generates a random move for the computer.
- `take_turn()` – Allows the current player to make a move.
- `play_game()` – Runs the game until someone wins or it ends in a draw.
- `play_again()` – Asks the user if they want to play another game.

The program checks every move to make sure it is valid before it puts a symbol on the board. After each move the program shows the updated board. When a player gets three symbols in a row the game says who won. If all nine squares are filled and no winner appears then that means the game ended in a tie.

## How to Run

1. Clone or download this repository.
2. Open the file `tic_tac_toe.c` in a C programming environment.
3. Compile and run the program. For example, using GCC:

   `gcc tic_tac_toe.c -o tic_tac_toe`

4. Enter a number from 0 to 8 to place your O on the board.
5. The computer will automatically choose an empty square for X.
6. Continue playing until someone wins or the game ends in a draw.
7. Enter `y` to play again or `q` to quit.

## Author

Dexter H. White
