#include "Player.h"
#include "Libraries.h"
using namespace std;

void Player::menu_stats() {
	system("cls||clear");
	cout << "---" << endl;
	cout << "Player stats!" << endl;
	cout << "---" << endl;
	cout << "Name: " << "\t" << "| " << NAME << endl;
	cout << "Class: " << "\t" << "| " << CLS << endl;
	cout << "Level: " << "\t" << "| " << LEVEL << endl;
	cout << "XP: " << "\t" << "| " << XP << "/" << MAXXP << endl;
	cout << "HP: " << "\t" << "| " << HP << "/" << MAXHP << endl;
	cout << "Power: " << "\t" << "| " << PW << endl;
	cout << "Healing" << "\t" << "| " << HEALING << endl;
	system("pause");
}