#include <iostream>
#include <iomanip>
#include <chrono>
#include <stack>
#include <array>


using namespace std;


const int LIMIT = 10; //sekund
const int L_PKT_WYGRANA = 5;



void wygrana(string gracz, bool& wygrane) {
    cout << "Wygrywa gracz " << gracz << " - GRATULACJE!" << endl;
    wygrane = true;
    cout << "ostatnie slowa? :" << endl;
    string zatrzymek;
    cin >> zatrzymek;
}

void sprawdz(char plansza[4][3][3], char x, char o, string gracz1, string gracz2, bool &wygrane) {
    
    char kandydat = NULL;
    int punkty = 0;

    //poziome sprawdzenie
    for (int dla2kandydatow = 0; dla2kandydatow <2; dla2kandydatow++){
        punkty = 0;
        if (dla2kandydatow == 0) kandydat = x;
        else kandydat = o;
        for (int iter = 0; iter <=2; iter+=2){
            for (int i = 0; i < 3; i++) {
                for (int k = 0+iter; k < 2+iter; k++) {
                    for (int j = 0; j < 3; j++) {
                        if (plansza[k][i][j] == kandydat) {
                            punkty += 1;
                        }
                        else {
                            //if (plansza[k][i][j]==x or plansza[k][i][j]==o)
                                //kandydat = plansza[k][i][j];
                            punkty = 0;
                        }
                        if (punkty == L_PKT_WYGRANA) {
                            if (kandydat == x) wygrana(gracz1, wygrane);
                            if (kandydat == o) wygrana(gracz2, wygrane);
                        }
                
                    }
                }
            }
        }
    }

    punkty = 0;
    kandydat = NULL;

    //pionowe sprawdzenie
    for (int dla2kandydatow = 0; dla2kandydatow < 2; dla2kandydatow++) {
        punkty = 0;
        if (dla2kandydatow == 0) kandydat = x;
        else kandydat = o;
        for (int iter = 0; iter < 2; iter++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0 + iter; k <= 2 + iter; k+=2) {
                    for (int i = 0; i < 3; i++) {
                        if (plansza[k][i][j] == kandydat) {
                            punkty += 1;
                        }
                        else {
                            //if (plansza[k][i][j] == x or plansza[k][i][j] == o)
                                //kandydat = plansza[k][i][j];
                            punkty = 0;
                        }
                        if (punkty == L_PKT_WYGRANA) {
                            if (kandydat == x) wygrana(gracz1, wygrane);
                            if (kandydat == o) wygrana(gracz2, wygrane);
                        }

                    }
                }
            }
        }
    }

    punkty = 0;


    //ukosne sprawdzenie w dol
    for (int dla2kandydatow = 0; dla2kandydatow < 2; dla2kandydatow++) {
        punkty = 0;
        if (dla2kandydatow == 0) kandydat = x;
        else kandydat = o;
        for (int iter = 0; iter < 2; iter++) {
            for (int k = 0 ; k <= 3; k += 3) {
                for (int i = 0 + iter, j = 0; i < 3 + iter && j < 3; j++, i++) {
                    if (plansza[k][i][j] == kandydat) {
                        punkty += 1;
                    }
                    else {
                        //if (plansza[k][i][j] == x or plansza[k][i][j] == o)
                            //kandydat = plansza[k][i][j];
                        punkty = 0;
                    }
                    if (punkty == L_PKT_WYGRANA) {
                        if (kandydat == x) wygrana(gracz1, wygrane);
                        if (kandydat == o) wygrana(gracz2, wygrane);
                    }

                }
            }
        }
    }

    punkty = 0;

    //ukosne sprawdzenie w gore
    for (int dla2kandydatow = 0; dla2kandydatow < 2; dla2kandydatow++) {
        punkty = 0;
        if (dla2kandydatow == 0) kandydat = x;
        else kandydat = o;
        for (int iter = 0; iter < 2; iter++) {
            for (int k = 2; k >= 1; k--) {
                for (int i = 2 - iter, j = 0; i >= 0 && j < 3; j++, i--) {
                    if (plansza[k][i][j] == kandydat) {
                        punkty += 1;
                    }
                    else {
                        if (plansza[k][i][j] == x or plansza[k][i][j] == o)
                            kandydat = plansza[k][i][j];
                        punkty = 0;
                    }
                    if (punkty == L_PKT_WYGRANA-1) {
                        if (kandydat == x) wygrana(gracz1, wygrane);
                        if (kandydat == o) wygrana(gracz2, wygrane);
                    }

                }
            }
        }
    }

    //sprawdzenie pojedynczych skosow przez 3 plansze----------
    //......w dol--------------
    kandydat = plansza[0][0][1];
    punkty = 0;
    
    for (int k=0; k<=3;k+=3){
        for (int i = 0, j = 1; i <= 1 && j <= 2; i++, j++) {
            if (plansza[k][i][j] == kandydat) punkty += 1;
        }
    }
    if (plansza[1][2][0] == kandydat)punkty += 1;
    if (punkty == L_PKT_WYGRANA) {
        if (kandydat == x) wygrana(gracz1, wygrane);
        if (kandydat == o) wygrana(gracz2, wygrane);
    }
    
    
    kandydat = plansza[0][1][0];
    punkty = 0;
    for (int k = 0; k <= 3; k += 3) {
        for (int i = 1, j = 0; i <= 2 && j <= 1; i++, j++) {
            if (plansza[k][i][j] == kandydat) punkty += 1;
        }
    }
    if (plansza[2][0][2] == kandydat)punkty += 1;
    if (punkty == L_PKT_WYGRANA) {
        if (kandydat == x) wygrana(gracz1, wygrane);
        if (kandydat == o) wygrana(gracz2, wygrane);
    }

    //......w gore-------------
    kandydat =plansza[2][1][0];
    punkty = 0;
    for (int k = 2; k >= 1; k--) {
        for (int i = 1, j = 0; i >= 0 && j < 2; i--, j++) {
            if (plansza[k][i][j] == kandydat) punkty += 1;
        }
    }
    if (plansza[0][2][2] == kandydat)punkty += 1;
    if (punkty == L_PKT_WYGRANA) {
        if (kandydat == x) wygrana(gracz1, wygrane);
        if (kandydat == o) wygrana(gracz2, wygrane);
    }

    kandydat = plansza[2][2][1];
    punkty = 0;
    for (int k = 2; k >= 1; k--) {
        for (int i = 2, j = 1; i >= 0 && j < 2; i--, j++) {
            if (plansza[k][i][j] == kandydat) punkty += 1;
        }
    }
    if (plansza[3][0][0] == kandydat)punkty += 1;
    if (punkty == L_PKT_WYGRANA) {
        if (kandydat == x) wygrana(gracz1, wygrane);
        if (kandydat == o) wygrana(gracz2, wygrane);
    }

}

void wypisz_graczy(string gracz1, string gracz2, char x, char o, char kogoruch, float limit1, float limit2, int runda) {
    for (int i = 0; i < 10; i++) cout << endl;
    cout << "RUCH " << runda << endl;
    cout << "GRACZ 1: " << setfill(' ') << setw(10) << gracz1 << " ZETON: " << x;
    cout << " POZOSTALY CZAS: "  << (int)limit1/60 << "min " << (int)limit1 % 60 <<"s";
    if (kogoruch == x) {
        cout << " - TWOJ RUCH!";
    }
    cout << endl;
    cout << "GRACZ 2: " << setw(10) << gracz2 << " ZETON: " << o;
    cout << " POZOSTALY CZAS: " << (int)limit2 / 60 << "min " << (int)limit2 % 60 << "s";
    if (kogoruch == o) {
        cout << " - TWOJ RUCH!";
    }
    cout << endl;
}

void rysuj_plansze(char plansza[4][3][3], string gracz1, string gracz2, char x, char o, char kogoruch, float limit1, float limit2, int runda) {
    
    wypisz_graczy(gracz1, gracz2, x, o, kogoruch, limit1, limit2, runda);

    cout << endl << setfill('-') << setw(30) << "-" << endl << endl;


    for (int goradol = 1; goradol <=2;goradol++){
        cout << char(201);

        for (int i = 0; i < 23; i++) {
            if (i % 4 == 3){
                
                if (i == 11) {
                    cout << char(187) << " " << char(201);
                }
                else cout << char(203);
            }

            else cout << char(205);
        }

        cout << char(187) << endl;

        for (int i = 0; i < 3; i++) {
            if (goradol == 1) {
                for (int k = 0; k<2;k++) {
                    for (int j = 0; j < 3;j++) {
                        cout << char(186) << " " << plansza[k][i][j] << " ";
                    }
                    if(k<1)cout << char(186) << " " ;
                }
                cout << char(186) << endl;
            
            }

            if (goradol == 2) {
                for (int k = 2; k < 4; k++) {
                    for (int j = 0; j < 3; j++) {
                        cout << char(186) << " " << plansza[k][i][j] << " ";
                    }
                    if (k < 3)cout << char(186) << " ";
                }
                cout << char(186) << endl;
            }
                

            if (i < 2) cout << char(204);
            else cout << char(200);
            for (int j = 0; j < 23; j++) {
                if (j % 4 == 3 && i != 2){
                    if (j == 11) cout << char(185) << " " << char(204);
                    else cout << char(206);
                }
                else {
                    if (i==2 && j==11) {
                        cout << char(188) << " " << char(200);
                    }
                    else{
                        if (!(j % 4 == 3)) cout << char(205);
                        if (i == 2 && j % 4 == 3) cout << char(202);
                    }
                }

            }
            if (i < 2)cout << char(185);
            else cout << char(188);
            cout << endl;

        }
    }
    cout << endl << setfill('-') << setw(30) << "-" << endl;
}

void wprawo(char plansza[3][3]) {
    char** planszaT = new char* [3];

    for (int i = 0; i < 3; i++) {
        planszaT[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            planszaT[i][j] = plansza[(2 - j)][i];
            
        }
        
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = planszaT[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        delete[] planszaT[i];
    }

    delete[] planszaT;
    
    
}

void wlewo(char plansza[3][3]) {
    char** planszaT = new char* [3];

    for (int i = 0; i < 3; i++) {
        planszaT[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            planszaT[i][j] = plansza[j][2-i];
            
        }
        
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = planszaT[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        delete[] planszaT[i];
    }

    delete[] planszaT;


}

void undo(char plansza[4][3][3], stack<array<int, 3>> &ruchy, stack<array<int, 2>> &obroty, char puste, char kogoruch, char x, char o, int typgry) {
    int poledopopisu = ruchy.size();
    int oile = 0;
    bool literka = false;

    do {
        cout << "O ile ruchow (max - " << poledopopisu << "): ";
        


        if ((cin>>oile) && oile && oile <= poledopopisu) {
            for (int iter = 0; iter < oile; iter++) {
                literka = false;
                if (typgry == 2){
                array<int, 2> obrot = obroty.top();
                obroty.pop();
                if (obrot[1] == 1) {
                    wlewo(plansza[obrot[0]]);
                }
                if (obrot[1] == 0) {
                    wprawo(plansza[obrot[0]]);
                }
                }
                array<int, 3> ost_ruch = ruchy.top();
                ruchy.pop();
                plansza[ost_ruch[0]][ost_ruch[1]][ost_ruch[2]] = puste;

            }
            break;
        }
        else cout << "Zle dane!" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        literka = true;
    }while (oile > poledopopisu or literka==true);
}

void postaw_zeton(char plansza[4][3][3], char x, char o, char puste, array<int, 3> &ost_ruch, stack<array<int, 3>>& ruchy, stack<array<int, 2>>& obroty, char &kogoruch, int typgry) {
    while(1){
        cout << "Podaj literke planszy (q,w,a,s) i numer pola (1-9)" << endl;
        char qwas, zx;
        int nr, k, i , j ;
    
        while(1){
            char qwas, zx;
            int nr, k, i, j;
            cin >> qwas;


            switch (qwas) {
                case 'q': {
                    k = 0;
                    break;
                }
                case 'w': {
                    k = 1;
                    break;
                }
                case 'a': {
                    k = 2;
                    break;
                }
                case 's': {
                    k = 3;
                    break;
                }
                default: {
                    cout << "Bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue; 
                }
            }
            
            cin >> nr;
            if (nr >= 1 && nr <= 3) {
                i = 2;
                j = nr - 1;

            }
            else if (nr >= 4 && nr <= 6) {
                i = 1;
                j = (nr - 1) - 3;

            }
            else if (nr >= 7 && nr <= 9) {
                i = 0;
                j = (nr - 1) - 6;
            }
            else{
                cout << "Bledne dane! Podaj cyfre od 1 do 9: " << endl;
                while(!(cin>>nr)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                    if (nr >= 1 && nr <= 3) {
                        i = 2;
                        j = nr - 1;
                
                    }
                    else if (nr >= 4 && nr <= 6) {
                        i = 1;
                        j = (nr - 1) - 3;
                
                    }
                    else if (nr >= 7 && nr <= 9) {
                        i = 0;
                        j = (nr - 1) - 6;
                
                    }
                }
                if (nr >= 1 && nr <= 3) {
                    i = 2;
                    j = nr - 1;

                }
                else if (nr >= 4 && nr <= 6) {
                    i = 1;
                    j = (nr - 1) - 3;

                }
                else if (nr >= 7 && nr <= 9) {
                    i = 0;
                    j = (nr - 1) - 6;
                }
            }
            
        
            if (plansza[k][i][j] == puste){
                plansza[k][i][j] = kogoruch;
                ost_ruch[0] = k;
                ost_ruch[1] = i;
                ost_ruch[2] = j;
                ruchy.push(ost_ruch);
                
                break;
            }
            else {
                cout << "Zajete!! Wybierz inne miejsce. " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }

        }
        if (typgry==2){
        cout << "Podaj literke planszy (q,w,a,s) i kierunek obrotu (z - w lewo, x - w prawo): " << endl;
        cin >> qwas;
        cin >> zx;

        switch (qwas) {
        case 'q': {
            k = 0;
            break;
        }
        case 'w': {
            k = 1;
            break;
        }
        case 'a': {
            k = 2;
            break;
        }
        case 's': {
            k = 3;
            break;
        }
        }

        if (zx == 'z'){
            wlewo(plansza[k]);
            obroty.push({ k, 0 });
        }
        

        if (zx == 'x'){
            wprawo(plansza[k]);
            obroty.push({ k, 1 });
        }
        }

        cout << "u - cofnij, dowolny znak - dalej" << endl;
        char u;
        cin >> u;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (u == 'u'){

            undo(plansza, ruchy, obroty, puste, kogoruch, x, o, typgry);
        }


        else break;
        
    }
    if (kogoruch == x) kogoruch = o;
    else kogoruch = x;
    
}


void wczytaj_graczy(string &gracz1, string &gracz2, char &x, char &o ) {
    cout << "Imie pierwszego gracza: " << endl;
    cin >> gracz1;

    cout << "Zeton pierwszego gracza (dowolny pojedynczy znak, np o, x): " << endl;
    cin >> x;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Imie drugiego gracza: " << endl;
    while (1) {
        cin >> gracz2;
        if (gracz1 == gracz2) {
            cout << "Podaj rozne imiona dla graczy! " << endl;
        }
        else break;
    }

    cout << "Zeton drugiego gracza (dowolny pojedynczy znak, np o, x): " << endl;
    while (1) {
        cin >> o;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (x == o) {
            cout << "Podaj rozne zetony dla graczy! " << endl;
        }
        else break;
    }
}



void pusteplansze(char plansza[4][3][3], char x, char o, char puste) {
    for (int k = 0; k < 2; k++) {

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                plansza[k][i][j] = puste;
            }
        }
    }
    for (int k = 2; k < 4; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                plansza[k][i][j] = puste;
            }
        }
    }
}

void help() {
    
    for(int i = 0; i < 25; i++) cout << endl;
    
    cout << "----PENTAGO----" << endl << endl;
    cout << "Pentago jest gra dwuosobowa na planszy. Plansza sklada sie z 4 ruchomych" << endl;
    cout << "czesci, ktore mozna obracac. Kazda czesc zawiera 9 miejsc na zetony." << endl;
    cout << "Gracze po kolei oddaja ruch skladajacy sie z 2 czesci:" << endl;
    cout << "   - dolozenia swojego zetonu na niezajete pole planszy; " << endl;
    cout << "   - obrot jednej z czesci planszy o 90 stopni " << endl;
    cout << "     w dowolnym kierunku." << endl;
    cout << "Nie mozna zrezygnowac z zadnej czesci ruchu." << endl;
    cout << "Wygrywa osoba, ktorej 5 zetonow, po pelnym ruchu, " << endl;
    cout << "sa ulozone w rzedzie / kolumnie / po skosach" << endl;
    cout << "(podobnie do gry kolko krzyzyk)." << endl << endl;
    cout << "---STEROWANIE---" << endl;
    cout << "Podczas ruchu, najpierw za pomoca q, w, a oraz s wybierz jedna z kolejnych" << endl;
    cout << "cwiartek planszy, nastepnie cyfra od 1 do 9, jak na klawiaturze numerycznej, " << endl;
    cout << "wybierz pole. Wtedy znowu wybierz cwiartke i obroc w x - prawo lub z - lewo." << endl;
    cout << "Mozesz takze cofnac sie o max. 4 ruchy za pomoca u - undo." << endl << endl;
    cout << "Dowolny znak - powrot do gry... ";
    char x;
    cin >> x;
    
}

void predef_plansza(char plansza[4][3][3], char x, char o, char puste) {
    pusteplansze(plansza, x, o, puste);

    plansza[0][0][1] = o;
    plansza[0][1][0] = x;
    plansza[0][1][1] = x;
    plansza[0][1][2] = o;
    plansza[0][2][1] = x;

    plansza[1][0][1] = x;
    plansza[1][1][0] = x;
    plansza[1][1][1] = o;

    plansza[2][0][0] = x;
    plansza[2][0][1] = x;
    plansza[2][1][0] = o;
    plansza[2][1][2] = x;
    plansza[2][2][1] = o;

    plansza[3][1][1] = o;
    plansza[3][2][1] = o;
    plansza[3][2][2] = o;
}

void pauza(float& pauza_czas) {
    auto pauza_start = chrono::high_resolution_clock::now();
    string odpauz;
    cin >> odpauz;
    auto pauza_stop = chrono::high_resolution_clock::now();
    chrono::duration<float> pauza = pauza_stop - pauza_start;
    pauza_czas = pauza.count();
}

void zmien_zeton(char plansza[4][3][3], char &x, char &o, char puste, array<int, 3>& ost_ruch, stack<array<int, 3>>& ruchy, stack<array<int, 2>>& obroty, char& kogoruch, int typgry) {
    cout << "Podaj nowy zeton: ";

    char nowy, stary = NULL;

    if (kogoruch == x) {
        cin >> nowy;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (nowy != o) {
            stary = x;
            x = nowy;
            cout << "Zeton zmieniono. " << endl;
            
        }
        else cout << "Nie wolno koledze zetonu zabierac!!!!" << endl;
    }
    if (kogoruch == o) {
        cin >> nowy;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (nowy != x) {
            stary = o;
            o = nowy;
            cout << "Zeton zmieniono. " << endl;
            
        }
        else cout << "Nie wolno koledze zetonu zabierac!!!!" << endl;
    }

    //podmiana wszystkich zetonow na planszach
    if (stary) {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (plansza[k][i][j] == stary)
                        plansza[k][i][j] = nowy;
                }
            }
        }
    }
    kogoruch = nowy;
    postaw_zeton(plansza, x, o, puste, ost_ruch, ruchy, obroty, kogoruch, typgry);
}


void opcje(char plansza[4][3][3], char &x, char &o, char puste, char &kogoruch, float &pauza_czas, array<int, 3>& ost_ruch, stack<array<int, 3>>& ruchy, stack<array<int, 2>>& obroty, int typgry) {
    cout << "p - pauza, o - wczytaj predef. plansze, h - opis programu/pomoc " << endl;
    cout << "z - zmien zeton" << endl;
    cout << "dowolny znak - powrot do gry... ";
    char wybor;
    
    cin >> wybor;
    switch(wybor){
    case 'p': {
        pauza(pauza_czas);
        break;
    }

    case 'o': {
        predef_plansza(plansza, x, o, puste);
        break;
    }

    case 'h': {
        help();
        break;
    }

    case 'z': {
        zmien_zeton(plansza, x, o, puste, ost_ruch, ruchy, obroty, kogoruch, typgry);
    }
    }

}

void menu(char plansza[4][3][3], char &x, char &o, char puste, array<int, 3> &ost_ruch, stack<array<int, 3>> &ruchy, stack<array<int, 2>> &obroty, char& kogoruch, string gracz1, string gracz2, bool& wygrane, float &pauza_czas, int typgry) {
    
    char wybor;
    cout << "r - wykonaj ruch, m - opcje " << endl;
    
    
    while(1){
        cin >> wybor;
        if (wybor == 'r') {
            postaw_zeton(plansza, x, o, puste, ost_ruch, ruchy, obroty, kogoruch, typgry);
            break;
    
        }
        if (wybor == 'm') {
            opcje(plansza, x, o, puste, kogoruch, pauza_czas, ost_ruch, ruchy, obroty, typgry);
            break;
    
        }
        cout << "Nieprawidlowy wybor!! Jeszcze raz. ";
    }
    
}


int main()
{
    //[ nr planszy ]  [ nr wiersza ]  [ nr kolumny ] 
    char plansza[4][3][3];
    array<int, 3> ost_ruch;

    char x = 'x';
    char o = 'o';
    char puste = ' ';
    char kogoruch;

    int typgry;

    int runda = 1;
    stack<array<int, 3>> ruchy;


    //[plansza, obrot] 0 - lewo, 1 - prawo
    stack<array<int, 2>> obroty;
    
    
    
  
    string gracz1, gracz2;
    float limit1 = LIMIT, limit2 = LIMIT;

    bool wygrane = false;
    
    cout << "Wybierz typ gry: 1 - kolko i krzyzyk; 2 - pentago " << endl;
    do{ 
        cin >> typgry;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (typgry != 1 && typgry != 2);

    wczytaj_graczy(gracz1, gracz2, x, o);

    kogoruch = x;

    pusteplansze(plansza, x, o, puste);

    
    

    //pętla główna------------------------------

    while (not wygrane) {
        
        rysuj_plansze(plansza, gracz1, gracz2, x, o, kogoruch, limit1, limit2, runda);
        sprawdz(plansza, x, o, gracz1, gracz2, wygrane);
        float pauza_czas = 0;
        
        if (wygrane) return(0);
        
        else {
            auto czas_start = chrono::high_resolution_clock::now();
            menu(plansza, x, o, puste, ost_ruch, ruchy, obroty, kogoruch, gracz1, gracz2, wygrane, pauza_czas, typgry);
            auto czas_stop = chrono::high_resolution_clock::now();
            chrono::duration<float> czas_rundy = czas_stop - czas_start;
            if (kogoruch == o) {
                limit1 -= (czas_rundy.count()-pauza_czas);
            }
            if (kogoruch == x) {
                limit2 -= (czas_rundy.count()-pauza_czas);
            }
            

        }
        if (limit1 <= 0) {
            cout << "KONIEC CZASU!" << endl;
            limit1 = 0;
            wygrana(gracz2, wygrane);
        }
        if (limit2 <= 0) {
            cout << "KONIEC CZASU!" << endl;
            limit2 = 0;
            wygrana(gracz1, wygrane);
        }
        runda++;
    }
    
    
}

