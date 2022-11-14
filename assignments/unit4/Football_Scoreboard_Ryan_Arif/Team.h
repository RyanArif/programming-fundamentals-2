// Specification file for Team class
#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team{
    private:
    std::string name;
    std::string coachName;
    bool homeStatus;
    int score;
    int timeoutCount;
    public:
        //default constructor
        Team(){
            name = "TEAM_NAME";
            coachName = "COACH_NAME";
            homeStatus = false;
            score = 0;
            timeoutCount = 0;
        }
        //alternative constructor
        Team(std::string n, std::string c, bool h){
            name = n;
            coachName = c;
            homeStatus = h;
            score = 0;
            timeoutCount = 0;
        }
        //mutators
        void setName(std::string);
        void setCoachName(std::string);
        void setHomeStatus(bool);
        void setScore(int);
        void setTimeoutCount(int);
        //accessors
        std::string getName() const;
        std::string getCoachName() const;
        bool getHomeStatus() const;
        int getScore() const;
        int getTimeoutCount() const;
        
        //overloaded operators
        Team operator++(int);
        Team operator--(int);
        Team operator+=(const Team&);
        Team operator-=(const Team&);
};

#endif
