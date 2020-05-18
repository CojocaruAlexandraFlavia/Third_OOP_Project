#include "PersonalTehnic.h"

PersonalTehnic::PersonalTehnic(int CNP, std::string nume, Film* film, int salariu):Persoana(CNP, nume, film, salariu)
{
    //std::cout<<"Constructor PersonalTehnic\n";
}
PersonalTehnic::PersonalTehnic(const PersonalTehnic& other):Persoana(other)
{
    //std::cout<<"Constructor copiere PersonalTehnic\n";
}
PersonalTehnic::~PersonalTehnic()
{
    //std::cout<<"Destructor PersonalTehnic\n";
}
PersonalTehnic& PersonalTehnic:: operator = (const PersonalTehnic& other)
{
    if(this != &other)
        this->Persoana:: operator = (other);
    return *this;
}
void PersonalTehnic::afisare()
{
    Persoana::afisare();
}
std::istream& operator >> (std::istream& in, PersonalTehnic& aux)

{
    in >> dynamic_cast<Persoana&>(aux);
    return in;
}
std::ostream& operator << (std::ostream& out, PersonalTehnic& aux)
{
    aux.afisare();
    return out;
}
int PersonalTehnic::bonus()
{
    return 0;
}
int PersonalTehnic::venit()
{
    return this->salariu;
}
