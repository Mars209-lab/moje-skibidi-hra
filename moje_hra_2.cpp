#include <iostream>
#include <string>
using namespace std;

int hracZivoty, hracMana, hracUtok, hracSpecial, hracZlato;
int maxZivoty, maxMana;
string classa;

int rovno(string a, string b) {
    return a == b;
}

int neniRovno(string a, string b) {
    return a != b;
}

void vypisClassy() {
    cout << "dostupne classy:\n";
    cout << "samurai  - Vyvazeny bojovnik s dobrym utokem a manou. (Perk: +10 utok)\n";
    cout << "rytir    - Vysoka obrana, ale nizsi utok. (Perk: +20 zivotu)\n";
    cout << "kocicka  - Velmi rychla a obratna. (Perk: +10 mana)\n";
    cout << "zlodej   - Silny specialni utok. (Perk: +10 special)\n";
    cout << "ninja    - Vyvazeny, ale s vysokou manou. (Perk: +10 mana a +5 utok)\n";
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
            pokracuj = 0;
        }
    }

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
    cout << "\n=== SEKCE: LES ===\n";
    if (boj("Vlk", 30, 5, 5) == 0) return 0;
    if (boj("Pavouk", 25, 4, 4) == 0) return 0;
    if (boj("Divoky pes", 40, 6, 6) == 0) return 0;
    if (boj("Had", 20, 7, 5) == 0) return 0;
    if (boj("Stinovy netopyr", 35, 8, 8) == 0) return 0;    //miniboss pro les
    return 1;
}
int sekcePoust(){
    cout << "SEKCE: PISECNA POUST" << endl;
    if (boj("suchon", 60, 18, 18) == 0 ) return 0;
    if (boj("stir", 40, 25, 25) == 0 ) return 0;
    if (boj("fatamorgana", 90, 15, 15) == 0 ) return 0;
    if (bojDvaNepratele("Gargoyle", 40, 10, 6, "Kostlivec", 35, 12, 5) == 0) return 0; //souboj se dvema naraz
    if (boj("pisecny hadron", 125, 50, 50) == 0 ) return 0;
    if (boj("dunovrch", 100, 35, 35) == 0 ) return 0;
    if (boj("scarrivon", 250, 45, 45) == 0 ) return 0;  //miniboss pro poust
    return 1;

}

int main() {
    vyberClassy();
    hracZlato = 85;
    vesnice();
    cout << endl;
    if (sekceLes() == 0) return 0;
    cout << endl;
    vesnice();
    cout << endl;
    if (sekcePoust() == 0) return 0;
    cout << endl;
    vesnice ();
    cout << "kanec.\n";
    return 0;
}
