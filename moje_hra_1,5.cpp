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
    int specialniutok = 0;

    cout << "zadej sve jmeno bojovniku: ";
    cin >> jmeno;

    while (potvrzeni !="ano") {
        cout << "vyber si svoji classu (samurai, rytir, kocicka, zlodej, ninja) " << endl;
        cout << "zadej nazev sve vysnene classy: " ;
        cin >> volba;
        cout << "_________________________________________________________________________________________________" << endl;
        if (volba == "samurai"){
            cout << "classa: samurai" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 10" << endl;
            cout << "utok = 4" << endl;
            cout << "mana = 5" << endl;
            cout << "specialni perky:" << endl;
            cout << "utok krvavou katanou (plosny utok) za 2 poskozeni navic, hituje vic nepratel na jednou" << endl;
            cout << "dark spell, zmateni nepritele (nepritel ztraci tah)" << endl;

        }else if (volba == "rytir"){
            cout << "classa: rytir" << endl;
            cout << "statistiky:" << endl;
            cout << "zivoty = 12" << endl;
            cout << "utok = 3" << endl;
            cout << "mana = 6" << endl;
            cout << "specialni perky:" << endl;
            cout << "mec na na vic, dvojite pozkozeni, dvakrat vetsi spotreba many na utok" << endl;
            cout << "hazeci kudla, vetsi sance na kriticke pozkozeni" << endl;

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
        cout << "______________________________________________________________________________________________________________" << endl;
    }

    classa = volba;

    if (classa == "samurai"){
        maxhp = hp = 10;
        maxmana = mana = 5;
        utok = 4;
        specialniutok = utok + 2;
    }else if (classa == "rytir"){
        maxhp = hp = 12;
        maxmana = mana = 6;
        utok = 3;
        specialniutok = utok * 2;
    }else if (classa == "kocicka"){
        maxhp = hp = 9;
        maxmana = mana = 7;
        utok = 4;
        specialniutok = 8;
    }else if (classa == "zlodej"){
        maxhp = hp = 12;
        maxmana = mana = 8;
        utok = 3;
    }else if (classa == "ninja"){
        maxhp = hp = 13;
        maxmana = mana = 9;
        utok = 5;
        specialniutok = 9;
    }

    cout << "vitej " << jmeno << endl;
    cout << "tva classa je: " << classa << endl;
    cout << "zivoty: " << hp << "/" << maxhp << ", mana: " << mana << "/" << maxmana << ", utok: " << utok << endl;
    cout << "_____________________________________________" << endl;
    string volbavesnice;
    cout << "tvuj ukol " << jmeno << " je najit a zneskodnit monstrum jez je hluboko ve vnitrozemi teto krajiny, na tve ceste te budu samozrejme doprovazet, preju hodne stesti" << endl;
    cout << "vypadas slabe co takhle jit se trochu vyzbrojit?" << endl;
    cout << "v dalce se rozsviti svetlo a rozhodnes se za nim jit" << endl;
    cout << "dorazil jsi do vesnice" << endl;
    cout << "asi u sebe moc penez nemas co?" << endl;
    cout << "tu mas par zlataku at mi hned neumres" << endl;
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
                cout << "______________________________________________________________________________" << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
                cout << "______________________________________________________________________________" << endl;
            }
        }else if (volbavesnice == "2"){
            if (zlataky >= 5){
                maxhp += 1;
                zlataky -= 5;
                cout << "max zivoty zvyseny na " << maxhp << endl;
                cout << "______________________________________________________________________________" << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
                cout << "______________________________________________________________________________" << endl;
            }
        }else if (volbavesnice == "3"){
            if (zlataky >= 5){
                maxmana += 1;
                zlataky -= 5;
                cout << "max mana zvysena na " << maxmana << endl;
                cout << "______________________________________________________________________________" << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
                cout << "______________________________________________________________________________" << endl;
            }
        }else if (volbavesnice == "4"){
            if (zlataky >= 7){
                utok += 1;
                zlataky -= 7;
                cout << "utok zvysen na " << utok << endl;
                cout << "______________________________________________________________________________" << endl;
            }else{
                cout << "nemas dost zlataku" << endl;
                cout << "______________________________________________________________________________" << endl;
            }
        }else if (volbavesnice == "5"){
            cout << "opoustis vesnici" << endl;
            cout << "______________________________________________________________________________" << endl;
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

    cout << "je na case aby jsi vyrazil obyvatele vesnic se obavaji utoku tak sup sup" << endl;
    cout << "vstupujes do lesa " << endl;

    string ready;
    cout << "mam takovou otazku: " << endl;
    cout << "jake je tvoje oblibene cislo z techto peti? (1, 2, 3, 4, 5) :";
    cin >> ready;

    int pocetsouboju = fakeRandom(ready, 3) + 2;
    cout << "v lese te ceka " << pocetsouboju << " nepratel" << endl;

    for (int souboj = 1; souboj <= pocetsouboju; ++souboj) {
        cout << "_________________________________________" << endl;
        cout << "Souboj " << souboj << " z " << pocetsouboju << endl;

    int monstrumtyp = fakeRandom(jmeno + to_string(souboj), 5);
    string jmenomonstra;
    int monstrumHP;
    int monstrumAT;

    if (monstrumtyp == 1){
        jmenomonstra = "Zavrhelix";
        monstrumHP = 6;
        monstrumAT = 3;
        cout << "velmi slaby a nemotorny tohle je ez (doufam)" << endl;
    }else if (monstrumtyp == 2){
        jmenomonstra = "Morvyn";
        monstrumHP = 10;
        monstrumAT = 5;
        cout << "takovej mensi tank hodne zivotu ale slabsi utok" << endl;
    }else if (monstrumtyp == 3) {
        jmenomonstra = "Drexil";
        monstrumHP = 15;
        monstrumAT = 10;
        cout << "umm....." << endl;
    }else if (monstrumtyp == 4) {
        jmenomonstra = "Strom";
        monstrumHP = 8;
        monstrumAT = 2;
        cout << "well co jsem jeste nevidel?" << endl;
    }else if (monstrumtyp == 5) {
        jmenomonstra = "Medvidek";
        monstrumHP = 20;
        monstrumAT = 8;
        cout << "juuuuuuuu meda beda" << endl;
    }

    cout << "potkal jsi " << jmenomonstra << " (" << monstrumHP << " zivotu, utok " << monstrumAT << ") " << endl;

    while (hp > 0 && monstrumHP > 0){
        string akce;
        cout << "co chces delat???" << endl;
        cout << "1 - utok" << endl;
        cout << "2 - specialni utok " << endl;
        cout << "3 - utek" << endl;
        cout << "vyber akci: ";
        cin >> akce;

        if (akce == "1"){
            if (mana < 1) {
                cout << "nedostatek many na utok" << endl;
                continue;
            }
            monstrumHP -= utok;
            mana -= 1;
            cout << "zautocil jsi a poskodil jsi nepritele o " << utok << " zivotu" << endl;

        }else if (akce == "3"){
            string pokusutek;
            cout << "napis cim chces monstrum rozptilit: ";
            cin >> pokusutek;
            int uteksance = fakeRandom(pokusutek, 2);

            if (uteksance == 1){
                cout << "utekl jsi gratulace" << endl;
                break;
            }else{
                cout << "utek se ti nepovedl" << endl;
                hp -= monstrumAT / 2;
                cout << jmenomonstra << " ti pri pokusu o utek udelil " << monstrumAT << " poskozeni" << endl;
            }

        }else if (akce == "2"){
            if (mana < 3) {
                cout << "nemas dost many na specialni utok!" << endl;
                continue;
            }

            if (classa == "samurai"){
                cout << "pouzivas krvavou katanu plosny utok" << endl;
                cout << "poskodil jsi nepritele o " << specialniutok << " zivotu" << endl;
                monstrumHP -= 6;
                mana -= 3;
            }else if (classa == "rytir"){
                cout << "pouzivas mec na na vic dvojite poskozeni" << endl;
                cout << "poskodil jsi nepritele o " << specialniutok << " zivotu" << endl;
                monstrumHP -= utok * 2;
                mana -= 4;
            }else if (classa == "kocicka"){
                cout << "vrhas smrtelne klubicko" << endl;
                cout << "poskodil jsi nepritele o " << specialniutok << " zivotu" << endl;
                monstrumHP -= 8;
                mana -= 5;
            }else if (classa == "zlodej"){
                cout << "provedl jsi kradez vybaveni a utocis" << endl;
                cout << "poskodil jsi nepritele o " << utok << " zivoty" << endl;
                monstrumHP -= 3;
                mana -= 3;
                monstrumAT = 0;
            }else if (classa == "ninja"){
                cout << "vrhas 3 surikeny" << endl;
                cout << "poskodil jsi nepritele o " << specialniutok << " zivotu" << endl;
                monstrumHP -= 9;
                mana -= 5;
            }

        }else{
            cout << "neplatna volba" << endl;
            continue;
        }

        if (monstrumHP <= 0){
            cout << "porazil jsi " << jmenomonstra << ", gratulace!" << endl;
            zlataky += 5;
            cout << "ziskal jsi 5 zlataku, ted mas " << zlataky << " zlataku" << endl;
            break;
        }

        if (monstrumAT > 0){
            hp -= monstrumAT;
            cout << jmenomonstra << " ti udelil " << monstrumAT << " poskozeni" << endl;
        }else{
            cout << jmenomonstra << " je omameny a neutoci" << endl;
            if (classa == "zlodej"){
                monstrumAT = (monstrumtyp == 1) ? 3 : (monstrumtyp == 2) ? 5 : 10;
            }
        }

        if (hp <= 0){
            cout << jmenomonstra << " te porazil a umiras" << endl;
            break;
        }

        int regeneracemany = 0;
        if (classa == "samurai") regeneracemany = 1;
        else if (classa == "rytir") regeneracemany = 1;
        else if (classa == "kocicka") regeneracemany = 2;
        else if (classa == "zlodej") regeneracemany = 2;
        else if (classa == "ninja") regeneracemany = 3;

        mana += regeneracemany;
        if (mana > maxmana) mana = maxmana;
        cout << "regenerujes " << regeneracemany << " many mas ted " << mana << "/" << maxmana << endl;
        cout << "zivoty: " << hp << "/" << maxhp << ", mana: " << mana << "/" << maxmana << endl;
    }

    if (hp <= 0){
        cout << "tvuj pribeh zde konci..." << endl;
        break;
    }

 }

    return 0;
}


