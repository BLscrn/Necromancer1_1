#ifndef NECRO
#define NECRO
#include <iostream>
#include "Interfaces.h"

namespace necro {

	class Necromancer : public IWork_data<Necro_data>, public ICreature {
	private:
		//Creature cr_stats;
		double max_mana;
		double real_mana;
		double exp;
		double assence;

	public:
		Necromancer();
		Necromancer(Necro_data);
		double GetNecrM_mana() { return this->max_mana; }
		void SetNecrM_mana(double Max) { this->max_mana = Max; }
		double GetNecrR_mana() { return this->real_mana; }
		void SetNecrR_mana(double Real) { this->real_mana = Real; }
		double GetNecrExp() { return this->exp; }
		void SetNecrExp(double exp) { this->exp = exp; }
		double GetNecrAssence() { return this->assence; }
		void SetNecrAssence(double Assence) { this->assence = Assence; }
		virtual Necro_data get_data();
		virtual void set_data(Necro_data data);
		virtual bool move(Lvl lvl, char direction) { return  Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual Coordinate death_cr() {/* add with game */Coordinate coor; coor.x = this->x; coor.y = this->y; return coor; };
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() { return Object::get_dateCO(); };
	};

	template <class T1>
	class ISpells {
	protected:
		std::string name;
		int level;
		vector<Undead> slaves;
	public:
		virtual void make_mage(Necromancer&, T1&) = 0;
		virtual void update_spell() = 0;
		virtual Spell get_data() = 0;
		virtual void set_date(Spell) = 0;
	};

	class Golem :public Enemy {
	private:
		double ignore_damm;

	public:
		Golem(Golem_data);
		Golem(Golem& other);
		Golem& operator = (const Golem other);
		virtual Golem_data get_dataG();
		virtual void set_dataG(Golem_data data);
		virtual DLenemy_data get_data();
		virtual void set_data(DLenemy_data data);
		virtual bool move(Lvl lvl, char direction) { return Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual Coordinate death_cr() {/* add with map */Coordinate coor; coor.x = this->x; coor.y = this->y; return coor;};
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() {return Object::get_dateCO(); };
		virtual void cause_dam(ICreature& Target) { return Enemy::cause_dam(Target); };
	};




}
#endif