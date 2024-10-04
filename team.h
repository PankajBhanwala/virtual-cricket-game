#include <vector>
#include "player.h"

class Team{
    
    public:
        Team();
        std::string name;
        int totalRuns;
        int totalWicketsLost;
        int totalBallBowled;
        std::vector<Player>players;
        
};