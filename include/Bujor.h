#ifndef BUJOR_H
#define BUJOR_H
#include "Floare.h"
#include <stdexcept>

class Bujor : public Floare{
int ct_ingrasamant;
public:
    //CONSTRUCTORI
    Bujor(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, const int zi_plantare_ = 0, const int ct_ingrasmant_ = 0);
    Bujor(const Bujor& other);

    //GETTERS
    //SETTERS

    //OPERATORI
    Bujor& operator=(const Bujor& other);
    
    //FUNCTII
    void Descrie(std::ostream& os) const override;
    void PuneIngrasamant();
    
    //DESTRUCTOR
    ~Bujor();
};


#endif /* BUJOR_H */