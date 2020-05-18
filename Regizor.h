#include "Persoana.h"


class Regizor:public Persoana
{
    const int sumaFixa = 100;
public:
    Regizor(int CNP = 0, std::string nume = "", Film* film = new Film, int salariu = 0);
    Regizor(const Regizor&);
    virtual ~Regizor();
    int bonus();
    int venit();
    friend std::istream& operator >> (std::istream&, Regizor&);
    friend std::ostream& operator << (std::ostream&, const Regizor&);
    Regizor& operator = (const Regizor& );
    int getSumaFixa() const;
    void afisare();
};


