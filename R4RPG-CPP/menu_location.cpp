#include "Libraries.h"
#include "Menus.h"
using namespace std;

void menu_location(Player& p) {
	while (true) {
		system("cls||clear");
		cout << "---" << endl;
		cout << "Choose next location!" << endl;
		cout << "---" << endl;
		cout << "1. Spawn" << endl;
		if (p.SANDSPASS == true) {
			cout << "2. Sands" << endl;
		}
		else {
			cout << "<CLOSED>" << endl;
		}
		if (p.SNOWKINGDOMPASS == true) {
			cout << "3. Snow kingdom" << endl;
		}
		else {
			cout << "<CLOSED>" << endl;
		}
		int n;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			p.LOCATION = "spawn";
			break;
		}
		if (n == 2 && p.SANDSPASS == true) {
			p.LOCATION = "sands";
			break;
		}
		if (n == 3 && p.SNOWKINGDOMPASS == true) {
			p.LOCATION = "snow kingdom";
			break;
		}
	}
}