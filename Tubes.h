#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define child(P) (P)->child
#define lastchild(P) (P)->lastchild
#define first(H) ((H).first)
#define last(H) ((H).last)
#define nil NULL

const int EXIT = 0;
const int ADD_PLAYER = 1;
const int SHOW_ALL_PLAYER_DATA = 2;
const int DELETE_PLAYER = 3;
const int ADD_SKILL = 4;
const int SHOW_ALL_SKILL = 5;
const int DELETE_SKILL = 6;
const int ADD_SKILL_TO = 7;
const int SHOW_ALL_SKILL_IN_PLAYER = 8;
const int DELETE_SKILL_PLAYER = 9;
const int SHOW_MOST_SKILL_FROM_ALL_PLAYER = 10;

struct player{
	string namaPlayer;
	int umur;
};
struct skill{
	string namaSkill;
	int durasi;
};

typedef struct elmPlayer * adr_Player;
typedef struct elmPlayerSkill * adr_Player_Skill;
typedef struct elmSkill * adr_Skill;

struct elmPlayer{
	player info;
	adr_Player_Skill child;
	adr_Player_Skill lastchild;
	adr_Player prev;
	adr_Player next;
};
struct listPlayer{
    adr_Player first;
    adr_Player last;
};
struct elmPlayerSkill{
	adr_Skill info;
	adr_Player_Skill prev;
	adr_Player_Skill next;
};
struct elmSkill{
	skill info;
	adr_Skill prev;
	adr_Skill next;
};
struct listSkill{
    adr_Skill first;
    adr_Skill last;
};
void showMenu();

void createPlayerList(listPlayer &LP);
adr_Player createElmPlayer(string namaPlayer, int umur);
void insertPlayer(listPlayer &LP, adr_Player adrPlayer);
adr_Player searchPlayer(listPlayer LP, string namaPlayer);
void deleteFirstPlayer(listPlayer &LP, adr_Player &adrPlayer);
void deleteAfterPlayer(adr_Player adrPlayerPrec, adr_Player &adrPlayer);
void deleteLastPlayer(listPlayer &LP, adr_Player &adrPlayer);
void deletePlayer(listPlayer &LP, string namaPlayer, adr_Player &deletedPlayer);
void printPlayer(player player);
void showPlayer(listPlayer LP);

void createSkillList(listSkill &LS);
adr_Skill createElmSkill(string namaSkill, int durasi);
void insertSkill(listSkill &LS, adr_Skill adrSkill);
adr_Skill searchSkill(listSkill LS, string namaSkill);
void deleteFirstSkill(listSkill &LS, adr_Skill &adrSkill);
void deleteAfterSkill(adr_Skill adrSkillPrec, adr_Skill &adrSkill);
void deleteLastSkill(listSkill &LS, adr_Skill &adrSkill);
void deleteSkill(listSkill &LS, string namaSkill, adr_Skill &deletedSkill);
void printSkill(skill skill);
void showSkill(listSkill LS);

adr_Player_Skill createElmPlayerSkill(adr_Skill adrSkill);
void giftSkill(adr_Player adrPlayer, adr_Player_Skill adrPlayerSkill);
adr_Player_Skill searchSkillinPlayer(adr_Player adrPlayer, string namaSkill);
void deleteFirstPlayerSkill(adr_Player adrPlayer, adr_Player_Skill &adrPlayerSkill);
void deleteLastPlayerSkill(adr_Player adrPlayer, adr_Player_Skill &adrPlayerSkill);
void deleteAfterPlayerSkill(adr_Player_Skill adrPlayerSkillPrec, adr_Player_Skill &adrPlayerSkill);
void deletePlayerSkill(adr_Player &adrPlayer, adr_Player_Skill adrPlayerSkill, adr_Player_Skill &deletedPlayerSkill);
void tarikSkill(adr_Player adrPlayer, adr_Player_Skill adrPlayerSkill, adr_Player_Skill &deletedPlayerSkill);
void showSkillinPlayer(adr_Player adrPlayer);
#endif // TUBES_H_INCLUDED
