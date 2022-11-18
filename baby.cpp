#include "baby.hpp"

Baby::Baby()
{

}

Baby::~Baby(){}

Baby::Baby(std::string name, int minQuant, int nbTakes)
{

    this->babyName = name;
    this->minQuantity =minQuant ;
   
    this->nbTakes = nbTakes;
    this->goalQuantity = minQuant * nbTakes;

}

int Baby::getMinQuant(){
    return this->minQuantity;
}



int Baby::getNbTakes(){
    return this->nbTakes;
}

int Baby::getGoalQuantity(){
    return this->goalQuantity;
}

std::string Baby::getName(){
    return this->babyName;
}
