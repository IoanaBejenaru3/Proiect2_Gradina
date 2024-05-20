#include "../include/FloareaSoarelui.h"

//CONSTRUCTORI
FloareaSoarelui::FloareaSoarelui(std::string denumire_, const int numar_boboci_, const int durata_viata_, const int zi_plantare_, const int numar_seminte_) : Floare(denumire_, numar_boboci_, durata_viata_, zi_plantare_), numar_seminte{numar_seminte_} {}
//constructor de copiere
FloareaSoarelui::FloareaSoarelui(const FloareaSoarelui& other) : Floare(other), numar_seminte{other.numar_seminte} {}

//OPERATORI
FloareaSoarelui& FloareaSoarelui::operator=(const FloareaSoarelui& other)
{
    //facem static cast obiectului derivat la unul de baza pt a ne putea folosi de operatorul definit acolo
    static_cast<Floare&>(*this) = other;
    //completam cu  ce avem specific derivatei
    numar_seminte = other.numar_seminte;
    return *this;
}

//FUNCTII

void FloareaSoarelui::Descrie(std::ostream& os) const
{
    os << "Floarea soarelui este o planta cu flori mari, de culoare galben stralucitor, care urmaresc miscarea soarelui, fiind cunoscuta pentru inaltimea sa impresionanta si pentru semintele sale bogate in ulei.\n ";
}

void FloareaSoarelui::AdunaSeminte() const
{
    std::cout << "Am adunat inca " << numar_seminte << " seminte.\n";
}

//DESTRUCTOR
FloareaSoarelui::~FloareaSoarelui()
{
    std::cout << "~FloareaSoarelui\n";
}