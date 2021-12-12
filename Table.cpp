#include <iostream>
#include "Interfaces.h"
#include "Table.h"
#include "Necro.h"
#include <stdexcept>




namespace necro {

	desiccation::desiccation() {
		this->level = 1;
		this->name = "Desiccation";
	}
	Spell desiccation::get_data() {
		Spell ret_data;
		ret_data.level = this->level;
		ret_data.name = this->name;
		ret_data.slaves = this->slaves;
		return ret_data;
	}
	void desiccation::set_date(Spell data) {
		this->level = data.level;
		this->name = data.name;
		this->slaves = data.slaves;
	}
	void desiccation::update_spell() {
		this->level++;
	}
	void desiccation::make_mage(Necromancer& Necro, Enemy*& Target) {
		if (Target->GetCrR_health() > 0 && Target->GetEnemyStL() == 0) {
			int ch;
			const char* ch1[] = {
				"1.Desiccate the corpe(Health):",
				"2.Devour the soul(Mana):"
			};
			for (int i = 0; i < 2; i++) {
				std::cout << ch1[i] << std::endl;
			}
			get_number(ch, "Make choice:");

			//Necro_data stats1 = Necro.get_data();
			if (Necro.GetNecrR_mana() - (40 - 40 * (0.1 * this->level)) < 0) {
				throw std::logic_error("not enought mana");
				
			}
			Necro.SetNecrR_mana(Necro.GetNecrR_mana() - (40 - 40 * (0.1 * this->level)));
			//Necro.set_data(stats1);
			if (ch == 1) {
				//Creature stats;
				//stats = Necro.get_dateC();
				Necro.GetCrM_health();
				//Necro.SetCrR_health();
				Necro.SetCrR_health((Target->GetCrM_health() * (this->level) / 10 + 5 * Target->GetCrLvl()) + Necro.GetCrR_health()
			> Necro.GetCrM_health() ? Necro.GetCrM_health() : (Target->GetCrM_health() * (this->level) / 10 + 5 * Target->GetCrLvl()) + Necro.GetCrR_health());
				//Necro.set_dateC(stats);
			}
			else if (ch == 2) {
				Necro_data stats = Necro.get_data();
				stats.real_mana = (Target->get_dateC().max_health * (this->level) / 10 + 5 * Target->get_dateC().level) + stats.real_mana
			> stats.max_mana ? stats.max_mana : (Target->get_dateC().max_health * (this->level) / 10 + 5 * Target->get_dateC().level) + stats.real_mana;
				Necro.set_data(stats);

			}
			//DLenemy_data data = Target->get_data();
			//data.statusL = 0;
			Target->SetEnemyStL(0);
			//data.cr_stats.max_health = -1;
			Target->SetEnemyStL(-1);
			//Target->set_data(data);

		}
		else {
			throw std::logic_error("Enemy is alive");
		}
		// try exept;

	}



	curse::curse() {
		this->level = 1;
		this->name = "Curse";
	}
	Spell curse::get_data() {
		Spell ret_data;
		ret_data.level = this->level;
		ret_data.name = this->name;
		ret_data.slaves = this->slaves;
		return ret_data;
	}
	void curse::set_date(Spell data) {
		this->level = data.level;
		this->name = data.name;
		this->slaves = data.slaves;
	}
	void curse::update_spell() {
		this->level++;
	}
	void curse::make_mage(Necromancer& Necro, Enemy*& Target) {
		//Necro_data stats = Necro.get_data();
		if (Necro.GetNecrR_mana() - (40 - 40 * (0.1 * this->level)) < 0) {
			throw std::logic_error("not enought mana");
		}
		//stats.real_mana -= (40 - 40 * (0.1 * this->level));
		Necro.SetNecrR_mana(Necro.GetNecrR_mana() - (40 - 40 * (0.1 * this->level)));
		//Creature stats1 = Target->get_dateC();
		//stats1.real_health -= 10 * (this->level) + (this->level);
		Target->SetCrR_health(Target->GetCrR_health() - 10 * (this->level) + (this->level));
		//Target->set_dateC(stats1);
		//Necro.set_data(stats);
	}




	necromancy::necromancy() {
		this->level = 1;
		this->name = "Necromancy";

	}
	Spell necromancy::get_data() {
		Spell ret_data;
		ret_data.level = this->level;
		ret_data.name = this->name;
		ret_data.slaves = this->slaves;
		return ret_data;
	}
	void necromancy::set_date(Spell data) {
		this->level = data.level;
		this->name = data.name;
		this->slaves = data.slaves;
	}
	void necromancy::update_spell() {
		this->level++;
	}

	void necromancy::make_mage(Necromancer& Necro, Enemy*& Target) {
		int ch;
		Enemy* ret_enemy = nullptr;
		for (int i = 0; i < this->slaves.getlen(); i++) {
			std::cout << i + 1 << ". " << this->slaves[i].get_data().name << " " << this->slaves[i].get_data().can_I << std::endl;
		}
		get_number(ch, "Chouse type: ");
		if (this->slaves[ch - 1].get_data().can_I == 0) {
			throw std::logic_error("You can't use this slave");
		}
		if (Target->get_data().statusL == 1) {
			throw std::logic_error("Enemy is alive");

		}
		Necro_data stats = Necro.get_data();
		if (stats.real_mana - (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->level + this->level) < 0) {
			throw std::logic_error("not enought mana");
		}
		stats.real_mana -= (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->level + this->level < 0);
		ret_enemy = this->slaves[ch - 1].become_slave(Necro.get_dateC(), *(Target));
		delete Target;
		Target = ret_enemy;
		Necro.set_data(stats);
	}
	morphism::morphism() {
		this->level = 1;
		this->name = "Morphism";
	}
	Spell morphism::get_data() {
		Spell ret_data;
		ret_data.level = this->level;
		ret_data.name = this->name;
		ret_data.slaves = this->slaves;
		return ret_data;
	}
	void morphism::set_date(Spell data) {
		this->level = data.level;
		this->name = data.name;
		this->slaves = data.slaves;
	}
	void morphism::update_spell() {
		this->level++;
	}

	void morphism::make_mage(Necromancer& Necro, Enemy*& Target) {
		int ch1;
		for (int i = 0; i < this->slaves.getlen(); i++) {
			std::cout << i + 1 << ". " << this->slaves[i].get_data().name << " " << this->slaves[i].get_data().can_I << std::endl;
		}
		get_number(ch1, "Chouse type: ");
		if (this->slaves[ch1 - 1].get_data().can_I == 0) {
			throw std::logic_error("You can't use this slave");

		}
		if (Target->get_data().statusL == 1) {
			throw std::logic_error("Enemy is alive");

		}
		if (!check_access(Target->get_data().type)) {
			throw std::logic_error("You can't transform to this type");

		}
		if (this->slaves[ch1 - 1].get_data().name == Target->get_data().type) {
			throw std::logic_error("You can't tranform to the same type");

		}
		Necro_data stats = Necro.get_data();
		if (stats.real_mana - (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->level + this->level) < 0) {
			throw std::logic_error("not enought mana");

		}

		stats.real_mana -= (Target->get_data().en_satas.damage + Target->get_data().cr_stats.max_health) / 2 - (15 * this->level + this->level < 0);
		for (int i = 0; i < this->slaves.getlen(); i++) {
			if (this->slaves[i].get_data().name == Target->get_data().type) {
				this->slaves[i].become_slave(Target->get_dateC(), *Target);
			}
		}
		DEnemy* ret_enemy = nullptr;
		ret_enemy = this->slaves[ch1 - 1].become_slave(Target->get_dateC(), *Target);
		delete Target;
		Target = ret_enemy;
		Necro.set_data(stats);

	}
	bool morphism::check_access(std::string type) {
		for (int i = 0; i < this->slaves.getlen(); i++) {
			if (this->slaves[i].get_data().name == type && this->slaves[i].get_data().can_I == 1) {
				return true;
			}
		}
		return false;
	}




}