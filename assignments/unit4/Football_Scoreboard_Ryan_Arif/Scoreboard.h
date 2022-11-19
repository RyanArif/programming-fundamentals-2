#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Team.h"

class Scoreboard{
    private: 
        Team homeTeam;
        Team awayTeam;
        int qtr;
        int down;
        int toGo;
        bool possession;
    public:
        //default constructor
        Scoreboard();       
        Scoreboard(Team &, Team &);

        //mutator functions
        void setHomeTeam(Team);
        void setAwayTeam(Team);
        void setQtr(int);
        void setDown(int);
        void setToGo(int);
        void setPosession(bool);
        //accessor functions
        Team getHomeTeam() const;
        Team getAwayTeam() const;
        int getQtr() const;
        int getDown() const;
        int getToGo() const;
        bool getPossession() const;
        
        //other functions
        void print();

};


#endif
