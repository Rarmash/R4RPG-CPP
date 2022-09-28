#include "Libraries.h"
#include "Menus.h"
using namespace std;

void mainmenu(Player &p) {
	while (true) {
		system("cls||clear");
		save(p);
		int n;
		cout << "---" << endl;
		cout << "Choose what to do!" << endl;
		cout << "---" << endl;
		cout << "1. Go fight!" << endl;
		//cout << "2. Go to the mine!" << endl;
		cout << "2. Check your stats!" << "\t" << "        | HP: " << p.HP << "/" << p.MAXHP << endl;
		//cout << "4. Check your inventory" << endl;
		if (p.SP > 0) {
			cout << "3. Upgrade your character" << "\t" << "| Skill points: " << p.SP << endl;
		}
		else {
			cout << "3. [CLOSED]" << endl;
		}
		if (p.MONEY > 0) {
			cout << "4. Open shop" << "\t" << "                | Money: " << p.MONEY << endl;
		}
		else {
			cout << "4. [CLOSED]" << endl;
		}
		//cout << "7. Open craft menu" << endl;
		string loc = p.LOCATION;
		loc[0] = toupper(loc[0]);
		for (int i = 1; loc[i] != '\0'; ++i) {
			loc[i] = tolower(loc[i]);
		}
		cout << "5. Change your location" << "\t" << "        | Current location: " << loc << endl;
		cout << "6. Close the game" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			menu_fight(p);
		}
		else if (n == 2) {
			p.menu_stats();
		}
		else if (n == 3) {
			menu_upgrade(p);
		}
		else if (n == 4) {
			menu_shop(p);
		}
		else if (n == 5) {
			menu_location(p);
		}
		else if (n == 6) {
			save(p);
			exit(0);
		}
	}
}