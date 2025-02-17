class TicTacToeGame {
    public:
        Board* board;
        
        // Constructor
        TicTacToeGame(int size) {
            board = new Board(size);
        }
        
        void initializeGame() {
            cout << "Game initialized!" << endl;
        }
        
        string startGame() {
            return "No winner yet!"; // Placeholder logic
        }
    };
    
    int main() {
        TicTacToeGame game(3);
        game.initializeGame();
        cout << "Game winner is: " << game.startGame() << endl;
        return 0;
    }