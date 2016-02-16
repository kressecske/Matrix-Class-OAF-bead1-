#ifndef FELSOMATRIX_H_INCLUDED
#define FELSOMATRIX_H_INCLUDED

class Matrix{
public:
	Matrix(int m);
	Matrix(const Matrix &m);					//UJ
	~Matrix();
	Matrix& operator=(const Matrix &m);			//UJ
	void Berak(int i,int j,int szam);
	void Feltolt(int szam);
	int Kiolvas(int i,int j) const;
	Matrix operator+(const Matrix &m) const;	//UJ

private:
	int _meret;
	int** _matrix;
};


#endif // FELSOMATRIX_H_INCLUDED
