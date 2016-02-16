#include "matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix(int m){
    //konstruktor
	_meret = m; //Mátrix mérete m:int
	_matrix = new int*[_meret]; //Lefoglal egy _meret hosszúságú tömböt a memóriában.

	for(int i=0;i<_meret;++i){
		_matrix[i] = new int[_meret]; //Fõátló felett _meret-i darab elem van. ezért mindig csak annyit kéne le foglalni.
    }
    //a _matrix tömb minden eleméhez lefoglal _meret hosszúságú tömböt így kapunk _meret*_meret (m*m) es mátrixot
    //Kiemenő adat: új null mátrix (Matrix)
}

Matrix::Matrix(const Matrix& m){
	//másoló konstruktor

	_meret = m._meret;          //Konstruktor elje
	_matrix = new int*[_meret];

	for(int i=0;i<m._meret;++i){
        _matrix[i] = new int[_meret];	//Konstruktor vége
		for(int j=0;j<m._meret;++j){
			_matrix[i][j] = m._matrix[i][j]; //Miután belement az i-edik sorba és lefoglalta a hozzá tartozó oszlopokat
        }                                    //Át másolja a paraméterül kapott m Mátrixból az elemeket az új mátrixba.
	}
	//Kimenő adat: új mátrix (Mátrix) aminek az értékei meg egyezzik a paraméterül kapott m Mátrixal.
}

Matrix::~Matrix(){
	//Szimpla Mátrix destruktor
	for(int i=0;i<_meret-i;++i){
		delete [] _matrix[i]; //Törli a lefoglalt oszlopokat.
    }
	delete [] _matrix; //Törli a lefoglalt mátrixot.
}


void Matrix::Berak(int i,int j,int szam){
	if(i<0 || j<0 || i>=_meret || j>=_meret ){
            throw OVERINDEXED;
    }
    if(j>=i){
        _matrix[i][j] = szam;
    }else if(i>j) throw NULLPART;
}


int Matrix::Kiolvas(int i,int j) const{
    //a mátrix i-edik sorának j edik oszlopának elem értékét adja vissza a Kiolvas metódus.
    if(i<0 || j<0 || i>=_meret || j>=_meret ){
            throw OVERINDEXED; //Ha elrontottuk az indexelés (- szám, vagy túl indexeltünk)
    }                          //Akkor OVERINDEXED kivételkezelést adunk.
	if(i>j) throw NULLPART;    //Ha főátlón kivül eső elemre hivatkozunk NULLPART kivételkezelés.
	return _matrix[i][j];      //Ha minden jó vissza adjuk a kiválaszott elem értékét.
}


void Matrix::Size(int m){
    //Egy adott mátrix méretét változtatjuk meg.
    if(m<0) {throw OVERINDEXED;} //Ha negatív számot akarunk megadni méretnek akkor OVERINDEXED kiv. dob
    if(m==_meret) {return;} //Ha meggondoljuk magunkat és ugyanazt a méretet adjuk meg ami volt akkor nem csinálunk semmit.
    if(m!=NULL){            //Ha más méretet adunk és nem NULL akkor töröljük a mátrixot. majd létrehozunk egy újat.
        //Szimpla Mátrix destruktor
        for(int i=0;i<_meret-i;++i){
            delete [] _matrix[i];
        }
        delete [] _matrix;
    }
    //Konstruktor.
    _meret = m;
	_matrix = new int*[_meret];

	for(int i=0;i<_meret;++i){
		_matrix[i] = new int[_meret];
    }

}

Matrix& Matrix::operator=(const Matrix &m){
    // = operátor megvalósítása. Az operátor értékül adja az értékadás jobboldalán adott mátrixot
    //a baloldaon álló mátrixnak.

	if(this == &m)  return *this;   //ha a=a alaku parancsot adtak ki akkor semmi dolgunk.


    if(_meret != m._meret) throw DIFFERENT; // Különbözõ méretü mátrixok esetén DIFFERENT kivételkezelés.

	for(int i=0;i<_meret;++i)	//DESTR
		delete [] _matrix[i];

	delete [] _matrix;			//DESTR VEGE

	_meret = m._meret;					//Másoló KONSTR
	_matrix = new int*[_meret];

	for(int i=0;i<_meret;++i){
		_matrix[i] = new int[_meret];
		for(int j=0;j<m._meret;++j){
			_matrix[i][j] = m._matrix[i][j];
        }
	}									//Másoló KONSTR VEGE

	return *this;
}

Matrix Matrix::operator+(const Matrix &m) const{
    //Az operátor két oldalán lévő mátrixot összeadja.
    //ehhez létrehoz egy 3. mátrixot aminek a mérete megeggyezik a mátrixok méretével.

	if(_meret != m._meret){throw DIFFERENT;} //Ha a két mátrix mérete különböző akkor DIFFERENT kivételt dobunk.

	Matrix osszeg(_meret);

	for(int i=0;i<_meret;++i){              //Végig járjuk a tömböket és összeadjuk az adott elemeket
		for(int j=0;j<_meret;++j){          //Az összeg mátrixba.
            osszeg._matrix[i][j] = _matrix[i][j] + m._matrix[i][j];
        }
    }
    //Kimenetel: az operátor kétoldalán lévő mátrixösszege (Mátrix).
	return osszeg;
}

Matrix Matrix::operator*(const Matrix &m) const{
    //Az operátor két oldalán lévő mátrixot összeadja.
    //ehhez létrehoz egy 3. mátrixot aminek a mérete megeggyezik a mátrixok méretével.
    if(_meret != m._meret){throw DIFFERENT;}//Ha a két mátrix mérete különböző akkor DIFFERENT kivételt dobunk.

	Matrix szorzat(_meret);
    //Működése az összeadáséval megeggyezik csak itt szorozzuk a kiolvasott értékeket.
	for(int i=0;i<_meret;++i){
		for(int j=0;j<_meret;++j){
            int tmp =0;
            for(int k=0;k<_meret;++k){
                tmp += _matrix[i][k] * m._matrix[k][j];
            }
            szorzat._matrix[i][j] = tmp;
        }
    }
    //Kimenetel: az operátor kétoldalán lévő mátrix szorzata (Mátrix).
	return szorzat;
}

std::ostream& operator<<(std::ostream& s, const Matrix& m){
    //Az operátor kiírja az adott Mátrix összes elemét. Ami kívül esik a felsőháromszög mátrixon aztis!
    for(int i=0; i<m._meret; ++i){
        for(int j=0; j<m._meret; ++j){
            s << std::setw(5) << m._matrix[i][j];
        }
        s << std::endl;
    }
    s<< std::endl;
    return s;
}

std::istream& operator>>(std::istream& s, Matrix& m)
{
    //Az operátor a standard bemenetről bekéri az adott mátrix felsőháromszögbe eső elemeit.
    for(int i=0; i<m._meret; ++i) {
            for(int j=0;j<m._meret;++j){
                if(i>j) { m._matrix[i][j] = 0; }
                else{
                    std::cout << "[" << i << "," << j << "]=";
                    s >> m._matrix[i][j];
                }
            }
    }
    return s;
}
