#include <iostream>
#include "Interfaces.h"
#include "Table.h"
#include "Necro.h"
//#include "Enemy.h"
#include <stdexcept>




namespace necro {

	desiccation::desiccation() {
		this->stats.level = 1;
		this->stats.name = "Desiccation";
	}
	Spell desiccation::get_data() {
		Spell ret_data;
		ret_data = this->stats;
		return ret_data;
	}
	void desiccation::set_date(Spell data) {
		this->stats = data;
	}
	void desiccation::update_spell() {
		this->stats.level++;
	}
	void desiccation::make_mage(Necromancer& Necro, Enemy*& Target) {
		if (Target->get_dateC().real_health > 0 && Target->get_data().statusL == 0) {
			int ch;
			const char* ch1[] = {
				"1.Desiccate the corpe(Health):",
				"2.Devour the soul(Mana):"
			};
			for (int i = 0; i < 2; i++) {
				std::cout << ch1[i] << std::endl;
			}
			get_number(ch, "Make choice:");

			Necro_data stats1 = Necro.get_data();
			if (stats1.real_mana - (40 - 40 * (0.1 * this->stats.level)) < 0) {
				throw std::logic_error("not enought mana");
				
			}
			stats1.real_mana -= (40 - 40 * (0.1 * this->stats.level));
			Necro.set_data(stats1);
			if (ch == 1) {
				Creature stats;
				stats = Necro.get_dateC();

				stats.real_health = (Target->get_dateC().max_health * (this->stats.level) / 10 + 5 * Target->get_dateC().level) + stats.real_health
			> stats.max_health ? stats.max_health : (Target->get_dateC().max_health * (this->stats.level) / 10 + 5 * Target->get_dateC().level) + stats.real_health;
				Necro.set_dateC(stats);
			}
			else if (ch == 2) {
				Necro_data stats = Necro.get_data();
				stats.real_mana = (Target->get_dateC().max_health * (this->stats.level) / 10 + 5 * Target->get_dateC().level) + stats.real_mana
			> stats.max_mana ? stats.max_mana : (Target->get_dateC().max_health * (this->stats.level) / 10 + 5 * Target->get_dateC().level) + stats.real_mana;
				Necro.set_data(stats);

			}
			DLenemy_data data = Target->get_data();
			data.statusL = 0;
			data.cr_stats.max_health = -1;
			Target->set_data(data);

		}
		else {
			throw std::logic_error("Enemy is alive");
		}
		// try exept;

	}



	curse::curse() {
		this->stats.level = 1;
		this->stats.name = "Curse";
	}
	Spell curse::get_data() {
		Spell ret_data;
		ret_data = this->stats;
		return ret_data;
	}
	void curse::set_date(Spell data) {
		this->stats = data;
	}
	void curse::update_spell() {
		this->stats.level++;
	}
	void curse::make_mage(Necromancer& Necro, Enemy*& Target) {
		Necro_data stats = Necro.get_data();
		if (stats.real_mana - (40 - 40 * (0.1 * this->stats.level)) < 0) {
			throw std::logic_error("not enought mana");
		}
		stats.real_mana -= (40 - 40 * (0.1 * this->stats.level));

		Creature stats1 = Target->get_dateC();
		stats1.real_health -= 10 * (this->stats.level) + (this->stats.level);
		Target->set_dateC(stats1);
		Necro.set_data(stats);
	}




	necromancy::necromancy() {
		this->stats.level = 1;
		this->stats.name = "Necromancy";

	}
	Spell necromancy::get_data() {
		Spell ret_data;
		ret_data = this->stats;
		return ret_data;
	}
	void necromancy::set_date(Spell data) {
		//this->stats = data;
		this->stats.level = data.level;
		this->stats.name = data.name;
		this->stats.slaves = data.slaves;
	}
	void necromancy::update_spell() {
		this->stats.level++;
	}

	void necromancy::make_mage(Necromancer& Necro, Enemy*& Target) {
		int ch;
		Enemy* ret_enemy = nullptr;
		for (int i = 0; i < this->stats.slaves.getlen(); i++) {
			std::cout << i + 1 << ". " << this->stats.slaves[i].get_data().name << " " << this->stats.slaves[i].get_data().can_I << std::endl;
		}
		get_number(ch, "Chouse type: ");
		if (this->stats.slaves[ch - 1].get_data().can_I == 0) {
			throw std::logic_error("You can't use this slave");
		}
		if (Target->get_data().statusL == 1) {
			throw std::logic_error("Enemy is alive");

		}
		Necro_data stats = Necro.get_data();
		if (stats.real_mana - (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->stats.level + this->stats.level) < 0) {
			throw std::logic_error("not enought mana");
		}
		stats.real_mana -= (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->stats.level + this->stats.level < 0);
		ret_enemy = this->stats.slaves[ch - 1].become_slave(Necro.get_dateC(), *(Target));
		delete Target;
		Target = ret_enemy;
		Necro.set_data(stats);
	}
	morphism::morphism() {
		this->stats.level = 1;
		this->stats.name = "Morphism";
	}
	Spell morphism::get_data() {
		Spell ret_data;
		ret_data = this->stats;
		return ret_data;
	}
	void morphism::set_date(Spell data) {
		this->stats = data;
	}
	void morphism::update_spell() {
		this->stats.level++;
	}

	void morphism::make_mage(Necromancer& Necro, Enemy*& Target) {
		int ch1;
		for (int i = 0; i < this->stats.slaves.getlen(); i++) {
			std::cout << i + 1 << ". " << this->stats.slaves[i].get_data().name << " " << this->stats.slaves[i].get_data().can_I << std::endl;
		}
		get_number(ch1, "Chouse type: ");
		if (this->stats.slaves[ch1 - 1].get_data().can_I == 0) {
			throw std::logic_error("You can't use this slave");

		}
		if (Target->get_data().statusL == 1) {
			throw std::logic_error("Enemy is alive");

		}
		if (!check_access(Target->get_data().type)) {
			throw std::logic_error("You can't transform to this type");

		}
		if (this->stats.slaves[ch1 - 1].get_data().name == Target->get_data().type) {
			throw std::logic_error("You can't tranform to the same type");

		}
		Necro_data stats = Necro.get_data();
		if (stats.real_mana - (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->stats.level + this->stats.level) < 0) {
			throw std::logic_error("not enought mana");

		}

		stats.real_mana -= (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->stats.level + this->stats.level < 0);
		for (int i = 0; i < this->stats.slaves.getlen(); i++) {
			if (this->stats.slaves[i].get_data().name == Target->get_data().type) {
				this->stats.slaves[i].become_slave(Target->get_dateC(), *Target);
			}
		}
		DEnemy* ret_enemy = nullptr;
		ret_enemy = this->stats.slaves[ch1 - 1].become_slave(Target->get_dateC(), *Target);
		delete Target;
		Target = ret_enemy;
		Necro.set_data(stats);

	}
	bool morphism::check_access(std::string type) {
		for (int i = 0; i < this->stats.slaves.getlen(); i++) {
			if (this->stats.slaves[i].get_data().name == type && this->stats.slaves[i].get_data().can_I == 1) {
				return true;
			}
		}
		return false;
	}




}