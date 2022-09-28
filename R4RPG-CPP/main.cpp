#include "Libraries.h"
#include "Menus.h"
#include "Player.h"
using namespace std;

int main()
{
    system("cls||clear");
    system("title R4RPG");
    Player p;
    load(p);
    mainmenu(p);
}