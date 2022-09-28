#pragma once
#include "Libraries.h"
using namespace std;

extern vector<string> enemiesspawn = { "witch", "skeleton", "zombie", "slime", "pillager", "spider", "giant spider", "bee", "wolf", "bunch of bees", "bat", "werewolf", "ghost", "dragon" };
extern vector<string> enemiesspawnregular = { "witch", "skeleton", "zombie", "slime", "pillager", "spider", "bee", "wolf", "bat" };
extern vector<string> enemiesspawnnormal = { "giant spider", "bunch of bees", "ghost" };
extern vector<string> enemiesspawnbosses = { "werewolf", "dragon" };

extern vector<int> enemiesspawnregularhp = { 10,11,12,13,14,15,16,17,18,19,20 };
extern vector<int> enemiesspawnregularpw = { 2,3,4,5,6,7,8,9,10 };
extern vector<int> enemiesspawnnormalhp = { 30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
extern vector<int> enemiesspawnnormalpw = { 6,7,8,9,10,11,12,13,14 };
extern vector<int> enemiesspawnbosseshp = { 75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100 };
extern vector<int> enemiesspawnbossespw = { 10,11,12,13,14,15,16,17,18,19,20 };

extern vector<string> enemiessands = { "vulture", "wither", "mummy", "scorpion", "antlion", "sand slime", "giant antlion", "the big mummy", "sandworm", "sarlacc", "living sand", "the sandman" };
extern vector<string> enemiessandsregular = { "mummy", "scorpion", "sand slime", "sandworm", "antlion", "living sand", "the sandman" };
extern vector<string> enemiessandsnormal = { "vulture", "the big mummy", "giant antlion" };
extern vector<string> enemiessandsbosses = { "wither", "sarlacc" };

extern vector<int> enemiessandsregularhp = { 30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
extern vector<int> enemiessandsregularpw = { 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
extern vector<int> enemiessandsnormalhp = { 55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95 };
extern vector<int> enemiessandsnormalpw = { 8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };
extern vector<int> enemiessandsbosseshp = { 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130 };
extern vector<int> enemiessandsbossespw = { 30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60 };