#ifndef TRANDAFIR_H
#define TRANDAFIR_H
#include "Floare.h"

class Trandafir : public Floare{
private:
    int numar_spini;
public:
    //CONSTRUCTORI
    Trandafir(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, const int zi_plantare_ = 0, const int numar_spini_ = 0);
    //constructor de copiere
    Trandafir(const Trandafir& other);

    //GETTERS
    //SETTERS

    //OPERATORI
    Trandafir& operator=(const Trandafir& other);

    //FUNCTII
    void Descrie(std::ostream& os) const override;
    //functie specifica acestei derivate, deci va aparea dynamic_cast
    void Atentioneaza() const;

    //DESTRUCTOR
    ~Trandafir();
};

#endif /* TRANDAFIR */