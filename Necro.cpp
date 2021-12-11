#include <iostream>
#include "Interfaces.h"
#include "Necro.h"

namespace necro {
	// Necromancer:
	Necromancer::Necromancer() {
		this->fraction = "Necromancer squad";//"Necromancer_squad";
		this->max_health = 100;
		this->name = "Necromancer";
		this->real_health = 100;
		this->x = 0;
		this->y = 0;
		this->assence = 0;
		this->exp = 0;
		this->level = 1;
		this->max_mana = 100;
		this->real_mana = 100;
	}
	Necromancer::Necromancer(Necro_data data) {
		this->fraction = data.cr_stats.fraction;
		this->max_health = data.cr_stats.max_health;
		this->name = data.cr_stats.name;
		this->real_health = data.cr_stats.real_health;
		this->x = data.coo_stats.x;
		this->y = data.coo_stats.y;
		this->assence = data.assence;
		this->exp = data.exp;
		this->level = data.cr_stats.level;
		this->max_mana = data.max_mana;
		this->real_mana = data.real_mana;
	}
	Necro_data Necromancer::get_data() {
		Necro_data ret_data;
		ret_data.cr_stats.fraction = this->fraction;
		ret_data.cr_stats.level = this->level;
		ret_data.cr_stats.max_health = this->max_health;
		ret_data.cr_stats.name = this->name;
		ret_data.cr_stats.real_health = this->real_health;
		ret_data.exp = this->exp;
		ret_data.max_mana = this->max_mana;
		ret_data.real_mana = this->real_mana;
		ret_data.assence = this->assence;
		ret_data.coo_stats.x = this->x;
		ret_data.coo_stats.y = this->y;
		return ret_data;
	}
	void Necromancer::set_data(Necro_data data) {
		this->fraction = data.cr_stats.fraction;
		this->level = data.cr_stats.level;
		this->max_health = data.cr_stats.max_health;
		this->name = data.cr_stats.name;
		this->real_health = data.cr_stats.real_health;
		this->assence = data.assence;
		this->exp = data.exp;
		this->max_mana = data.max_mana;
		this->real_mana = data.real_mana;
		this->x = data.coo_stats.x;
		this->y = data.coo_stats.y;
	}


	//Golem:
	Golem::Golem(Golem_data basic_data) {
		this->x = basic_data.coo_stats.x;
		this->y = basic_data.coo_stats.y;
		this->fraction = basic_data.cr_stats.fraction;
		this->level = basic_data.cr_stats.level;
		this->max_health = basic_data.cr_stats.max_health;
		this->name = basic_data.cr_stats.name;
		this->real_health = basic_data.cr_stats.real_health;
		this->ignore_damm = basic_data.ignore_damm;
		this->chance_F = basic_data.en_satas.chance;
		this->damage = basic_data.en_satas.damage;
		this->status = basic_data.en_satas.status;
		this->type = basic_data.type;
		this->statusL = 1;
	}
	Golem::Golem(Golem& other) {
		this->x = other.GetCooX();
		this->y = other.GetCooY();
		this->fraction = other.GetCrFraction();
		this->max_health = other.GetCrM_health();
		this->real_health = other.GetCrR_health();
		this->name = other.GetCrName();
		this->level = other.GetCrLvl();
		this->chance_F = other.GetEnemyCh();
		this->damage = other.GetEnemyDam();
		this->status = other.GetEnemySt();
		this->statusL = other.GetEnemyStL();
		this->type = other.GetEnemyType();
	}
	Golem& Golem::operator = (const Golem other) {
		this->y = other.y;
		this->x = other.x;
		this->name = other.name;
		this->damage = other.damage;
		this->chance_F = other.chance_F;
		this->fraction = other.fraction;
		this->ignore_damm = other.ignore_damm;
		this->level = other.level;
		this->statusL = other.statusL;
		this->type = other.type;
		this->max_health = other.max_health;
		this->real_health = other.real_health;
		this->status = other.status;
		return *this;
	}
	Golem_data Golem::get_dataG() {
		Golem_data help;
		help.coo_stats.x = this->x;
		help.coo_stats.y = this->y;
		help.cr_stats.fraction = this->fraction;
		help.cr_stats.level = this->level;
		help.cr_stats.max_health = this->max_health;
		help.cr_stats.real_health = this->real_health;
		help.cr_stats.name = this->name;
		help.en_satas.chance = this->chance_F;
		help.en_satas.damage = this->damage;
		help.en_satas.status = this->status;
		help.statusL = this->statusL;
		help.type = this->type;
		help.ignore_damm = this->ignore_damm;
		return help;
	}
	void Golem::set_dataG(Golem_data data) {
		this->fraction = data.cr_stats.fraction;
		this->max_health = data.cr_stats.max_health;
		this->real_health = data.cr_stats.real_health;
		this->name = data.cr_stats.name;
		this->level = data.cr_stats.level;
		this->chance_F = data.en_satas.chance;
		this->damage = data.en_satas.damage;
		this->status = data.en_satas.status;
		this->statusL = data.statusL;
		this->type = data.type;
		this->x = data.coo_stats.x;
		this->y = data.coo_stats.y;
		this->ignore_damm = data.ignore_damm;
	}

	DLenemy_data Golem::get_data() {
		DLenemy_data help;
		help.coor_stats.x = this->x;
		help.coor_stats.y = this->y;
		help.cr_stats.fraction = this->fraction;
		help.cr_stats.level = this->level;
		help.cr_stats.max_health = this->max_health;
		help.cr_stats.real_health = this->real_health;
		help.cr_stats.name = this->name;
		help.en_satas.chance = this->chance_F;
		help.en_satas.damage = this->damage;
		help.en_satas.status = this->status;
		help.statusL = this->statusL;
		help.type = this->type;
		return help;
	}
	void Golem::set_data(DLenemy_data data) {
		this->fraction = data.cr_stats.fraction;
		this->max_health = data.cr_stats.max_health;
		this->real_health = data.cr_stats.real_health;
		this->name = data.cr_stats.name;
		this->level = data.cr_stats.level;
		this->chance_F = data.en_satas.chance;
		this->damage = data.en_satas.damage;
		this->status = data.en_satas.status;
		this->statusL = data.statusL;
		this->type = data.type;
		this->x = data.coor_stats.x;
		this->y = data.coor_stats.y;
	}

}