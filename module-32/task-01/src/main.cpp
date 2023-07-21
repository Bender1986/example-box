#include <iostream>
#include <fstream>

struct Film
{
    std::string name;
    std::string country;
    std::string date;
    std::string creater;
    std::string author;
    std::string director;
    std::string producer;
    std::string* character;
    std::string* actor;    
};

int main(int, char**){

    Film film = {.name = "Секретные материалы", .country = "США", .date = "10.09.1993", .creater = "Ten Thirteen Productions 20th Century Fox Television",
                .author = "Крис Картер", .director = "Крис Картер", .producer = "Крис Картер", 
                .character= new std::string[2]{"Данна Скалли", "Фокс Малдер"}, .actor = new std::string[2]{"Девид Духовны", "Джиллиан Андерсон"}};
    

    std::ofstream file("film.json");
    
    file << "{\n" 
            <<" \"name\":" << " \"" << film.name << "\",\n"
            <<" \"country\":" << " \"" <<  film.country << "\",\n"
            <<" \"date\":" << " \"" << film.date << "\",\n"
            <<" \"creater\":" << " \"" << film.creater << "\",\n"
            <<" \"author\":" << " \"" << film.author << "\",\n"
            <<" \"director\":" << " \"" << film.director << "\",\n"
            <<" \"producer\":" << " \"" << film.producer << "\",\n"
            <<" \"character\":\n" 
                <<" {\n"
                <<"  \"character1\":" << " \"" << film.character[0] << "\",\n"
                <<"  \"character2\":" << " \"" << film.character[1] << "\"\n"
                <<" } \n"
            <<" \"actor\":\n" 
                <<" { \n"
                <<"   \"actor1\":" << " \"" << film.actor[0] << "\",\n"
                <<"   \"actor2\":" << " \"" << film.actor[1] << "\"\n"
                <<" } \n"
        << "}";

    file.close();
}
