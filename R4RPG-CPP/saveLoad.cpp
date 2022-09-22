#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <locale>
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
	cout << "Enter your name: ";
	cin >> p.NAME;
	int d = 0;
	string cls0, cls;
	locale loc;
	while (d != 1) {
		cout << "Enter desired character class (Heavy, Medic or Warrior): ";
		cin >> cls0;
		for (auto elem : cls0) {
			cls += tolower(elem, loc);
		}
		if (cls == "heavy") {
			p.CLS = "Heavy";
			p.HP = 25;
			p.MAXHP = 25;
			p.HEALING = 5;
			p.PW = 2;
			d = 1;
		}
		else if (cls == "medic") {
			p.CLS = "Medic";
			p.HP = 10;
			p.MAXHP = 10;
			p.HEALING = 15;
			p.PW = 2;
			d = 1;
		}
		else if (cls == "warrior") {
			p.CLS = "Warrior";
			p.HP = 10;
			p.MAXHP = 10;
			p.HEALING = 5;
			p.PW = 6;
			d = 1;
		}
	}
	p.LEVEL = 1;
	p.XP = 0;
	p.MAXXP = 5;
	p.HEALING = 5;
	p.SP = 0;
	p.MONEY = 0;
	p.HPPOTION = 10;
}