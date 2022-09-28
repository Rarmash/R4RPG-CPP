#include "Libraries.h"
#include "Enemies.h"
#include "Menus.h"
using namespace std;

template<class C, typename T>
bool contains(C&& c, T t) {
	return std::find(std::begin(c), std::end(c), t) != std::end(c);
};

void menu_fight(Player &p) {
	system("cls||clear");
	save(p);

	srand(time(0));
	string enemy = enemiesspawn[rand() % enemiesspawn.size()];

	//generator
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> plus_ehp();
	uniform_int_distribution<> plus_epw();

	if (contains(enemiesspawnregular, enemy)) {
		plus_ehp(10, 20);
		plus_epw(2, 10);
	}
	else if (contains(enemiesspawnnormal, enemy)) {
		plus_ehp(30, 50);
		plus_epw(6, 14);
	}
	else if (contains(enemiesspawnnormal, enemy)) {
		plus_ehp(75, 100);
		plus_epw(10, 20);
	}

	uniform_int_distribution<> randAttack(1, 2);
	uniform_int_distribution<> runAway(1, 5);

	int ehp = plus_ehp + ceil(p.MAXHP * 0.33);
	int epw = plus_epw + ceil(p.PW * 0.25);

	while (ehp > 0) {
		int n;
		cout << "---" << endl;
		cout << enemy << ": " << ehp << ". Power: " << epw << endl;
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