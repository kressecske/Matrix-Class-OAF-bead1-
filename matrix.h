#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>


class Matrix{
    public:
        enum Exceptions{OVERINDEXED,NULLPART, DIFFERENT};
        Matrix(){_meret = 0; _matrix =NULL;}
        Matrix(int m);
        Matrix(const Matrix &m);
        ~Matrix();

        void Berak(int i,int j,int szam);
        int Kiolvas(int i,int j) const;
        void Size(int m);

        Matrix& operator=(const Matrix &m);			//UJ
        Matrix operator+(const Matrix &m) const;	//UJ
        Matrix operator*(const Matrix &m) const;	//UJ

        friend std::ostream& operator<<(std::ostream& s, const Matrix& m);
        friend std::istream& operator>>(std::istream& s, Matrix& m);


    private:
        int _meret;
        int** _matrix;
};


#endif // MATRIX_H_INCLUDED
