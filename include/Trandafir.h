#ifndef TRANDAFIR_H
#define TRANDAFIR_H
#include "Floare.h"

class Trandafir : public Floare{
private:
    int numar_spini;
public:
    //CONSTRUCTORI
    Trandafir(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, std::string culoare_ = "", const int numar_spini_ = 0);


    //OPERATORI
    

    //FUNCTII
    void Descrie(std::ostream& os) const override;
    //functie specifica acestei derivate, deci va aparea dynamic_cast
    void Atentioneaza();

    //DESTRUCTOR
    ~Trandafir();
};

#endif /* TRANDAFIR */