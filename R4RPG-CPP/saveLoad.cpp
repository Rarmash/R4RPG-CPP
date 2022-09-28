#include "Libraries.h"
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
	j["location"] = p.LOCATION;
	j["sandspass"] = p.SANDSPASS;
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
		try {
			p.NAME = j["name"];
		}
		catch (const exception& ex) {
			p.NAME = "Player";
		}
		try {
			p.CLS = j["cls"];
		}
		catch (const exception& ex) {
			p.CLS = "Warrior";
		}
		try {
			p.LEVEL = j["level"];
		}
		catch (const exception& ex) {
			p.LEVEL = 1;
		}
		try {
			p.XP = j["xp"];
		}
		catch (const exception& ex) {
			p.XP = 0;
		}
		try {
			p.MAXXP = j["maxxp"];
		}
		catch (const exception& ex) {
			p.MAXXP = 5;
		}
		try {
			p.HP = j["hp"];
		}
		catch (const exception& ex) {
			p.HP = 10;
		}
		try {
			p.MAXHP = j["maxhp"];
		}
		catch (const exception& ex) {
			p.MAXHP = 10;
		}
		try {
			p.PW = j["pw"];
		}
		catch (const exception& ex) {
			p.PW = 6;
		}
		try {
			p.HEALING = j["healing"];
		}
		catch (const exception& ex) {
			p.HEALING = 5;
		}
		try {
			p.SP = j["sp"];
		}
		catch (const exception& ex) {
			p.SP = 0;
		}
		try {
			p.MONEY = j["money"];
		}
		catch (const exception& ex) {
			p.MONEY = 0;
		}
		try {
			p.HPPOTION = j["hppotion"];
		}
		catch (const exception& ex) {
			p.HPPOTION = 10;
		}
		try {
			p.LOCATION = j["location"];
		}
		catch (const exception& ex) {
			p.LOCATION = "spawn";
		}
		try {
			p.SANDSPASS = j["sandspass"];
		}
		catch (const exception& ex) {
			p.SANDSPASS = false;
		}
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
	p.SP = 0;
	p.MONEY = 0;
	p.HPPOTION = 10;
	p.LOCATION = "spawn";
	p.SANDSPASS = false;
}