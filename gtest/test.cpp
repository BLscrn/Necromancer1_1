#include "pch.h"
#include "../Necromancer1_1/Interfaces.h"
#include "../Necromancer1_1/Necro.h"
#include "../Necromancer1_1/Table.h"
#include "../Necromancer1_1/Map.h"
#include "../Necromancer1_1/ConClass.h"


using namespace necro;
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(SetGet, SetGet) {
	Necromancer necr1;
	ASSERT_EQ(100, necr1.GetCrM_health());
	necr1.SetCrM_health(111);
	ASSERT_EQ(111, necr1.GetCrM_health());
	ASSERT_EQ("Necromancer squad", necr1.GetCrFraction());
	necr1.SetCrFraction("qwerty");
	ASSERT_EQ("qwerty", necr1.GetCrFraction());
	ASSERT_EQ(100, necr1.GetCrR_health());
}

TEST(Vector, vector) {
	vector<summoner> TestVt;
	ASSERT_EQ(0, TestVt.getlen());
	summoner help; 
	help.chance = 0.1;
	help.summoner = 1;
	TestVt.push_back(help);
	ASSERT_EQ(1, TestVt.getlen());
	ASSERT_EQ(0.1, TestVt[0].chance);
	vector<summoner> TestVt1;
	TestVt1 = TestVt;
	ASSERT_EQ(1, TestVt1.getlen());
	ASSERT_EQ(0.1, TestVt1[0].chance);
	help.chance = 0.2;
	help.summoner = 0;
	TestVt1.push_back(help);
	ASSERT_EQ(2, TestVt1.getlen());
	TestVt1.remove(0);
	ASSERT_EQ(1, TestVt1.getlen());
	ASSERT_EQ(0.2, TestVt1[0].chance);
}


TEST(Vector, Iterator) {
	vector<summoner> TestVt;
	vector<summoner> TestVt1;
	summoner help;
	help.chance = 0.1;
	help.summoner = 1;
	TestVt.push_back(help);
	TestVt1 = TestVt;
	help.chance = 0.2;
	help.summoner = 0;
	TestVt1.push_back(help);
	Iterator<summoner> Iter1;
	Iterator<summoner> Iter2;
	Iter1 = TestVt.begin();
	ASSERT_EQ(0.1, (* Iter1).chance);
	Iter2 = TestVt1.begin();
	ASSERT_EQ(0.1, (*Iter2).chance);
	ASSERT_EQ(false, Iter1 == Iter2);
	++Iter2;
	ASSERT_EQ(0.2, (*Iter2).chance);
	--Iter2;
	ASSERT_EQ(0.1, (*Iter2).chance);

}


TEST(Eenemy, Damm) {
	DLenemy_data d_en;
	d_en.coor_stats.x = 0;
	d_en.coor_stats.y = 0;
	d_en.cr_stats.fraction = "qwerty";
	d_en.cr_stats.level = 2;
	d_en.cr_stats.max_health = 100;
	d_en.cr_stats.name = "en1";
	d_en.cr_stats.real_health = 100;
	d_en.en_satas.chance = 0.5;
	d_en.en_satas.damage = 50;
	d_en.en_satas.status = 1;
	d_en.statusL = 1;
	d_en.su_stats.chance = 0;
	d_en.su_stats.summoner = 0;
	d_en.type = "1";
	LEnemy En1(d_en);
	d_en.cr_stats.name = "en2";
	d_en.coor_stats.x = 1;
	LEnemy En2(d_en);
	En1.cause_dam(En2);
	
	ASSERT_EQ(100, En2.GetCrR_health());
}