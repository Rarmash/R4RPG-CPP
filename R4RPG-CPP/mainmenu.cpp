#include <iostream>
using namespace std;

void mainmenu() {
	int n;
	cout << "---\n";
	cout << "Choose what to do!\n";
	cout << "---\n";
	cout << "1. Go fight!\n";
	cout << "2. Check your stats!\n";
	cout << "3. Close the game\n";
	cout << "Number: ";
	cin >> n;
	if (n == 1) {
		void menu_fight();
	}
	else if (n == 2) {
		void menu_stats();
	}
	else if (n == 3) {
		exit(0);
	}
	else {
		system("cls||clear");
		mainmenu();
	}
}