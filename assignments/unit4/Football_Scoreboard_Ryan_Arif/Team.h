// Specification file for Team class
#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team{
    private:
    std::string name;
    std::string coachName;
    std::string city;
    bool homeStatus;
    int score;
    int timeoutCount;
    public:
        Team();
        Team(std::string n, std::string cn, std::string ci, bool h);

        //mutators
        void setName(std::string);
        void setCoachName(std::string);
        void setCity(std::string);
        void setHomeStatus(bool);
        void setScore(int);
        void setTimeoutCount(int);
        //accessors
        std::string getName() const;
        std::string getCoachName() const;
        std::string getCity() const;
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
