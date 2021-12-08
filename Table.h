#ifndef TABLE
#define TABLE
#include <iostream>
#include "Interfaces.h"
#include "Necro.h"
#include "ConClass.h"

namespace necro {

	class desiccation : public ISpells<LEnemy> {
	private:
		Spell stats;
	public:
		desiccation();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, LEnemy&);
		virtual void update_spell();
	};

	class curse :public ISpells<LEnemy> {
	private:
		Spell stats;
	public:
		curse();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, LEnemy&);
		virtual void update_spell();
	};
	class necromancy : public ISpells<LEnemy> {
	private:
		Spell stats;
	public:
		necromancy();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, LEnemy&);
		virtual void update_spell();
		//void add_creature(Slave);
		//~necromancy();

	};
	class morphism : public ISpells<LEnemy> {
	private:
		Spell stats;
	public:
		morphism();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, LEnemy&);
		virtual void update_spell();
		bool check_access(std::string);
		//void add_creature(Slave);
		//~morphism();
	};


}



#endif