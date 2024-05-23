#ifndef FLOARE_H
#define FLOARE_H
#include <string>
#include <iostream>

//clasa de baza va implementa regula celor 5
//iar derivatele vor implementa regula celor 3

//interfata 
//avem planta la modul general care are cateva lucruri valabile indiferent de tip
class Planta{
    virtual void AfisareInformatii() const= 0;
    //virtual void Descrie() const = 0;
};

//clasa abstracta
//avem floare care este neinstantiabila in gradina noastra pentru ca nu stim ce fel de flaore e

class Floare : public Planta{
protected: //avem nevoie de ele in derivate si pentru a evita definirea multor getters le facem protected
    std::string denumire;
    //aici vom tine gradul de "inflorire", doar daca avem bobocul > grad_inflorire vom planta bobocul
    int *boboci;
    int numar_boboci;
    int durata_viata;
    int zi_plantare;
public:
    //CONSTRUCTORI
    //constructor
    Floare(std::string denumire_ = "", const int numar_boboci_ = 0, const int durata_viata_ = 0, const int zi_plantare_ = 0);
    //constructor de copiere
    Floare(const Floare& other);
    //constructor de mutare
    Floare(Floare&& other) noexcept;

    //GETTEERS
    std::string GetDenumire();
    int GetZiPlantare();
    int GetDurataViata();

    //SETTERS

    //OPERATORI
    //operator de afisare pentru o floare
    friend std::ostream& operator<<(std::ostream& os, const Floare& floare);
    //operator de atribuire prin copiere
    Floare& operator=(const Floare& other);
    //operator de atribuire prin mutare
    Floare& operator=(Floare&& other);

    //FUNCTII OVERRIDE
    //spunem la general ce este o floare
    virtual void AfisareInformatii() const override; //implementeaza o functie a interfetei

    //FUNCTII VIRTUALE PURE
    //descriem pe scurt floarea specifica (derivata)
    virtual void Descrie(std::ostream& os) const = 0; //nu impementeaza functia interfetei inca, ulterior in derivate

    //FUNCTII VIRTUALE
    

    //FUNCTII "NORMALE"
    //aflam cati boboci sunt viabili
    int FloriDePlantat(const int numar);
    void MesajPlantareBoboci() const;

    //DESTRUCTOR
    //destructor virtual deoarece avem resurse alocate dinamic si este foarte important
    virtual ~Floare();
};


#endif /* FLOARE_H */