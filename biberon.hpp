#include "baby.hpp"
#include "liste.hpp"
#include <iostream>
#include "database.hpp"
struct heure{
    int heure;
    int minutes;
};

class Biberon
{
    private:

    heure heureDePrise; // the hour where the bottle is taken

    Baby myBaby; // the baby who associated to this bottle
    int drankQuantity; // what he drank
    int bottleQuant;
    bool puke; // did he puke?
    int timer;
    int id;
    sqlite3* db;


    public:

    Biberon();
    Biberon(int drankQuantity, int bottleQuant, Baby myBaby, Liste* myList, sqlite3* db, int id);
    ~Biberon();

    void setTimer(int); //set interval
    void puked(); // set puke to true if the baby puked
    void setHour(heure); // set hour
    void showDrankQuantity(); // set quantity drank
    Baby getBaby(); // 
    Liste getListe();





};