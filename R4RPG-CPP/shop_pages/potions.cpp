#include <iostream>
#include "../Menus.h"
using namespace std;

void shop_potions(Player& p) {
	while (p.MONEY > 0) {
		system("cls||clear");
		save(p);
		int n;
		cout << "---" << endl;
		cout << "Choose potions! Money: " << p.MONEY << endl;
		cout << "---" << endl;
		cout << "1. 5 heal potions (+" << p.HEALING << " to HP) - " << p.HPPOTION << " in the inventory" << "\t" << "[COST: 1]" << endl;
		cout << "2. Exit to shop menu" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			if (p.MONEY >= 1) {
				p.MONEY -= 1;
				p.HPPOTION += 5;
			}
			else {
				cout << "---" << endl;
				cout << "Not enough money." << endl;
			}
		}
		else if (n == 2) {
			break;
		}
	}
}