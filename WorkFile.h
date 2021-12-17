#ifndef WORKFILE
#define WORKFILE
#include <iostream>
#include <stdio.h>
#include <curses.h>
#include "Interfaces.h"
#include "Necro.h"
#include "Table.h"
#include "ConClass.h"
#include "Map.h"
namespace necro {

	void safe_NecroF(Necro_data, std::string); // Necro stats during the game;
	Necro_data get_NecroF(std::string fname); // get data from file;
	void safe_EnemyF(vector<DLenemy_data>, std::string); // Enemy stats during the game
	vector<DLenemy_data> get_EnemyF(std::string); // get data from file
	void safe_GolemF(vector<Golem_data>, std::string); // basic golem stats;
	vector<Golem_data> get_GolemF(std::string); // get data from file
	void safe_SlavesF(vector<Slave>, std::string); // slave stats during the game
	vector<Slave> get_SlavesF(std::string); // get data from file
	void safe_SpellF(vector<Spell>, std::string); // spell stats during the game
	vector<Spell> get_SpellF(std::string); // get data from file
	void safe_LvlF(Lvl lvl, std::string);
	Lvl get_LvlF(std::string);


	void write_cr(All_Creature fdata, FILE* f);
	All_Creature read_cr(FILE* f);



}
#endif