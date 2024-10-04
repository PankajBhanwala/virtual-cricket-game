#include "game.h"
using namespace std;

int main() {
    string userName;
    cout << "Enter Your Name: ";
    getline(cin,userName);
    
    Game game;
    game.welcomeUser(userName);
    game.viewInstruction();
    game.showAllPlayers();
    game.selectPlayers();
    game.showTeamPlayers();
    cin.clear();    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // usleep(30000000);
    game.toss();
    game.startFirstInning();
    game.startSecondInning();

    return 0;
}