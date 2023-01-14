#include <iostream>
#include "Tubes.h"

using namespace std;

int main()
{

    player x;
    skill y;
    listPlayer LP;
    listSkill LS;
    createPlayerList(LP);
    createSkillList(LS);
    adr_Player adrPlayer,deletedPlayer,searchPlayerList,searchDeletedPlayer;
    adr_Skill adrSkill,deletedSkill,searchSkillList,searchDeletedSkill;
    string namaPlayer, namaSkill;
    int umur, durasi;

    namaPlayer = "Ronald";
    umur = 27;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Max";
    umur = 24;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Jules";
    umur = 18;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Lalatina";
    umur = 24;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Rose";
    umur = 21;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Antonia";
    umur = 27;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);
    namaPlayer = "Karna";
    umur = 30;
    adrPlayer = createElmPlayer(namaPlayer,umur);
    insertPlayer(LP, adrPlayer);

    namaSkill = "Blessing";
    durasi = 45;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "Invincible";
    durasi = 30;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "Healing";
    durasi = 45;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "MultipleStrong";
    durasi = 30;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "Dreamin";
    durasi = 25;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "MultipleStamina";
    durasi = 30;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);
    namaSkill = "Brahmastra";
    durasi = 45;
    adrSkill = createElmSkill(namaSkill,durasi);
    insertSkill(LS, adrSkill);

    adrPlayer = first(LP);
    adrSkill = first(LS);

    searchPlayerList = searchPlayer(LP, "Karna");
    searchSkillList = searchSkill(LS, "Brahmastra");
    adr_Player_Skill newPlayerSkill = createElmPlayerSkill(searchSkillList);
    giftSkill(searchPlayerList, newPlayerSkill);
    searchPlayerList = searchPlayer(LP, "Karna");
    searchSkillList = searchSkill(LS, "Dreamin");
    newPlayerSkill = createElmPlayerSkill(searchSkillList);
    giftSkill(searchPlayerList, newPlayerSkill);
    searchPlayerList = searchPlayer(LP, "Karna");
    searchSkillList = searchSkill(LS, "MultipleStrong");
    newPlayerSkill = createElmPlayerSkill(searchSkillList);
    giftSkill(searchPlayerList, newPlayerSkill);
    searchPlayerList = searchPlayer(LP, "Rose");
    searchSkillList = searchSkill(LS, "Dreamin");
    newPlayerSkill = createElmPlayerSkill(searchSkillList);
    giftSkill(searchPlayerList, newPlayerSkill);
    searchPlayerList = searchPlayer(LP, "Max");
    searchSkillList = searchSkill(LS, "Invincible");
    newPlayerSkill = createElmPlayerSkill(searchSkillList);
    giftSkill(searchPlayerList, newPlayerSkill);

    adrPlayer = first(LP);
    adrSkill = first(LS);

    showMenu();
    int choose;
    cout << "Pilih Menu : ";
    cin >> choose;
    while(choose != EXIT){
        switch(choose){
            case ADD_PLAYER:system("cls");{
                cout<<"Nama Player  : "; cin>>namaPlayer;
                cout<<"Umur         : "; cin>>umur;
                adrPlayer = createElmPlayer(namaPlayer,umur);
                insertPlayer(LP, adrPlayer);
                break;
            }
            case SHOW_ALL_PLAYER_DATA:system("cls");{
                showPlayer(LP);
                break;
            }
            case DELETE_PLAYER:system("cls");{
                cout<<"Masukkan Nama Player : "; cin>>namaPlayer;
                deletePlayer(LP, namaPlayer, deletedPlayer);
                searchDeletedPlayer = searchPlayer(LP, namaPlayer);
                if(searchDeletedPlayer == nil) {
                    cout << "Player Berhasil Dihapus " << namaPlayer << endl;
                }
                break;
            }
            case ADD_SKILL:system("cls");{
                cout<<"Nama Skill  : "; cin>>namaSkill;
                cout<<"Durasi      : "; cin>>durasi;
                adrSkill = createElmSkill(namaSkill,durasi);
                insertSkill(LS, adrSkill);
            }
            case SHOW_ALL_SKILL:system("cls");{
                showSkill(LS);
                break;
            }
            case DELETE_SKILL:system("cls");{
                cout<<"Masukkan Nama Skill : "; cin>>namaSkill;
                deleteSkill(LS, namaSkill, deletedSkill);
                searchDeletedSkill = searchSkill(LS, namaSkill);
                if(searchDeletedSkill == nil) {
                    cout << "Skill Berhasil Dihapus " << namaSkill << endl;
                }
                break;
            }
            case ADD_SKILL_TO:system("cls");{
                showPlayer(LP);
                cout<<"Masukkan Nama Player : "; cin>>namaPlayer;
                searchPlayerList = searchPlayer(LP, namaPlayer);
                if(searchPlayerList != nil){
                    showSkill(LS);
                    cout<<"Masukkan Nama Skill  : "; cin>>namaSkill;
                    searchSkillList = searchSkill(LS, namaSkill);
                    if(searchSkillList != nil){
                        newPlayerSkill = createElmPlayerSkill(searchSkillList);
                        giftSkill(searchPlayerList, newPlayerSkill);
                        cout<<"Skill "<<namaSkill<<" Berhasil Ditambahkan ke Player "<<namaPlayer<<endl;
                    }
                }
                break;
            }
            case SHOW_ALL_SKILL_IN_PLAYER:system("cls");{
                showPlayer(LP);
                cout<<"Masukkan Nama Player : "; cin>>namaPlayer;
                searchPlayerList = searchPlayer(LP, namaPlayer);
                if(searchPlayerList != nil) {
                    showSkillinPlayer(searchPlayerList);
                }
                break;
            }
            case DELETE_SKILL_PLAYER:system("cls");{
                adr_Player_Skill searchSkillPlayer, deletedPlayerSkill;
                cout<<"Masukkan Nama Player : "; cin>>namaPlayer;
                searchPlayerList = searchPlayer(LP, namaPlayer);
                if(searchPlayerList != nil){
                    cout<<"Masukkan Nama Skill  : "; cin>>namaSkill;
                    searchSkillPlayer = searchSkillinPlayer(searchPlayerList,namaSkill);
                    if(searchSkillPlayer != nil){
                        tarikSkill(searchPlayerList, searchSkillPlayer, deletedPlayerSkill);
                    }
                    cout<<"Skill "<<namaSkill<<" Berhasil Dihapus Dari Player "<<namaPlayer<<endl;
                }
                break;
            }
            case SHOW_MOST_SKILL_FROM_ALL_PLAYER:system("cls");{}
        }
        if(choose == 2 || choose == 5 || choose == 8 || choose == 9){
            showMenu();
        }else{
            system("cls");
            showMenu();
        }
        cout << "Pilih Menu : "; cin >> choose;
    }
    cout << "Happy Editing Player" << endl;
    return 0;
}
