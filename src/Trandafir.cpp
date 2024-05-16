#include "../include/Trandafir.h"

//CONSTRUCTORI

Trandafir::Trandafir(std::string denumire_, const int numar_boboci_, const int durata_viata_, const int zi_plantare_, std::string culoare_, const int numar_spini_) : Floare(denumire_, numar_boboci_, durata_viata_, zi_plantare_, culoare_), numar_spini{numar_spini_} {}

//constructor de copiere
Trandafir::Trandafir(const Trandafir& other) : Floare(other), numar_spini{other.numar_spini} {}


//OPERATORI

//operator de atribuire prin copiere
Trandafir& Trandafir::operator=(const Trandafir& other)
{
    //obiectului curent ii aplicam static cast pentru a putea folosi operatorul egal suprascris acolo
    static_cast <Floare&> (*this) = other;
    //acum ne ocupam de partea specifica ob de tip Trandafir
    numar_spini = other.numar_spini;
    return *this;
}


//FUNCTII

void Trandafir::Descrie(std::ostream& os) const
{
    os << "Trandafirul este o floare elegantă și parfumată, cunoscută pentru petalele sale delicate și colorate. Este un simbol al iubirii și frumuseții.\n";
}

void Trandafir::Atentioneaza() const
{
    if(numar_spini != 0)
        std::cout << "ATENTIE! Nu te intepa in spini! \n";
}

//DESTRUCTOR

Trandafir::~Trandafir()
{
    std::cout << "~Trandafir\n";
}