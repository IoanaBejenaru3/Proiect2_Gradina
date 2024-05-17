#include "../include/Bujor.h"

//CONSTRUCTOR

Bujor::Bujor(std::string denumire_, const int numar_boboci_, const int durata_viata_, const int zi_plantare_, std::string culoare_) : Floare(denumire_, numar_boboci_, durata_viata_, zi_plantare_, culoare_) {}

//constructor de copiere
Bujor::Bujor(const Bujor &other) : Floare(other) {}


//OPERATORI

Bujor& Bujor::operator=(const Bujor& other)
{
    //facem static cast asupra obiectului curent de tip Bujor si ne folosim de operatorul = supraincarcat in cadrul clasei Floare pentru a copia din other
    static_cast<Floare&>(*this) = other;
    //nu avem alte variabile deci nu mai copiem nimic
}

void Bujor::Descrie(std::ostream& os) const
{
    os << "Bujorul este o plantă perenă cu flori mari, colorate și parfumate, din familia Paeoniaceae. Florile sale pot fi albe, roz, roșii și alte culori, fiind foarte apreciate în aranjamente florale.\n";
}

