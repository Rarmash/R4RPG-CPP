#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "Menus.h"
using namespace std;

void menu_fight(Player &p) {
	system("cls||clear");

	//generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 10);
	uniform_int_distribution<> distr1(1, 5);
	uniform_int_distribution<> randAttack(1, 2);
	uniform_int_distribution<> runAway(1, 5);

	int ehp = distr(gen);
	int epw = distr1(gen);

	while (ehp > 0) {
		int n;
		cout << "---" << endl;
		cout << "Enemy: " << ehp << ". Power: " << epw << endl;
		cout << p.NAME << ": " << p.HP << "/" << p.MAXHP << ". Power: " << p.PW << endl;
		cout << "---" << endl;
		cout << "1. Punch with power " << p.PW << endl;
		cout << "2. Use heal potion (+" << p.HEALING << ")" << endl;
		cout << "3. Run away!" << endl;
		cout << "Number: ";
		cin >> n;
		if (n == 1) {
			int r = randAttack(gen);
			if (r == 1) {
				ehp -= p.PW;
				system("cls||clear");
				cout << "---" << endl;
				cout << "You hit the enemy!" << endl;
			}
			else if (r == 2) {
				p.HP -= epw;
				system("cls||clear");
				cout << "---" << endl;
				cout << "Enemy hit you!" << endl;
				if (p.HP <= 0) {
					cout << "---" << endl;
					cout << "YOU'VE LOST!" << endl;
					cout << "---";
					chrono::milliseconds timespan(5000);
					this_thread::sleep_for(timespan);
					exit(0);
				}
			}
		}
		else if (n == 2) {
			system("cls||clear");
			p.HP += p.HEALING;
			if (p.HP > p.MAXHP) {
				p.HP = p.MAXHP;
			}
			cout << "---" << endl;
			cout << "+" << p.HEALING << " HP..." << endl;
		}
		else if (n == 3) {
			system("cls||clear");
			int r = runAway(gen);
			if (r == 5) {
				cout << "---" << endl;
				cout << "You ran away!" << endl;
				break;
			}
			else {
				cout << "---" << endl;
				cout << "You can't run!" << endl;
			}
		}
	}
	p.XP += 1;
	if (p.XP >= p.MAXXP) {
		p.XP = 0;
		p.MAXXP *= 5;
		p.LEVEL += 1;
	}
}