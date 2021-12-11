#include <iostream>
#include "Interfaces.h"
#include "Necro.h"
#include "Map.h"
#include <random>


namespace necro {
	//Alive enemy:


	bool Object::move(Lvl lvl, char way) {
		if (way == 'w' && this->y - 1 > -1 && lvl.field[this->x][this->y - 1].What_it < 2) {
			this->y -= 1;
			return true;
		}
		else if (way == 'd' && this->x + 1 < lvl.size_x && lvl.field[this->x + 1][this->y].What_it < 2) {
			this->x += 1;
			return true;
		}
		else if (way == 's' && this->y + 1 < lvl.size_y && lvl.field[this->x][this->y + 1].What_it < 2) {
			this->y += 1;
			return true;
		}
		else if (way == 'a' && this->x - 1 > -1 && lvl.field[this->x - 1][this->y].What_it < 2) {
			this->y -= 1;
			return true;
		}
		return false;
	}

	Coordinate Object::get_dateCO() {
		Coordinate coor;
		coor.x = this->x;
		coor.y = this->y;
		return coor;
	}
	void Object::set_dateCO(Coordinate data) {
		this->x = data.x;
		this->y = data.y;
	}

	void ICreature::set_dateC(Creature data) {
		this->fraction = data.fraction;
		this->max_health = data.max_health;
		this->real_health = data.real_health;
		this->name = data.name;
		this->level = data.level;
	}
	Creature ICreature::get_dateC() {
		Creature ret_data;
		ret_data.fraction = this->fraction;
		ret_data.level = this->level;
		ret_data.max_health = this->max_health;
		ret_data.name = this->name;
		ret_data.real_health = this->real_health;
		return ret_data;
	}


	Enemy::Enemy() {
		this->x = 0;
		this->y = 0;
		this->fraction = "";
		this->level = 0;
		this->max_health = 0;
		this->real_health = 0;
		this->name = "";
		this->chance_F = 0;
		this->damage = 0;
		this->status = 0;
		this->statusL = 0;
		this->type = "";
	}
	void Enemy::cause_dam(ICreature& Target) {
		Creature data_CT = Target.get_dateC();
		Coordinate data_COT = Target.get_dateCO();
		if ((this->x - data_COT.x) * (this->x - data_COT.x) + (this->y - data_COT.y) * (this->y - data_COT.y) == 1) {
			//random
			data_CT.real_health -= this->damage;
			Target.set_dateC(data_CT);
		}
		else {
			throw std::logic_error("");
		}

	}

	LEnemy::LEnemy() {
		this->x = 0;
		this->y = 0;
		this->fraction = "";
		this->level = 0;
		this->max_health = 0;
		this->name = "";
		this->real_health = 0;
		this->chance_F = 0;
		this->damage = 0;
		this->status = 0;
		this->statusL = 0;
		this->chance = 0;
		this->summoner = 0;
		this->type = "";
	}

	LEnemy::LEnemy(LEnemy& other) {
		//DLenemy_data help = other.get_data();
		//this->coor = other.coor;
		this->x = other.GetCooX();
		this->y = other.GetCooY();
		//this->cr_stats = other.cr_stats;
		this->fraction = other.GetCrFraction();
		this->max_health = other.GetCrM_health();
		this->real_health = other.GetCrR_health();
		this->name = other.GetCrName();
		this->level = other.GetCrLvl();
		//this->en_satas = other.en_satas;
		this->chance_F = other.GetEnemyCh();
		this->damage = other.GetEnemyDam();
		this->status = other.GetEnemySt();
		this->statusL = other.GetEnemyStL();
		this->type = other.GetEnemyType();
		//this->su_stats = other.su_stats;
		this->summoner = other.GetSummSu();
		this->chance = other.GetSumCh();
	}

	LEnemy::LEnemy(DLenemy_data basic_data) {
		this->fraction = basic_data.cr_stats.fraction;
		this->level = basic_data.cr_stats.level;
		this->max_health = basic_data.cr_stats.max_health;
		this->name = basic_data.cr_stats.name;
		this->real_health = basic_data.cr_stats.real_health;
		this->chance = basic_data.en_satas.chance;
		this->damage = basic_data.en_satas.damage;
		this->status = basic_data.en_satas.status;
		this->statusL = basic_data.statusL;
		this->chance = basic_data.su_stats.chance;
		this->summoner = basic_data.su_stats.summoner;
		this->type = basic_data.type;
		this->x = basic_data.coor_stats.x;
		this->y = basic_data.coor_stats.y;
	}
	DLenemy_data LEnemy::get_data() {
		DLenemy_data help;
		help.coor_stats.x = this->x;
		help.coor_stats.y = this->y;
		help.cr_stats.fraction = this->fraction;
		help.cr_stats.level = this->level;
		help.cr_stats.max_health = this->max_health;
		help.cr_stats.real_health = this->real_health;
		help.cr_stats.name = this->name;
		help.en_satas.chance = this->chance;
		help.en_satas.damage = this->damage;
		help.en_satas.status = this->status;
		help.statusL = this->statusL;
		help.su_stats.chance = this->chance;
		help.su_stats.summoner = this->summoner;
		help.type = this->type;
		return help;
	}
	void LEnemy::set_data(DLenemy_data data) {
		this->fraction = data.cr_stats.fraction;
		this->max_health = data.cr_stats.max_health;
		this->real_health = data.cr_stats.real_health;
		this->name = data.cr_stats.name;
		this->level = data.cr_stats.level;
		this->chance_F = data.en_satas.chance;
		this->damage = data.en_satas.damage;
		this->status = data.en_satas.status;
		this->statusL = data.statusL;
		this->chance = data.su_stats.chance;
		this->summoner = data.su_stats.summoner;
		this->type = data.type;
		this->x = data.coor_stats.x;
		this->y = data.coor_stats.y;
	}
	

	Coordinate LEnemy::death_cr() {
		this->real_health = this->max_health;
		this->statusL = 0;
		return this->get_dateCO();
	}
	LEnemy& LEnemy::operator = (LEnemy other) {
		//DLenemy_data help = other.get_data();
		//this->coor = other.coor;
		this->x = other.GetCooX();
		this->y = other.GetCooY();
		//this->cr_stats = other.cr_stats;
		this->fraction = other.GetCrFraction();
		this->max_health = other.GetCrM_health();
		this->real_health = other.GetCrR_health();
		this->name = other.GetCrName();
		this->level = other.GetCrLvl();
		//this->en_satas = other.en_satas;
		this->chance_F = other.GetEnemyCh();
		this->damage = other.GetEnemyDam();
		this->status = other.GetEnemySt();
		this->statusL = other.GetEnemyStL();
		this->type = other.GetEnemyType();
		//this->su_stats = other.su_stats;
		this->summoner = other.GetSummSu();
		this->chance = other.GetSumCh();
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
		if (random > this->chance * 10) {
			//action
		}
		return demon;
	}

	DEnemy::DEnemy() {
		this->x = 0;
		this->y = 0;
		this->fraction = "";
		this->level = 0;
		this->max_health = 0;
		this->name = "";
		this->real_health = 0;
		this->chance = 0;
		this->damage = 0;
		this->status = 0;
		this->statusL = 0;
		this->chance = 0;
		this->summoner = 0;
		this->type = "";
	}

	DEnemy::DEnemy(DEnemy& other) {
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
		this->summoner = other.GetSummSu();
		this->chance = other.GetSumCh();
	}

	DEnemy::DEnemy(DLenemy_data basic_data) {
		this->fraction = basic_data.cr_stats.fraction;
		this->level = basic_data.cr_stats.level;
		this->max_health = basic_data.cr_stats.max_health;
		this->name = basic_data.cr_stats.name;
		this->real_health = basic_data.cr_stats.real_health;
		this->chance = basic_data.en_satas.chance;
		this->damage = basic_data.en_satas.damage;
		this->status = basic_data.en_satas.status;
		this->statusL = basic_data.statusL;
		this->chance = basic_data.su_stats.chance;
		this->summoner = basic_data.su_stats.summoner;
		this->type = basic_data.type;
		this->x = basic_data.coor_stats.x;
		this->y = basic_data.coor_stats.y;
	}

	DLenemy_data DEnemy::get_data() {
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
		help.su_stats.chance = this->chance;
		help.su_stats.summoner = this->summoner;
		
		return help;
	}
	void DEnemy::set_data(DLenemy_data data) {
		this->fraction = data.cr_stats.fraction;
		this->max_health = data.cr_stats.max_health;
		this->real_health = data.cr_stats.real_health;
		this->name = data.cr_stats.name;
		this->level = data.cr_stats.level;
		this->chance_F = data.en_satas.chance;
		this->damage = data.en_satas.damage;
		this->status = data.en_satas.status;
		this->statusL = data.statusL;
		this->chance = data.su_stats.chance;
		this->summoner = data.su_stats.summoner;
		this->type = data.type;
		this->x = data.coor_stats.x;
		this->y = data.coor_stats.y;
	}

	DEnemy& DEnemy::operator = (DEnemy other) {
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
		this->summoner = other.GetSummSu();
		this->chance = other.GetSumCh();
		return *this;
	}
	Coordinate DEnemy::death_cr() {
		this->real_health = 0;
		this->max_health = -1;
		this->statusL = 0;
		return this->get_dateCO();
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
		if (random > this->chance * 10) {
			//action
		}
		return demon;
	}

	Slave Undead::get_data() {
		Slave ret_data;
		ret_data.can_I = this->can_I;
		ret_data.damage_kof = this->damage_kof;
		ret_data.fraction = this->fraction;
		ret_data.name = this->name;
		return ret_data;
	}
	void Undead::set_data(Slave data) {
		this->can_I = data.can_I;
		this->damage_kof = data.damage_kof;
		this->fraction = data.fraction;
		this->name = data.name;
	}
	DEnemy* Undead::become_slave(Creature Who, Enemy& Target) {
		if (this->can_I == true) {
			DLenemy_data stats;
			stats = Target.get_data();
			if (stats.statusL == 0 && stats.type == this->name) {
				stats.cr_stats.max_health /= this->damage_kof;
				stats.en_satas.damage /= this->damage_kof;
				Target.set_data(stats);
				return nullptr;
			}
			else {
				stats.cr_stats.name.erase(stats.cr_stats.name.length() - stats.type.length(), stats.type.length());
				stats.cr_stats.name += this->name;
				stats.en_satas.damage *= this->damage_kof;
				stats.cr_stats.max_health *= this->damage_kof;
				stats.cr_stats.fraction = Who.fraction;
				stats.type = this->name;
				stats.statusL = 0;

				DEnemy* Demon = new DEnemy;
				Demon->set_data(stats);
				return Demon;
			}
		}
	}
	void Undead::become_available() {
		this->can_I;
	}
	Undead::Undead() {
		this->can_I = 0;
		this->damage_kof = 0;
		this->fraction = "";
		this->name = "";
	}

	Undead::Undead(const Undead& other) {
		this->can_I = other.can_I;
		this->damage_kof = other.damage_kof;
		this->fraction = other.fraction;
		this->name = other.name;
	}

	Undead& Undead::operator = (const Undead other) {
		this->can_I = other.can_I;
		this->damage_kof = other.damage_kof;
		this->fraction = other.fraction;
		this->name = other.name;
		return *this;
	}
}