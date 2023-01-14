#include <iostream>
#include "Tubes.h"
using namespace std;

void showMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << ADD_PLAYER << ". Tambahkan Player Baru" << endl;
    cout << SHOW_ALL_PLAYER_DATA << ". Tampilkan Semua Data Player"<< endl;
    cout << DELETE_PLAYER << ". Hapus Player Tertentu" << endl;
    cout << ADD_SKILL << ". Tambahkan Skill Baru" << endl;
    cout << SHOW_ALL_SKILL<< ". Tampilkan Semua Data Skill" << endl;
    cout << DELETE_SKILL << ". Hapus Skill Tertentu" << endl;
    cout << ADD_SKILL_TO << ". Tambahkan Skill Pada Player" << endl;
    cout << SHOW_ALL_SKILL_IN_PLAYER<< ". Tampilkan Semua Data Skill Yang Ada Dalam Semua Player" << endl;
    cout << DELETE_SKILL_PLAYER << ". Hapus Skill Pada Player" << endl;
    cout << SHOW_MOST_SKILL_FROM_ALL_PLAYER << ". Tampilkan Player dengan Skill Terbanyak" << endl;
    cout << EXIT << ". Keluar" << endl;
    cout << "====================================" << endl;
}
void createPlayerList(listPlayer &LP){
    first(LP) = nil;
    last(LP) = nil;
}
adr_Player createElmPlayer(string namaPlayer, int umur){
    adr_Player p = new elmPlayer;
    info(p).namaPlayer = namaPlayer;
    info(p).umur = umur;
    next(p) = nil;
    prev(p) = nil;
    child(p) = nil;
    lastchild(p) = nil;
    return p;
}
void insertPlayer(listPlayer &LP, adr_Player adrPlayer){
    if(first(LP) == nil && last(LP) == nil) {
        first(LP) = adrPlayer;
        last(LP) = adrPlayer;
        next(adrPlayer) = first(LP);
        prev(adrPlayer) = last(LP);
    }else{
        next(adrPlayer) = first(LP);
        prev(adrPlayer) = last(LP);
        next(last(LP)) = adrPlayer;
        last(LP) = adrPlayer;
        prev(first(LP)) = last(LP);
    }
}

adr_Player searchPlayer(listPlayer LP, string namaPlayer){
    adr_Player found = nil;
    if(first(LP) == nil && last(LP) == nil) {
        return nil;
    }else{
        adr_Player p = first(LP);
        while(next(p) != first(LP) && found == nil) {
            if(info(p).namaPlayer == namaPlayer) {
                found = p;
            }
            p = next(p);
        }
        if(found == nil && info(p).namaPlayer == namaPlayer){
            found = p;
        }
    }
    return found;
}
void deleteFirstPlayer(listPlayer &LP, adr_Player &adrPlayer){
    if(first(LP) == nil && last(LP) == nil) {
        cout << "Tidak ada Player yang dihapus" << endl;
    } else if(next(first(LP)) == first(LP)) {
        adrPlayer = first(LP);
        first(LP) = nil;
        last(LP) = nil;
    } else {
        adrPlayer = first(LP);
        first(LP) = next(first(LP));
        next(last(LP)) = first(LP);
        prev(first(LP)) = last(LP);
        next(adrPlayer) = nil;
        prev(adrPlayer) = nil;
    }
}
void deleteAfterPlayer(adr_Player adrPlayerPrec, adr_Player &adrPlayer){
    adrPlayer = next(adrPlayerPrec);
    next(adrPlayerPrec) = next(adrPlayer);
    prev(next(adrPlayer)) = adrPlayerPrec;
    prev(adrPlayer) = nil;
    next(adrPlayer) = nil;
}
void deleteLastPlayer(listPlayer &LP, adr_Player &adrPlayer){
    if(first(LP) == nil && last(LP) == nil) {
        cout << "Tidak ada Player yang dihapus" << endl;
    } else if(next(first(LP)) == first(LP)) {
        adrPlayer = first(LP);
        first(LP) = nil;
        last(LP) = nil;
    } else {
        adrPlayer = last(LP);
        last(LP) = prev(last(LP));
        prev(first(LP)) = last(LP);
        next(last(LP)) = first(LP);
        next(adrPlayer) = nil;
        prev(adrPlayer) = nil;
    }
}
void deletePlayer(listPlayer &LP, string namaPlayer, adr_Player &deletedPlayer){
    adr_Player searchPlayerData = searchPlayer(LP, namaPlayer);
    if(searchPlayerData != NULL) {
        if(searchPlayerData == first(LP)) {
            deleteFirstPlayer(LP, deletedPlayer);
        } else if(searchPlayerData == last(LP) && next(searchPlayerData) == first(LP)) {
            deleteLastPlayer(LP, deletedPlayer);
        } else {
            deleteAfterPlayer(prev(searchPlayerData), deletedPlayer);
        }
    } else {
        cout << "Player yang dicari tidak ada" << endl << endl;
    }
}
void printPlayer(player player) {
    cout << "Nama Player : " << player.namaPlayer<< endl;
    cout << "Umur        : " << player.umur<< endl;
}
void showPlayer(listPlayer LP) {
    adr_Player adrLP;

    if(first(LP) == nil && last(LP) == nil){
        cout << "Empty List" << endl;
    }else{
        adrLP = first(LP);
        int counter = 1;
        while(adrLP != last(LP)){
            cout << "============= Player " << counter << " =============" << endl;
            printPlayer(info(adrLP));
            counter += 1;
            adrLP = next(adrLP);
        }
        cout << "============= Player " << counter << " =============" << endl;
        printPlayer(info(last(LP)));
    }
}
void createSkillList(listSkill &LS){
    first(LS) = nil;
    last(LS) = nil;
}
adr_Skill createElmSkill(string namaSkill, int durasi){
    adr_Skill s = new elmSkill;
    info(s).namaSkill = namaSkill;
    info(s).durasi = durasi;
    next(s) = nil;
    prev(s) = nil;
    return s;
}
void insertSkill(listSkill &LS, adr_Skill adrSkill){
    if(first(LS) == nil && last(LS) == nil) {
        first(LS) = adrSkill;
        last(LS) = adrSkill;
        next(adrSkill) = first(LS);
        prev(adrSkill) = last(LS);
    }else{
        next(adrSkill) = first(LS);
        prev(adrSkill) = last(LS);
        next(last(LS)) = adrSkill;
        last(LS) = adrSkill;
        prev(first(LS)) = last(LS);
    }
}
//searchSkill
adr_Skill searchSkill(listSkill LS, string namaSkill){
    adr_Skill found = nil;
    if(first(LS) == nil && last(LS) == nil) {
        cout<<"Empty List"<<endl;
    }else{
        adr_Skill s = first(LS);
        while(next(s) != first(LS) && found == nil) {
            if(info(s).namaSkill == namaSkill) {
                found = s;
            }
            s = next(s);
        }
    }
    return found;
}
void deleteFirstSkill(listSkill &LS, adr_Skill &adrSkill){
    if(first(LS) == nil && last(LS) == nil) {
        cout << "Tidak ada Skill yang dihapus" << endl;
    } else if(next(first(LS)) == first(LS)) {
        adrSkill = first(LS);
        first(LS) = nil;
        last(LS) = nil;
    } else {
        adrSkill = first(LS);
        first(LS) = next(first(LS));
        next(last(LS)) = first(LS);
        prev(first(LS)) = last(LS);
        next(adrSkill) = nil;
        prev(adrSkill) = nil;
    }
}
void deleteAfterSkill(adr_Skill adrSkillPrec, adr_Skill &adrSkill){
    adrSkill = next(adrSkillPrec);
    next(adrSkillPrec) = next(adrSkill);
    prev(next(adrSkill)) = adrSkillPrec;
    prev(adrSkill) = nil;
    next(adrSkill) = nil;
}
void deleteLastSkill(listSkill &LS, adr_Skill &adrSkill){
    if(first(LS) == nil && last(LS) == nil) {
        cout << "Tidak ada Skill yang dihapus" << endl;
    } else if(next(first(LS)) == first(LS)) {
        adrSkill = first(LS);
        first(LS) = nil;
        last(LS) = nil;
    } else {
        adrSkill = last(LS);
        last(LS) = prev(last(LS));
        prev(first(LS)) = last(LS);
        next(last(LS)) = first(LS);
        next(adrSkill) = nil;
        prev(adrSkill) = nil;
    }
}
void deleteSkill(listSkill &LS, string namaSkill, adr_Skill &deletedSkill){
    adr_Skill searchSkillData = searchSkill(LS, namaSkill);
    if(searchSkillData != nil) {
        if(searchSkillData == first(LS)) {
            deleteFirstSkill(LS, deletedSkill);
        } else if(searchSkillData == last(LS) && next(searchSkillData) == first(LS)) {
            deleteLastSkill(LS, deletedSkill);
        } else {
            deleteAfterSkill(prev(searchSkillData), deletedSkill);
        }
    } else {
        cout << "Skill yang dicari tidak ada" << endl << endl;
    }
}
void printSkill(skill skill) {
    cout << "Nama Skill : " << skill.namaSkill<< endl;
    cout << "Durasi     : " << skill.durasi<< endl;
}
void showSkill(listSkill LS) {
    adr_Skill adrLS;

    if(first(LS) == nil && last(LS) == nil){
        cout << "Empty List" << endl;
    }else{
        adrLS = first(LS);
        int counter = 1;
        while(adrLS != last(LS)){
            cout << "============= Skill " << counter << " =============" << endl;
            printSkill(info(adrLS));
            counter += 1;
            adrLS = next(adrLS);
        }
        cout << "============= Skill " << counter << " =============" << endl;
        printSkill(info(last(LS)));
    }
}
adr_Player_Skill createElmPlayerSkill(adr_Skill adrSkill){
    adr_Player_Skill adrPlayerSkill = new elmPlayerSkill;
    info(adrPlayerSkill) = adrSkill;
    next(adrPlayerSkill) = nil;
    prev(adrPlayerSkill) = nil;
    return adrPlayerSkill;
}
void giftSkill(adr_Player adrPlayer, adr_Player_Skill adrPlayerSkill){
    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        child(adrPlayer) = adrPlayerSkill;
        lastchild(adrPlayer) = adrPlayerSkill;
    } else {
        prev(adrPlayerSkill) = lastchild(adrPlayer);
        next(lastchild(adrPlayer)) = adrPlayerSkill;
        lastchild(adrPlayer) = adrPlayerSkill;
    }
}
adr_Player_Skill searchSkillinPlayer(adr_Player adrPlayer, string namaSkill) {
    adr_Player_Skill found = nil;

    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        cout << "Tidak ada Skill dalam Player ini" << endl;
    } else {
        adr_Player_Skill trace = child(adrPlayer);
        while(trace != nil && found == nil) {
            if(info(info(trace)).namaSkill == namaSkill) {
                found = trace;
            }
            trace = next(trace);
        }
    }
    return found;
}
void deleteFirstPlayerSkill(adr_Player adrPlayer, adr_Player_Skill &adrPlayerSkill){
    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        cout << "Tidak ada Skill" << endl;
    } else {
        adrPlayerSkill = child(adrPlayer);
        if(child(adrPlayer) == lastchild(adrPlayer)) {
            child(adrPlayer) = nil;
            lastchild(adrPlayer) = nil;
        } else {
            child(adrPlayer) = next(adrPlayerSkill);
            next(adrPlayerSkill) = nil;
            prev(child(adrPlayer)) = nil;
        }
    }
}
void deleteLastPlayerSkill(adr_Player adrPlayer, adr_Player_Skill &adrPlayerSkill){
    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        cout << "Tidak ada Skill" << endl;
    } else {
        adrPlayerSkill = lastchild(adrPlayer);
        if(child(adrPlayer) == lastchild(adrPlayer)) {
            child(adrPlayer) = nil;
            lastchild(adrPlayer) = nil;
        } else {
            lastchild(adrPlayer) = prev(lastchild(adrPlayer));
            prev(adrPlayerSkill) = nil;
            next(lastchild(adrPlayer)) = nil;
        }
    }
}
void deleteAfterPlayerSkill(adr_Player_Skill adrPlayerSkillPrec, adr_Player_Skill &adrPlayerSkill){
    adrPlayerSkill = next(adrPlayerSkillPrec);
    next(adrPlayerSkillPrec) = next(adrPlayerSkill);
    prev(next(adrPlayerSkill)) = adrPlayerSkillPrec;
    prev(adrPlayerSkill) = nil;
    next(adrPlayerSkill) = nil;
}
void deletePlayerSkill(adr_Player &adrPlayer, adr_Player_Skill adrPlayerSkill, adr_Player_Skill &deletedPlayerSkill){
    if(adrPlayerSkill != nil){
        if(adrPlayerSkill == child(adrPlayer)) {
            deleteFirstPlayerSkill(adrPlayer, deletedPlayerSkill);
        } else if(adrPlayerSkill == lastchild(adrPlayer)) {
            deleteLastPlayerSkill(adrPlayer, deletedPlayerSkill);
        } else {
            deleteAfterPlayerSkill(prev(adrPlayerSkill), deletedPlayerSkill);
        }
    } else {
        cout << "Skill yang dicari tidak ada" << endl << endl;
    }
}
void tarikSkill(adr_Player adrPlayer, adr_Player_Skill adrPlayerSkill, adr_Player_Skill &deletedPlayerSkill) {
    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        cout << "Tidak ada data Skill" << endl;
    } else {
        deletePlayerSkill(adrPlayer, adrPlayerSkill, deletedPlayerSkill);
    }
}
void showSkillinPlayer(adr_Player adrPlayer) {
    if(child(adrPlayer) == nil && lastchild(adrPlayer) == nil) {
        cout << "Tidak memiliki Skill" << endl;
    } else {
        adr_Player_Skill trace = child(adrPlayer);
        int counter = 1;
        while(trace != child(adrPlayer)) {
            cout << "============= Skill " << counter << " =============" << endl;
            printSkill(info(info(trace)));
            counter += 1;
            trace = next(trace);
        }
        cout << "============= Skill " << counter << " =============" << endl;
        printSkill(info(info(lastchild(adrPlayer))));
        printSkill(info(info(prev(lastchild(adrPlayer)))));
    }
}
