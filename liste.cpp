#include "liste.hpp"
#include <iostream>

Liste::Liste(sqlite3* db){ this->db = db;};

Liste::~Liste(){};

void Liste::buyPoudre(){
    int newValue = this->poudreDeLait + 780 * this->milkPackToBuy;
    this->poudreDeLait += 780 * this->milkPackToBuy;
        std::string sql = std::string(
			"UPDATE LIST "\
			"SET MilkPowder = "+ std::to_string(newValue) + ", " + "MilkToBUY = 0");
		SQL(this->db, sql.c_str());
    this->milkPackToBuy = 0;
};
void Liste::buyWater(){
    int newValue = this->mlEau + 1000 * this->waterBottlesToBuy;
    this->mlEau += 1000 * this->waterBottlesToBuy;
        std::string sql = std::string(
			"UPDATE LIST "\
			"SET Water = "+ std::to_string(newValue) + ", " + " waterToBuy = 0");
		SQL(this->db, sql.c_str());
    this->waterBottlesToBuy = 0;    
};
void Liste::addMilkToList(int number){
    int newValue = this->milkPackToBuy + number;
    this->milkPackToBuy += number;
        std::string sql = std::string(
			"UPDATE LIST "\
			"SET MilkToBUY = "+ std::to_string(newValue));
		SQL(this->db, sql.c_str());
};
void Liste::addWaterToList(int number){
    int newValue = this->waterBottlesToBuy + number;
    this->waterBottlesToBuy += number;
        std::string sql = std::string(
			"UPDATE LIST "\
			"SET WaterToBuy = "+ std::to_string(newValue));
		SQL(this->db, sql.c_str());
};

void Liste::setPowder(int number){
    this->poudreDeLait = number;
}
void Liste::setWater(int number){
    this->mlEau = number;

}

int Liste::getPowder(){return this->poudreDeLait;}
int Liste::getWater(){return this->mlEau;}