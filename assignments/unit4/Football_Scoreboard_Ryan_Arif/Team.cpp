#include "Team.h"
#include <string>

using namespace std;

Team::Team(){
    name = "TEAM_NAME";
    coachName = "COACH_NAME";
    city = "CITY";
    homeStatus = false;
    score = 0;
    timeoutCount = 0;
}

Team::Team(std::string n, std::string cn, std::string ci, bool h){
    name = n;
    coachName = cn;
    city = ci;
    homeStatus = h;
    score = 0;
    timeoutCount = 0;
} 

//sets the name of the team
void Team::setName(string n)
{
    name = n;
}

//sets the coach's name of the team
void Team::setCoachName(string cn)
{
    coachName = cn;
}

//sets the city name for the team 
void Team::setCity(string ci)
{
    city = ci;
}

//sets the home status for the team
void Team::setHomeStatus(bool b)
{
    homeStatus = b;
}

//sets the score for the team
void Team::setScore(int i)
{
    score = i;
}

//sets the timeout count for the team
void Team::setTimeoutCount(int i)
{
    timeoutCount = i;
}

//gets the name of the team
string Team::getName() const
{
    return name;
}

//gets the coach's name for the team
string Team::getCoachName() const
{
    return coachName;
}

string Team::getCity() const
{
    return city;
}

//gets the home status for the team
bool Team::getHomeStatus() const
{
    return homeStatus;
}

//gets the score for the team
int Team::getScore() const
{
    return score;
} 

//gets the timeout count for the team
int Team::getTimeoutCount() const
{
    return timeoutCount;
}

//OVERLOADED OPERATORS

//overloaded increment operator (postfix)
//increments the score
Team Team::operator++(int)
{
    score++;
    return *this;
}

//overloaded decrement operator
//decrements the score
Team Team::operator--(int)
{
    score--;
    return *this;
}

// += operator
Team Team::operator+=(const Team& obj)
{
    this->score += obj.score;
    return *this;
}

//-= operator
Team Team::operator-=(const Team& obj)
{
    this->score -= obj.score;
    return *this;
}