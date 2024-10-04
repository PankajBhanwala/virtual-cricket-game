#include "game.h"
using namespace std;

Game::Game() {
    playerPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;
    ballNo=0;
    
    player[0] = "Rohit";
    player[1] = "Rahul";
    player[2] = "Pujara";
    player[3] = "Kholi";
    player[4] = "Rahane";
    player[5] = "Pant";
    player[6] = "Jadeja";
    player[7] = "Ashwin";
    player[8] = "Shami";
    player[9] = "Ishant";
    player[10] = "Bumrah";
    
    isFirstInning = false;
    teamA.name = "Team A";
    teamB.name = "Team B";
}

void Game::welcomeUser(string name) {
    cout << endl << "\t\t-----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t Welcome to Virtual Cricket," << name << "!\t\t" << endl;
    cout << "\t\t-----------------------------------------------------------------------------------" << endl<<endl;
}

void Game::viewInstruction() {
        cout << "\t\t\tPress Enter to View Instructions: ";
        cin.get();
        cout << endl;
    
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t|=============== Instructions ===============|" << endl;
        cout << "\t\t\t|--------------------------------------------|" << endl;
        cout << "\t\t\t| 1. Create 2 team from pool of 11 player    |" << endl;
        cout << "\t\t\t| 2. Each team will have 4 players           |" << endl;
        cout << "\t\t\t| 3. Lead the toss decide the choice of play |" << endl;
        cout << "\t\t\t| 4. Each innings will be of 6 balls         |" << endl;
        cout << "\t\t\t----------------------------------------------" << endl << endl;
}

void Game::showAllPlayers() {
        cout << "\t\t\tPress Enter to View Players: ";
        cin.get();
        cout << endl;
        
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t|============== Pool of Players =============|" << endl;
        cout << "\t\t\t----------------------------------------------" << endl << endl;
        for (int i=0;i<totalPlayers;i++) {
            cout << "\t\t\t[" << i+1 << "] " << player[i] << endl;
        }
}

int Game::takeIntegerInput() {
        int n;
        while (!(cin>>n)) {                                         // if user enter any invalid value then (cin>>n) this expression generates error flags
            cin.clear();                                            // clear error flags    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // clear input buffer memory. 
        cout << endl << "\t\t\tInvalid Input! Please Enter Integer Value: ";
        }
        return n;
}

bool Game::validateSelectedPlayer(int index) {
        int n;
        vector<Player>players;
        
        players = teamA.players;
        n = players.size();
        for (int i = 0; i<n ; i ++) {
            if (players[i].uniqueId == index)
            return false;
        }
        
        players = teamB.players;
        n = players.size();
        for (int i = 0; i<n ; i++)
            if (players[i].uniqueId == index) {
                return false;
            }
    return true;
}

void Game::selectPlayers() {
        cout << endl << "\t\t\tPress Enter to continue: ";
        cin.get();
        
        cout << "\t\t\t----------------------------------------------------------------" << endl;
        cout << "\t\t\t========= Enter Number of Player that you want to add ==========" << endl;
        cout << "\t\t\t====== Example: If you want to Select 'Rohit' then Enter 1 =====" << endl;
        cout << "\t\t\t----------------------------------------------------------------" << endl << endl;
        
        for (int i=0;i < playerPerTeam; i++) {
            
            TeamASelection:
            Player teamAPlayers;
            cout << "\t\t\tChoose Player " << i + 1 << " of " << teamA.name << ": ";
            int PlayerIdTeamA = takeIntegerInput() - 1;
            if (PlayerIdTeamA < 0 || PlayerIdTeamA > 10) {
                cout << endl << "\t\t\tPlease Select From the Given Players" << endl << endl;
                goto TeamASelection;
            }  else if (!(validateSelectedPlayer(PlayerIdTeamA))) {
                cout << endl << "\t\t\tPlayer has been already selected. Please select other player." << endl << endl;
                goto TeamASelection;
                } else {
                cout << endl;
                teamAPlayers.name = player[PlayerIdTeamA];
                teamAPlayers.uniqueId = PlayerIdTeamA;
                teamA.players.push_back(teamAPlayers);
            }
            
            Player teamBPlayers;
            TeamBSelection:
            cout << "\t\t\tChoose Player " << i + 1 << " of " << teamB.name << ": ";
            int PlayerId = takeIntegerInput() - 1;
            if (PlayerId < 0 || PlayerId > 10) {
                cout << endl << "\t\t\tPlease Select From the Given Players." << endl << endl;
                goto TeamBSelection;
            } else if (!(validateSelectedPlayer(PlayerId))) {
                cout << endl << "\t\t\tPlayer has been already selected. Please select other player." << endl << endl;
                goto TeamBSelection;
            } else {
                cout << endl;
                teamBPlayers.name = player[PlayerId];
                teamBPlayers.uniqueId = PlayerId;
                teamB.players.push_back(teamBPlayers);
            }
        }
}

void Game::showTeamPlayers() {
    
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;
    
    cout << "\t\t\tDisplaying Selected Team..." << endl;
    //usleep(300000);
    
    cout << "\t\t\t-------------------------\t\t\t-------------------------" << endl;
    cout << "\t\t\t|\t" << teamA.name << "\t\t|\t\t\t|\t" << teamB.name << "\t\t|" << endl; 
    cout << "\t\t\t-------------------------\t\t\t-------------------------" << endl;
    for (int i = 0; i < playerPerTeam; i++) {
        cout << "\t\t\t[" << i+1 << "] " << teamAPlayers[i].name << "\t\t\t\t\t[" << i+1 << "] " << teamBPlayers[i].name << endl;
    }
    cout << "\t\t\t-------------------------\t\t\t-------------------------" << endl; 
}

void Game::toss() {
    
    cout << endl << endl << "\t\t\tPress Enter to Toss: ";
    cin.get();
    
    cout << endl << endl << "\t\t\t------------------------------------------------" << endl;
    cout << "\t\t\t==================Let's Toss====================" << endl;
    cout << "\t\t\t------------------------------------------------" << endl << endl;
    
    cout << "\t\t\tTosing the coin..." << endl << endl;
    //sleep(3);
    
    int randomValue;
    srand(time(NULL));
    randomValue = rand()%2;
    string selectedTeam;
    
    switch(randomValue) {
        case 0:
            cout << "\t\t\tTeam A won the toss." << endl << endl;
            tossChoice(teamA);
            break;
        case 1:
            cout << "\t\t\tTeam B won the toss." << endl << endl;
            tossChoice(teamB);
            break;
    }
}
void Game::tossChoice(Team tossWinnerTeam) {
    
    cout<<"\t\t\tEnter 1 to bat or 2 to bowl first."<<endl;
    cout<<"\t\t\t1. Bat"<<endl;
    cout<<"\t\t\t2. Bowl"<<endl;
    
    cout<<endl<<"\t\t\tInput: ";
    
    int tossInput = takeIntegerInput();
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    switch(tossInput) {
        case 1:
            cout<<endl<<"\t\t\t---------------------------------------------------------------";
            cout<<endl<<"\t\t\t\t"<<tossWinnerTeam.name<<" won the toss and decided to bat first."<<endl;
            cout<<"\t\t\t---------------------------------------------------------------"<<endl;
            if(tossWinnerTeam.name.compare("Team A") == 0) {
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            } else {
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
            
        case 2:
            cout<<endl<<"\t\t\t---------------------------------------------------------------";
            cout<<endl<<"\t\t\t\t"<<tossWinnerTeam.name<<" won the toss and decided to bowl first."<<endl;
            cout<<"\t\t\t---------------------------------------------------------------"<<endl;
            if(tossWinnerTeam.name.compare("Team B") == 0) {
                battingTeam = &teamA;
                bowlingTeam = &teamB;
            } else {
                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
        default:
            cout<<"\t\t\tInvalid Input. Please try again." <<endl<<endl;
            tossChoice(tossWinnerTeam);
            break;
    }
}

void Game::startFirstInning() {
    cout<<endl<<endl;
    cout<<"\t\t\tPress Enter to start first inning: ";
    cin.get();
    
    cout<<endl<<"\t\t\t---------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\tFIRST INNING STARTS"<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------"<<endl;
    isFirstInning = true;
    
    intializePlayers();
    playInning();
}
void Game::intializePlayers() {
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];
    
    cout<<endl;
    cout<<"\t\t\t"<<batsman->name<<" will Bat for "<<battingTeam->name<<endl;
    cout<<"\t\t\t"<<bowler->name<<" will Bowl for "<<bowlingTeam->name<<endl;
    
}
void Game::playInning() {
    for(int i=0;i<maxBalls;i++)
    {
    cout<<endl<<endl<<"\t\t\tPress Enter to bowl....";
    cin.get();
    
    cout<<"\t\t\t"<<bowler->name<<" bowling..."<<endl<<endl;
    bat();
    if(!validateInningsScore())
        break;
    }
}
void Game::bat() {
    srand(time(NULL));
    int runsScored = rand()%7;
    batsman->runsScored += runsScored;
    batsman->ballsPlayed += 1;
    battingTeam->totalRuns += runsScored;
    
    bowler->ballsBowled += 1;
    bowler->runsGiven += runsScored;
    bowlingTeam->totalBallBowled +=1;
    string pre;
    switch(bowlingTeam->totalBallBowled) {
        case 1:
            pre= "st";
            break;
        case 2:
            pre= "nd";
            break;
        case 3:
            pre= "rd";
            break;
        default:
            pre= "th";
            break;
    }
    if(runsScored != 0) {
        cout<<"\t\t\t"<<batsman->name<<" scored "<<runsScored;
        if(runsScored==1){
            cout<<" run on "<<bowlingTeam->totalBallBowled<<pre<<" ball";
        } else {
            cout<<" runs on "<<bowlingTeam->totalBallBowled<<pre<<" ball";
        }
        showGameScorecard();
    }else {
        cout<<"\t\t\t"<<batsman->name<<" OUT!";
        battingTeam->totalWicketsLost += 1;
        bowler->wicketsTaken += 1;
        showGameScorecard();
        int nextPlayerIndex = battingTeam->totalWicketsLost;
        batsman = &battingTeam->players[nextPlayerIndex];
        if(bowlingTeam->totalBallBowled!=6)
        cout<<"\t\t\tNext Batsman -> "<<batsman->name<<endl;
    }
}
bool Game::validateInningsScore() {
    if(isFirstInning){
        if(battingTeam->totalWicketsLost==playerPerTeam||bowlingTeam->totalBallBowled==maxBalls){
            cout<<endl<<endl<<"\t\t\t\t\t||| FIRST INNING ENDS |||"<<endl<<endl;
            cout<<"\t\t\tSUMMARY OF FIRST INNING: "<<endl;
            cout<<"\t\t\tBatting Team: "<<battingTeam->name<<endl;
            cout<<"\t\t\tTotal Runs Scored: "<<battingTeam->totalRuns<<endl;
            cout<<"\t\t\tWickets Lost: "<<battingTeam->totalWicketsLost<<endl;
            cout<<"\t\t\tNumber of Balls Played: "<<bowlingTeam->totalBallBowled<<endl;
            cout<<endl<<"\t\t\t-------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\t\t"<<bowlingTeam->name<<" needs "<<battingTeam->totalRuns+1<<" runs to win the match"<<endl;
            cout<<"\t\t\t-------------------------------------------------------------"<<endl;
            return false;
        }
    }else{
        if(battingTeam->totalWicketsLost==playerPerTeam||bowlingTeam->totalBallBowled==maxBalls||battingTeam->totalRuns>bowlingTeam->totalRuns){
            cout<<endl<<endl<<"\t\t\t\t\t    ||| SECOND INNING ENDS |||"<<endl<<endl;
            cout<<"\t\t\tSUMMARY OF SECOND INNING: "<<endl;
            cout<<"\t\t\tBatting Team: "<<battingTeam->name<<endl;
            cout<<"\t\t\tTotal Runs Scored: "<<battingTeam->totalRuns<<endl;
            cout<<"\t\t\tWickets Lost: "<<battingTeam->totalWicketsLost<<endl;
            cout<<"\t\t\tNumber of Balls Played: "<<bowlingTeam->totalBallBowled<<endl;
            return false;
        }
    }
    return true;
}
void Game::showGameScorecard() {
    cout<<endl<<"\t\t\t--------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<battingTeam->name<<"  "<<battingTeam->totalRuns<<" - "<<battingTeam->totalWicketsLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<batsman->name<<" "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<") \t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<endl;
    cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl;
}
void Game::startSecondInning() {
    cout<<endl<<endl;
    cout<<"\t\t\tPress Enter to start second inning: ";
    cin.get();
    
    cout<<endl<<"\t\t\t---------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\tSECOND INNING STARTS"<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------"<<endl;
    isFirstInning = false;
    
    if(battingTeam == &teamA) {
        battingTeam = &teamB;
        bowlingTeam = &teamA;
    } else {
        battingTeam = &teamA;
        bowlingTeam = &teamB;
    }
    intializePlayers();
    playInning();
    
    cout<<endl<<"\t\t\t\t\t\t||| MATCH ENDS |||"<<endl<<endl;
    
    cout<<"\t\t\tPress Enter to Display Winner: ";
    cin.get();
    cout<<"\t\t\t--------------------------------------------------------"<<endl; 
    if(battingTeam->totalRuns > bowlingTeam->totalRuns){
        cout<<"\t\t\t\t\t"<<battingTeam->name<<" WON THE MATCH"<<endl;
    } else {
        cout<<"\t\t\t\t\t"<<bowlingTeam->name<<" WON THE MATCH"<<endl;
    }
    cout<<"\t\t\t--------------------------------------------------------"<<endl<<endl<<endl;
    
    cout<<"\t\t\tPress Enter to Display Summary of Match: ";
    cin.get();
    
    cout<<endl<<"\t\t\t"<<battingTeam->name<<endl;
    cout<<"\t\t\t==================================================================="<<endl;
    cout<<"\t\t\t|  PLAYER\t\t\tBATTING\t\t\tBOWLING   |"<<endl;
    for(int i=0;i<playerPerTeam;i++) {
        batsman = &battingTeam->players[i];
        cout<<"\t\t\t|-----------------------------------------------------------------|"<<endl;
        if(i!=0){
            cout<<"\t\t\t|  ["<<i+1<<"] "<<batsman->name<<"\t\t\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed<<")\t\t\t"<<batsman->ballsBowled<<"-"<<batsman->runsGiven<<"-"<<batsman->wicketsTaken<<"     |"<<endl;
        } else {
            cout<<"\t\t\t|  ["<<i+1<<"] "<<batsman->name<<"\t\t\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed<<")\t\t\t"<<batsman->ballsBowled<<"-"<<batsman->runsGiven<<"-"<<batsman->wicketsTaken<<"    |"<<endl;
        }
    }
    cout<<"\t\t\t==================================================================="<<endl<<endl<<endl;
    
    cout<<"\t\t\t"<<bowlingTeam->name<<endl;
    cout<<"\t\t\t==================================================================="<<endl;
    cout<<"\t\t\t|  PLAYER\t\t\tBATTING\t\t\tBOWLING   |"<<endl;
    for(int i=0;i<playerPerTeam;i++) {
        batsman = &bowlingTeam->players[i];
        cout<<"\t\t\t|-----------------------------------------------------------------|"<<endl;
        if(i!=0){
            cout<<"\t\t\t|  ["<<i+1<<"] "<<batsman->name<<"\t\t\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed<<")\t\t\t"<<batsman->ballsBowled<<"-"<<batsman->runsGiven<<"-"<<batsman->wicketsTaken<<"     |"<<endl;
        } else {
            cout<<"\t\t\t|  ["<<i+1<<"] "<<batsman->name<<"\t\t\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed<<")\t\t\t"<<batsman->ballsBowled<<"-"<<batsman->runsGiven<<"-"<<batsman->wicketsTaken<<"    |"<<endl; 
        }
    }
    cout<<"\t\t\t==================================================================="<<endl<<endl<<endl;
}




