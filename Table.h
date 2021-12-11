#ifndef TABLE
#define TABLE
#include <iostream>
#include "Interfaces.h"
#include "Necro.h"
#include "ConClass.h"

namespace necro {

	class desiccation : public ISpells<Enemy*> {
	public:
		desiccation();
		virtual Spell get_data();
		std::string GetSpellName() { return this->name; }
		void SetSpellName(std::string Name) { this->name = Name; }
		int GetSpellLvl() { return this->level; }
		void SetSpellLvl(int Lvl) { this->level = Lvl; }
		vector<Undead> GetSpellSl() { return this->slaves; }
		void SetSpellLvl(vector<Undead> Sl) { this->slaves = Sl; }
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, Enemy*&);
		virtual void update_spell();
	};

	class curse :public ISpells<Enemy*> {
	public:
		curse();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, Enemy*&);
		virtual void update_spell();
	};
	class necromancy : public ISpells<Enemy*> {
	public:
		necromancy();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, Enemy*&);
		virtual void update_spell();
		//void add_creature(Slave);
		//~necromancy();

	};
	class morphism : public ISpells<Enemy*> {
	public:
		morphism();
		virtual Spell get_data();
		virtual void set_date(Spell data);
		virtual void make_mage(Necromancer&, Enemy*&);
		virtual void update_spell();
		bool check_access(std::string);
		//void add_creature(Slave);
		//~morphism();
	};


}



#endif