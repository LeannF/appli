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
    int quantityPut; // What I put in my bottle
    
    
    
    public:

    Biberon();
    Biberon(int drankQuantity, int bottleQuant, Baby myBaby, Liste* myList, sqlite3* db);
    ~Biberon();
    
    void puked();
    void setHour(heure);
    void showDrankQuantity();
    Baby getBaby();
    Liste getListe();
    

    
    

};