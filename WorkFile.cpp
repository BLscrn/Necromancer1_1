#include <iostream>
#include <stdio.h>
#include <curses.h>
#include "Interfaces.h"
#include "Necro.h"
#include "Table.h"
#include "WorkFile.h"
#include "Map.h"
#include <fstream>
namespace necro {


	void write_cr(All_Creature fdata, FILE* f) {
		int help_int = fdata.cr_stats.name.length();
		fwrite(&help_int, sizeof(int), 1, f);
		fwrite(&fdata.cr_stats.name[0], sizeof(char), fdata.cr_stats.name.length() + 1, f);
		fwrite(&fdata.cr_stats.max_health, sizeof(double), 1, f);
		fwrite(&fdata.cr_stats.real_health, sizeof(double), 1, f);
		fwrite(&fdata.cr_stats.level, sizeof(double), 1, f);
		help_int = fdata.cr_stats.fraction.length();
		fwrite(&help_int, sizeof(int), 1, f);
		fwrite(&fdata.cr_stats.fraction[0], sizeof(char), fdata.cr_stats.fraction.length() + 1, f);
		fwrite(&fdata.coor_stats, sizeof(Coordinate), 1, f);
	}

	All_Creature read_cr(FILE* f) {
		All_Creature ret_data;
		int help_int;
		char* help_st = nullptr;
		fread(&help_int, sizeof(int), 1, f);
		help_st = new char[help_int + 1];
		fread(help_st, sizeof(char), help_int + 1, f);
		ret_data.cr_stats.name = std::string(help_st);
		delete[] help_st;
		fread(&ret_data.cr_stats.max_health, sizeof(double), 1, f);
		fread(&ret_data.cr_stats.real_health, sizeof(double), 1, f);
		fread(&ret_data.cr_stats.level, sizeof(double), 1, f);
		fread(&help_int, sizeof(int), 1, f);
		help_st = new char[help_int + 1];
		fread(help_st, sizeof(char), help_int + 1, f);
		ret_data.cr_stats.fraction = std::string(help_st);
		fread(&ret_data.coor_stats, sizeof(Coordinate), 1, f);
		delete[] help_st;
		return ret_data;
	}

	void safe_NecroF(Necro_data fdata, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		//fwrite(&fdata, sizeof(Necro_data), 1, f);
		All_Creature help_cr;
		help_cr.coor_stats = fdata.coo_stats;
		help_cr.cr_stats = fdata.cr_stats;
		write_cr(help_cr, f);
		fwrite(&fdata.assence, sizeof(double), 1, f);
		fwrite(&fdata.exp, sizeof(double), 1, f);
		fwrite(&fdata.max_mana, sizeof(double), 1, f);
		fwrite(&fdata.real_mana, sizeof(double), 1, f);
		fclose(f);

	}
	Necro_data get_NecroF(std::string fname) {
		FILE* f;
		char* help_st = nullptr;
		int help_int;
		f = fopen(fname.c_str(), "rb");
		Necro_data ret_data;
		All_Creature help_data = read_cr(f);
		ret_data.cr_stats = help_data.cr_stats;
		ret_data.coo_stats = help_data.coor_stats;
		//fread(&ret_data, sizeof(Necro_data), 1, f);
		fread(&ret_data.assence, sizeof(double), 1, f);
		fread(&ret_data.exp, sizeof(double), 1, f);
		fread(&ret_data.max_mana, sizeof(double), 1, f);
		fread(&ret_data.real_mana, sizeof(double), 1, f);
		fclose(f);
		return ret_data;
	}

	void safe_EnemyF(vector<DLenemy_data> fdata, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		int help_int = fdata.getlen();
		All_Creature help_cr;
		Iterator<DLenemy_data> help_vectB;
		Iterator<DLenemy_data> help_vectE;
		help_vectB = fdata.begin();
		help_vectE = fdata.end();
		fwrite(&help_int, sizeof(int), 1, f);
		for (help_vectB; help_vectB != help_vectE; ++help_vectB) {
			help_cr.coor_stats = (*help_vectB).coor_stats;
			help_cr.cr_stats = (*help_vectB).cr_stats;
			write_cr(help_cr, f);
			fwrite(&(*help_vectB).en_satas, sizeof(enemy), 1, f);
			fwrite(&(*help_vectB).statusL, sizeof(bool), 1, f);
			fwrite(&(*help_vectB).su_stats, sizeof(summoner), 1, f);
			help_int = (*help_vectB).type.length();
			fwrite(&help_int, sizeof(int), 1, f);
			fwrite(&(*help_vectB).type[0], sizeof(char), help_int + 1, f);
		}
		fclose(f);
	}
	vector<DLenemy_data> get_EnemyF(std::string fname) {
		FILE* f;
		int kol, help_int;
		All_Creature help_cr;
		char* help_char = nullptr;
		vector<DLenemy_data> ret_data;
		DLenemy_data add_el;
		f = fopen(fname.c_str(), "rb");
		fread(&kol, sizeof(int), 1, f);
		for (int i = 0; i < kol; i++) {
			help_cr = read_cr(f);
			add_el.coor_stats = help_cr.coor_stats;
			add_el.cr_stats = help_cr.cr_stats;
			fread(&add_el.en_satas, sizeof(enemy), 1, f);
			fread(&add_el.statusL, sizeof(bool), 1, f);
			fread(&add_el.su_stats, sizeof(summoner), 1, f);
			fread(&help_int, sizeof(int), 1, f);
			help_char = new char[help_int + 1];
			fread(help_char, sizeof(char), help_int + 1, f);
			add_el.type = std::string(help_char);
			delete[] help_char;
			ret_data.push_back(add_el);
		}
		fclose(f);
		return ret_data;
	}

	void safe_GolemF(vector<Golem_data> fdata, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		int help_int = fdata.getlen();
		All_Creature help_cr;
		Iterator<Golem_data> help_vectB;
		Iterator<Golem_data> help_vectE;
		help_vectB = fdata.begin();
		help_vectE = fdata.end();
		fwrite(&help_int, sizeof(int), 1, f);
		for (help_vectB; help_vectB != help_vectE; ++help_vectB) {
			help_cr.coor_stats = (*help_vectB).coo_stats;
			help_cr.cr_stats = (*help_vectB).cr_stats;
			write_cr(help_cr, f);
			fwrite(&(*help_vectB).en_satas, sizeof(enemy), 1, f);
			fwrite(&(*help_vectB).ignore_damm, sizeof(double), 1, f);
			help_int = (*help_vectB).type.length();
			fwrite(&help_int, sizeof(int), 1, f);
			fwrite(&(*help_vectB).type[0], sizeof(char), help_int + 1, f);
			fwrite(&(*help_vectB).statusL, sizeof(bool), 1, f);
		}
		fclose(f);
	}
	vector<Golem_data> get_GolemF(std::string fname) {
		FILE* f;
		int kol, help_int;
		All_Creature help_cr;
		char* help_char = nullptr;
		Golem_data add_el;
		vector<Golem_data> ret_data;
		f = fopen(fname.c_str(), "rb");
		fread(&kol, sizeof(int), 1, f);
		for (int i = 0; i < kol; i++) {
			help_cr = read_cr(f);
			add_el.coo_stats = help_cr.coor_stats;
			add_el.cr_stats = help_cr.cr_stats;
			fread(&add_el.en_satas, sizeof(enemy), 1, f);
			fread(&add_el.ignore_damm, sizeof(double), 1, f);
			fread(&help_int, sizeof(int), 1, f);
			help_char = new char[help_int + 1];
			fread(help_char, sizeof(char), help_int + 1, f);
			add_el.type = std::string(help_char);
			delete[] help_char;
			fread(&add_el.statusL, sizeof(bool), 1, f);
			ret_data.push_back(add_el);
		}
		fclose(f);
		return ret_data;
	}

	void safe_SlavesF(vector<Slave> fdata, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		char* help_st = nullptr;
		int help_int = fdata.getlen();
		Iterator<Slave> help_vectB;
		Iterator<Slave> help_vectE;
		help_vectB = fdata.begin();
		help_vectE = fdata.end();
		fwrite(&help_int, sizeof(int), 1, f);
		for (help_vectB; help_vectB != help_vectE; ++help_vectB) {
			help_int = (*help_vectB).name.length();
			fwrite(&help_int, sizeof(int), 1, f);
			fwrite(&(*help_vectB).name[0], sizeof(char), (*help_vectB).name.length() + 1, f);
			help_int = (*help_vectB).fraction.length();
			fwrite(&help_int, sizeof(int), 1, f);
			fwrite(&(*help_vectB).fraction[0], sizeof(char), (*help_vectB).fraction.length() + 1, f);
			fwrite(&(*help_vectB).damage_kof, sizeof(double), 1, f);
			fwrite(&(*help_vectB).can_I, sizeof(bool), 1, f);
		}
		fclose(f);
	}

	vector<Slave> get_SlavesF(std::string fname) {
		FILE* f;
		vector<Slave> ret_data;
		int kol, help_int;
		char* help_char = nullptr;
		f = fopen(fname.c_str(), "rb");
		Slave add_el;
		fread(&(kol), sizeof(int), 1, f);
		for (int i = 0; i < kol; i++) {
			fread(&help_int, sizeof(int), 1, f);
			help_char = new char[help_int + 1];
			fread(help_char, sizeof(char), help_int + 1, f);
			add_el.name = std::string(help_char);
			delete[] help_char;
			fread(&help_int, sizeof(int), 1, f);
			help_char = new char[help_int + 1];
			fread(help_char, sizeof(char), help_int + 1, f);
			add_el.fraction = std::string(help_char);
			delete[] help_char;
			fread(&add_el.damage_kof, sizeof(double), 1, f);
			fread(&add_el.can_I, sizeof(bool), 1, f);
			ret_data.push_back(add_el);
		}
		fclose(f);
		return ret_data;
	}
	void safe_SpellF(vector<Spell> fdata, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		char* help_st = nullptr;
		int help_int = fdata.getlen();
		Iterator<Spell> help_vectB;
		Iterator<Spell> help_vectE;
		help_vectB = fdata.begin();
		help_vectE = fdata.end();
		fwrite(&help_int, sizeof(int), 1, f);
		for (help_vectB; help_vectB != help_vectE; ++help_vectB) {
			help_int = (*help_vectB).name.length();
			fwrite(&help_int, sizeof(int), 1, f);
			fwrite(&(*help_vectB).name[0], sizeof(char), (*help_vectB).name.length() + 1, f);
			fwrite(&(*help_vectB).level, sizeof(int), 1, f);
		}
		fclose(f);
	}
	vector<Spell> get_SpellF(std::string fname) {
		FILE* f;
		int kol, help_int;
		char* help_char = nullptr;
		vector<Spell> ret_data;
		Spell add_el;
		f = fopen(fname.c_str(), "rb");
		fread(&kol, sizeof(int), 1, f);
		for (int i = 0; i < kol; i++) {
			fread(&help_int, sizeof(int), 1, f);
			help_char = new char[help_int + 1];
			fread(help_char, sizeof(char), help_int + 1, f);
			add_el.name = std::string(help_char);
			delete[] help_char;
			fread(&add_el.level, sizeof(int), 1, f);
			ret_data.push_back(add_el);
		}
		fclose(f);
		return ret_data;
	}

	void safe_LvlF(Lvl lvl, std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "wb");
		fwrite(&lvl.size_x, sizeof(int), 1, f);
		fwrite(&lvl.size_y, sizeof(int), 1, f);
		for (int i = 0; i < lvl.size_x; i++) {
			for (int j = 0; j < lvl.size_y; j++) {
				fwrite(&lvl.field[i][j], sizeof(Field), 1, f);
			}
		}
		fclose(f);
	}
	Lvl get_LvlF(std::string fname) {
		FILE* f;
		f = fopen(fname.c_str(), "rb");
		Lvl ret_lvl;
		fread(&ret_lvl.size_x, sizeof(int), 1, f);
		fread(&ret_lvl.size_y, sizeof(int), 1, f);
		ret_lvl.field.resize(ret_lvl.size_x);
		for (int i = 0; i < ret_lvl.size_x; i++) {
			ret_lvl.field[i].resize(ret_lvl.size_y);
		}

		for (int i = 0; i < ret_lvl.size_x; i++) {
			for (int j = 0; j < ret_lvl.size_y; j++) {
				fread(&ret_lvl.field[i][j], sizeof(Field), 1, f);
			}
		}
		fclose(f);
		return ret_lvl;
	}
    Lvl readFlvl(std::string fname){
        std::ifstream f;
        f.open("map.bin");
        Lvl ret_lvl;
        f >> ret_lvl.size_x;
        f >> ret_lvl.size_y;
        ret_lvl.field.resize(ret_lvl.size_x);
        for (int i = 0; i < ret_lvl.size_x; i++) {
            ret_lvl.field[i].resize(ret_lvl.size_y);
        }
        for (int i = 0; i < ret_lvl.size_x; i++) {
            for (int j = 0; j < ret_lvl.size_y; j++) {
                f >> ret_lvl.field[i][j].What_it;
                ret_lvl.field[i][j].coo.x = i;
                ret_lvl.field[i][j].coo.y = j;
                ret_lvl.field[i][j].distance = -1;
                ret_lvl.field[i][j].flag = false;
                ret_lvl.field[i][j].next = nullptr;
                ret_lvl.field[i][j].previous = nullptr;
            }
        }
        f.close();
        return ret_lvl;
    }

    char chse_way(vector<vector<Field>> map , Coordinate begin,Coordinate end){

        Field* help_end;
        help_end = &map[end.x][end.y];
        if(help_end->previous == nullptr){return '/';}
        else{
            while(help_end->previous->previous != nullptr){
                help_end = help_end->previous;
            }
        }
        if(map[begin.x + 1][begin.y].coo.y == help_end->coo.y && map[begin.x + 1][begin.y].coo.x == help_end->coo.x){
            return 'd';
        }else if(map[begin.x - 1][begin.y].coo.y == help_end->coo.y && map[begin.x - 1][begin.y].coo.x == help_end->coo.x){
            return 'a';
        }else if(map[begin.x][begin.y + 1].coo.y == help_end->coo.y && map[begin.x][begin.y + 1].coo.x == help_end->coo.x){
            return 's';
        }else if(map[begin.x ][begin.y-1].coo.y == help_end->coo.y && map[begin.x ][begin.y-1].coo.x == help_end->coo.x){
            return 'w';
        }
    }
}

