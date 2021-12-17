//
// Created by kirill on 17.12.2021.
//
#ifndef NECROMANCER_GAME_H
#define NECROMANCER_GAME_H
#include <iostream>
#include <stdio.h>
#include <curses.h>
#include "Interfaces.h"
#include "Necro.h"
#include "Table.h"
#include "ConClass.h"
#include "Map.h"
namespace  necro {
    class game {
    private:
    Necromancer necr;
    vector<Enemy*> Enemy_mas;
    vector<Golem> Golem_mas;
    vector<ISpells<Enemy*>> Spells_mas;
    vector<Slave> Slaves_mas;
    Level* Lvl;
    public:

    };


}
#endif //NECROMANCER_GAME_H
