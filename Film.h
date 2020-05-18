#pragma once
#include <string>
#include<iostream>

class Film
{
    std::string nume;
    std::string tip;
    double durata;
    int incasari;
public:
    Film(std::string nume="", std::string tip="", double durata=0, int incasari=0);
    Film(const Film&);
    virtual ~Film();
    Film& operator = (const Film&);
    friend std::istream& operator >> (std::istream&, Film& );
    friend std::ostream& operator << (std::ostream&, Film& );
    std::string getNume() const;
    std::string getTip() const;
    double getDurata() const;
    int getIncasari() const;
    void setNume(std::string );
    void setTip(std::string );
    void setDurata(double);
    void setIncasari(int);
    void afisare();
};


