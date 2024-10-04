#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include "team.h"

class Game {
    public:
        Game();
        int playerPerTeam;
        int maxBalls;
        int totalPlayers;
        std::string player[11];
        bool isFirstInning;
        Team teamA, teamB;
        Team *battingTeam, *bowlingTeam;
        Player *batsman,*bowler;
        int ballNo;
    
        void welcomeUser(std::string);
        void viewInstruction();
        void showAllPlayers();
        int takeIntegerInput();
        void selectPlayers();
        bool validateSelectedPlayer(int);
        void showTeamPlayers();
        void tossChoice(Team);
        void validateToss(int);
        void toss();
        void startFirstInning();
        void intializePlayers();
        void playInning();
        void bat();
        bool validateInningsScore();
        void showGameScorecard();
        void startSecondInning();
};