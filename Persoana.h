#pragma once
#include <string>
#include <iostream>
#include "Film.h"
#include <vector>

class Persoana
{
protected:
    int CNP; /// 5 = barbat, 6 = femeie
    std::string nume;
    Film* film;
    int salariu;
public:
    Persoana(int CNP = 0, std::string nume = "", Film* film = new Film, int salariu = 0);
    Persoana(const Persoana& );
    Persoana& operator = (const Persoana& );
    virtual ~Persoana();
    virtual void afisare();
    virtual int bonus()=0;
    virtual int venit()=0;
    friend std::istream& operator >> (std::istream&, Persoana& );
    friend std::ostream& operator << (std::ostream& , Persoana&);
    int getSalariu() const;
    Film* getFilm() const ;
};

