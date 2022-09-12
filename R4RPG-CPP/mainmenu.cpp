#include <iostream>
using namespace std;

int mainmenu() {
	int n;
	cout << "---\n";
	cout << "Choose what to do!\n";
	cout << "---\n";
	cout << "1. Go fight!\n";
	cout << "2. Close the game\n";
	cout << "Number: ";
	cin >> n;
	if (n == 1) {
		int menu_fight();
	}
	else if (n == 2) {
		exit(0);
	}
	else {
		system("cls||clear");
		mainmenu();
	}
	return 0;
}