#include <iostream>
#include <memory>
#include "dog.h"
#include "toy.h"

int main()
{
    Dog dog1("Bim");
    Dog dog2("Tuzik");
    Dog dog3("Noname");

    std::shared_ptr<Toy> toy = std::make_shared<Toy>("Bone");

    dog1.GetToy(toy);
    dog2.GetToy(toy);

    dog2.GetToy(toy);

    dog1.DropToy();
    dog3.DropToy();

    return 0;
}