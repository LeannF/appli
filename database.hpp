#pragma once
#include "sqlite/sqlite3.h"
#include <vector>
#include <iostream>
#include <string>
//#include <array>


struct DBElement {
	std::string key;
	std::string value;
};
int callback(void* data, int argc, char** argv, char** azColName);
std::vector<DBElement> dataFetch(sqlite3* db, const char* query);
void SQL(sqlite3* db, const char* sql);
sqlite3* createDatabase();