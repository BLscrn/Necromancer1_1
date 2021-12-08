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
		virtual Necro_data get_data();
		virtual void set_data(Necro_data data);
		virtual bool move(Lvl lvl, char direction) { return  Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual Coordinate death_cr() {/* add with game */ };
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() { return Object::get_dateCO(); };
	};

	template <class T1>
	class ISpells {
	protected:
		Spell stats;
	public:
		virtual void make_mage(Necromancer&, T1&) = 0;
		virtual void update_spell() = 0;
		virtual Spell get_data() = 0;
		virtual void set_date(Spell) = 0;
	};

	class Golem : public IWork_data<Golem_data>, public ICreature {
	private:
		//Creature cr_stats;
		enemy en_satas;
		std::string type;
		double ignore_damm;

	public:
		virtual Golem_data get_data();
		virtual void set_data(Golem_data data);
		virtual bool move(Lvl lvl, char direction) { return Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual Coordinate death_cr() {/* add with map */ };
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() { return Object::get_dateCO(); };
	};




}
#endif