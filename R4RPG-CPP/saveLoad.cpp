#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include "Menus.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

void save(Player &p) {
	json j;
	j["name"] = p.NAME;
	j["cls"] = p.CLS;
	j["level"] = p.LEVEL;
	j["xp"] = p.XP;
	j["maxxp"] = p.MAXXP;
	j["hp"] = p.HP;
	j["maxhp"] = p.MAXHP;
	j["pw"] = p.PW;
	j["healing"] = p.HEALING;
	j["sp"] = p.SP;
	j["money"] = p.MONEY;
	j["hppotion"] = p.HPPOTION;
	remove("saves.json");
	ofstream o("saves.json");
	o << setw(4) << j << endl;
	BOOL result = SetFileAttributes(L"saves.json", FILE_ATTRIBUTE_HIDDEN);
	o.close();
}

void load(Player& p) {
	ifstream testFile;
	testFile.open("saves.json");
	if (testFile) {
		ifstream i("saves.json");
		json j;
		i >> j;
		p.NAME = j["name"];
		p.CLS = j["cls"];
		p.LEVEL = j["level"];
		p.XP = j["xp"];
		p.MAXXP = j["maxxp"];
		p.HP = j["hp"];
		p.MAXHP = j["maxhp"];
		p.PW = j["pw"];
		p.HEALING = j["healing"];
		p.SP = j["sp"];
		p.MONEY = j["money"];
		p.HPPOTION = j["hppotion"];
	}
	else {
		saveCreate(p);
	}
}

void saveCreate(Player& p) {
	p.NAME = "Player";
	p.CLS = "Warrior";
	p.LEVEL = 1;
	p.XP = 0;
	p.MAXXP = 5;
	p.HP = 10;
	p.MAXHP = 10;
	p.PW = 1;
	p.HEALING = 2;
	p.SP = 0;
	p.MONEY = 0;
	p.HPPOTION = 5;
}