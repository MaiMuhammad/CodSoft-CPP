#include <bits/stdc++.h>
#define endL "\n"
using namespace std;

class TicTacToe {
public:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameOver;

    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
    }

    void displayBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) {
                    cout << "|";
                }
            }
            cout << endL;
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    void move() {
        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isValid(row, col));

        board[row][col] = currentPlayer;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void play() {
        while (!gameOver) {
            displayBoard();
            move();
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endL;
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endL;
                gameOver = true;
            }
            else
                switchPlayer();
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.play();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}