#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <typeinfo>
#include "Film.h"
#include "Persoana.h"
#include "Actor.h"
#include "Regizor.h"
#include "PersonalTehnic.h"
#include "MyException.h"
#include <algorithm>

template <class T>
class FirmaDistributie
{
    std::vector<Film*> filme;
    std::vector<T*> personal;
    static int nrFilme;
    static int nrPersonal;
public:
    FirmaDistributie() {}
    FirmaDistributie(std::vector<Film*> f, std::vector<T*> p, int nrf, int nrp)
    {
        nrFilme = nrf;
        for(int i = 0; i < nrFilme; i++)
            filme.push_back(f[i]);

        nrPersonal = nrp;
        for(int i = 0; i < nrPersonal; i++)
            personal.push_back(p[i]);

    }
    FirmaDistributie(const FirmaDistributie<T>& other )
    {
        nrFilme = other.nrFilme;
        for(int i = 0; i < nrFilme; i++)
            filme.push_back(other.filme[i]);

        nrPersonal = other.nrPersonal;
        for(int i = 0; i < nrPersonal; i++)
            personal.push_back(other.personal[i]);
    }
    ~FirmaDistributie()
    {
        for(int i = 0; i < nrFilme; ++i)
            delete filme[i];
        for(int i = 0; i < nrPersonal; ++i)
            delete personal[i];
    }
    static int getNrFilme()
    {
        return nrFilme;
    }
    static int getNrPersonal()
    {
        return nrPersonal;
    }
    std::vector<Film*> getFilme() const
    {
        return this->filme;
    }
    std::vector<T*> getPersonal() const
    {
        return this->personal;
    }
    FirmaDistributie& operator = (const FirmaDistributie<T>& aux )
    {
        if (this != &aux)
        {
            nrFilme = aux.nrFilme;
            for(int i = 0; i < nrFilme; i++)
                filme.push_back(aux.filme[i]);

            nrPersonal = aux.nrPersonal;
            for(int i = 0; i < nrPersonal; i++)
                personal.push_back(aux.personal[i]);
        }
        return *this;
    }
    void introduceFilm(Film* f)
    {
        nrFilme++;
        filme.push_back(f);
    }
    void introducePersoana(T* p)
    {
        class std::vector<T*>::iterator it = std::find(personal.begin(), personal.end(), p);
        if(it == personal.end())
        {
            std::cout<<"Tipul personalului este: "<<typeid(T).name()<<"\n";
            nrPersonal++;
            personal.push_back(p);
            introduceFilm(p->getFilm());
        }
        else
            throw MyException();
    }
    friend std::istream& operator >> (std::istream& in, FirmaDistributie<T>& aux)
    {
        std::cout << "Introduceti nr personalului: ";
        int n;
        in >> n;
        std::cout<<"Introduceti personalul: ";
        for(int i=0; i < n; ++i)
        {
            T* r = new T;
            in >> *r;
            aux.introducePersoana(r);
        }
        return in;
    }
    friend std::ostream& operator << (std::ostream& out, const FirmaDistributie<T>& aux)
    {
        out << "   Personalul: ";
        for(int i =0; i<aux.nrPersonal; i++)
            aux.personal[i]->afisare();
        return out;
    }
};
template<class T>
int FirmaDistributie<T>::nrFilme = 0;
template<class T>
int FirmaDistributie<T>::nrPersonal = 0;

template<>
class FirmaDistributie<Actor>
{
    std::vector<Film*> filme;
    std::vector<Actor*> personal;
    static int nrFilme;
    static int nrPersonal;
    static int nrActoriPrincipali;
public:
    FirmaDistributie<Actor>()
    {
        //std::cout<<"Constructor firma specializata\n";
    }
    FirmaDistributie<Actor>(std::vector<Film*> f, std::vector<Actor*> p, int nrf, int nrp, int nrap)
    {
        this->nrFilme = nrf;
        for(int i = 0; i < nrFilme; i++)
            filme.push_back(f[i]);

        this->nrPersonal = nrp;
        for(int i = 0; i < nrPersonal; i++)
            personal.push_back(p[i]);
        this->nrActoriPrincipali = nrap;

    }
    FirmaDistributie<Actor>(const FirmaDistributie<Actor>& other )
    {
        this->nrFilme = other.nrFilme;
        for(int i = 0; i < nrFilme; i++)
            this->filme.push_back(other.filme[i]);

        this->nrPersonal = other.nrPersonal;
        for(int i = 0; i < nrPersonal; i++)
            this->personal.push_back(other.personal[i]);
    }
    ~FirmaDistributie<Actor>()
    {
        for(int i=0; i<nrFilme; ++i)
            delete filme[i];
        for(int i=0; i<nrPersonal; ++i)
            delete personal[i];
    }
    static int getNrFilme()
    {
        return nrFilme;
    }
    static int getNrPersonal()
    {
        return nrPersonal;
    }
    static int getNrActoriPrincipali()
    {
        return nrActoriPrincipali;
    }
    std::vector<Film*> getFilme() const
    {
        return this->filme;
    }
    std::vector<Actor*> getPersonal() const
    {
        return this->personal;
    }
    FirmaDistributie<Actor>& operator = (const FirmaDistributie<Actor>& aux )
    {
        if (this != &aux)
        {
            nrFilme = aux.nrFilme;
            for(int i = 0; i < nrFilme; i++)
                filme.push_back(aux.filme[i]);

            nrPersonal = aux.nrPersonal;
            for(int i = 0; i < nrPersonal; i++)
                personal.push_back(aux.personal[i]);
        }
        return *this;
    }
    void introduceFilm(Film* f)
    {
        nrFilme++;
        filme.push_back(f);
    }
    void introducePersoana(Actor* p)
    {
        std::vector<Actor*>::iterator it = std::find(personal.begin(), personal.end(), p);
        if(it == personal.end())
        {
            nrPersonal++;
            personal.push_back(p);
            introduceFilm(p->getFilm());
            if (p->getRol() == "principal")
                nrActoriPrincipali++;
        }
        else
            throw MyException();
    }

    friend std::istream& operator >> (std::istream& in, FirmaDistributie<Actor>& aux )
    {
        std::cout << "Introduceti nr personalului: ";
        int n;
        in >> n;
        std::cout<<"Introduceti actorii: ";
        for(int i=0; i < n; ++i)
        {
            Actor* a = new Actor;
            in >> *a;
            aux.introducePersoana(a);

        }
        return in;
    }
    friend std::ostream& operator << (std::ostream& out, const FirmaDistributie<Actor>& aux)
    {
        out << "   Actorii: \n";
        for(int i = 0; i<aux.nrPersonal; i++)
            aux.personal[i]->afisare();
        return out;
    }
};
int FirmaDistributie<Actor>::nrFilme = 0;
int FirmaDistributie<Actor>::nrPersonal = 0;
int FirmaDistributie<Actor>::nrActoriPrincipali = 0;

int main()
{
    Film* f1 = new Film("twilight", "horror", 2, 15000);
    std::vector<Actor*> actori;
    Actor* a1 = new Actor(2, "Ion", f1, 200, "principal");
    FirmaDistributie<Actor> firma;
    firma.introducePersoana(a1);
    try
    {
        firma.introducePersoana(a1);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::set<std::tuple<Persoana*, Film*, int>> persoane;;
    int n;
    std::cout << "Introduceti n: ";
    std::cin >> n;
    for(int i = 0; i < n; ++i )
    {
        std::cout<<"Introduceti tipul: (0 = actor, 1 = regizor, 2 = personal tehnic)";
        int op;
        std::cin >> op;
        if(op == 0)
        {
            Actor * a = new Actor;
            std::cin >> *a;
            Film* f = a->getFilm();
            int bonus = a->bonus();
            std::tuple <Persoana*, Film*, int> temp = std::make_tuple(a, f, bonus);
            persoane.insert(temp);

        }
        else if(op == 1)
        {
            Regizor* r = new Regizor;
            std::cin >> *r;
            Film* f = r->getFilm();
            int bonus = r->bonus();
            std::tuple <Persoana*, Film*, int> temp = std::make_tuple(r, f, bonus);
            persoane.insert(temp);
        }
        else if (op == 2)
        {
            PersonalTehnic* p = new PersonalTehnic;
            std::cin >> *p;
            Film* f = p->getFilm();
            int bonus = p->bonus();
            std::tuple <Persoana*, Film*, int> temp = std::make_tuple(p, f, bonus);
            persoane.insert(temp);
        }
        else
            std::cout<<"Introduceti o optiune valida!\n";
    }
    for (std::set<std::tuple<Persoana*, Film*, int>>::iterator it = persoane.begin(); it != persoane.end(); ++it )
    {
        std::tuple<Persoana*, Film*, int> temp = *it;
        Persoana* p = std::get<0>(temp);
        std::cout<<*p;
        Film* f = std::get<1>(temp);
        std::cout<<*f;
        std::cout<<"Bonusul: "<<std::get<2>(temp);
    }
    Persoana* pers[2];
    Film f("saw", "horror", 2, 269);
    Actor aux(5, "Ion", &f, 200, "principal");
    Regizor reg(6, "Ana", &f, 500);
    pers[0] = &aux;
    pers[1] = &reg;
    pers[0]->afisare();
    std::cout<<"\n"<<pers[1]->venit();
    return 0;
}
