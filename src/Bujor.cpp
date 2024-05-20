#include "../include/Bujor.h"

//CONSTRUCTOR

Bujor::Bujor(std::string denumire_, const int numar_boboci_, const int durata_viata_, const int zi_plantare_) : Floare(denumire_, numar_boboci_, durata_viata_, zi_plantare_) {}

//constructor de copiere
Bujor::Bujor(const Bujor &other) : Floare(other) {}


//OPERATORI

Bujor& Bujor::operator=(const Bujor& other)
{
    //facem static cast asupra obiectului curent de tip Bujor si ne folosim de operatorul = supraincarcat in cadrul clasei Floare pentru a copia din other
    static_cast<Floare&>(*this) = other;
    //nu avem alte variabile deci nu mai copiem nimic
    return *this;
}


//FUNCTII

void Bujor::Descrie(std::ostream& os) const
{
    os << "Bujorul este o planta perena cu flori mari, colorate si parfumate, din familia Paeoniaceae. Florile sale pot fi albe, roz, rosii si alte culori, fiind foarte apreciate in aranjamente florale.\n";
}

void Bujor::PuneIngrasamant()
{
    for(int i = 0; i < numar_boboci; i++)
        boboci[i] ++;
    std::cout << "Am pus ingrasamant.\n";
}

Bujor::~Bujor()
{
    std::cout << "~Bujor\n";
}