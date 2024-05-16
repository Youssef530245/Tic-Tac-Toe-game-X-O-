#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TicTacToe {
private:
    vector<string> board;
    string currentPlayer;

public:
    TicTacToe() {
        // Initialize the game board
        for (int i = 0; i < 9; i++) {
            board.push_back("-");
        }
        currentPlayer = "X";
    }

    // Print the game board
    void printBoard() {
        cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }

    // Handle a player's turn
    void takeTurn() {
        cout << currentPlayer << "'s turn." << endl;
        cout << "Choose a place from 1-9: ";
        int position;
        cin >> position;
        position -= 1;
        while (position < 0 || position > 8 || board[position] != "-") {
            cout << "Invalid input or position already taken. Choose a different position ya sahpy: ";
            cin >> position;
            position -= 1;
        }
        board[position] = currentPlayer;
        printBoard();
    }

    // Check if the game is over
    string checkGameOver() {
        // Check for a win
        if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
            (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
            (board[6] == board[7] && board[7] == board[8] && board[6] != "-") ||
            (board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
            (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
            (board[2] == board[5] && board[5] == board[8] && board[2] != "-") ||
            (board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
            (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
            return "win";
        }
        // Check for a tie
        else if (count(board.begin(), board.end(), "-") == 0) {
            return "tie";
        }
        // Game is not over
        else {
            return "play";
        }
    }

    // Switch to the other player
    void switchPlayer() {
        currentPlayer = currentPlayer == "X" ? "O" : "X";
    }

    // Play the game
    void play() {
        printBoard();
        bool gameOver = false;
        while (!gameOver) {
            takeTurn();
            string gameResult = checkGameOver();
            if (gameResult == "win") {
                cout << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (gameResult == "tie") {
                cout << "It's a tie!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }
};



int main() {
    TicTacToe game;
    game.play();




    return 0;
}