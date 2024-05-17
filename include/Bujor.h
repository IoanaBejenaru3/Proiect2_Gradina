#ifndef BUJOR_H
#define BUJOR_H
#include "Floare.h"

class Bujor : public Floare{
public:
    //CONSTRUCTORI
    Bujor(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, const int zi_plantare_ = 0, std::string culoare_ = "");
    Bujor(const Bujor& other);

    //OPERATORI
    Bujor& operator=(const Bujor& other);
    
    //FUNCTII
    void Descrie(std::ostream& os) const override;
    void PuneIngrasamant();
    
    //DESTRUCTOR
    ~Bujor();
};


#endif /* BUJOR_H */