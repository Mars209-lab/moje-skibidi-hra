#include <iostream>
#include <string>
using namespace std;

int hracZivoty, hracMana, hracUtok, hracSpecial, hracZlato;
string classa;

void vypisClassy() {
    cout << "Dostupne classy:\n";
    cout << "samurai  - Vyvazeny bojovnik s dobrym utokem a manou. (Perk: +10 utok)\n";
    cout << "rytir    - Vysoka obrana, ale nizsi utok. (Perk: +20 zivotu)\n";
    cout << "kocicka  - Velmi rychla a obratna. (Perk: +10 mana)\n";
    cout << "zlodej   - Silny specialni utok. (Perk: +10 special)\n";
    cout << "ninja    - Vyvazeny, ale s vysokou manou. (Perk: +10 mana a +5 utok)\n";
}

void vyberClassy() {
    bool vybrano = false;
    while (vybrano == false) {
        vypisClassy();
        cout << "\nZadej nazev classy: ";
        cin >> classa;

        if (classa == "samurai") {
            hracZivoty = 100;
            hracMana = 50;
            hracUtok = 20 + 10;
            hracSpecial = 35;
            vybrano = true;
        } else if (classa == "rytir") {
            hracZivoty = 120 + 20;
            hracMana = 40;
            hracUtok = 15;
            hracSpecial = 30;
            vybrano = true;
        } else if (classa == "kocicka") {
            hracZivoty = 80;
            hracMana = 60 + 10;
            hracUtok = 25;
            hracSpecial = 30;
            vybrano = true;
        } else if (classa == "zlodej") {
            hracZivoty = 90;
            hracMana = 40;
            hracUtok = 20;
            hracSpecial = 30 + 10;
            vybrano = true;
        } else if (classa == "ninja") {
            hracZivoty = 90;
            hracMana = 50 + 10;
            hracUtok = 20 + 5;
            hracSpecial = 30;
            vybrano = true;
        } else {
            cout << "Neplatna classa. Zkus to znovu.\n";
            continue;
        }

        string potvrzeni;
        cout << "Vybral jsi classu " << classa << ". Potvrdit? (ano/ne): ";
        cin >> potvrzeni;

        if (potvrzeni != "ano") {
            vybrano = false;
        }
    }
}

bool boj(string jmenoMonstra, int zivotyMonstra, int utokMonstra, int zlatoZaMonstrum) {
    cout << "\nNarazil jsi na monstrum: " << jmenoMonstra << " [" << zivotyMonstra << " HP, " << utokMonstra << " utok]\n";
    bool bojPokracuje = true;

    while (bojPokracuje == true && hracZivoty > 0 && zivotyMonstra > 0) {
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
                zivotyMonstra -= hracUtok;
                hracMana -= 5;
                cout << "Zautocil jsi a zpusobil " << hracUtok << " poskozeni.\n";
            } else {
                cout << "Nemas dostatek many na normalni utok.\n";
            }
        } else if (volba == 2) {
            if (hracMana >= 20) {
                int dmg = hracUtok * 2;
                zivotyMonstra -= dmg;
                hracMana -= 20;
                cout << "Pouzil jsi specialni utok a zpusobil " << dmg << " poskozeni.\n";
            } else {
                cout << "Nemas dostatek many na specialni utok.\n";
            }
        } else if (volba == 3) {
            cout << "Opustil jsi boj.\n";
            return true;
        } else {
            cout << "Neplatna volba.\n";
            continue;
        }

        if (zivotyMonstra > 0) {
            hracZivoty -= utokMonstra;
            cout << jmenoMonstra << " te zasahlo za " << utokMonstra << " poskozeni.\n";
        } else {
            cout << "Porazil jsi " << jmenoMonstra << ". Ziskavas " << zlatoZaMonstrum << " zlataku.\n";
            hracZlato += zlatoZaMonstrum;
            bojPokracuje = false;
        }

        if (hracZivoty <= 0) {
            cout << "Byl jsi porazen.\n";
            return false;
        }
    }

    return true;
}

void vesnice() {
    cout << "\nVitej ve vesnici. Mas " << hracZlato << " zlataku.\n";
    bool veVesnici = true;

    while (veVesnici == true) {
        cout << "\nVyber moznost:\n";
        cout << "1 - Doplnit zivoty (10 zl) [+30 HP]\n";
        cout << "2 - Doplnit manu (10 zl) [+30 MP]\n";
        cout << "3 - Vylepsit utok (15 zl) [+5 utok]\n";
        cout << "4 - Opustit vesnici\n";
        cout << "Zadej cislo volby: ";

        int volba;
        cin >> volba;

        if (volba == 1 && hracZlato >= 10) {
            hracZivoty += 30;
            hracZlato -= 10;
            cout << "Zivoty doplneny. Mas nyni " << hracZivoty << " zivotu.\n";
        } else if (volba == 2 && hracZlato >= 10) {
            hracMana += 30;
            hracZlato -= 10;
            cout << "Mana doplnena. Mas nyni " << hracMana << " many.\n";
        } else if (volba == 3 && hracZlato >= 15) {
            hracUtok += 5;
            hracZlato -= 15;
            cout << "Utok vylepsen. Nyni utok: " << hracUtok << "\n";
        } else if (volba == 4) {
            veVesnici = false;
        } else {
            cout << "Neplatna volba nebo nedostatek zlata.\n";
        }
    }
}

bool sekceLes() {
    cout << "\n=== SEKCE: LES ===\n";
    if (boj("Vlk", 30, 5, 5) == false) return false;
    if (boj("Pavouk", 25, 4, 4) == false) return false;
    if (boj("Divoky pes", 40, 6, 6) == false) return false;
    if (boj("Had", 20, 7, 5) == false) return false;
    if (boj("Stinovy netopyr", 35, 8, 8) == false) return false;
    return true;
}

int main() {
    vyberClassy();
    hracZlato = 0;

    if (sekceLes() == false) return 0;

    vesnice();

    cout << "Hra skoncila. Dekuji za hrani.\n";
    return 0;
}
