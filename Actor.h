#include "Persoana.h"

class Actor:public Persoana
{
    std::string rol;
public:
    Actor(int CNP = 0, std::string nume = "", Film* film = new Film, int salariu = 0, std::string rol = "");
    Actor(const Actor&);
    virtual ~Actor();
    friend std::istream& operator >> (std::istream&, Actor&);
    friend std::ostream& operator <<(std::ostream&, Actor&);
    Actor& operator = (const Actor&);
    void afisare();
    int bonus();
    int venit();
    std::string getRol() const;
};


