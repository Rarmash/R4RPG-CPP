#include <iostream>
#include "Menus.h"
using namespace std;

void mainmenu(Player &p) {
	while (true) {
		system("cls||clear");
		int n;
		cout << "---" << endl;
		cout << "Choose what to do!" << endl;
		cout << "---" << endl;
		cout << "1. Go fight!" << endl;
		cout << "2. Check your stats!" << endl;
		cout << "3. Close the game" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			menu_fight(p);
		}
		else if (n == 2) {
			p.menu_stats();
		}
		else if (n == 3) {
			exit(0);
		}
		else {
			system("cls||clear");
			mainmenu(p);
		}
	}
}