#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "player.h"



int main(int, char**) {

    std::istringstream s1("2021/01/12");
    std::tm tm1 = {};   
    s1>>std::get_time(&tm1, "%Y/%m/%d");

    std::istringstream s2("2021/02/10");
    std::tm tm2 = {};   
    s2>>std::get_time(&tm2, "%Y/%m/%d");

    std::istringstream s3("2021/03/23");
    std::tm tm3 = {};   
    s3>>std::get_time(&tm3, "%Y/%m/%d");


    Track t1 = {"track1", tm1, 100};
    Track t2 = {"track2", tm2, 120};
    Track t3 = {"track3", tm3, 300};


    Player player;
    player.add(t1);
    player.add(t2);
    player.add(t3);


    std::string command;

    while (command != "exit")
    {
        std::cout<<"Input command (play, pause, next, stop, exit): ";
        std::cin >> command;

        if (command == "exit")
           return 0;

        if (command == "play") {
            player.play();
            continue;
        }

        if (command == "stop") {
            player.stop();
            continue;
        }

        if (command == "pause") {
            player.pause();
            continue;
        }

         if (command == "next") {
            player.next();
            continue;
        }

        std::cout << "Unknow input command"<<std::endl;

    }  


   
    return 0;
    

}
