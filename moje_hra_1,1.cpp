#include <iostream>
using namespace std;

int main(){
    string jmeno;
    string volba;
    string potvrzeni = "ne";
    string classa;
    int hp = 0;
    int maxhp = 0;
    int mana = 0;
    int maxmana = 0;
    int utok = 0;
    int zlataky = 10;

    cout << "zadej sve jmeno bojovniku: ";
    cin >> jmeno;

    while (potvrzeni !="ano") {
        cout << "vyber si svoji classu (samurai, rytir, kocicka, zlodej, ninja)";
        cout << "zadej nazev sve vysnene classy: ";
        cin >> volba;

        if (volba == "samurai"){
            cout << "classa: samurai" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 10" << endl;
            cout << "utok = 4" << endl;
            cout << "mana = 5" << endl;
            cout << "specialni perky:" << endl;
            cout << "utok krvavou katanou (plosny utok) za 2 poskozeni, hituje vic nepratel na jednou" << endl;
            cout << "dark spell, zmateni nepritele (nepritel ztraci tah)" << endl;
        }else if (volba == "rytir"){
            cout << "classa: rytir" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 12" << endl;
            cout << "utok = 3" << endl;
            cout << "mana = 6" << endl;
            cout << "specialni perky:" << endl;
            cout << "mec na na vic, dvojite pozkozeni, dvakrat vetsi spotreba many na utok" << endl;
            cout << "kazeci kudla, vetsi sance na kriticke pozkozeni" << endl;
        }else if (volba == "kocicka"){
            cout << "classa: kocicka" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 9" << endl;
            cout << "utok = 4" << endl;
            cout << "mana = 7" << endl;
            cout << "specialni perky:" << endl;
            cout << "klubicko, smrtelne vrhaci klubicko, vetsi sance na kriticke pozkozeni" << endl;
            cout << "roztomilost, zmateni nepritele (nepritel ztraci tah)" << endl;
        }else if (volba == "zlodej"){
            cout << "classa: zlodej"<< endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 12" << endl;
            cout << "utok = 3" << endl;
            cout << "mana = 8" << endl;
            cout << "specialni perky:";
            cout << "kradez vybaveni, nepritel na svem pristim tahu dava 0 pozkozeni" << endl;
        }else if (volba == "ninja"){
            cout << "classa: ninja" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 13" << endl;
            cout << "utok = 5" << endl;
            cout << "mana = 9" << endl;
            cout << "specialni perky:" << endl;
            cout << "surikeny, 3 nebezpecne surikeny (kazdej suriken za 3 pozkozeni" << endl;
            cout << "sneaky peaky utok, utok ze zadu, vetsi sance na kriticke pozkozeni" << endl;
        }else{
            cout << "ngl ale neumis napsat classu tak ja k je predepsana????" << endl;
            continue;
    }
        cout << "jsi si jisty ze chces tuto classu uz ji nubudes moct zmenit? (ano / ne):" << endl;
        cin >> potvrzeni;

    }

    classa = volba;

    if (classa == "samurai"){
        maxhp = hp = 10;
        maxmana = mana = 5;
        utok = 4;
    }else if (classa == "rytir"){
        maxhp = hp = 12;
        maxmana = mana = 6;
        utok = 3;
    }else if (classa == "kocicka"){
        maxhp = hp = 9;
        maxmana = mana = 7;
        utok = 4;
    }else if (classa == "zlodej"){
        maxhp = hp = 12;
        maxmana = mana = 8;
        utok = 3;
    }else if (classa == "ninja"){
        maxhp = hp = 13;
        maxmana = mana = 9;
        utok = 5;
    }

    cout << "vitej " << jmeno << endl;
    cout << "tva classa je: " << classa << endl;
    cout << "zivoty: " << hp << "/" << maxhp << ", mana: " << mana << "/" << maxmana << ", utok: " << utok << endl;

    return 0;




}
