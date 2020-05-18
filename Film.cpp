#include "Film.h"

Film::Film(std::string nume, std::string tip, double durata, int incasari):nume(nume), tip(tip), durata(durata), incasari(incasari)
{
    //std::cout<<"Constructor Film\n";
}
Film::Film(const Film& other):nume(other.nume),tip(other.tip), durata(other.durata), incasari(other.incasari)
{
    //std::cout<<"Constructor copiere Film\n";
}
Film::~Film()
{
   // std::cout<<"Destructor Film\n";
}
std::string Film::getNume() const
{
    return this->nume;
}
std::string Film::getTip() const
{
    return this->tip;
}
double Film::getDurata() const
{
    return this->durata;
}
int Film::getIncasari() const
{
    return this->incasari;
}
void Film::setDurata(double aux)
{
    this->durata = aux;
}
void Film::setNume(std::string aux)
{
    this->nume = aux;
}
void Film::setTip(std::string aux)
{
    this->tip = aux;
}
void Film::setIncasari(int aux)
{
    this->incasari = aux;
}
std::istream& operator >> (std::istream& in, Film& aux)
{
    std::cout<<"Introduceti numele filmului: ";
    in>>aux.nume;
    std::cout<<"Introduceti tipul filmului: ";
    in>>aux.tip;
    std::cout<<"Introduceti durata filmului: ";
    in>>aux.durata;
    std::cout<<"Introduceti incasarile filmului: ";
    in>>aux.incasari;
    return in;
}
Film& Film::operator=(const Film& aux)
{
    if(this != &aux)
    {
        this->nume = aux.nume;
        this->durata = aux.durata;
        this->incasari = aux.incasari;
        this->tip= aux.tip;
    }
    return *this;
}
void Film::afisare()
{
    std::cout<<"Numele filmului: "<<this->nume;
    std::cout<<"\nTipul filmului: "<<this->tip;
    std::cout<<"\nDurata filmului: "<<this->durata;
    std::cout<<"\nIncasarile filmului: "<<this->incasari;
    std::cout<<"\n";
}
std::ostream& operator << (std::ostream& out, Film& aux)
{
    aux.afisare();
    return out;
}
