#include "../include/Floare.h"

Floare::Floare(std::string denumire_, const int numar_boboci_, const int durata_viata_, std::string culoare_) : denumire{denumire_}, numar_boboci{numar_boboci_}, durata_viata{durata_viata_}, culoare{culoare_}
{
    if(numar_boboci_ == 0)
        boboci = nullptr;
    else 
        boboci = new Floare[numar_boboci_];
}