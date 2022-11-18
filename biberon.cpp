
#include <iostream>
#include "biberon.hpp"



Biberon::Biberon(){
    std::cout << "ok created";
    this->puke = false;
}

Biberon::Biberon(int drankQuantity, int bottleQuant, Baby myBaby, Liste* myList, sqlite3* db, int id){
    this->drankQuantity = drankQuantity;
    this->myBaby = myBaby;
    this->bottleQuant = bottleQuant;
    this->id = id;

    int newPowder = myList->getPowder() - bottleQuant * 15/100;
    int newWater = myList->getWater() - bottleQuant;
    myList->setPowder(newPowder);
    myList->setWater(newWater);

    std::string sql = std::string(
			"UPDATE LIST "\
			"SET MilkPowder = " + std::to_string(newPowder) + ", Water = " + std::to_string(newWater) +"");
		SQL(db, sql.c_str());


    std::cout << myList->getWater() << std::endl;
    std::cout << myList->getPowder() << std::endl; 
  
}


Biberon::~Biberon(){}

void Biberon::puked(){
    this->puke = false;
    // std::string sql = std::string(
	// 		"UPDATE BIBERON "\
	// 		"SET puke = '"+ std::to_string(1) + "' WHERE ID = " + std::to_string(this->id));
	// 	SQL(this->db, sql.c_str());
}


void Biberon::setHour(heure heureDePrise)
{
    this->heureDePrise = heureDePrise;
    std::cout << "Biberon prit a  " << heureDePrise.heure << "h" << heureDePrise.minutes << std::endl;
}
void Biberon::setTimer(int time){
    this->timer = time;
}

Baby Biberon::getBaby(){return this->myBaby;}