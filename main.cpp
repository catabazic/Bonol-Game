#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool gata;
int color=3;
int colorB=1;
int colorR=4;

int state[17] = { 2, 3, 2, 2, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 1, 1, 3 };
int n = 100;
string game[101];
void paginaPrincipala(int color);
void text(int var);
void next();
void render();
void render_2(int q,int g[16]);
void terenJoaca(int l);
int click_function(){
    const int DELAY = 50;
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN)) delay(DELAY);

        getmouseclick(WM_LBUTTONDOWN, x, y);


        if(x>50 && x<175 && y>120 && y<245)  {
                cout<<1;
                setcolor(YELLOW);
                rectangle(50,120,175,245);
                return 1;
        }
        if(x>175 && x<300 && y>120 && y<245) {
                cout<<2;
                setcolor(YELLOW);
                rectangle(175,120,300,245);
                return 2;
        }
        if(x>300 && x<425 && y>120 && y<245) {
                cout<<3;
                setcolor(YELLOW);
                rectangle(300,120,425,245);
                return 3;
        }
        if(x>425 && x<550 && y>120 && y<245) {
                cout<<4;
                setcolor(YELLOW);
                rectangle(425,120,550,245);
                return 4;
        }
        if(x>50 && x<175 && y>245 && y<370)  {
                cout<<5;
                setcolor(YELLOW);
                rectangle(50,245,175,370);
                return 5;
        }
        if(x>175 && x<300 && y>245 && y<370) {
                cout<<6;
                setcolor(YELLOW);
                rectangle(175,245,300,370);
                return 6;
        }
        if(x>300 && x<425 && y>245 && y<370) {
                cout<<7;
                setcolor(YELLOW);
                rectangle(300,245,425,370);
                return 7;
        }
        if(x>425 && x<550 && y>245 && y<370) {
                cout<<8;
                setcolor(YELLOW);
                rectangle(425,245,550,370);
                return 8;
        }
        if(x>50 && x<175 && y>370 && y<495)  {
                cout<<9;
                setcolor(YELLOW);
                rectangle(50,370,175,495);
                return 9;
        }
        if(x>175 && x<300 && y>370 && y<495) {
                cout<<10;
                setcolor(YELLOW);
                rectangle(175,370,300,495);
                return 10;
        }
        if(x>300 && x<425 && y>370 && y<495) {
                cout<<11;
                setcolor(YELLOW);
                rectangle(300,370,425,495);
                return 11;
        }
        if(x>425 && x<550 && y>370 && y<495) {
                cout<<12;
                setcolor(YELLOW);
                rectangle(425,370,550,495);
                return 12;
        }
        if(x>50 && x<175 && y>495 && y<620)  {
                cout<<13;
                setcolor(YELLOW);
                rectangle(50,495,175,620);
                return 13;
        }
        if(x>175 && x<300 && y>495 && y<620) {
                cout<<14;
                setcolor(YELLOW);
                rectangle(175,495,300,620);
                return 14;
        }
        if(x>300 && x<425 && y>495 && y<620) {
                cout<<15;
                setcolor(YELLOW);
                rectangle(300,495,425,620);
                return 15;
        }
        if(x>425 && x<550 && y>495 && y<620) {
                cout<<16;
                setcolor(YELLOW);
                rectangle(425,495,550,620);
                return 16;
        }
        if(x>=450 && x<=580 && y>=690 && y<=730)
        {   gata = true;
            closegraph();
            paginaPrincipala(color);
        }
        return 0 ;

};
bool
check(int q[17], int y, int x) {
    if (x > 16 || x < 1) return false;
    if ((y % 4 == 0 && x % 4 == 1) || (y % 4 == 1 && x % 4 == 0)) return false;
    if (q[x] == 3) return false;
    if (!(q[x] == 0) && !(q[x] == q[0])) return false;
    return true;
}
bool
check_a(int q[17], int x) {
    if (x > 16 || x < 1) return false;

    if (q[x] == 3) return false;
    if (!(q[x] == 0) && !(q[x] == q[0])) return false;
    return true;
}
void afiseaza_state(){
 for (int i = 1;i<=16;i++){
    cout<< state[i] << " ";


 }
 cout << endl;
}

bool V3U1L(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 1;
    if (!check(q, a, b)) return false;
    int c = b + 4;
    if (!check(q, b, c)) return false;
    int d = c + 4;
    if (!check(q, c, d)) return false;

    int points[4] = { a, b, c, d };

    if (points[1] !=  p2) return false;
    if (points[2] !=  p3) return false;
    if (points[3] !=  p4) return false;

    return true;
}
bool V3U1R(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 1;
    if (!check(q, a, b)) return false;
    int c = b + 3;
    if (!check(q, b, c)) return false;
    int d = c + 4;
    if (!check(q, c, d)) return false;

    int points[4] = { a, b, c, d };

    if (points[1] !=  p2) return false;
    if (points[2] !=  p3) return false;
    if (points[3] !=  p4) return false;

    return true;
}
bool V3R1U(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 2;
    if (!check(q, a, b)) return false;
    int c = b + 1;
    if (!check(q, b, c)) return false;
    int d = c + 1;
    if (!check(q, c, d)) return false;

    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;

    return true;
}
bool V3R1D(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 1;
    if (!check(q, a, b)) return false;
    int c = b + 1;
    if (!check(q, b, c)) return false;
    int d = c + 4;

    if (!check(q, c, d)) return false;

    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;

    return true;
}
bool V3L1U(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 4;
    if (!check(q, a, b)) return false;
    int c = b + 1;
    if (!check(q, b, c)) return false;
    int d = c + 1;
    if (!check(q, c, d)) return false;
    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;
    return true;
}
bool V3L1D(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 1;
    if (!check(q, a, b)) return false;
    int c = b + 1;
    if (!check(q, b, c)) return false;
    int d = c + 2;
    if (!check(q, c, d)) return false;

    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;

    return true;
}
bool V3D1L(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 4;
    if (!check(q, a, b)) return false;
    int c = b + 3;
    if (!check(q, b, c)) return false;
    int d = c + 1;
    if (!check(q, c, d)) return false;

    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;

    return true;
}
bool V3D1R(int q[17], int p1, int p2, int p3, int p4) {
    int a = p1;
    if (!check_a(q, a)) return false;
    int b = a + 4;
    if (!check(q, a, b)) return false;
    int c = b + 4;
    if (!check(q, b, c)) return false;
    int d = c + 1;
    if (!check(q, c, d)) return false;

    int points[4] = {a, b, c, d};

    if (points[1] != p2) return false;
    if (points[2] != p3) return false;
    if (points[3] != p4) return false;
    return true;
}
bool
isRealyL(int b[17], int T[4]) {

    sort(T,T+4);
    int p1, p2, p3, p4;
    p1 = T[0];
    p2 = T[1];
    p3 = T[2];
    p4 = T[3];

    if (b[p1] == b[0] && b[p2] == b[0] && b[p3] == b[0] && b[p4] == b[0]) return false;
    if (
        V3U1L(b, p1, p2, p3, p4) ||
        V3U1R(b, p1, p2, p3, p4) ||
        V3R1U(b, p1, p2, p3, p4) ||
        V3R1D(b, p1, p2, p3, p4) ||
        V3L1U(b, p1, p2, p3, p4) ||
        V3L1D(b, p1, p2, p3, p4) ||
        V3D1L(b, p1, p2, p3, p4) ||
        V3D1R(b, p1, p2, p3, p4)
        ) {
        return true;
    }
    else {
        return false;
    }
    return false;

}
void
fix_history(int nr) {
    string s;
    for (int i = 0; i < 17; i++) {
        s += to_string(state[i]);
        s += '#';
    };

    game[nr] = s;

}
string
join_function(int q[4], char x) {
    string s;
    s += '#';
    for (int i = 0; i < 4; i++) {
        s += to_string(q[i]);
        s += x;
    };
    return s;

}

/*
  GENERAREA POSIBILELOR L
*/

string G3R1D(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 1;
    if (!check(q, a, b)) return "";
    int c = b + 1;
    if (!check(q, b, c)) return "";
    int d = c + 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3R1U(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 1;
    if (!check(q, a, b)) return "";
    int c = b + 1;
    if (!check(q, b, c)) return "";
    int d = c - 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3L1D(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 1;
    if (!check(q, a, b)) return "";
    int c = b - 1;
    if (!check(q, b, c)) return "";
    int d = c + 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3L1U(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 1;
    if (!check(q, a, b)) return "";
    int c = b - 1;
    if (!check(q, b, c)) return "";
    int d = c - 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3U1R(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 4;
    if (!check(q, a, b)) return "";
    int c = b - 4;
    if (!check(q, b, c)) return "";
    int d = c + 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3U1L(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 4;
    if (!check(q, a, b)) return "";
    int c = b - 4;
    if (!check(q, b, c)) return "";
    int d = c - 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3D1L(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 4;
    if (!check(q, a, b)) return "";
    int c = b + 4;
    if (!check(q, b, c)) return "";
    int d = c - 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G3D1R(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 4;
    if (!check(q, a, b)) return "";
    int c = b + 4;
    if (!check(q, b, c)) return "";
    int d = c + 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G1D3L(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 4;
    if (!check(q, a, b)) return "";
    int c = b - 1;
    if (!check(q, b, c)) return "";
    int d = c - 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G1D3R(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 4;
    if (!check(q, a, b)) return "";
    int c = b + 1;
    if (!check(q, b, c)) return "";
    int d = c + 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G1U3R(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 4;
    if (!check(q, a, b)) return "";
    int c = b + 1;
    if (!check(q, b, c)) return "";
    int d = c + 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G1U3L(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 4;
    if (!check(q, a, b)) return "";
    int c = b - 1;
    if (!check(q, b, c)) return "";
    int d = c - 1;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#'); s+='@';
    return s;
}

string G1R3U(int q[17], int p1) {
    int a = p1;
        if (!check_a(q, a)) return "";
    int b = a + 1;
    if (!check(q, a, b)) return "";
    int c = b - 4;
    if (!check(q, b, c)) return "";
    int d = c - 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#');
    s+='@';
    return s;
}

string G1R3D(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a + 1;
    if (!check(q, a, b)) return "";
    int c = b + 4;
    if (!check(q, b, c)) return "";
    int d = c + 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#');
    s+='@';
    return s;
}

string G1L3D(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 1;
    if (!check(q, a, b)) return "";
    int c = b + 4;
    if (!check(q, b, c)) return "";
    int d = c + 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#');
    s+='@';
    return s;
}

string G1L3U(int q[17], int p1) {
    int a = p1;
    if (!check_a(q, a)) return "";
    int b = a - 1;
    if (!check(q, a, b)) return "";
    int c = b - 4;
    if (!check(q, b, c)) return "";
    int d = c - 4;
    if (!check(q, c, d)) return "";
    if (q[a] == q[0] && q[b] == q[0] && q[c] == q[0] && q[d] == q[0]) return "";
    int points[4] = {a, b, c, d};

    string s;
    s = join_function(points,'#');
    s+='@';
    return s;
}

/*
   ------------ GENERAREA POSIBILELOR L  -------------------
*/
void filter_int(int b[16]) {
    int k = 16;
    for (int i = 0; i < k; i++)
    {
        if (b[i] == 0) {

            k--;
            for (int j = i; j < k; j++)
            {

                b[j] = b[j + 1];

            }
        }
        if (b[i] == 0) i--;
    }

};
void carouriLibere(int b[17],int a[16]) {

    for (int i = 1; i <= 16; i++) {
        if ((b[i] == 0) || (b[i]) == b[0]) {
            a[i - 1] = i;

        }
        else  a[i - 1] = 0;
    }
    filter_int(a);
}



string GeneratedL(int b[17]) {
    string variante;
    int car_free[16];
    carouriLibere(b, car_free);
    for (int i = 0; i < 11; i++) {
        int p = car_free[i];
        variante = variante + (G3U1L(b, p));
        variante = variante + (G3U1R(b, p));
        variante = variante + (G3R1D(b, p));
        variante = variante + (G3R1U(b, p));
        variante = variante + (G3L1D(b, p));
        variante = variante + (G3R1U(b, p));
        variante = variante + (G3D1L(b, p));
        variante = variante + (G3D1R(b, p));
        variante = variante + (G1D3L(b, p));
        variante = variante + (G1D3R(b, p));
        variante = variante + (G1U3R(b, p));
        variante = variante + (G1U3L(b, p));
        variante = variante + (G1R3U(b, p));
        variante = variante + (G1R3D(b, p));
        variante = variante + (G1L3D(b, p));
        variante = variante + (G1L3U(b, p));

    }

    return variante;

};

/*
   ------------ GENERAREA POSIBILELOR L  -------------------
*/



 bool gameOver(string variante) {
    int n_v = variante.length();
    return ((n_v == 0));
}
 string alegerea_variantei(string variante) {
     int k=0;
     int num = 5;
     for (int  i = 0; i < variante.length(); i++)
     {
         if (variante[i] == '@') k++;
     }
     int random = rand() % k + 1;

     for (int i = 0; i < random - 1; i++)
     {
         variante.erase(0,variante.find('@')+1) ;

     }
     variante.erase(variante.find('@'), variante.length() - variante.find('@') );


     return variante;
}

 void fixarePozitieNoua(string pozitie) {
     int valoare = state[0];
     int b[4];
     int k=0;
     while (pozitie.find('#') < 40) {
        pozitie[pozitie.find('#')] = ' ';
        int position = pozitie.find('#');
        if (pozitie[position-2]!= ' ') {
            char numb[2] = { pozitie[position - 2],pozitie[position - 1] };
            int number =  (numb[0]-48) * 10 + numb[1]-48;
            b[k] = number;

        }
        else {
            int number = pozitie[position - 1]-48;
            b[k] = number;

        }
        k++;
        if (pozitie.length() - 1 == pozitie.find('#')) { break; };
     }


     for (int i = 1; i <= 16; i++) {
         if (state[i] == valoare) {
             state[i] = 0;
         }
     }
     for (int i = 0; i < 4; i++) {
         state[b[i]] = valoare;
     }
 }
 void plasarePietriiCC() {
     int pozitii_stone[2];
     int k = 0;
     for (int i = 1; i <= 16; i++) {
         if (state[i] == 3) {
             pozitii_stone[k] = i;
             k++;
         }
     }

     int v = rand() % 2;


     state[pozitii_stone[v]] = 0;
     k = 0;
     int  pozitii_stone_variante[7];
     for (int i = 1; i <= 16; i++) {
         if (state[i] == 0){
             pozitii_stone_variante[k] = i;
             k++;
         }
     }

     int temp = pozitii_stone_variante[rand() % k];
     cout << temp << " "<< k<< endl;
     state[temp] = 3;
 }
 void modificareJucator() {
     if (state[0] == 1) {
         state[0] = 2;
     }
     else {
         state[0] = 1;
     }

 }
 void who_won() {
     if (state[0] == 1) {
         text(7);
     }
     else {
         text(8);

     }
 }

 void plasareaPietriiPP(int q[17]) {

     next();
     text(4);
     int click_1;
     bool realyWall=false;
     do
     {
         click_1 = click_function();

         for (int i = 1 ; i<=16;i++)
         {
             if (state[click_1]==3)realyWall = true;
         }
         if(!realyWall)
         {   terenJoaca(50);
             next();
             text(2);
         };
     }while (realyWall == false);
      realyWall = false;
      next();
      text(5);
      int click_2;
     do
     {
         click_2 = click_function();
         for (int i = 1 ; i<=16;i++)
         {
             if (state[click_2]==0)realyWall = true;
         }
         if(!realyWall)
         {
             next();
             text(2);
         };
     }while (realyWall == false);

     if (q[click_1] == 3) {
         q[click_1] = 0;
         q[click_2] = 3;
     };

 };

void gameToState(string g,int b[16]){
     int valoare = state[0];

     int k=0;

   while (g.find('#') < 40)
    {
        g[g.find('#')] = ' ';
        int position = g.find('#');
        int number = g[position - 1]-48;
        b[k] = number;
        k++;
        if (g.length() - 1 == g.find('#')) { break; };
    }




}



//==================================================================

void clbuton();
void paginaPrincipala(int color);
void Setting(int color);

//==================================================================

void titlu(int n){
    settextjustify(1,1);
    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 8);
    outtextxy(n, 75, "Bonol");
}

void menu(int n /*450 1050*/){
    setfillstyle(SOLID_FILL,RED);
    bar(n,690,n+130,730);
    setcolor(BLACK);
    rectangle(n,690,n+130,730);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(n+10, 720, "Back to menu");
}

//=================================================================

void terenJoaca(int l /*50 , 650*/){
    setcolor(WHITE);
    for(int i=120;i<=620;i+=125){
        line(l,i,l+500,i);
    }
    for(int j=l;j<=l+500;j+=125){
        line(j,120,j,620);
    }
}

void now(){
    settextjustify(0,1);
    setcolor(WHITE);
    setbkcolor(color);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(35, 645, "Acum merge:");

    if(state[0]==1){
        setcolor(colorB);
        outtextxy(5,670,"Jucatorul Albastru");
    }else if(state[0]==2){
        setcolor(colorR);
        outtextxy(5,670,"  Jucatorul    Rosu");
    }
}

void next(){
    setfillstyle(SOLID_FILL,color);
    bar(176,631,440,690);

}

void Redeseneaza(){
    setfillstyle(SOLID_FILL,RED);
    bar(180,660,310,685);
    setcolor(BLACK);
    rectangle(180,660,310,685);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(185, 680, "Redeseneaza");
}

void Done(){
    setfillstyle(SOLID_FILL,RED);
    bar(345,660,420,685);
    setcolor(BLACK);
    rectangle(345,660,420,685);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(360, 680, "Done");
}

void Continuie(){
    setfillstyle(SOLID_FILL,RED);
    bar(305,660,400,685);
    setcolor(BLACK);
    rectangle(305,660,400,685);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(310, 680, "Continue");
}

void Da(){
    setfillstyle(SOLID_FILL,RED);
    bar(345,660,420,685);
    setcolor(BLACK);
    rectangle(345,660,420,685);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(360, 680, "Da");
}

void Skip(){
    setfillstyle(SOLID_FILL,RED);
    bar(180,660,310,685);
    setcolor(color);
    rectangle(180,660,310,685);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(RED);
    setcolor(WHITE);
    settextjustify(0,1);
    outtextxy(195, 680, "Treci peste");
}

void text(int var){

    settextjustify(1,1);
    setbkcolor(color);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    switch (var){
case 1:{outtextxy(300,650,"Schimbati pozitia piesei L!") ;break;}
case 2:{outtextxy(300,650,"Miscare incorecta, alegeti din nou!");break;}
case 3:{outtextxy(300,650,"Doriti sa schimbati pozitia lui L?");break;}
case 4:{outtextxy(300,650,"Selectati piatra ");break;}
case 5:{outtextxy(300,650,"Alegeti noua pozitie a pietrei!");break;}
case 6:{outtextxy(300,650,"Doriti sa scimbati pozitia pietrei?");break;}
case 7:{
    bar(0,630,300,700);
    settextjustify(1,1);
    setcolor(colorR);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(300,670,"Jucatorul rosu a castigat!");
    break;
    }

case 8:{
    bar(0,630,300,700);
    settextjustify(1,1);
    setcolor(colorB);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(300,670,"Jucatorul albastru a castigat!");
    break;
    }
    case 9:{outtextxy(300,650,"Calculatorul, a efectuat miscarea");break;}
    };


}

//=================================================================

void blueL(int colorB){
    setcolor(WHITE); setfillstyle(SOLID_FILL,colorB);
    bar(101,551,150,600);
    bar(101,601,150,650);
    bar(101,651,150,700);
    bar(151,651,200,700);
    rectangle(101,551,150,600);
    rectangle(101,601,150,650);
    rectangle(101,651,150,700);
    rectangle(151,651,200,700);
}

void redL(int colorR){
    setcolor(WHITE); setfillstyle(SOLID_FILL,colorR);
    bar(251,551,300,600);
    bar(251,601,300,650);
    bar(251,651,300,700);
    bar(301,651,350,700);
    rectangle(251,551,300,600);
    rectangle(251,601,300,650);
    rectangle(251,651,300,700);
    rectangle(301,651,350,700);
}

void sett(){
    settextjustify(1,1);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
    outtextxy(300,150,"Settings");
}

void alege(int pozitie, char alege[100], char v1[50], char v2[50], int cl1, int cl2){
    int i = 210+100*(pozitie-1);
    settextjustify(0,1);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    outtextxy(50,i,"Alege ");
    outtextxy(50+textwidth("Alege "),i,alege);

    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    int j = i + textheight("A")-5;
    setfillstyle(SOLID_FILL,cl1);
    bar(300,j,320,j+20);
    rectangle(300,j,320,j+20);
    outtextxy(330,j+20,v1);

    int m = j + textheight("A")+10;
    setfillstyle(SOLID_FILL,cl2);
    bar(300,m,320,m+20);
    rectangle(300,m,320,m+20);
    outtextxy(330,m+20,v2);
}

void clAlege(){
    if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        for(int n=225; n<=425; n+=100){
        for(int m=255; m<=455; m+=100){
        if(x<300 && x>320 && x<n && x>n+20 && y<m && y>m+20){
            gata=true;
        }else if(x>=300 && x<= 320 ){
            if(y>=225 && y<=245 ){
                color = 3;
                closegraph();
                Setting(color);
            }else if(y>=255 && y<=275 ){
                color = 2;
                closegraph();
                Setting(color);
            }else if(y>=325 && y<=345 ){
                colorB=1;
                closegraph();
                Setting(color);
            }else if(y>=355 && y<=375 ){
                colorB=9;
                closegraph();
                Setting(color);
            }else if(y>=425 && y<=445 ){
                colorR=4;
                closegraph();
                Setting(color);

            }else if(y>=455 && y<=475 ){
                colorR=12;
                closegraph();
                Setting(color);

            }

            }
        }}}}


//==================================================================

void joc(){
    settextjustify(0,0);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    char *t1 = "        Jocul L este un joc de doi jucatori jucat pe o tabla de patrate ";
    char *t2 = "4x4. Fiecare jucator are un tetromino in forma de L de 3x2 si exista ";
    char *t3 = "doua piese neutre 1x1";
    outtextxy(50,150, t1);
    outtextxy(50,150+textheight(t1), t2);
    outtextxy(50,150+textheight(t1)+textheight(t2), t3);

    void* image=new char[imagesize(0, 0, 300,300)];
    readimagefile("LImage.bmp",80,500,280,700);
}

void reguli(){
    settextjustify(0,0);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(100,230, "Reguli");

    char *t1="      La fiecare tura, un jucator trebuie sa-si mute mai intai piesa L si";
    char *t2="apoi poate, optional, sa mute oricare dintre piesele neutre. Jocul este";
    char *t3="castigat lasand adversarul in imposibilitatea de a-si muta piesa L intr-o";
    char *t4="noua pozitie.";
    char *t5="      Piesele nu de pot suprapune sau acoperi alte piese. La mutarea piesei ";
    char *t6="L, aceasta este ridicata si apoi plasata in patrate goale oriunde pe tabla.";
    char *t7="Acesta poate fi rotit sau chiar rasturnat in acest sens; singura regula este";
    char *t8="ca trebuie sa se termine intr-o pozitie diferita de cea pe care a inceput-o -";
    char *t9="acoperind astfel cel putin un patrat pe care nu l-a acoperit anterior. Pentru";
    char *t10="a muta piesa neutra, un jocator pur si simplu o ridica apoi o plaseaza intr-un";
    char *t11="patrat gol oriunde pe tabla.";

    int t=0;
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    outtextxy(50,240+textheight("Reguli"),t1);
    t=textheight(t1);
    outtextxy(50,240+textheight("Reguli")+t,t2);
    t+=textheight(t2);
    outtextxy(50,240+textheight("Reguli")+t,t3);
    t+=textheight(t3);
    outtextxy(50,240+textheight("Reguli")+t,t4);
    t+=textheight(t4);
    outtextxy(50,240+textheight("Reguli")+t,t5);
    t+=textheight(t5);
    outtextxy(50,240+textheight("Reguli")+t,t6);
    t+=textheight(t6);
    outtextxy(50,240+textheight("Reguli")+t,t7);
    t+=textheight(t7);
    outtextxy(50,240+textheight("Reguli")+t,t8);
    t+=textheight(t8);
    outtextxy(50,240+textheight("Reguli")+t,t9);
    t+=textheight(t9);
    outtextxy(50,240+textheight("Reguli")+t,t10);
    t+=textheight(t10);
    outtextxy(50,240+textheight("Reguli")+t,t11);
}

//==================================================================

void buton(char nume[15], char pozitie){
    int i=120+pozitie*95;
    setfillstyle(SOLID_FILL,RED);
    bar(80,i,520,i+80);
    setcolor(BLACK);
    rectangle(80,i,520,i+80);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    setcolor(WHITE);
    setbkcolor(RED);
    settextjustify(1,1);
    outtextxy(300, i+50, nume);
}
void paginaPrincipala(int color);


void clmenu(int n/*450 1050*/){
    if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        if(x>=n && x<=n+130 && y>=690 && y<=730){
            closegraph();
            paginaPrincipala(color);
        }
    }
}

bool confirm_done(){
  const int DELAY = 50;
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN)) delay(DELAY);

        getmouseclick(WM_LBUTTONDOWN, x, y);


        if(x>345 && x<420 && y>660 && y<685)return true;
        if(x>180 && x<310 && y>660 && y<685)return false;

};

bool want(){
  const int DELAY = 50;
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN)) delay(DELAY);

        getmouseclick(WM_LBUTTONDOWN, x, y);


        if(x>180 && x<310 && y>660 && y<685)return true;
        if(x>345 && x<420 && y>660 && y<685)return false;
}

bool confirm_comp(){
  const int DELAY = 50;
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN)) delay(DELAY);

        getmouseclick(WM_LBUTTONDOWN, x, y);



        if(x>305 && x<400 && y>660 && y<685)return false;
}

void massive(int masive[4]){
  int temp, k = 0;
           do
        {
            temp = click_function();
            if (temp != 0)
            {
                masive[k] = temp;
                k++;

            }
            if (gata) break;
        }while( k < 4 );
}

int click_sageti_CC(int number){
    const int DELAY = 50;
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN)) delay(DELAY);

        getmouseclick(WM_LBUTTONDOWN, x, y);



        if(x>475 && x<550 && y>660 && y<700){ number= number - 1; return number;}
        if(x>650 && x<725 && y>660 && y<700){ number= number + 1; return number;}
        if(x>1050 && x<1180 && y>690 && y<730) return -1;
        else return n;
}

//=================================================================

void deseneaza_patrat(int x, int y, int col){
    void* image=new char[imagesize(0, 0, 600,750)];


        switch (col) {

        case 0:
            setcolor(color); setfillstyle(SOLID_FILL,color);
            bar(x,y,x+124,y+124);readimagefile("photo.bmp",x,y,x+123,y+123);break;
        case 1:
            setcolor(colorB); setfillstyle(SOLID_FILL,colorB);
            bar(x,y,x+124,y+124);break;
        case 2:
            setcolor(colorR); setfillstyle(SOLID_FILL,colorR);
            bar(x,y,x+124,y+124);break;
        case 3:
            setcolor(color); setfillstyle(SOLID_FILL,color);
            bar(x,y,x+124,y+124);readimagefile("photo.bmp",x,y,x+123,y+123);
            setcolor(BLACK); setfillstyle(SOLID_FILL,BLACK);
            fillellipse(x+62,y+62,50,50);
         };

 }

void render() {
     int x=0, y=0, col;

     for (int i = 0; i < 16; i++)
     {
         x=i%4+1;
         y=i/4+1;
         col=state[i+1];
         x=(x-1) * 125 + 50+1;
         y=(y-1) * 125+ 120+1;
         deseneaza_patrat(x, y, col);

     }
    now();
    terenJoaca(50);
    next();
 }

void render_2(int q, int g[16]) {
     int x=0, y=0, col;

     for (int i = 0; i < 16; i++)
     {
         x=i%4+1;
         y=i/4+1;
         col=g[i];
         x=(x-1) * 125 + q+1;
         y=(y-1) * 125+ 120+1;
         deseneaza_patrat(x, y, col);

     }

    terenJoaca(q);

 }

//=================================================================

int gCC() {
    int count;
     fix_history(0);
     for ( count = 1; count <= n; count++) {
         string variante = GeneratedL(state);
         if (!gameOver(variante)) {
             fixarePozitieNoua(alegerea_variantei(variante));
             plasarePietriiCC();
             modificareJucator();
             afiseaza_state();

             fix_history(count);
         }
         else {
             cout << "Game Over" << endl;

             return count;
         }
     }
     return count;
 }

void updateState(){
    state[0] = 2;
    state[1] = 3;
    state[2] = 2;
    state[3] = 2;
    state[4] = 0;
    state[5] = 0;
    state[6] = 1;
    state[7] = 2;
    state[8] = 0;
    state[9] = 0;
    state[10] =1 ;
    state[11] = 2;
    state[12] = 0;
    state[13] = 0;
    state[14] = 1;
    state[15] = 1;
    state[16] = 3;
}

void miscareaComputer(){
    string variante = GeneratedL(state);
    if (!gameOver(variante)){
        fixarePozitieNoua(alegerea_variantei(variante));
        plasarePietriiCC();
        modificareJucator();
    }

};

//=================================================================


void dreapta(){
    setfillstyle(SOLID_FILL,RED);
    bar(475,660,550,700);
    setcolor(BLACK);
    rectangle(475,660,550,700);
    line(490,680,535,680);
    line(490,680,510,690);
    line(490,680,510,670);

}

void stanga(){
    setfillstyle(SOLID_FILL,RED);
    bar(650,660,725,700);
    setcolor(BLACK);
    rectangle(650,660,725,700);
    line(665,680,710,680);
    line(690,690,710,680);
    line(690,670,710,680);

};

void text_2(int var){
   char buffer[100];


  // print "My age is " and age variable to buffer variable
    sprintf(buffer,"miscarea : %d  " , var);
    settextjustify(1,1);
    setbkcolor(color);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    outtextxy(300,105,buffer);




}

void text_3(int var){
   char buffer[100];


  // print "My age is " and age variable to buffer variable
    sprintf(buffer,"miscarea : %d  " , var);
    settextjustify(1,1);
    setbkcolor(color);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    outtextxy(900,105,buffer);




}


//==================================================================

void paginaPrincipala(int color){
    initwindow(600,750,"menu");
    setbkcolor(color); clearviewport();

    titlu(300);
    buton("1x1", 0);
    buton("1xComp", 1);
    buton("CompxComp", 2);
    buton("Settings", 3);
    buton("Regulile jocului", 4);
    buton("Exit", 5);
    gata = false;
    do{
    clbuton();
    }while (!gata);

    getch(); closegraph();
}

void PlvsPl(int color){
    initwindow(600,750,"PLvsPL");
    setbkcolor(color); clearviewport(); setcolor(WHITE);
    titlu(300);
    updateState();
    render();
    menu(450);
    next();

    do
    {
        int click_massive[4];



          do
          {
                next();
                text(1);
                terenJoaca(50);
                massive(click_massive);
                next();
                text(3);
                Done();
                Redeseneaza();

          }while (!confirm_done());

          if (isRealyL(state, click_massive))
          {
                string s = join_function(click_massive, '#');
                fixarePozitieNoua(s);
                render();
                text(6);
                Skip();
                Da();
                if (!gameOver(GeneratedL(state))) if(!want())plasareaPietriiPP(state);
                modificareJucator();
                render();
          }else
          {
                    next();
                    text(2);
                    render();
          }

    }
    while (!gameOver(GeneratedL(state)) == true);
     who_won();


    getch(); closegraph();
}

void PlvsC(int color){
    initwindow(600,750,"PLvsPL");

    setbkcolor(color); clearviewport(); setcolor(WHITE);
    updateState();
    titlu(300);
    render();
    menu(450);
    next();
    int miscare = 1;
    do
    {
        int click_massive[4];


        if (state[0]==miscare)
        {
            miscareaComputer();
            render();
            text(9);
            Continuie();
            if (confirm_comp());

        }else
        {
            do
            {
                next();
                text(1);
                terenJoaca(50);
                massive(click_massive);
                next();
                text(3);
                Done();
                Redeseneaza();
            }while (!confirm_done());

            if (isRealyL(state, click_massive))
            {

                string s = join_function(click_massive, '#');
                fixarePozitieNoua(s);
                render();
                text(6);
                Skip();
                Da();
                if (!gameOver(GeneratedL(state))) if(!want())plasareaPietriiPP(state);
                modificareJucator();
                render();
            }else
            {
                next();
                text(2);
                render();
            }

        }


    }
    while (!gameOver(GeneratedL(state)) == true);
     who_won();

    getch(); closegraph();
}

void CvsC(int color){
    initwindow(1200,750);
    setbkcolor(color); clearviewport(); setcolor(WHITE);
    updateState();
    titlu(600);
    menu(1050);


    int k = gCC()-1;
    int limita = k+1;
    bool back_not_to_menu = true;
    dreapta();
    stanga();
    do{

        int local_state_1[16];
        int local_state_2[16];
        gameToState(game[k-1],local_state_1);
        gameToState(game[k],local_state_2);
        render_2(50,local_state_1);
        render_2(650,local_state_2);
        text_2(k-1);
        text_3(k);
        k = click_sageti_CC(k);
        if (k==0)k=1;
        if (k == limita)k= limita -1;
        if (k == -1)
        {
            closegraph();
            paginaPrincipala(color);
        }

    } while (back_not_to_menu );





}

void Setting(int color){
    initwindow(600,750);
    setbkcolor(color); clearviewport();

    titlu(300);
    sett();
    alege(1,"culoarea de fundal", "CYAN", "GREEN", CYAN, GREEN);
    alege(2,"culoarea L1","BLUE","LIGHTBLUE", BLUE, LIGHTBLUE);
    alege(3,"culoarea L2","RED","LIGHTRED", RED, LIGHTRED);
    menu(450);
    blueL(colorB);
    redL(colorR);
    do{
        clAlege();
        clmenu(450);
    }while (!gata);
    getch(); closegraph();
}

void ReguliJoc(int color){
    closegraph();
    initwindow(600,750);
    setbkcolor(color); clearviewport();

    titlu(300);
    reguli();
    joc();
    menu(450);
    click_function();

    getch(); closegraph();

}
void clbuton(){
    if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        for(int j=120; j<=685; j+=95){
        if(x>80 && x<520&& y>j && y<j+9){
            gata=true;

            }else if(x>80 && x<520){
            if(y>=120 && y<=210){
                closegraph();
                PlvsPl(color);
            }else if(y>=215 && y<=305){
                closegraph();
                PlvsC(color);
            }else if(y>=310 && y<=400){
                closegraph();
                CvsC(color);
            }else if(y>=405 && y<=505){
                closegraph();
                Setting(color);
            }else if(y>=500 && y<=590){
                closegraph();
                ReguliJoc(color);
            }else if(y>=595 && y<=685){
                closegraph();
            }}}
    }
}

//=================================================================

//==================================================================

int main(){   srand(time(0));



  paginaPrincipala(color);


}
