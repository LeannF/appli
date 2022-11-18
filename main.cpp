#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "sqlite/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define SIZE 20
#define PAS 35

#include "biberon.hpp"
#include "window.hpp"
#include "Functions.hpp"
#include "text.hpp"
#include "image.hpp"
#include "database.cpp"
#include "database.hpp"
  
int myId = 0;
Baby makeBaby(sqlite3* db){
    const char* sql = "SELECT * FROM BABY";
	std::vector<DBElement> data = dataFetch(db, sql);

    string name;
    int minQuantity , nbTakes;
	bool existingBaby = data.size();

	if (existingBaby) {

		cout << "You already have a baby\n";
		minQuantity = stoi(data[2].value);
        cout << minQuantity; 
		nbTakes = stoi(data[3].value);
        cout << nbTakes;
		name = data[1].value;
        cout << name; 

	}
	else {
		cout << "Name ?";
		cin >> name;
		cout << "Minimum Quantity : ";
		cin >> minQuantity;
		cout << "How much takes ? ";
		cin >> nbTakes;


		std::string sql = std::string(
			"INSERT INTO BABY(name,minQuant,nTakes) "\
			"VALUES('" + name + "', " + std::to_string(minQuantity) + ", " + std::to_string(nbTakes) + ");");
		    SQL(db, sql.c_str()
        );
	}

	Baby baby(name, minQuantity, nbTakes);
	return baby;
}
void createList(sqlite3* db, Liste *maListe) {
	int milkPowder, water;

	const char* sql = "SELECT * FROM LIST";
	std::vector<DBElement> data = dataFetch(db, sql);


	bool existingList = data.size();
 
	if (existingList) {
		
        maListe->setPowder(stoi(data[0].value));
        maListe->setWater(stoi(data[1].value) );
		cout << "\nEnd of list";

	}
	else {
		cout << "Enter your stock of milk : ";
	    cin >> milkPowder;
        cout << "Enter your stock of water : ";
	    cin >> water;
        std::string sql = std::string(
			"INSERT INTO LIST(MilkPowder,Water, MilkToBUY, WaterToBuy) "\
			"VALUES(" + std::to_string(milkPowder) + ", " + std::to_string(water) +", 0, 0);");
		    SQL(db, sql.c_str()
        );

        
        maListe->setPowder(milkPowder);
        maListe->setWater(water);
	}

};

Biberon createBib(Baby baby, Liste* myList, sqlite3* db, int id) {
    id += 1;
	int quantity, bottleQuant,hour, minutes, interval;

	cout << "Enter the quantity drank : ";
	cin >> quantity;
    cout << "Enter the quantity put : ";
	cin >> bottleQuant;

	// cout << "Enter the interval for the alarm : ";
	// cin >> interval;

	Biberon bib(quantity, bottleQuant, baby, myList, db, id);

    cout << "Enter the hour : ";
	cin >> hour;
	cout << "Minutes : ";
	cin >> minutes;

    heure monHeure;
    monHeure.heure = hour;
    monHeure.minutes = minutes;
    bib.setHour(monHeure); 
 
    std::string sql = std::string(
        "INSERT INTO BIBERON(QuantDrank,QuantBottle,baby, puke, hour , minutes) "\
        "VALUES("+ std::to_string(quantity) + ", " + std::to_string(bottleQuant) + ", '" + baby.getName() + "', 0, " + std::to_string(hour) + ", " + std::to_string(minutes) + ");");
        SQL(db, sql.c_str()
    ); 

	return bib;   


}
int main(void) 
{ 
    sqlite3* db =  createDatabase();
    Baby baby = makeBaby(db);
    cout << "okkkk";
    Liste* maListe = new Liste(db);
    createList(db, maListe);

    Biberon bib1 = createBib(baby, maListe, db, myId);   // <-- Function to create a biberno 
    bib1.puked();
    // maListe->addWater(2); //<-- funciton to add water pack to the list 
    // maListe->buyWater(); // <-- function to buy water and to add the exact quantity to the stock


    // The stock get modified and it modify the db aswell. 
    MainWindow window;

    Uint32 frame_rate, frame_time, frame_delay = 20;
    window.init("Appli", 1920, 1080); // Creation de la fenetre 
    Text text(window.getRenderer(), "./font/Roboto/Roboto-Black.ttf", 30, "Data", {255, 255, 255, 255});

    Image image(window.getRenderer(), 120, 120, 100, 100, "./img/biberon.jpg");

    SDL_Event event;
    string inputText;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    SDL_StartTextInput();

    while(window.running() == true )
    {
       
        frame_rate = SDL_GetTicks();
        SDL_SetRenderDrawColor(window.getRenderer(), 46, 64, 83, 255); // Donne la couleur du render
        SDL_RenderClear(window.getRenderer());
        text.display(window.getRenderer());

        image.show(window.getRenderer());
        SDL_RenderPresent(window.getRenderer());

        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT ){             
                window.clean();
                break;
            }
            MouseKeyEvent(event, inputText, keystates);
        }
        

        frame_time = SDL_GetTicks() - frame_rate;
        if(frame_time < frame_delay){
            SDL_Delay( frame_delay - frame_time );
        }
    }
    
    return 0;
}

