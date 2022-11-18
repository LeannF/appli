#include <string>
class Baby
{
    public:
    Baby();
    ~Baby();
    Baby(std::string, int, int);
    int getMinQuant();
    int getNbTakes();
    int getGoalQuantity();
    std::string getName();


    private:
        int minQuantity; // the minimum quantity that our baby drinks
        int nbTakes; // how much takes per day (to calculate the goalQuantity per Day and )
        int goalQuantity; // how much milk per day you would like your baby to drink
        std::string babyName;
        

};      