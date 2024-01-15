#include <iostream>
#include "Warcaby/Game/game.h"
#include "Warcaby/types.h"

#include "Warcaby/Renderer/ascii_renderer.hpp"

using namespace std;

int main() {
    
    // tworzymy obiekt gry
    Game game;
    AsciiRenderer renderer;

    array<int, 2> UserInput1, UserInput2;
    string player;
    string mess = "";

    // glowna petla gry
    while(game.gameState == ONGOING){

        renderer.printBoard(game.getBoard());
        player = game.currentMove == SYMBOL_WHITE ? "Bialy" : "Czarny";
        renderer.printMessage(mess + "\n\nRuch gracza: " + player + "\nPodaj ruch");
        
        UserInput1 = renderer.getUserInput();
        UserInput2 = renderer.getUserInput();
        
        mess = game.update(UserInput1[0], UserInput1[1], UserInput2[0], UserInput2[1]);
        

    }

    // wypisujemy kto wygral
    //cout << "Wygral gracz: " << game.gameState << endl;
    
    return 0;
}