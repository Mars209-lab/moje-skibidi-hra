#include <iostream>
using namespace std;
int fakeRandom(string input, int max) {
    int sum = 0;
    for (char c : input) {
        sum += c;
    }
    return (sum % max) + 1;
}




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
    int zlataky = 15;

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
    cout << "_____________________________________________" << endl;
    string volbavesnice;
    cout << "dorazil jsi do vesnice" << endl;
    cout << "mas " << zlataky << " zlataku" << endl;

    while (true){
        cout << "co chces delat? (napis cislo)" << endl;
        cout << "1 - doplnit zivoty (3 zlataky)" << endl;
        cout << "2 - zvysit max zivoty o 1 (5 zlataku)" << endl;
        cout << "3 - zvysit max manu o 1 (5 zlataku)" << endl;
        cout << "4 - zvysit utok o 1 (7 zlataku)" << endl;
        cout << "5 - odejit z vesnice" << endl;
        cin >> volbavesnice;

        if (volbavesnice == "1"){
            if (zlataky >= 3){
                hp = maxhp;
                zlataky -= 3;
                cout << "zivoty doplneny, mas ted " << hp << "/" << maxhp << " zivotu" << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
            }
        }else if (volbavesnice == "2"){
            if (zlataky >= 5){
                maxhp += 1;
                zlataky -= 5;
                cout << "max zivoty zvyseny na " << maxhp << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
            }
        }else if (volbavesnice == "3"){
            if (zlataky >= 5){
                maxmana += 1;
                zlataky -= 5;
                cout << "max mana zvysena na " << maxmana << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
            }
        }else if (volbavesnice == "4"){
            if (zlataky >= 7){
                utok += 1;
                zlataky -= 7;
                cout << "utok zvysen na " << utok << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
            }
        }else if (volbavesnice == "5"){
            cout << "opoustis vesnici" << endl;
            break;
        }else{
            cout << "neplatna volba" << endl;
        }
    }
    cout << endl;
    cout << "________________________________________" << endl;
    cout << "statistiky po vesnici:" << endl;;
    cout << "zivoty: " << hp << "/" << maxhp << endl;
    cout << "mana: " << mana << "/" << maxmana << endl;
    cout << "utok: " << utok << endl;
    cout << "zlataky: " << zlataky << endl;
    cout << "________________________________________" << endl;

    cout << "vstupujes do divoke divociny kde na tebe cihaji ruzne nepratele" << endl;

    string ready;
    cout << "jake je tvoje oblibene cislo? (1, 2, 3) :";
    cin >> ready;

    int monstrumtyp = fakeRandom (ready, 3);

    string jmenomonstra;
    int monstrumHP;
    int monstrumAT;

    if (monstrumtyp == 1) {
        jmenomonstra = "Zavrhelix ";
        monstrumHP = 6;
        monstrumAT = 3;
    }else if (monstrumtyp == 2){
        jmenomonstra = "Morvyn";
        monstrumHP = 10;
        monstrumAT = 5;
    }else{
        jmenomonstra = "drexil";
        monstrumHP = 15;
        monstrumAT = 10;
    }
    cout << "potkal jsi " << jmenomonstra << " ( " << monstrumHP << " zivotu, utok " << monstrumAT << " ) " << endl;

    while (hp > 0 && monstrumHP > 0) {
        string akce;
        cout << "co chces delat???  " << endl;
        cout << "1 - utok" << endl;
        cout << "2 - utek" << endl;
        cout << "vyber akci: " << endl;
        cin >> akce;

        if  (akce == "1"){
            monstrumHP -= utok;
            cout << "zautocil jsi a poskodil jsi nepritele o " << utok << endl;

            if (monstrumHP <= 0) {
                cout << "porazil jsi: " << jmenomonstra << "gratulace "<< endl;
                zlataky += 5;
                cout << "ziskal jsi 5 zlataku, ted mas " << zlataky << " zlataku " << endl;
                break;
            }

            hp -= monstrumAT;
            cout << jmenomonstra << "nepritel te poskodil o " << monstrumAT << endl;

            if (hp <= 0){
                cout << jmenomonstra << "te porazil a umiras" << endl;
                break;
            }
        }else if (akce == "2"){
            string pokusutek;
            cout << "napis cim chces monstrum rozptilit: " << endl;
            cin >> pokusutek;
            int uteksance = fakeRandom (pokusutek, 2);

            if (uteksance == 1){
                cout << "utekl jsi gratulace" << endl;
                break;
            }else{
                cout << "utek se ti nepovedl" <<endl;
                hp -= monstrumAT;
                cout << jmenomonstra << "ti pri pokus o utek udelil " << monstrumAT << "poskozeni" << endl;

                if (hp <= 0) {
                    cout << "pri tvem pokusu o utek jsi byl zabit " << endl;
                    break;
                }
            }
        }else {
            cout << "neplatna volba" << endl;
        }
    }
    cout << "konec souboje" << endl;
    cout << "tve aktualni statistiky: " << endl;
    cout << "zivoty: " << hp << "/" << maxhp << endl;
    cout << "mana: " << mana << "/" << maxmana << endl;
    cout << "utok: " << utok << endl;
    cout << "zlataky: " << zlataky << endl;

    return 0;
}






