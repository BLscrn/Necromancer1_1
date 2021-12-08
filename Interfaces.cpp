#include <iostream>
#include "Interfaces.h"
#include "Necro.h"
#include "Map.h"
#include <random>


namespace necro {
	//Alive enemy:


	bool Object::move(Lvl lvl, char way) {
		if (way == 'w' && this->coor.y - 1 > -1 && lvl.field[this->coor.x][this->coor.y - 1].What_it < 2) {
			this->coor.y -= 1;
			return true;
		}
		else if (way == 'd' && this->coor.x + 1 < lvl.size_x && lvl.field[this->coor.x + 1][this->coor.y].What_it < 2) {
			this->coor.x += 1;
			return true;
		}
		else if (way == 's' && this->coor.y + 1 < lvl.size_y && lvl.field[this->coor.x][this->coor.y + 1].What_it < 2) {
			this->coor.y += 1;
			return true;
		}
		else if (way == 'a' && this->coor.x - 1 > -1 && lvl.field[this->coor.x - 1][this->coor.y].What_it < 2) {
			this->coor.y -= 1;
			return true;
		}
		return false;
	}

	Coordinate Object::get_dateCO() {
		return this->coor;
	}
	void Object::set_dateCO(Coordinate data) {
		this->coor = data;
	}

	void ICreature::set_dateC(Creature data) {
		this->cr_stats = data;
	}
	Creature ICreature::get_dateC() {
		Creature ret_data;
		ret_data = this->cr_stats;
		return ret_data;
	}


	Enemy::Enemy() {
		this->coor.x = 0;
		this->coor.y = 0;
		this->cr_stats.fraction = "";
		this->cr_stats.level = 0;
		this->cr_stats.max_health = 0;
		this->cr_stats.real_health = 0;
		this->cr_stats.name = "";
		this->en_satas.chance = 0;
		this->en_satas.damage = 0;
		this->en_satas.status = 0;
		this->statusL = 0;
		this->type = "";
	}
	void Enemy::cause_dam(ICreature& Target) {
		Creature data_CT = Target.get_dateC();
		Coordinate data_COT = Target.get_dateCO();
		if ((this->coor.x - data_COT.x) * (this->coor.x - data_COT.x) + (this->coor.y - data_COT.y) * (this->coor.y - data_COT.y) == 1) {
			//random
			data_CT.real_health -= this->en_satas.damage;
			Target.set_dateC(data_CT);
		}
		else {
			throw std::logic_error("");
		}

	}

	LEnemy::LEnemy() {
		this->coor.x = 0;
		this->coor.y = 0;
		this->cr_stats.fraction = "";
		this->cr_stats.level = 0;
		this->cr_stats.max_health = 0;
		this->cr_stats.name = "";
		this->cr_stats.real_health = 0;
		this->en_satas.chance = 0;
		this->en_satas.damage = 0;
		this->en_satas.status = 0;
		this->statusL = 0;
		this->su_stats.chance = 0;
		this->su_stats.summoner = 0;
		this->type = "";
	}

	LEnemy::LEnemy(LEnemy& other) {
		DLenemy_data help = other.get_data();
		this->coor = other.coor;
		this->cr_stats = other.cr_stats;
		this->en_satas = other.en_satas;
		this->statusL = other.statusL;
		this->su_stats = other.su_stats;
		this->type = other.type;
	}

	LEnemy::LEnemy(DLenemy_data basic_data) {
		this->cr_stats.fraction = basic_data.cr_stats.fraction;
		this->cr_stats.level = basic_data.cr_stats.level;
		this->cr_stats.max_health = basic_data.cr_stats.max_health;
		this->cr_stats.name = basic_data.cr_stats.name;
		this->cr_stats.real_health = basic_data.cr_stats.real_health;
		this->en_satas.chance = basic_data.en_satas.chance;
		this->en_satas.damage = basic_data.en_satas.damage;
		this->en_satas.status = basic_data.en_satas.status;
		this->statusL = basic_data.statusL;
		this->su_stats.chance = basic_data.su_stats.chance;
		this->su_stats.summoner = basic_data.su_stats.summoner;
		this->type = basic_data.type;
		this->coor = basic_data.coor_stats;
	}
	DLenemy_data LEnemy::get_data() {
		DLenemy_data help;
		help.coor_stats = this->coor;
		help.cr_stats = this->cr_stats;
		help.en_satas = this->en_satas;
		help.statusL = this->statusL;
		help.su_stats = this->su_stats;
		help.type = this->type;
		return help;
	}
	void LEnemy::set_data(DLenemy_data data) {
		this->cr_stats = data.cr_stats;
		this->en_satas = data.en_satas;
		this->statusL = data.statusL;
		this->su_stats = data.su_stats;
		this->type = data.type;
		this->coor = data.coor_stats;
	}
	

	Coordinate LEnemy::death_cr() {
		this->cr_stats.real_health = this->cr_stats.max_health;
		this->statusL = 0;
		return this->coor;
	}
	LEnemy& LEnemy::operator = (LEnemy other) {
		DLenemy_data help = other.get_data();
		this->coor = other.coor;
		this->cr_stats = other.cr_stats;
		this->en_satas = other.en_satas;
		this->statusL = other.statusL;
		this->su_stats = other.su_stats;
		this->type = other.type;
		return *this;
	}
	DLenemy_data LEnemy::Call_cr() {
		DLenemy_data demon;
		int random;
		auto gen_x = []() {
			static std::mt19937 rng{ std::random_device()() };
			static std::uniform_int_distribution<int> distr(1, 10);
			return distr(rng);
		};
		random = gen_x();
		if (random > this->su_stats.chance * 10) {
			//action
		}
		return demon;
	}

	DEnemy::DEnemy() {
		this->coor.x = 0;
		this->coor.y = 0;
		this->cr_stats.fraction = "";
		this->cr_stats.level = 0;
		this->cr_stats.max_health = 0;
		this->cr_stats.name = "";
		this->cr_stats.real_health = 0;
		this->en_satas.chance = 0;
		this->en_satas.damage = 0;
		this->en_satas.status = 0;
		this->statusL = 0;
		this->su_stats.chance = 0;
		this->su_stats.summoner = 0;
		this->type = "";
	}

	DEnemy::DEnemy(DEnemy& other) {
		DLenemy_data help = other.get_data();
		this->coor = other.coor;
		this->cr_stats = other.cr_stats;
		this->en_satas = other.en_satas;
		this->statusL = other.statusL;
		this->su_stats = other.su_stats;
		this->type = other.type;
	}

	DEnemy::DEnemy(DLenemy_data basic_data) {
		this->cr_stats.fraction = basic_data.cr_stats.fraction;
		this->cr_stats.level = basic_data.cr_stats.level;
		this->cr_stats.max_health = basic_data.cr_stats.max_health;
		this->cr_stats.name = basic_data.cr_stats.name;
		this->cr_stats.real_health = basic_data.cr_stats.real_health;
		this->en_satas.chance = basic_data.en_satas.chance;
		this->en_satas.damage = basic_data.en_satas.damage;
		this->en_satas.status = basic_data.en_satas.status;
		this->statusL = basic_data.statusL;
		this->su_stats.chance = basic_data.su_stats.chance;
		this->su_stats.summoner = basic_data.su_stats.summoner;
		this->type = basic_data.type;
		this->coor = basic_data.coor_stats;
	}

	DLenemy_data DEnemy::get_data() {
		DLenemy_data help;
		help.coor_stats = this->coor;
		help.cr_stats = this->cr_stats;
		help.en_satas = this->en_satas;
		help.statusL = this->statusL;
		help.su_stats = this->su_stats;
		help.type = this->type;
		return help;
	}
	void DEnemy::set_data(DLenemy_data data) {
		this->cr_stats = data.cr_stats;
		this->en_satas = data.en_satas;
		this->statusL = data.statusL;
		this->su_stats = data.su_stats;
		this->type = data.type;
		this->coor = data.coor_stats;
	}

	DEnemy& DEnemy::operator = (DEnemy other) {
		DLenemy_data help = other.get_data();
		this->coor = other.coor;
		this->cr_stats = other.cr_stats;
		this->en_satas = other.en_satas;
		this->statusL = other.statusL;
		this->su_stats = other.su_stats;
		this->type = other.type;
		return *this;
	}
	Coordinate DEnemy::death_cr() {
		this->cr_stats.real_health = 0;
		this->cr_stats.max_health = -1;
		this->statusL = 0;
		return this->coor;
	}
	DLenemy_data DEnemy::Call_cr() {
		DLenemy_data demon;
		int random;
		auto gen_x = []() {
			static std::mt19937 rng{ std::random_device()() };
			static std::uniform_int_distribution<int> distr(1, 10);
			return distr(rng);
		};
		random = gen_x();
		if (random > this->su_stats.chance * 10) {
			//action
		}
		return demon;
	}

	Slave Undead::get_data() {
		return this->Undead_stats;
	}
	void Undead::set_data(Slave data) {
		this->Undead_stats.can_I = data.can_I;
		this->Undead_stats.damage_kof = data.damage_kof;
		this->Undead_stats.fraction = data.fraction;
		this->Undead_stats.name = data.name;
	}
	DEnemy* Undead::become_slave(Creature Who, Enemy& Target) {
		if (this->Undead_stats.can_I == true) {
			DLenemy_data stats;
			stats = Target.get_data();
			if (stats.statusL == 0 && stats.type == this->Undead_stats.name) {
				stats.cr_stats.max_health /= this->Undead_stats.damage_kof;
				stats.en_satas.damage /= this->Undead_stats.damage_kof;
				Target.set_data(stats);
				return nullptr;
			}
			else {
				stats.cr_stats.name.erase(stats.cr_stats.name.length() - stats.type.length(), stats.type.length());
				stats.cr_stats.name += this->Undead_stats.name;
				stats.en_satas.damage *= this->Undead_stats.damage_kof;
				stats.cr_stats.max_health *= this->Undead_stats.damage_kof;
				stats.cr_stats.fraction = Who.fraction;
				stats.type = this->Undead_stats.name;
				stats.statusL = 0;

				DEnemy* Demon = new DEnemy;
				Demon->set_data(stats);
				return Demon;
			}
		}
	}
	void Undead::become_available() {
		this->Undead_stats.can_I;
	}
	Undead::Undead() {
		this->Undead_stats.can_I = 0;
		this->Undead_stats.damage_kof = 0;
		this->Undead_stats.fraction = "";
		this->Undead_stats.name = "";
	}

	Undead::Undead(const Undead& other) {
		this->Undead_stats.can_I = other.Undead_stats.can_I;
		this->Undead_stats.damage_kof = other.Undead_stats.damage_kof;
		this->Undead_stats.fraction = other.Undead_stats.fraction;
		this->Undead_stats.name = other.Undead_stats.name;
	}

	Undead& Undead::operator = (const Undead other) {
		this->Undead_stats.can_I = other.Undead_stats.can_I;
		this->Undead_stats.damage_kof = other.Undead_stats.damage_kof;
		this->Undead_stats.fraction = other.Undead_stats.fraction;
		this->Undead_stats.name = other.Undead_stats.name;
		return *this;
	}
}