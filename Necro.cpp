#include <iostream>
#include "Interfaces.h"
#include "Necro.h"

namespace necro {
	// Necromancer:
	Necromancer::Necromancer() {
		this->cr_stats.fraction = "Necromancer squad";//"Necromancer_squad";
		this->cr_stats.max_health = 100;
		this->cr_stats.name = "Necromancer";
		this->cr_stats.real_health = 100;
		this->coor.x = 0;
		this->coor.y = 0;
		this->assence = 0;
		this->exp = 0;
		this->cr_stats.level = 1;
		this->max_mana = 100;
		this->real_mana = 100;
	}
	Necromancer::Necromancer(Necro_data data) {
		this->cr_stats.fraction = data.cr_stats.fraction;
		this->cr_stats.max_health = data.cr_stats.max_health;
		this->cr_stats.name = data.cr_stats.name;
		this->cr_stats.real_health = data.cr_stats.real_health;
		this->coor.x = data.coo_stats.x;
		this->coor.y = data.coo_stats.y;
		this->assence = data.assence;
		this->exp = data.exp;
		this->cr_stats.level = data.cr_stats.level;
		this->max_mana = data.max_mana;
		this->real_mana = data.real_mana;
	}
	Necro_data Necromancer::get_data() {
		Necro_data ret_data;
		ret_data.cr_stats = this->cr_stats;
		ret_data.exp = this->exp;
		ret_data.max_mana = this->max_mana;
		ret_data.real_mana = this->real_mana;
		ret_data.assence = this->assence;
		ret_data.coo_stats = this->coor;
		return ret_data;
	}
	void Necromancer::set_data(Necro_data data) {
		this->cr_stats = data.cr_stats;
		this->assence = data.assence;
		this->exp = data.exp;
		this->cr_stats.level = data.cr_stats.level;
		this->max_mana = data.max_mana;
		this->real_mana = data.real_mana;
		this->coor = data.coo_stats;
	}


	//Golem:

	Golem_data Golem::get_data() {
		Golem_data ret_data;
		ret_data.cr_stats = this->cr_stats;
		ret_data.en_satas = this->en_satas;
		ret_data.ignore_damm = this->ignore_damm;
		ret_data.type = this->type;
		ret_data.coo_stats = this->coor;
		return ret_data;
	}
	void Golem::set_data(Golem_data data) {
		this->cr_stats = data.cr_stats;
		this->en_satas = data.en_satas;
		this->ignore_damm = data.ignore_damm;
		this->type = data.type;
		this->coor = data.coo_stats;
	}

}