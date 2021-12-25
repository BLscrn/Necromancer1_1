#include <iostream>
//#include "Enemy.h"
#include "Interfaces.h"
#include "Necro.h"
#include "Table.h"
#include "ConClass.h"
#include "WorkFile.h"
#include "ConClass.h"
#include <map>
#include <string>
#include "Map.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>
using namespace necro;
int main() {
    const int HEIGHT_MAP = 32;//размер карты высота
    const int WIDTH_MAP = 32;//размер карты ширина
    Lvl lvl1 = readFlvl("map.bin");
    vector<DLenemy_data> endata_mas;

    endata_mas = get_EnemyF("EnemyNG.bin");
    vector<Enemy*> en_mas;
    en_mas.resize(endata_mas.getlen());
    for(int i = 0; i < endata_mas.getlen(); i++){
        en_mas[i] = new LEnemy(endata_mas[i]);
    }
    for(int i = 0; i < endata_mas.getlen(); i++){
        en_mas[i]->SetSprite("../img/knight1.png");
    }
    vector<ISpells<Enemy*>*> table;
    table.resize(4);
    table[0] = new desiccation;
    table[1] = new curse;
    table[2] = new necromancy;
    table[3] = new morphism;


    vector<Slave> Slaves;
   /* Slaves.resize(2);
    Slaves[0].name = "Zombie";
    Slaves[0].fraction = "Other";
    Slaves[0].can_I = 1;
    Slaves[0].damage_kof = 0.6;

    Slaves[1].name = "Vampire";
    Slaves[1].fraction = "Other";
    Slaves[1].can_I = 1;
    Slaves[1].damage_kof = 0.8;

    safe_SlavesF(Slaves,"Slaves.bin");
    */
    Slaves = get_SlavesF("Slaves.bin");
    vector<Undead> sl_mas;
    sl_mas.resize(Slaves.getlen());
    for(int i = 0 ; i < Slaves.getlen();i++){
        sl_mas[i].set_data(Slaves[i]);
    }
    table[0]->SetSlaves(sl_mas);
    table[1]->SetSlaves(sl_mas);
    table[2]->SetSlaves(sl_mas);
    table[3]->SetSlaves(sl_mas);


    sf::String TileMap[HEIGHT_MAP] = {
            "11111111111111111111111111111111",
            "17000071210000000000000001000001",
            "10077001010000000600000001000001",
            "10077001010000000000060003000001",
            "10000001010000000000000001000001",
            "10077001040000600000000601116111",
            "10700701010000000000000001770001",
            "10000001010060000000066661770001",
            "11111141010000000600066661000001",
            "10010001010000000000066661000001",
            "10010001011141111111111111110001",
            "10010001011101111111111100010001",
            "10014111411101111111111101010001",
            "10000000011101111111111101010001",
            "10000000011101111111111101000001",
            "10000000011101111111111101110001",
            "10000000011101111111111100060001",
            "11111111111101111111111101111111",
            "10000000040100000000001100040771",
            "10100000010100000000000111110001",
            "10100000010100000000000300000001",
            "10141114110100066666000111111101",
            "10100100010100066666000100400101",
            "10100100710000066666000100100101",
            "10111111110000066666000300400401",
            "10000000010000066666000111111111",
            "11111111010000066666000100000001",
            "10000001010000066666000100707071",
            "10011121010000066666000300077701",
            "10011111010000000000000100070701",
            "10000004010000000000000100000001",
            "11111111111111111111111111111111",
    };

    Level map1(lvl1);


    sf::Image wall;
    wall.loadFromFile("../img/wall1.png");
    sf::Texture wallT;
    wallT.loadFromImage(wall);
    sf::Sprite wallS;
    wallS.setTexture(wallT);


    sf::Image floor;
    floor.loadFromFile("../img/floor1.png");
    sf::Texture floorT;
    floorT.loadFromImage(floor);
    sf::Sprite floorS;
    floorS.setTexture(floorT);


    sf::Image door;
    door.loadFromFile("../img/door1.png");
    sf::Texture doorT;
    doorT.loadFromImage(door);
    sf::Sprite doorS;
    doorS.setTexture(doorT);

    sf::Image essence;
    essence.loadFromFile("../img/essence1.png");
    sf::Texture essenceT;
    essenceT.loadFromImage(essence);
    sf::Sprite essenceS;
    essenceS.setTexture(essenceT);


    sf::Image lava;
    lava.loadFromFile("../img/lava1.png");
    sf::Texture lavaT;
    lavaT.loadFromImage(lava);
    sf::Sprite lavaS;
    lavaS.setTexture(lavaT);

    sf::Image ladder;
    ladder.loadFromFile("../img/ladder1.png");
    sf::Texture ladderT;
    ladderT.loadFromImage(ladder);
    sf::Sprite ladderS;
    ladderS.setTexture(ladderT);

    sf::Image zb;
    zb.loadFromFile("../img/corpse1.png");
    sf::Texture zbT;
    zbT.loadFromImage(zb);
    sf::Sprite zbS;
    zbS.setTexture(zbT);

    sf::Image spell;
    spell.loadFromFile("../img/mage1.png");
    sf::Texture spellT;
    spellT.loadFromImage(spell);
    sf::Sprite spellS;
    spellS.setTexture(spellT);

    zbS.setPosition(2*32,3*32);
    sf::RenderWindow window(sf::VideoMode(32*32, 32*32), "My window");

    // run the program as long as the window is open
    Necromancer necr1;
    necr1.SetCooX(1);
    necr1.SetCooY(18);
    int x1,y1,num;
    necr1.SetNecrM_mana(100000);
    necr1.SetNecrR_mana(100000);
    int Q = 0;
    Coordinate begin;
    Coordinate end;
    en_mas[0]->SetCooX(14);
    en_mas[0]->SetCooY(7);
    en_mas[1]->SetCooX(1);
    en_mas[1]->SetCooY(17);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        necr1.GetSprite().setPosition( necr1.GetCooY()* 32,necr1.GetCooX()* 32);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                necr1.move(map1.get_data(),'w');
                necr1.GetSprite().setPosition(necr1.GetCooY()* 32,necr1.GetCooX()* 32);
                window.draw(necr1.GetSprite());
                sleep(1);
                std::cout << necr1.GetCooX() << "  " << necr1.GetCooY() << std::endl ;
                std::cout << map1.get_data().field[necr1.GetCooX()][necr1.GetCooY()].What_it << std::endl ;
                Q = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
              necr1.move(map1.get_data(),'s');
                necr1.GetSprite().setPosition(necr1.GetCooY()* 32,necr1.GetCooX()* 32);
                window.draw(necr1.GetSprite());
                sleep(1);
                std::cout << necr1.GetCooX() << "  " << necr1.GetCooY() << std::endl ;
                std::cout << map1.get_data().field[necr1.GetCooX()][necr1.GetCooY()].What_it << std::endl ;;
                Q = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                necr1.move(map1.get_data(),'a');
                necr1.GetSprite().setPosition(necr1.GetCooY()* 32,necr1.GetCooX()* 32);
                window.draw(necr1.GetSprite());
                sleep(1);
                std::cout << necr1.GetCooX() << "  " << necr1.GetCooY() << std::endl ;
                std::cout << map1.get_data().field[necr1.GetCooX()][necr1.GetCooY()].What_it << std::endl ;;
                Q = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                necr1.move(map1.get_data(),'d');
                necr1.GetSprite().setPosition(necr1.GetCooX()* 32,necr1.GetCooY()* 32);
                window.draw(necr1.GetSprite());
                sleep(1);
                std::cout << necr1.GetCooX() << "  " << necr1.GetCooY() << std::endl ;
                std::cout << map1.get_data().field[necr1.GetCooX()][necr1.GetCooY()].What_it << std::endl ;;
                Q = 1;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            y1 = sf::Mouse::getPosition(window).x / 32;
            x1 = sf::Mouse::getPosition(window).y / 32;
            spellS.setPosition(y1*32,x1*32);
            window.draw(spellS);
            window.display();

            num = -1;
            for(int i = 0; i < en_mas.getlen();i++){
                if(en_mas[i]->GetCooX() == x1 && en_mas[i]->GetCooY() == y1){
                    num = i;
                }
            }
            sleep(1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            sleep(1);
            table[0]->make_mage(necr1,en_mas[num]);
            Q = 1;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            sleep(1);
            table[1]->make_mage(necr1,en_mas[num]);
            Q = 1;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            sleep(1);
            table[2]->make_mage(necr1, en_mas[num]);
            if(en_mas[num]->GetEnemyType() == "Zombie"){
                en_mas[num]->SetSprite("../img/zombie1.png");
            }else if(en_mas[num]->GetEnemyType() == "Vampire"){
                en_mas[num]->SetSprite("../img/vampire1.png");
            }
            Q = 1;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
            sleep(1);
            table[3]->make_mage(necr1, en_mas[num]);
            if(en_mas[num]->GetEnemyType() == "Zombie"){
                en_mas[num]->SetSprite("../img/zombie1.png");
            }else if(en_mas[num]->GetEnemyType() == "Vampire"){
                en_mas[num]->SetSprite("../img/vampire1.png");
            }
            Q = 1;
        }

        for(int i = 0; i < en_mas.getlen();i++){
            if(en_mas[i]->GetCrR_health() <= 0){
                en_mas[i]->death_cr();
            }
        }


        for(int i = 0; i < en_mas.getlen();i++){
            if(en_mas[i]->GetEnemyStL() == 0 && en_mas[i]->GetCrM_health() > 0){
                en_mas[i]->SetSprite("../img/corpse1.png");
            }else if(en_mas[i]->GetEnemyStL() == 0 && en_mas[i]->GetCrM_health() == -1){
                en_mas.remove(i);
            }
        }


        if(Q == 1){
            for(int i = 0; i < en_mas.getlen();i++ ){
                if(en_mas[i]->GetCrFraction() != "Necromancer squad" && en_mas[i]->GetEnemyStL() == 1){
                    int tr = 0;
                    char way;
                    tr = en_mas[i]->cause_dam(necr1);

                    if(tr != 1) {
                        begin.x = en_mas[i]->GetCooX();
                        begin.y = en_mas[i]->GetCooY();
                        end.x = necr1.GetCooX();
                        end.y = necr1.GetCooY();
                        map1.find_way(begin,end);
                        way = chse_way(map1.get_data().field,begin,end);
                        en_mas[i]->move(map1.get_data(), way);
                    }
                }
            }
            Q = 0;
        }




            window.clear(sf::Color::Black);

        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == '1')  {wallS.setTexture(wallT); wallS.setPosition(j * 32, i * 32); window.draw(wallS);}
                if (TileMap[i][j] == '0')  {floorS.setTexture(floorT); floorS.setPosition(j * 32, i * 32); window.draw(floorS);}
                if ((TileMap[i][j] == '3' || TileMap[i][j] == '4' )) {doorS.setTexture(doorT); doorS.setPosition(j * 32, i * 32); window.draw(doorS);}
                if (TileMap[i][j] == '2')  {ladderS.setTexture(ladderT); ladderS.setPosition(j * 32, i * 32);window.draw(ladderS);}
                if (TileMap[i][j] == '6')  {lavaS.setTexture(lavaT); lavaS.setPosition(j * 32, i * 32); window.draw(lavaS);}
                if (TileMap[i][j] == '7')  {essenceS.setTexture(essenceT); essenceS.setPosition(j * 32, i * 32); window.draw(essenceS);}
            }

        necr1.GetSprite().setPosition( necr1.GetCooY()* 32,necr1.GetCooX()* 32);
        window.draw(necr1.GetSprite());
        window.draw(zbS);
        for(int i = 0 ; i < en_mas.getlen();i++){
            en_mas[i]->GetSprite().setPosition(en_mas[i]->GetCooY()* 32,en_mas[i]->GetCooX()* 32);
            window.draw(en_mas[i]->GetSprite());
        }
        window.display();
    }



	return 0;
}