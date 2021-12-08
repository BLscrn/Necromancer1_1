#ifndef INTERFACES
#define INTERFACES
#include <iostream>
#include "ConClass.h"
#include "Map.h"
namespace necro {

	template <class N>
	int get_number(N& a, const char* text) {
		bool flag = false;
		if (text != "") {
			std::cout << text << std::endl;
		}
		do {

			if (flag == true) {
				std::cout << "Error, try again:";
				flag = false;
			}
			std::cin >> a;
			if (std::cin.eof() || std::cin.bad()) {
				return -1;
			}
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(3333, '\n');
				flag = true;
			}

		} while (flag == true);
		std::cin.clear();
		std::cin.ignore(3333, '\n');
		return 0;
	}
	struct Slave {
		std::string name;
		double damage_kof;
		std::string fraction;
		bool can_I;
	};
	struct Creature
	{
		std::string name;
		double max_health;
		double real_health;
		std::string fraction;
		double level;
	};
	struct All_Creature
	{
		Creature cr_stats;
		Coordinate coor_stats;
	};
	struct enemy
	{
		double damage;
		int chance;
		bool status;

	};
	struct summoner
	{
		bool summoner;
		int chance;
	};

	struct Golem_data
	{
		Creature cr_stats;
		Coordinate coo_stats;
		enemy en_satas;
		std::string type;
		double ignore_damm;
		bool statusL;
	};
	struct DLenemy_data
	{
		Creature cr_stats;
		enemy en_satas;
		summoner su_stats;
		Coordinate coor_stats;
		bool statusL;
		std::string type;


	};
	struct Necro_data
	{
		double max_mana;
		double real_mana;
		Creature cr_stats;
		Coordinate coo_stats;
		double exp;
		double assence;
	};

	/*
	template <class M>
	struct  Any_mas{
		M* mas;
		int kol;
	};
	*/




	template <class T>
	class IWork_data {
	public:
		virtual T get_data() = 0;
		virtual void set_data(T) = 0;
	private:
	};



	template <class T2>
	class ISlaves
	{
	public:
		virtual void become_slave(Creature Who, T2&) = 0;
		virtual Slave get_data() = 0;
		virtual void set_data(Slave) = 0;
		virtual void become_available() = 0;
	};
	class Object {
	protected:
		Coordinate coor;
	public:
		virtual bool move(Lvl, char) = 0;
		virtual Coordinate get_dateCO() = 0;
		virtual void set_dateCO(Coordinate) = 0;
	};

	class ICreature : public Object {
	protected:
		Creature cr_stats;
	public:
		virtual Creature get_dateC() = 0;
		virtual void set_dateC(Creature) = 0;
		virtual Coordinate death_cr() = 0;
	};

	class Summoner:public virtual ICreature {
	protected:
		summoner su_stats;
	public:
		virtual DLenemy_data Call_cr() = 0;
	};


	class Enemy :public virtual ICreature {
	protected:
		enemy en_satas;
		bool statusL;
		std::string type;
	public:
		Enemy();
		virtual DLenemy_data get_data() = 0;
		virtual void set_data(DLenemy_data data) = 0;
		virtual Coordinate death_cr() = 0;
		virtual void cause_dam(ICreature&) = 0;
	};
	class LEnemy :public Enemy, public  Summoner{
	public:
		LEnemy();
		LEnemy(DLenemy_data);
		LEnemy(LEnemy& other);
		LEnemy& operator = (const LEnemy other);
		virtual Coordinate death_cr();
		virtual DLenemy_data get_data();
		virtual void set_data(DLenemy_data data);
		virtual bool move(Lvl lvl, char direction) { return Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() { return Object::get_dateCO(); };
		virtual void cause_dam(ICreature& Target) { return Enemy::cause_dam(Target); };
		virtual DLenemy_data Call_cr();
	};

	class DEnemy :public Enemy, public  Summoner {
	public:
		DEnemy();
		DEnemy(DLenemy_data);
		DEnemy(DEnemy& other);
		virtual Coordinate death_cr();
		DEnemy& operator = (const DEnemy other);
		virtual DLenemy_data get_data();
		virtual void set_data(DLenemy_data data);
		virtual bool move(Lvl lvl, char direction) { return Object::move(lvl, direction); };
		virtual Creature get_dateC() { return ICreature::get_dateC(); };
		virtual void set_dateC(Creature data) { return ICreature::set_dateC(data); };
		virtual void set_dateCO(Coordinate data) { return Object::set_dateCO(data); };
		virtual Coordinate get_dateCO() { return Object::get_dateCO(); };
		virtual void cause_dam(ICreature& Target) { return Enemy::cause_dam(Target); };
		virtual DLenemy_data Call_cr();
	};
	class Undead {
	private:
		Slave Undead_stats;
	public:
		Undead();
		Undead(const Undead& other);
		Undead& operator = (const Undead other);
		virtual Slave get_data();
		virtual void set_data(Slave);
		virtual DEnemy* become_slave(Creature Who, Enemy&);
		virtual void become_available();
	};

	struct Spell {
		std::string name;
		int level;
		vector<Undead> slaves;
	};

}

#endif