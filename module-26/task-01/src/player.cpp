#include "player.h"
#include <ctime>
#include <iomanip>
#include <string>

    /* Get name track */
    const std::string& Track::getName() const {
        return m_name;
    }  


    /* Get date track */
    const std::tm& Track::getDate() const {
        
        //const std::tm& strDate = //std::put_time(&m_date);  // std::to_string(m_date.tm_year) + "/" + std::to_string(m_date.tm_mon) + "/" + std::to_string(m_date.tm_mday);        

        return m_date;
    }


    /* Get duration track */
    const int& Track::getDuration() const {
        return m_duration;
    }



    /* Add */
    void Player::add(const Track& t){ 
        m_tracks.push_back(t);        
    }


    /* Play */
    void Player::play() {

        if (m_state == State::PLAY) {

          std::cout << "Player: State is play ["<<m_track.getName()<<"]"<<std::endl;
          
          return;
        }


        if (m_state == State::PAUSE) {

            m_state = State::PLAY;

            std::cout << "Track: "<< m_track.getName() << "state is play"<<std::endl;

            return;
        }
        
        std::cout << "Input name track: ";
        std::string name;
        std::cin >> name;

        /* Find Track*/
        for(const auto& it: m_tracks) {
            if (it.getName() == name) {

                m_state = State::PLAY;

                m_track = it;

                std::cout << "Player: Name: " << it.getName() << " Creater: " << std::put_time(&it.getDate(),"%Y/%m/%d") << " Duration: " << it.getDuration()<<std::endl;  
               
                std::cout << "Player: State is play ["<<m_track.getName()<<"]"<<std::endl;

                return;
            }   
        }

        /* Unknow track */
        std::cout << "Unknow track :(" << std::endl;

    }


    /* Pause */
    void Player::pause() {

        if (m_state != State::PLAY)
          return;

        m_state == State::PAUSE;

        std::cout << "Player: State is pause ["<<m_track.getName()<<"]"<<std::endl; 
    }


     /* Stop */
    void Player::stop() {

        if (m_state == State::STOP)
           return;
        
        m_state = State::STOP;

        std::cout << "Player: State is stop"<<std::endl; 
    }

    /* Next */
    void Player::next() {
        
        if (m_state == State::STOP)
           return;
        
        std::srand(time(nullptr));

        int id = rand() % m_tracks.size();

        m_track = m_tracks[id];
        
        m_state = State::PLAY;

        std::cout << "Player: Name: " << m_track.getName() << " Creater: " << std::put_time(&m_track.getDate(),"%Y/%m/%d") << " Duration: " << m_track.getDuration()<<std::endl;  

        std::cout << "Player: State is play ["<<m_track.getName()<<"]"<<std::endl;  

    }
