#pragma once
#include "database.hpp"

using namespace std;

// This is the callback statement which allows the tables to output their data




int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	std::vector<DBElement>* p_data = static_cast<std::vector<DBElement>*>(data);
	for (i = 0; i < argc; i++) {
		DBElement element;
		element.key = std::string(azColName[i]);

		element.value = std::string(argv[i]);

		p_data->push_back(element);

		
	}

	printf("\n");
	return 0;
};
	



sqlite3* createDatabase()
{
	sqlite3* db; //this allows the use of a database statement (db)
	//sqlite3_stmt* stmt; //a statement
	int rc = sqlite3_open("test", &db);  //This crates the database
	char* error;  //This crates the error message
 
	// this creates all the tables that are going to be used, with all the different columns
	rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS BABY (ID INTEGER PRIMARY KEY NOT NULL, name varchar(100), minQuant INT, nTakes INT, UNIQUE (name, minQuant, nTakes));" \
		"CREATE TABLE IF NOT EXISTS BIBERON(ID INTEGER PRIMARY KEY NOT NULL, QuantDrank INT, QuantBottle INT, baby varchar(100),  puke INT, hour INT , minutes INT);" \
		"CREATE TABLE IF NOT EXISTS LIST(MilkPowder INT, Water INT, MilkToBUY INT NOT NULL, WaterToBuy INT NOT NULL, UNIQUE (MilkPowder, Water, MilkToBuy, WaterToBuy));", NULL, NULL, &error);

	if (rc != SQLITE_OK) {
		cout << "error: " << error << "\n";  //This outputs the error message created in the tables
	}
	else {
		cout << "BABY, BIBERON and LIST created successfuly\n"; //this outputs that everything was created successfuly if there were no errors
	};

	return db;
}

	
std::vector<DBElement> dataFetch(sqlite3* db, const char* query) {

	char* error;
	std::vector<DBElement> data;
	int rc = sqlite3_exec(db, query, callback, &data, &error);
	if (rc != SQLITE_OK) {
		cout << "insert error 1: " << error << "\n"; //This outputs the error message
	}
	else {
		cout << "ok\n"; //this outputs that everything was created successfuly if there were no errors
	}

	return data;

}

void SQL(sqlite3* db, const char* sql) {
	char* error = 0;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &error);

	if (rc) {
		cerr << sql << "\n--> SQL error\n";
	}
	else {
		cout << sql << "\n--> SQL done !\n";
	}
}
			
	

	//query = string("INSERT INTO List('MilkPowder', 'Water', 'MilkToBUY', 'WaterToBuy') VALUES( ") + MilkPowder + "," + Water + "," + MilkToBuy + "," + WaterToBuy + "); ";

	
	