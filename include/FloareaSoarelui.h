#ifndef FLOAREASOARELUI_H
#define FLOAREASOARELUI_H
#include "Floare.h"


class FloareaSoarelui : public Floare{
private:
    int numar_seminte;
public:
    //CONSTRUCTORI
    FloareaSoarelui(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, const int zi_plantare_ = 0, const int numar_seminte_ = 0);
    //constructor de copiere
    FloareaSoarelui(const FloareaSoarelui& other);

    //GETTERS
    //SETTERS

    //OPERATORI
    FloareaSoarelui& operator=(const FloareaSoarelui& other);
    //FUNCTII
    void Descrie(std::ostream& os) const override;
    void AdunaSeminte() const;
    //DESTRUCTOR
    ~FloareaSoarelui();
};


#endif /* FLOAREASOARELUI */