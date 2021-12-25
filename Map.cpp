#include <iostream>
#include <stdio.h>
#include <curses.h>
#include "Map.h"
#include "ConClass.h"
namespace necro {
	Level::Level(int x, int y) {
		this->size_x = x;
		this->size_y = y;
		this->next_lvl = nullptr;
		this->prev_lvl = nullptr;
		this->field.resize(x);
		for (int i = 0; i < x; i++) {
			this->field[i].resize(y);
			for (int j = 0; j < y; j++) {
				this->field[i][j].distance = -1;
				this->field[i][j].next = nullptr;
				this->field[i][j].previous = nullptr;
				this->field[i][j].What_it = 0;
				this->field[i][j].flag = 0;
				this->field[i][j].coo.x = i;
				this->field[i][j].coo.y = j;
			}
		}
	}
	Level::Level(Lvl lvl) {
		this->size_x = lvl.size_x;
		this->size_y = lvl.size_y;
		this->field.resize(this->size_x);
		for (int i = 0; i < this->size_x; i++) {
			this->field[i].resize(this->size_y);
		}

		for (int i = 0; i < this->size_x; i++) {
			for (int j = 0; j < this->size_y; j++) {
				this->field[i][j] = lvl.field[i][j];
			}
		}
	}
	Lvl Level::get_data() {
		Lvl ret_date;
		ret_date.field = this->field;
		Field help = this->field[3][4];
		ret_date.size_x = this->size_x;
		ret_date.size_y = this->size_y;
		return ret_date;
	}
	void Level::set_data(Lvl lvl) {
		this->field = lvl.field;
		this->size_x = lvl.size_x;
		this->size_y = lvl.size_y;
	}

	Field Level::get_inf(int x1, int y1) {
		return this->field[x1][y1];
	}
	void Level::set_inf(int x1, int y1, Field coordinate) {
		this->field[x1][y1].distance = coordinate.distance;
		this->field[x1][y1].next = coordinate.next;
		this->field[x1][y1].previous = coordinate.previous;
		this->field[x1][y1].What_it = coordinate.What_it;
	}
    bool Level::check_Q(vector<Field*> Q, Coordinate Coo){
        for(int i = 0 ; i < Q.getlen(); i++){
            if(Coo.x == Q[i]->coo.x && Coo.y == Q[i]->coo.y){
                return false;
            }
        }
        return true;
    }


	bool Level::Q_move(vector<Field*>& Q, int num, Coordinate goal) {
		Coordinate help;
		help.x = Q[num]->coo.x;
		help.y = Q[num]->coo.y;
		help.x += 1;
		if (check_per(help) && check_el(&(this->field[help.x][help.y])) ) {
			count_path(Q[num], this->field[help.x][help.y]);
			if (help.x == goal.x && help.y == goal.y) { return true; }
            if(check_Q(Q, help)) {
                Q.push_back(&(this->field[help.x][help.y]));
            }

		}
		help.x -= 2;
		if (check_per(help) && check_el(&(this->field[help.x][help.y])) ) {
			count_path(Q[num], this->field[help.x][help.y]);
			if (help.x == goal.x && help.y == goal.y) { return true; }
            if(check_Q(Q, help)) {
                Q.push_back(&(this->field[help.x][help.y]));
            }
		}
		help.x += 1;
		help.y += 1;
		if (check_per(help) && check_el(&(this->field[help.x][help.y])) ) {
			count_path(Q[num], this->field[help.x][help.y]);
			if (help.x == goal.x && help.y == goal.y) { return true; }
            if(check_Q(Q, help)) {
                Q.push_back(&(this->field[help.x][help.y]));
            }
		}
		help.y -= 2;
		if (check_per(help) && check_el(&(this->field[help.x][help.y])) ) {
			count_path(Q[num], this->field[help.x][help.y]);
			if (help.x == goal.x && help.y == goal.y) { return true; }
            if(check_Q(Q, help)) {
                Q.push_back(&(this->field[help.x][help.y]));
            }
		}
		Q[num]->flag = 1;
		Q.remove(num);
		return false;

	}
	void Level::find_way(Coordinate begin, Coordinate end) {
		vector<Field*> Q;
		for (int i = 0; i < this->size_x; i++) {
			for (int j = 0; j < this->size_y; j++) {
				this->field[i][j].distance = -1;
				this->field[i][j].flag = 0;
				this->field[i][j].previous = nullptr;
			}
		}
		this->field[begin.x][begin.y].distance = 0;
		if (!check_per(begin)) {
			//error
		}
		if (!check_per(end)) {
			//error
		}

		Q.push_back(&(this->field[begin.x][begin.y]));
		bool ch;
		while (Q.getlen() != 0) {

			ch = Q_move(Q, find_n_q(Q, end), end);
			if (ch) { break; }
		}


	}

	bool Level::check_per(Coordinate coo) {
		if (coo.x >= this->size_x || coo.x < 0 || coo.y >= this->size_y || coo.y < 0) {
			return false;
		}
		return true;

	}
	bool Level::check_el(Field* cell) {
		if (cell->What_it == 1 || cell->flag == 1 || cell->What_it == 4 || cell->What_it == 3) {
			return false;
		}
		return true;
	}
	int Level::find_n_q(vector<Field*> Q, Coordinate goal) {
		double prev = Q[0]->distance + len_to_goal(Q[0]->coo, goal);
		int num = 0;
		for (int i = 0; i < Q.getlen(); i++) {
			if (prev > Q[i]->distance + len_to_goal(Q[i]->coo, goal)) {
				prev = Q[i]->distance + len_to_goal(Q[i]->coo, goal);
				num = i;
			}
		}
		return num;
	}
	double Level::len_to_goal(Coordinate coo, Coordinate goal) {
		return (coo.x - goal.x) * (coo.x - goal.x) + (coo.y - goal.y) * (coo.y - goal.y);
	}
	void Level::count_path(Field* prev, Field& cell) {
		int help_dist;
		help_dist = prev->What_it == 6 ? prev->distance + 20 : prev->distance + 1;
		if (cell.distance != -1) {
			cell.distance = cell.distance < help_dist ? cell.distance : help_dist;
			cell.previous = cell.distance < help_dist ? cell.previous : prev;
		}
		else {
			cell.distance = help_dist;
			cell.previous = prev;
		}
	}


}