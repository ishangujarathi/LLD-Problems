#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PlayingPiece {
public:
    string pieceType;
    
    // Constructor
    PlayingPiece(string type) {
        pieceType = type;
    }
};

class Board {
public:
    int size;
    vector<vector<PlayingPiece*>> board;

    // Constructor
    Board(int boardSize) {
        size = boardSize;
        board = vector<vector<PlayingPiece*>>(size, vector<PlayingPiece*>(size, nullptr));
    }

    bool addPiece(int row, int column, PlayingPiece* playingPiece) {
        if (board[row][column] != nullptr) {
            return false;
        }
        board[row][column] = playingPiece;
        return true;
    }

    vector<pair<int, int>> getFreeCells() {
        vector<pair<int, int>> freeCells;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == nullptr) {
                    freeCells.emplace_back(i, j);
                }
            }
        }
        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != nullptr) {
                    cout << board[i][j]->pieceType << "   ";
                } else {
                    cout << "    ";
                }
                cout << " | ";
            }
            cout << endl;
        }
    }

    bool isWinner(int row, int col, string pieceType) {
        bool rowMatch = true, colMatch = true, diagMatch = true, antiDiagMatch = true;
        
        for (int i = 0; i < size; i++) {
            if (board[row][i] == nullptr || board[row][i]->pieceType != pieceType) rowMatch = false;
            if (board[i][col] == nullptr || board[i][col]->pieceType != pieceType) colMatch = false;
            if (board[i][i] == nullptr || board[i][i]->pieceType != pieceType) diagMatch = false;
            if (board[i][size - i - 1] == nullptr || board[i][size - i - 1]->pieceType != pieceType) antiDiagMatch = false;
        }
        return rowMatch || colMatch || diagMatch || antiDiagMatch;
    }
};

class Player {
public:
    string name;
    PlayingPiece* piece;
    
    Player(string playerName, PlayingPiece* playerPiece) {
        name = playerName;
        piece = playerPiece;
    }
};

class TicTacToeGame {
public:
    Board* board;
    queue<Player*> players;

    TicTacToeGame(int size) {
        board = new Board(size);
    }

    void initializeGame() {
        players.push(new Player("Player1", new PlayingPiece("X")));
        players.push(new Player("Player2", new PlayingPiece("O")));
        cout << "Game initialized!" << endl;
    }

    string startGame() {
        while (true) {
            Player* currentPlayer = players.front();
            players.pop();
            board->printBoard();
            
            if (board->getFreeCells().empty()) {
                return "Tie";
            }
            
            int row, col;
            cout << "Player " << currentPlayer->name << ", enter row and column: ";
            cin >> row >> col;
            
            if (!board->addPiece(row, col, currentPlayer->piece)) {
                cout << "Invalid move, try again!" << endl;
                players.push(currentPlayer);
                continue;
            }
            
            if (board->isWinner(row, col, currentPlayer->piece->pieceType)) {
                return currentPlayer->name;
            }
            players.push(currentPlayer);
        }
    }
};

int main() {
    TicTacToeGame game(3);
    game.initializeGame();
    cout << "Game winner is: " << game.startGame() << endl;
    return 0;
}
