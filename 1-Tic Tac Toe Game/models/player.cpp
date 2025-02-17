#include <string>

using namespace std;

class Player {
public:
    string name;
    PlayingPiece* playingPiece;

    Player(string name, PlayingPiece* playingPiece) {
        this->name = name;
        this->playingPiece = playingPiece;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    PlayingPiece* getPlayingPiece() {
        return playingPiece;
    }

    void setPlayingPiece(PlayingPiece* playingPiece) {
        this->playingPiece = playingPiece;
    }
};
