#include <iostream>
#include <string>
using namespace std;

int hracZivoty, hracMana, hracUtok, hracSpecial, hracZlato;
int maxZivoty, maxMana;
int hracXP = 0, hracLevel = 1, dalsiLevelXP = 20;
string classa;

int rovno(string a, string b) {
    return a == b;
}

void vypisClassy() {
    cout << "dostupne classy:\n";
    cout << "samurai - HP = 100, MP = 50, utok = 20 + perk, special = 35 atack, level = 1 (perk +10 atack)" << endl;;
    cout << "rytir - HP = 120 + perk, MP = 40, utok = 15, special = 30 atack, level = 1 (perk +20 HP)" << endl;
    cout << "kocicka - HP = 80, MP = 60 + perk, utok = 25, special = 30 atack, level = 1 (perk +10 MP)" << endl;
    cout << "zlodej - HP = 90, MP = 40, utok = 20, special = 30 + perk atack, level = 1 (perk +10 special atack)" << endl;
    cout << "ninja - HP = 90, MP = 50 + perk, utok = 20 + perk, special = 30 atack, level = 1 (perk +10 MP, +5 atack)" << endl;;
}

int vyberClassy() {
    int hotovo = 0;
    while (hotovo == 0) {
        vypisClassy();
        cout << "\nZadej nazev classy: ";
        cin >> classa;

        if (rovno(classa, "samurai")) {
            maxZivoty = 100;
            maxMana = 50;
            hracUtok = 20 + 10;
            hracSpecial = 35;
        } else if (rovno(classa, "rytir")) {
            maxZivoty = 120 + 20;
            maxMana = 40;
            hracUtok = 15;
            hracSpecial = 30;
        } else if (rovno(classa, "kocicka")) {
            maxZivoty = 80;
            maxMana = 60 + 10;
            hracUtok = 25;
            hracSpecial = 30;
        } else if (rovno(classa, "zlodej")) {
            maxZivoty = 90;
            maxMana = 40;
            hracUtok = 20;
            hracSpecial = 30 + 10;
        } else if (rovno(classa, "ninja")) {
            maxZivoty = 90;
            maxMana = 50 + 10;
            hracUtok = 20 + 5;
            hracSpecial = 30;
        } else {
            cout << "Neplatna classa. Zkus to znovu.\n";
            continue;
        }

        string potvrzeni;
        cout << "Vybral jsi classu " << classa << ". Potvrdit? (ano/ne): ";
        cin >> potvrzeni;

        if (rovno(potvrzeni, "ano")) {
            hotovo = 1;
        }
    }

    hracZivoty = maxZivoty;
    hracMana = maxMana;
    return 0;
}

void pridatXP(int xp) {
    hracXP += xp;
    cout << "Ziskal jsi " << xp << " XP. (Celkem: " << hracXP << "/" << dalsiLevelXP << ")\n";

    int leveledUp = 0;
    while (hracXP >= dalsiLevelXP) {
        hracXP -= dalsiLevelXP;
        hracLevel += 1;
        dalsiLevelXP += 10;
        leveledUp = 1;

        maxZivoty += 20;
        hracZivoty = maxZivoty;
        maxMana += 15;
        hracMana = maxMana;
        hracUtok += 10;

        cout << "Postoupil jsi na level " << hracLevel << "! (+20 HP, +15 MP, +10 utok)\n";
    }
}


int boj(string jmenoMonstra, int zivotyMonstra, int utokMonstra, int zlatoZaMonstrum) {
    cout << "\nNarazil jsi na monstrum: " << jmenoMonstra << " [" << zivotyMonstra << " HP, " << utokMonstra << " utok]\n";
    int pokracuje = 1;

    while (pokracuje == 1 && hracZivoty > 0 && zivotyMonstra > 0) {
        cout << "\nTve zivoty: " << hracZivoty << " | Tva mana: " << hracMana << "\n";
        cout << "Zivoty monstra: " << zivotyMonstra << "\n";

        cout << "Vyber akci:\n";
        cout << "1 - Normalni utok (" << hracUtok << " dmg, -5 MP)\n";
        cout << "2 - Specialni utok (" << hracUtok * 2 << " dmg, -20 MP)\n";
        cout << "3 - Utek\n";
        cout << "Zadej cislo volby: ";

        int volba;
        cin >> volba;

        if (volba == 1) {
            if (hracMana >= 5) {
                zivotyMonstra = zivotyMonstra - hracUtok;
                hracMana = hracMana - 5;
                cout << "Zautocil jsi a zpusobil " << hracUtok << " poskozeni.\n";
            } else {
                cout << "Nemas dostatek many.\n";
            }
        } else if (volba == 2) {
            if (hracMana >= 20) {
                int dmg = hracUtok * 2;
                zivotyMonstra = zivotyMonstra - dmg;
                hracMana = hracMana - 20;
                cout << "Specialni utok za " << dmg << ".\n";
            } else {
                cout << "Nemas dostatek many.\n";
            }
        } else if (volba == 3) {
            cout << "Utek.\n";
            return 1;
        } else {
            cout << "Neplatna volba.\n";
        }

        if (zivotyMonstra <= 0) {
            pridatXP(10);
            int suma = 0;
            int i = 0;
            while (jmenoMonstra[i] != '\0') {
                suma = suma + (int)jmenoMonstra[i];
                i = i + 1;
            }
            suma = suma + zlatoZaMonstrum * 3 + hracZivoty;
            int padne = 0;
            if ((suma % 100) < 50) padne = 1;

            if (padne == 1) {
                cout << "Porazil jsi " << jmenoMonstra << ". Ziskavas " << zlatoZaMonstrum << " zlataku.\n";
                hracZlato = hracZlato + zlatoZaMonstrum;
            } else {
                cout << "Porazil jsi " << jmenoMonstra << ", ale nic z nej nevypadlo.\n";
            }
            pokracuje = 0;
        } else {
            hracZivoty = hracZivoty - utokMonstra;
            cout << jmenoMonstra << " te zasahlo za " << utokMonstra << ".\n";
            if (hracZivoty <= 0) {
                cout << "Byl jsi porazen.\n";
                return 0;
            }
        }
    }
    return 1;
}

int bojDvaNepratele(string jmeno1, int zivoty1, int utok1, int zlato1, string jmeno2, int zivoty2, int utok2, int zlato2) {
    int pokracuj = 1;
    while (pokracuj == 1 && hracZivoty > 0 && (zivoty1 > 0 || zivoty2 > 0)) {
        cout << "\nTve zivoty: " << hracZivoty << " | Tva mana: " << hracMana << "\n";
        if (zivoty1 > 0) {
            cout << jmeno1 << ": " << zivoty1 << " HP\n";
        }
        if (zivoty2 > 0) {
            cout << jmeno2 << ": " << zivoty2 << " HP\n";
        }

        cout << "Vyber akci:\n";
        cout << "1 - Normalni utok (" << hracUtok << " dmg, -5 MP)\n";
        cout << "2 - Specialni utok (" << hracUtok * 2 << " dmg, -20 MP)\n";
        cout << "3 - Utek\n";
        cout << "Zadej cislo volby: ";
        int volba;
        cin >> volba;

        if (volba == 3) {
            cout << "Opustil jsi boj.\n";
            return 1;
        }

        int cil = 0;
        if ((zivoty1 > 0 && zivoty2 > 0) || (zivoty1 > 0 && zivoty2 <= 0) || (zivoty1 <= 0 && zivoty2 > 0)) {
            cout << "Na ktere monstrum utocis? (1-" << jmeno1 << ", 2-" << jmeno2 << "): ";
            cin >> cil;
        }

        int dmg = 0;
        if (volba == 1 && hracMana >= 5) {
            dmg = hracUtok;
            hracMana -= 5;
        }
        if (volba == 2 && hracMana >= 20) {
            dmg = hracUtok * 2;
            hracMana -= 20;
        }

        if (dmg > 0) {
            if (cil == 1 && zivoty1 > 0) {
                zivoty1 -= dmg;
                cout << "Zautocil jsi na " << jmeno1 << " za " << dmg << " poskozeni.\n";
            } else if (cil == 2 && zivoty2 > 0) {
                zivoty2 -= dmg;
                cout << "Zautocil jsi na " << jmeno2 << " za " << dmg << " poskozeni.\n";
            } else {
                cout << "Spatny cil nebo mrtve monstrum.\n";
            }
        }

        if (zivoty1 > 0) {
            hracZivoty -= utok1;
            cout << jmeno1 << " te zasahlo za " << utok1 << ".\n";
        }
        if (zivoty2 > 0) {
            hracZivoty -= utok2;
            cout << jmeno2 << " te zasahlo za " << utok2 << ".\n";
        }

        if (zivoty1 <= 0 && zlato1 > 0) {
            int sance = (jmeno1[0] + jmeno1[1] + hracZivoty + hracMana + hracUtok) % 2;
            if (sance == 0) {
                hracZlato += zlato1;
                cout << "Z " << jmeno1 << " padlo " << zlato1 << " zlataku.\n";
                zlato1 = 0;
            } else {
                cout << jmeno1 << " nezanechal zadne zlato.\n";
                zlato1 = 0;
            }
        }

        if (zivoty2 <= 0 && zlato2 > 0) {
            int sance = (jmeno2[0] + jmeno2[1] + hracMana + hracZivoty + hracSpecial) % 2;
            if (sance == 0) {
                hracZlato += zlato2;
                cout << "Z " << jmeno2 << " padlo " << zlato2 << " zlataku.\n";
                zlato2 = 0;
            } else {
                cout << jmeno2 << " nezanechal zadne zlato.\n";
                zlato2 = 0;
            }
        }

        if (hracZivoty <= 0) {
            cout << "Byl jsi porazen.\n";
            return 0;
        }

        if (zivoty1 <= 0 && zivoty2 <= 0) {
            cout << "Oba nepratele byli porazeni.\n";
            pridatXP(10);
            pokracuj = 0;

        }
    }

    return 1;
}

int bojTriNepratele(string jmeno1, int zivoty1, int utok1, int zlato1,
                    string jmeno2, int zivoty2, int utok2, int zlato2,
                    string jmeno3, int zivoty3, int utok3, int zlato3) {
    int pokracuj = 1;
    while (pokracuj == 1 && hracZivoty > 0 && (zivoty1 > 0 || zivoty2 > 0 || zivoty3 > 0)) {
        cout << "\nTve zivoty: " << hracZivoty << " | Tva mana: " << hracMana << "\n";
        if (zivoty1 > 0) cout << jmeno1 << ": " << zivoty1 << " HP\n";
        if (zivoty2 > 0) cout << jmeno2 << ": " << zivoty2 << " HP\n";
        if (zivoty3 > 0) cout << jmeno3 << ": " << zivoty3 << " HP\n";

        cout << "Vyber akci:\n";
        cout << "1 - Normalni utok (" << hracUtok << " dmg, -5 MP)\n";
        cout << "2 - Specialni utok (" << hracUtok * 2 << " dmg, -20 MP)\n";
        cout << "3 - Utek\n";
        cout << "Zadej cislo volby: ";
        int volba;
        cin >> volba;

        if (volba == 3) {
            cout << "Opustil jsi boj.\n";
            return 1;
        }

        int cil = 0;
        if ((zivoty1 > 0 || zivoty2 > 0 || zivoty3 > 0)) {
            cout << "Na ktere monstrum utocis? (1-" << jmeno1 << ", 2-" << jmeno2 << ", 3-" << jmeno3 << "): ";
            cin >> cil;
        }

        int dmg = 0;
        if (volba == 1 && hracMana >= 5) {
            dmg = hracUtok;
            hracMana -= 5;
        }
        if (volba == 2 && hracMana >= 20) {
            dmg = hracUtok * 2;
            hracMana -= 20;
        }

        if (dmg > 0) {
            if (cil == 1 && zivoty1 > 0) {
                zivoty1 -= dmg;
                cout << "Zautocil jsi na " << jmeno1 << " za " << dmg << " poskozeni.\n";
            } else if (cil == 2 && zivoty2 > 0) {
                zivoty2 -= dmg;
                cout << "Zautocil jsi na " << jmeno2 << " za " << dmg << " poskozeni.\n";
            } else if (cil == 3 && zivoty3 > 0) {
                zivoty3 -= dmg;
                cout << "Zautocil jsi na " << jmeno3 << " za " << dmg << " poskozeni.\n";
            } else {
                cout << "Spatny cil nebo mrtve monstrum.\n";
            }
        }

        if (zivoty1 > 0) {
            hracZivoty -= utok1;
            cout << jmeno1 << " te zasahlo za " << utok1 << ".\n";
        }
        if (zivoty2 > 0) {
            hracZivoty -= utok2;
            cout << jmeno2 << " te zasahlo za " << utok2 << ".\n";
        }
        if (zivoty3 > 0) {
            hracZivoty -= utok3;
            cout << jmeno3 << " te zasahlo za " << utok3 << ".\n";
        }

        if (zivoty1 <= 0 && zlato1 > 0) {
            int sance = (jmeno1[0] + hracZivoty + hracMana + hracUtok) % 2;
            if (sance == 0) {
                hracZlato += zlato1;
                cout << "Z " << jmeno1 << " padlo " << zlato1 << " zlataku.\n";
            } else {
                cout << jmeno1 << " nezanechal zadne zlato.\n";
            }
            zlato1 = 0;
        }
        if (zivoty2 <= 0 && zlato2 > 0) {
            int sance = (jmeno2[0] + hracZivoty + hracMana + hracSpecial) % 2;
            if (sance == 0) {
                hracZlato += zlato2;
                cout << "Z " << jmeno2 << " padlo " << zlato2 << " zlataku.\n";
            } else {
                cout << jmeno2 << " nezanechal zadne zlato.\n";
            }
            zlato2 = 0;
        }
        if (zivoty3 <= 0 && zlato3 > 0) {
            int sance = (jmeno3[0] + hracZivoty + hracMana + hracSpecial) % 2;
            if (sance == 0) {
                hracZlato += zlato3;
                cout << "Z " << jmeno3 << " padlo " << zlato3 << " zlataku.\n";
            } else {
                cout << jmeno3 << " nezanechal zadne zlato.\n";
            }
            zlato3 = 0;
        }

        if (hracZivoty <= 0) {
            cout << "Byl jsi porazen.\n";
            return 0;
        }

        if (zivoty1 <= 0 && zivoty2 <= 0 && zivoty3 <= 0) {
            cout << "Vsechna monstra byla porazena.\n";
            pridatXP(10);
            pokracuj = 0;
        }
    }

    return 1;
}

int bojMiniboss(string jmeno, int zivoty, int utok, int zlato) {
    int pokracuj = 1;

    while (pokracuj == 1 && hracZivoty > 0 && zivoty > 0) {
        hracZivoty -= utok;
        cout << "\n" << jmeno << " na tebe utoci a zpusobil ti " << utok << " poskozeni.\n";

        if (hracZivoty <= 0) {
            cout << "Byl jsi porazen minibossem.\n";
            return 0;
        }

        cout << "Tve zivoty: " << hracZivoty << " | Tva mana: " << hracMana << "\n";
        cout << jmeno << ": " << zivoty << " HP\n";

        cout << "Vyber akci:\n";
        cout << "1 - Normalni utok (" << hracUtok << " dmg, -5 MP)\n";
        cout << "2 - Specialni utok (" << hracUtok * 2 << " dmg, -20 MP)\n";
        cout << "3 - Utek\n";
        cout << "Zadej cislo volby: ";
        int volba;
        cin >> volba;

        if (volba == 3) {
            cout << "Opustil jsi boj s minibossem.\n";
            return 1;
        }

        int dmg = 0;
        if (volba == 1 && hracMana >= 5) {
            dmg = hracUtok;
            hracMana -= 5;
        }
        if (volba == 2 && hracMana >= 20) {
            dmg = hracUtok * 2;
            hracMana -= 20;
        }

        if (dmg > 0) {
            zivoty -= dmg;
            cout << "Zautocil jsi na minibosse " << jmeno << " za " << dmg << " poskozeni.\n";
        } else {
            cout << "Nemas dost many na zvolenou akci.\n";
        }

        if (zivoty <= 0) {
            cout << "Miniboss " << jmeno << " byl porazen.\n";
            hracZlato += zlato;
            cout << "Z minibosse padlo " << zlato << " zlataku.\n";
            pridatXP(20);
            pokracuj = 0;
        }
    }

    return 1;
}

int soubojLarvog(string jmeno, int zivoty, int utokZaklad, int zlatoDrop) {
    int kolo = 1;
    int faze = 1;
    int jed = 0;

    while (hracZivoty > 0 && zivoty > 0) {
        cout << "\n--- Kolo " << kolo << " ---\n";
        faze = ((kolo - 1) / 3) % 5 + 1;
        cout << "Faze " << faze << " - " << jmeno << ": " << zivoty << " HP\n";
        cout << "Tve zivoty: " << hracZivoty << ", Mana: " << hracMana << "\n";

        int dmgBoss = 0;
        if (faze == 2) {
            dmgBoss = utokZaklad + ((hracZivoty + hracMana + kolo) % 4 == 0 ? utokZaklad : 0);
        } else if (faze == 3) {
            dmgBoss = utokZaklad;
            if (jed == 0) {
                jed = 3;
                cout << jmeno << " te otravil!\n";
            }
        } else if (faze == 5) {
            int u1 = 10 + ((kolo + 3) % 11);
            int u2 = 10 + ((kolo + 7) % 11);
            int u3 = 10 + ((kolo + 9) % 11);
            dmgBoss = u1 + u2 + u3;
            cout << jmeno << " (Imago) uderil 3x: " << u1 << ", " << u2 << ", " << u3 << "\n";
        } else if (faze == 4) {
            dmgBoss = 0;
            cout << jmeno << " je v kokonove forme a nehybe se.\n";
        } else {
            dmgBoss = utokZaklad / 2;
        }

        hracZivoty -= dmgBoss;
        if (dmgBoss > 0) cout << jmeno << " ti zpusobil " << dmgBoss << " poskozeni.\n";

        if (jed > 0) {
            hracZivoty -= 3;
            cout << "Jed ti zpusobil 3 poskozeni.\n";
            jed--;
        }

        if (hracZivoty <= 0) {
            cout << "Byl jsi porazen.\n";
            return 0;
        }

        cout << "\nVyber akci:\n";
        cout << "1 - Normalni utok (" << hracUtok << " dmg, -5 MP)\n";
        cout << "2 - Specialni utok (" << hracUtok * 2 << " dmg, -20 MP)\n";
        cout << "3 - Utek\nVolba: ";
        int volba;
        cin >> volba;

        if (volba == 3) {
            cout << "Opustil jsi boj.\n";
            return 1;
        }

        int dmg = 0;
        if (volba == 1 && hracMana >= 5) {
            dmg = hracUtok;
            hracMana -= 5;
        }
        if (volba == 2 && hracMana >= 20) {
            dmg = hracUtok * 2;
            hracMana -= 20;
        }

        if (faze != 4) {
            zivoty -= dmg;
            if (dmg > 0) cout << "Zpusobil jsi " << dmg << " poskozeni.\n";
        } else {
            cout << jmeno << " je nezranitelny – kokon.\n";
        }

        if (faze == 1) {
            zivoty += 2;
            cout << jmeno << " si regeneroval 2 HP.\n";
        }

        kolo++;
    }

    cout << "\nPorazil jsi " << jmeno << "!\n";
    hracZlato += zlatoDrop;
    cout << "Ziskal jsi " << zlatoDrop << " zlataku.\n";
    return 1;
}

int vesnice() {
    cout << "\nVitej ve vesnici. Mas " << hracZlato << " zlataku.\n";
    int hotovo = 0;

    while (hotovo == 0) {
        cout << "\nVyber moznost:\n";
        cout << "1 - Doplnit zivoty (10 zl) [+30 HP, max " << maxZivoty << "]\n";
        cout << "2 - Doplnit manu (10 zl) [+30 MP, max " << maxMana << "]\n";
        cout << "3 - Vylepsit utok (15 zl) [+5 utok]\n";
        cout << "4 - Zvysit max zivoty (20 zl) [+20 max HP, +10 HP]\n";
        cout << "5 - Zvysit max manu (20 zl) [+20 max MP, +10 MP]\n";
        cout << "6 - Opustit vesnici\n";
        cout << "Zadej cislo volby: ";

        int volba;
        cin >> volba;

        if (volba == 1 && hracZlato >= 10) {
            hracZivoty += 30;
            if (hracZivoty > maxZivoty) hracZivoty = maxZivoty;
            hracZlato -= 10;
            cout << "Zivoty doplneny. Mas nyni " << hracZivoty << " zivotu.\n";
        } else if (volba == 2 && hracZlato >= 10) {
            hracMana += 30;
            if (hracMana > maxMana) hracMana = maxMana;
            hracZlato -= 10;
            cout << "Mana doplnena. Mas nyni " << hracMana << " many.\n";
        } else if (volba == 3 && hracZlato >= 15) {
            hracUtok += 5;
            hracZlato -= 15;
            cout << "Utok vylepsen. Nyni utok: " << hracUtok << "\n";
        } else if (volba == 4 && hracZlato >= 20) {
            maxZivoty += 20;
            hracZivoty += 10;
            hracZlato -= 20;
            cout << "Max zivoty zvyseny. Nyni max: " << maxZivoty << "\n";
        } else if (volba == 5 && hracZlato >= 20) {
            maxMana += 20;
            hracMana += 10;
            hracZlato -= 20;
            cout << "Max mana zvysena. Nyni max: " << maxMana << "\n";
        } else if (volba == 6) {
            hotovo = 1;
        } else {
            cout << "Neplatna volba nebo nedostatek zlata.\n";
        }
    }
    return 0;
}

int sekceLes() {
    cout << "SEKCE: LES "<< endl;
    if (boj("Vlk", 30, 5, 5) == 0) return 0;
    if (boj("Pavouk", 25, 4, 4) == 0) return 0;
    if (boj("Divoky pes", 40, 6, 6) == 0) return 0;
    if (boj("Had", 20, 7, 5) == 0) return 0;
    if (bojMiniboss("Stinovy netopyr", 45, 10, 15) == 0) return 0; // miniboss pro les
    return 1;
}
int sekcePoust(){
    cout << "SEKCE: PISECNA POUST" << endl;
    if (boj("suchon", 60, 18, 18) == 0 ) return 0;
    if (boj("stir", 40, 25, 25) == 0 ) return 0;
    if (boj("fatamorgana", 90, 15, 15) == 0 ) return 0;
    if (bojDvaNepratele("stir 2", 40, 10, 6, "stir 3", 35, 12, 5) == 0) return 0; //souboj se dvema naraz
    if (boj("pisecny hadron", 125, 50, 50) == 0 ) return 0;
    if (boj("dunovrch", 100, 35, 35) == 0 ) return 0;
    if (bojMiniboss("scarrivon", 250, 45, 50) == 0) return 0; // miniboss por poust
    return 1;
}
int sekceHory(){
    cout << "SEKCE: SKALNATE HORY" << endl;
    if (boj("jester", 110, 30, 30) == 0 ) return 0;
    if (bojTriNepratele("velky netopyr", 35, 10, 12, "stredni netopyr", 25, 8, 10, "maly netopyr", 15, 6, 8) == 0) return 0; // souboj se trema naraz
    if (boj("vexalyn", 210, 55, 40) == 0 ) return 0;
    if (boj("hountmire", 180, 35, 25) == 0 ) return 0;
    if (bojMiniboss("sneaky rock golem on the bridge", 410, 40, 60) == 0) return 0; // miniboss pro hory
    return 1;
}
int sekceBazina(){
    cout << "SEKCE: NEPRUPUSTNA BAZINA" << endl;
    if (bojMiniboss("fubashi", 550, 65, 60) == 0) return 0; // miniboss pro bazinu
    if (soubojLarvog("Larvog", 850, 105, 150) == 0) return 0; // hlavni boss
    return 1;
}
int main() {
    vyberClassy();
    hracZlato = 125;
    vesnice();
    cout << endl;
    cout << "v lese nemame zadne info o silnich nepratelich" << endl;
    if (sekceLes() == 0) return 0;
    cout << endl;
    vesnice();
    cout << endl;
    cout << "doufam ze mas sebou dost vody protoze pouste byvaji nebezpecne" << endl;
    if (sekcePoust() == 0) return 0;
    cout << endl;
    vesnice ();
    cout << endl;
    cout << "v horach se skryva mnoho silnych nepratel" << endl;
    if (sekceHory() == 0) return 0;
    cout << endl;
    vesnice ();
    cout << endl;
    cout << "zde nase hlidka zahlidla pouze dva enemaky to by melo byt ez" << endl;
    if (sekceBazina() == 0) return 0;
    cout << endl;
    cout << "Gratulace porazil jsi Larvoga." << endl;
    cout << "konec kanec" << endl;
    return 0;
}
