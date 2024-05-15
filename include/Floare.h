#ifndef FLOARE_H
#define FLOARE_H
#include <string>
#include <iostream>

//interfata 
//avem planta la modul general care are cateva lucruri valabile indiferent de tip
class Planta{
    virtual void AfisareInformatii() const= 0;
};

//clasa abstracta
//avem floare care este neinstantiabila in gradina noastra pentru ca nu stim ce fel de flaore e

class Floare : public Planta{
private:
    std::string denumire;
    //aici vom tine gradul de "inflorire", doar daca avem bobocul > grad_inflorire vom planta bobocul
    int *boboci;
    int numar_boboci;
    int durata_viata;
    std::string culoare;
public:
    //CONSTRUCTORI
    //constructor
    Floare(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, std::string culoare_ = "");
    //constructor de copiere
    Floare(const Floare& other);
    //constructor de mutare
    Floare(Floare&& other) noexcept;

    //GETTEERS
    std::string GetDenumire();
    //OPERATORI
    //operator de afisare pentru o floare
    friend std::ostream& operator<<(std::ostream& os, const Floare& floare);
    //operator de atribuire prin copiere
    Floare& operator=(const Floare& other);
    //operator de atribuire prin mutare
    Floare& operator=(Floare&& other);

    //FUNCTII OVERRIDE
    //spunem la general ce este o floare
    void AfisareInformatii() const override;

    //FUNCTII VIRTUALE PURE
    //descriem pe scurt floarea specifica (derivata)
    virtual void Descrie(std::ostream& os) const = 0;

    //FUNCTII VIRTUALE
    

    //FUNCTII "NORMALE"
    void IncrementeazaBoocii(const int numar);
    

    //DESTRUCTOR
    //destructor virtual deoarece avem resurse alocate dinamic si este foarte important
    virtual ~Floare();
};


#endif /* FLOARE_H */