#include <iostream>
#include "Menus.h"
using namespace std;

void menu_upgrade(Player &p) {
	while (p.SP > 0) {
		system("cls||clear");
		int n;
		cout << "---" << endl;
		cout << "Choose your upgrades! Skill points: " << p.SP;
		cout << "---" << endl;
		cout << "1. HP: " << p.HP << "/" << p.MAXHP << endl;
		cout << "2. Power: " << p.PW << endl;
		cout << "3. Healing potions power: " << p.HEALING << endl;
		cout << "4. Exit to main menu" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			p.SP -= 1;
			p.HP += 5;
			p.MAXHP += 5;
		}
		else if (n == 2) {
			p.SP -= 1;
			p.PW += 1;
		}
		else if (n == 3) {
			p.SP -= 1;
			p.HEALING += 1;
		}
		else if (n == 4) {
			break;
		}
	}
}