#include <iostream>
#include <vector>

using namespace std;

enum class PieceType {
    X,
    O
};

class PlayingPiece {
public:
    PieceType pieceType;

    PlayingPiece(PieceType type) {
        pieceType = type;
    }
};

class Board {
private:
    int size;
    vector<vector<PlayingPiece*>> board;

public:
    Board(int size) {
        this->size = size;
        board.resize(size, vector<PlayingPiece*>(size, nullptr));
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
                    freeCells.push_back({i, j});
                }
            }
        }
        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != nullptr) {
                    cout << (board[i][j]->pieceType == PieceType::X ? "X" : "O") << "   ";
                } else {
                    cout << "    ";
                }
                cout << " | ";
            }
            cout << endl;
        }
    }
};
