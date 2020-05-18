#include "Actor.h"

Actor::Actor(int CNP, std::string nume, Film* film, int salariu, std::string rol):Persoana(CNP,nume,film,salariu), rol(rol)
{
    //std::cout<<"Constructor Actor\n";
}
Actor::Actor(const Actor& other): Persoana(other)
{
    this->rol = other.rol;
    //std::cout<<"Constructor copiere Actor\n";
}
Actor& Actor:: operator = (const Actor& other)
{
    if(this != &other){
        this->Persoana::operator = (other);
        this->rol=other.rol;
    }
    return *this;
}
Actor::~Actor()
{
   // std::cout<<"Destructor Actor\n";
}
std::istream& operator >> (std::istream& in, Actor& aux)
{
    in >> dynamic_cast<Persoana&>(aux);
    std::cout<<"Introduceti rolul: ";
    in >> aux.rol;
    return in;
}
std::ostream& operator << (std::ostream& out, Actor& aux)
{
    aux.afisare();
    return out;
}
void Actor::afisare()
{
    this->Persoana::afisare();
    std::cout<<"\nRolul: "<<this->rol;
    std::cout<<"\n";
}
int Actor:: bonus()
{
    if (this->rol == "principal")
    {
        return 10 * (this->film->getIncasari()) / 100;
    }
    return 0;
}
int Actor:: venit()
{
    return this->bonus() + this->salariu;
}
std::string Actor:: getRol() const
{
    return this->rol;
}

