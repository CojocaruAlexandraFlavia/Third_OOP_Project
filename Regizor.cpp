#include "Regizor.h"

Regizor::Regizor(int CNP, std::string nume, Film* film, int salariu):Persoana(CNP, nume, film, salariu)
{
    //std::cout<<"Constructor Regizor\n";
}
Regizor::Regizor(const Regizor & other): Persoana(other)
{
    //std::cout<<"Constructor copiere Regzior\n";
}
Regizor::~Regizor()
{
    //std::cout<<"Destructor Regizor\n";
}
int Regizor::bonus()
{
    return this->sumaFixa;
}
int Regizor::venit()
{
    return this->bonus() + this->salariu;
}
std::istream& operator >> (std::istream& in, Regizor& aux)
{
    in >> dynamic_cast<Persoana&>(aux);
    return in;
}
std::ostream& operator << (std::ostream& out, Regizor& aux)
{
    aux.afisare();
    return out;
}
Regizor& Regizor:: operator = (const Regizor& other)
{
    if(this != &other)
    {
        this->Persoana::operator = (other);
    }
    return *this;
}
void Regizor::afisare()
{
    this->Persoana::afisare();
    std::cout<<"\nSuma fixa este: "<<this->sumaFixa;
    std::cout<<"\n";
}
int Regizor::getSumaFixa() const
{
    return this->sumaFixa;
}
