#include <iostream>
//#include "Enemy.h"
#include "Interfaces.h"
#include "Necro.h"
#include "Table.h"
#include "ConClass.h"
#include "WorkFile.h"
#include "ConClass.h"
#include <map>
#include <string>
#include "Map.h"
using namespace necro;
int main() {
	/*
	vector<DLenemy_data> Enemy_NG;
	vector<Golem_data> Golems;
	vector<Slave> Slaves;
	vector<Spell> Spells;
	std::map<std::string, ISpells<LEnemy>*> test;
	ISpells<LEnemy>* first_s = new desiccation;
	ISpells<LEnemy>* second_s = new curse;
	ISpells<LEnemy>* third_s = new necromancy;
	ISpells<LEnemy>* fourth_s = new morphism;
	Spells.push_back(first_s->get_data());
	Spells.push_back(second_s->get_data());
	Spells.push_back(third_s->get_data());
	Spells.push_back(fourth_s->get_data());
	safe_SpellF(Spells, "Spells.bin");
	Spells = get_SpellF("Spells.bin");

	test.insert(std::pair<std::string, ISpells<LEnemy>*>("desiccation", first_s));
	test.insert(std::pair<std::string, ISpells<LEnemy>*>("curse", second_s));
	test.insert(std::pair<std::string, ISpells<LEnemy>*>("necromancy", third_s));
	test.insert(std::pair<std::string, ISpells<LEnemy>*>("morphism", fourth_s));

	Level lvl1(10, 10);
	Lvl hlpL = lvl1.get_data();
	hlpL.field[2][4].What_it = 6;
	hlpL.field[3][3].What_it = 6;
	hlpL.field[4][3].What_it = 6;
	lvl1.set_data(hlpL);
	Coordinate begin;
	begin.x = 1;
	begin.y = 2;
	Coordinate end;
	end.x = 3;
	end.y = 4;
	lvl1.find_way(begin, end);
	safe_LvlF(lvl1.get_data(), "lvl1.bin");
	Level lvl12(get_LvlF("lvl1.bin"));
	Lvl help_lvl = lvl12.get_data();
	Field end1 = lvl12.get_data().field[3][4];

	Necromancer necr1;
	safe_NecroF(necr1.get_data(), "NecroF.bin");
	Necromancer necr2(get_NecroF("NecroF.bin"));


	//necromancy spel1;
	//morphism spel2;
	Slave cr_1;
	Undead cr1;
	Golem_data golem1;
	Golem_data golem_data;
	golem_data.coo_stats.x = 0;
	golem_data.coo_stats.y = 0;
	golem_data.cr_stats.fraction = "golem";
	golem_data.cr_stats.level = 1;
	golem_data.cr_stats.max_health = 150;
	golem_data.cr_stats.real_health = 150;
	golem_data.cr_stats.name = "Grock";
	golem_data.en_satas.chance = 100;
	golem_data.en_satas.damage = 40;
	golem_data.en_satas.status = 0;
	golem_data.ignore_damm = 30;
	golem_data.type = "stone";
	Golems.push_back(golem_data);
	safe_GolemF(Golems, "Golems.bin");
	Golems = get_GolemF("Golems.bin");

	cr_1.can_I = 1;
	cr_1.damage_kof = 0.2;
	cr_1.fraction = "Other";
	cr_1.name = "Gost";
	Slaves.push_back(cr_1);
	cr1.set_data(cr_1);
	Spell help = (test["necromancy"]->get_data());




	cr_1.can_I = 1;
	cr_1.damage_kof = 0.4;
	cr_1.fraction = "Other";
	cr_1.name = "Lesha";
	Slaves.push_back(cr_1);
	safe_SlavesF(Slaves, "Slaves.bin");
	Slaves = get_SlavesF("Slaves.bin");
	help.slaves.push_back(cr1);
	cr_1 = Slaves[1];
	cr1.set_data(cr_1);
	help.slaves.push_back(cr1);
	test["necromancy"]->set_date(help);
	test["morphism"]->set_date(help);

	Iterator<Undead> test_i(help.slaves.begin());
	Iterator<Undead> test_i1;
	test_i1 = help.slaves.end();
	std::cout << (test_i1 == test_i);
	++test_i;
	--test_i1;


	DLenemy_data mob_1;
	mob_1.cr_stats.fraction = "Holy orden";
	mob_1.cr_stats.level = 2;
	mob_1.cr_stats.max_health = 60;
	mob_1.cr_stats.name = "knight";
	mob_1.cr_stats.real_health = 60;
	mob_1.en_satas.chance = 60;
	mob_1.en_satas.damage = 60;
	mob_1.en_satas.status = 0;
	mob_1.statusL = 1;
	mob_1.su_stats.chance = 20;
	mob_1.su_stats.summoner = 0;
	mob_1.type = "";
	mob_1.coor_stats.x = 1;
	mob_1.coor_stats.y = 0;
	LEnemy mob1(mob_1);
	Enemy_NG.push_back(mob_1);
	mob_1.cr_stats.name = "Skeleton";
	mob_1.cr_stats.max_health = 100;
	mob_1.cr_stats.max_health = 100;
	mob_1.en_satas.chance = 100;
	mob_1.en_satas.damage = 100;
	mob_1.cr_stats.fraction = "Evil";
	Enemy_NG.push_back(mob_1);
	LEnemy mob2(mob_1);
	safe_EnemyF(Enemy_NG, "EnemyNG.bin");
	Enemy_NG = get_EnemyF("EnemyNG.bin");
	LEnemy  qwerty = Enemy_NG[1];

	try {
		mob1.cause_dam(necr1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		test["necromancy"]->make_mage(necr1, mob1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	//desiccation spel4;

	test["morphism"]->update_spell();
	//spel2.make_mage(necr1, mob1);
	//curse spel3;
	//spel2.make_mage(necr1, mob1);
	test["curse"]->update_spell();
	test["curse"]->update_spell();
	test["curse"]->update_spell();
	test["curse"]->update_spell();
	try {
		test["curse"]->make_mage(necr1, mob1);
		test["curse"]->make_mage(necr1, mob1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	if (mob1.get_dateC().real_health <= 0) {
		mob1.death_cr();
	}
	
	Necro_data data = necr1.get_data();
	data.real_mana = 100;
	necr1.set_data(data);
	try {
		test["necromancy"]->make_mage(necr1, mob1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	data = necr1.get_data();
	data.real_mana = 100;
	necr1.set_data(data);

	try {
		test["morphism"]->make_mage(necr1, mob1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	*/
	return 0;
}