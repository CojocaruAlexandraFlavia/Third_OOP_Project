#include "Persoana.h"


class PersonalTehnic:public Persoana
{
public:
    PersonalTehnic(int CNP = 0, std::string nume = "", Film* film = new Film, int salariu = 0);
    PersonalTehnic(const PersonalTehnic&);
    virtual ~PersonalTehnic();
    void afisare();
    friend std::istream& operator >>(std::istream&, PersonalTehnic&);
    friend std::ostream& operator << (std::ostream&, const PersonalTehnic&);
    PersonalTehnic& operator = (const PersonalTehnic& );
    int bonus();
    int venit();
};


