#include "Persoana.h"

Persoana::Persoana(int CNP, std::string nume, Film* film, int salariu ): CNP(CNP), nume(nume),film(film), salariu(salariu)
{
    //std::cout<<"Constructor Persoana\n";
}
Persoana::Persoana(const Persoana& other):CNP(other.CNP), nume(other.nume), film(other.film), salariu(other.salariu)
{
    //std::cout<<"Constructor copiere Persoana\n";
}
Persoana::~Persoana()
{
    //std::cout<<"Destructor Persoana\n";
}
Persoana& Persoana::operator=(const Persoana& other)
{
    if(this != &other){
        this->CNP=other.CNP;
        this->film=other.film;
        this->nume=other.nume;
        this->salariu=other.salariu;
    }
    return *this;
}
std::istream& operator >> (std::istream& in, Persoana& aux)
{
    std::cout<< "PERSOANA: \n";
    std::cout<<"Introduceti CNP-ul: ";
    in>>aux.CNP;
    std::cout<<"Introduceti numele: ";
    in>>aux.nume;
    std::cout<<"Introduceti filmul: \n";
        Film* f = new Film;
        in >> *f;
        aux.film = f;
    std::cout<<"Introduceti salariul: ";
    in>>aux.salariu;
    return in;
}
std::ostream& operator << (std::ostream& out,  Persoana& aux)
{
    aux.afisare();
    return out;
}
int Persoana:: getSalariu() const
{
    return this->salariu;
}
Film* Persoana:: getFilm()
{
    return this->film;
}
void Persoana::afisare()
{
    std::cout<<"CNP: "<<this->CNP;
    std::cout<<"\nNume: "<<this->nume;
    std::cout<<"\nFilm: ";
    std::cout<<"\n  Nume film: "<<this->film->getNume();
    std::cout<<"\n  Tipul: "<<this->film->getTip();
    std::cout<<"\n  Durata: "<<this->film->getDurata();
    std::cout<<"\n  Incasarile: "<<this->film->getIncasari();
    std::cout<<"\nSalariu: "<<this->salariu;
}
