#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ctime>
#include <vector>

class Track {

    private:
    
    std::string m_name;
    std::tm     m_date;
    int         m_duration;
    
    public: 
    
    Track(std::string name = "NoName", std::tm date = tm{}, int durarion = 0): 
         m_name{name}, m_date{date}, m_duration{durarion}   { 
    }

    /* Get name track */
    const std::string& getName() const;


    /* Get date track */
    const std::tm& getDate() const;


    /* Get duration track */
    const int& getDuration() const;

};



/* Player */
class Player {

    private: 
    std::vector<Track> m_tracks;
    Track m_track;
    

    public:

    enum State {

        PLAY = 1,
        PAUSE = 2,
        STOP = 3
    }; 
    
    private:
    State m_state = State::STOP;


    public:
    Player() {
        
    }

    /* Add */
    void add(const Track& t);

    /* Play */
    void play(); 

    /* Pause */
    void pause(); 

     /* Stop */
    void stop(); 

    /* Next */
    void next();    


};

#endif