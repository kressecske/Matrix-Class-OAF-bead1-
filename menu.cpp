#include "menu.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Menu::Run()
{
    int c = 0;
    do{
        MenuWrite();
        cin >> c;
        switch(c){
        case 1: cin >> a; break;
        case 2: cout << a; break;
        case 3: Sizer(); break;
        case 4: Get(); break;
        case 5: Set(); break;
        case 6: Sum(); break;
        case 7: Mul(); break;
        }
    }while(c!=0);
}
void Menu::MenuWrite()
{
    cout << endl << endl;
    cout << " 1. -Matrix feltoltese" << endl;
    cout << " 2. -Matrix kiirasa" << endl;
    cout << " 3. -Matrix meretenek valtoztatasa" << endl;
    cout << " 4. -Matrix adott elemenek lekerdezese" << endl;
    cout << " 5. -Matrix adott elemenek felulirasa" << endl;
    cout << " 6. -Matrixhoz egy masik matrix hozzaadasa" << endl;
    cout << " 7. -Matrix szorzasa egy masik matrixszal" << endl;
    cout << " 0. -Kilepes" << endl;
}

void Menu::Get(){
    int i,j;
    cout << "Adja meg a sor indexet:"; cin >> i;
    cout << "Adja meg az oszlop indexet:"; cin >> j;
    cout << "m[" << i << "," << j << "]= ";
    try{
        cout << a.Kiolvas(i,j);
    }catch(Matrix::Exceptions ex){
        switch (ex){
        case Matrix::OVERINDEXED :
            cout << "Tulindexeles!" << endl; break;
        case Matrix::NULLPART :
            cout << 0 << endl; break;
        }
    }
}

void Menu::Set(){
    int i,j;
    int szam;
    cout << "Adja meg a sor indexet:"; cin >> i;
    cout << "Adja meg az oszlop indexet:"; cin >> j;
    try{
        cout << "Adja meg az erteket:"; cin >> szam;
        a.Berak(i,j,szam);
    }catch(Matrix::Exceptions ex){
        switch (ex){
        case Matrix::OVERINDEXED :
            cout << "Tulindexeles!" << endl; break;
        case Matrix::NULLPART :
            cout << "Felsomatrixon kivul eso elem nem irhato!\n"; break;
        }
    }
}

void Menu::Sizer(){
    cout << "a Matrix uj merete: ";
    int sizer;
    cin >> sizer;
    try{a.Size(sizer);}
    catch(Matrix::Exceptions ex){
        switch(ex){
        case Matrix::OVERINDEXED:
            cout << "Nem megfelelo meret lett megadva" << endl; break;
        }
    }
}

void Menu::Sum(){
    cout << "Masodik matrix merete:" << endl;
    int s;
    cin >> s;
    Matrix b(s);
    cout << "Masodik matrix feltoltese:" << endl;
    cin >> b;
    try{
        cout << "a+b=" << endl << a+b << endl;
    }catch(Matrix::Exceptions ex){
        switch (ex){
        case Matrix::DIFFERENT :
            cout << "A ket matrix merete kulonbozik!" << endl; break;
        }
    }
}

void Menu::Mul(){
    cout << "Masodik matrix merete:" << endl;
    int s;
    cin >> s;
    Matrix b(s);
    cout << "Masodik matrix feltoltese:" << endl;
    cin >> b;
    try{
        cout << "a*b=" << endl << a*b << endl;
    }catch(Matrix::Exceptions ex){
        switch (ex){
        case Matrix::DIFFERENT :
            cout << "A ket matrix merete kulonbozik!" << endl; break;
        }
    }
}
