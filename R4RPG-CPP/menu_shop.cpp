#include "Libraries.h"
#include "Menus.h"
using namespace std;

void menu_shop(Player &p) {
	while (p.MONEY > 0) {
		system("cls||clear");
		save(p);
		int n;
		cout << "---" << endl;
		cout << "Choose a category! Money: " << p.MONEY << endl;
		cout << "---" << endl;
		cout << "1. Potions" << endl;
		cout << "2. Exit to main menu" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			shop_potions(p);
		}
		else if (n == 2) {
			break;
		}
	}
}