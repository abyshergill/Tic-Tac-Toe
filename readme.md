# Tic Tac Toe Game in C

This is a simple command-line Tic Tac Toe game written in C. Two players can play against each other on a 3x3 grid.

---

## How to Play

1.  **Compilation**:
    * The game uses standard C libraries. You'll need a C compiler (like GCC) to compile the `main.c` file (assuming your code is in a file named `main.c`).
    * Open a terminal or command prompt.
    * Navigate to the directory where you saved the C file.
    * Compile the code using a command like:
        ```bash
        gcc main.c -o tictactoe
        ```
        (This will create an executable file named `tictactoe` or `tictactoe.exe` on Windows).

2.  **Running the Game**:
    * After successful compilation, run the game from the terminal using:
        ```bash
        ./tictactoe
        ```
        or on Windows:
        ```bash
        tictactoe.exe
        ```
    * The game board will be displayed. Player 1 is 'X' and Player 2 is 'O'.

3.  **Making a Move**:
    * Players take turns entering a number from 1 to 9, corresponding to the desired cell on the board:

        ```
          1 | 2 | 3
        -----------
          4 | 5 | 6
        -----------
          7 | 8 | 9
        ```
    * The game will prompt the current player for their selection.

4.  **Winning the Game**:
    * The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the game.
    * If all cells are filled and no player has won, the game is a draw.

5.  **Quitting the Game**:
    * During your turn, you can enter 'Q' or 'q' to quit the game.

6.  **Play Again?**:
    * After a game ends (win, draw, or quit), you will be asked if you want to play again.
    * Enter 'Y' or 'y' to start a new game.
    * Enter 'N' or 'n' to exit.

---

## Game Logic Overview

* The game board is represented by a global character array `array`.
* The `main` function controls the game loop, alternating turns between Player 1 and Player 2.
* `arch()` function: Clears the screen and redraws the Tic Tac Toe board with the current state.
* `user_input(int player_turn)`: Prompts the current player for their move (a number from 1-9) or to quit ('Q'/'q'). It validates the input.
* `cardboard(int position_location, int loop_turn)`: Updates the game board array with the player's mark ('X' or 'O') if the chosen cell is empty. It checks for win conditions after each move or if the game is a draw.
* `win_check()`: Checks all possible winning combinations for both players.
* `game_continue()`: Asks the players if they want to play another round after a game concludes.
* `chartoascii(int user_input)`: Converts the character input (e.g., '1') to its corresponding integer value for board indexing or a special value for quitting.

---

## Code Structure

The project consists of the following functions:

* `main()`: Main game loop and logic.
* `arch()`: Displays the game board.
* `user_input()`: Handles player input.
* `cardboard()`: Processes player moves and checks game status.
* `win_check()`: Determines if a player has won.
* `game_continue()`: Prompts to play again.
* `chartoascii()`: Converts character input to integer.

---

## Dependencies

* `stdio.h`
* `string.h`
* `stdlib.h`
* `stdbool.h`
* `unistd.h` (Note: `unistd.h` and `system("cls")` / `system("a.exe")` might have portability issues. `cls` is a Windows command, `a.exe` implies a Windows executable name. For cross-platform compatibility, consider alternative methods for clearing the screen and restarting the game.)

---

## Author

* [Kuldeep Singh] [Email : shergillkuldeep@outook.com]