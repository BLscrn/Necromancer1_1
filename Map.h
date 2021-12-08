#ifndef MAP
#define MAP
#include "ConClass.h"
namespace necro {

	struct Coordinate {
		double x;
		double y;
	};

	struct Field {
		Coordinate coo;
		int What_it; // 0 - blank,1 - lava, 2 - ladder, 3 - Odoor, 4- Cdoor , 5 - creature, 6 - wall, 7 - essence
		int distance;
		Field* previous;
		Field* next;
		bool flag;
	};

	struct Lvl {
		int size_x;
		int size_y;
		vector<vector<Field>> field;
	};


	class Level {
	private:
		int size_x;
		int size_y;
		vector<vector<Field>> field;
		Level* next_lvl;
		Level* prev_lvl;
		bool Q_move(vector<Field*>&, int num, Coordinate goal);
		bool check_el(Field*);
		bool check_per(Coordinate coo);
		int find_n_q(vector<Field*> Q, Coordinate goal);
		double len_to_goal(Coordinate coo, Coordinate goal);
		void count_path(Field* prev, Field& cell);
	public:
		Level(int x, int y);
		Level(Lvl lvl);
		Lvl get_data();
		void set_data(Lvl);
		Field get_inf(int x1, int y1);
		void set_inf(int x1, int y1, Field coordinate);
		void find_way(Coordinate begin, Coordinate end);

	};

}

#endif