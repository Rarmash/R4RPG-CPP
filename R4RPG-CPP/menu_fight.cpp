#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <cmath>
#include "Menus.h"
using namespace std;

void menu_fight(Player &p) {
	system("cls||clear");
	save(p);

	//generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(10, 20);
	uniform_int_distribution<> distr1(1, 5);
	uniform_int_distribution<> randAttack(1, 2);
	uniform_int_distribution<> runAway(1, 5);

	int ehp = distr(gen) + ceil(p.MAXHP * 0.33);
	int epw = distr1(gen) + ceil(p.PW * 0.25);

	while (ehp > 0) {
		int n;
		cout << "---" << endl;
		cout << "Enemy: " << ehp << ". Power: " << epw << endl;
		cout << p.NAME << ": " << p.HP << "/" << p.MAXHP << ". Power: " << p.PW << endl;
		cout << "---" << endl;
		cout << "1. Punch with power " << p.PW << endl;
		cout << "2. Use heal potion (+" << p.HEALING << ") (" << p.HPPOTION << " left)" << endl;
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
			if (p.HPPOTION > 0) {
				p.HP += p.HEALING;
				p.HPPOTION -= 1;
				if (p.HP > p.MAXHP) {
					p.HP = p.MAXHP;
				}
				cout << "---" << endl;
				cout << "+" << p.HEALING << " HP..." << endl;
			}
			else {
				cout << "---" << endl;
				cout << "Not enough potions!" << endl;
			}
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
	if (ehp <= 0) {
		p.MONEY += 1;
		p.SP += 1;
		p.XP += 1;
		if (p.XP >= p.MAXXP) {
			p.XP = 0;
			p.MAXXP *= 5;
			p.LEVEL += 1;
		}
	}
}