#include "database.hpp"


class Liste
{
    private:

        int poudreDeLait; //stock
        int mlEau;

        int milkPackToBuy = 0;
        int waterBottlesToBuy = 0;
        sqlite3* db; 
    
    public:

        Liste(sqlite3* db);
        ~Liste();
        void buyPoudre();
        void buyWater();
        void addMilkToList(int);
        void addWaterToList(int);
    
        void setPowder(int number);
        void setWater(int number);
        int getPowder();
        int getWater();
        // void addProduct(char);

};
