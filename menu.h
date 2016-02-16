#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "matrix.h"

class Menu{
    public:
        Menu(){a.Size(3);}
        void Run();
    private:
        Matrix a;
        void MenuWrite();
        void Get();
        void Sizer();
        void Set();
        void Sum();
        void Mul();
};

#endif // MENU_H_INCLUDED
