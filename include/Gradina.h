#ifndef GRADINA_H
#define GRADINA_H
#include "floare.h"
#include <vector>

//pentru aceasta clasa nu voi implementa regula celor 5 deoarece am resurse alocate dinamic
//dar voi implementa regula celor 3 pentru a repeta notiunile invatate

class Gradina{
private:
    std::vector <Floare&> flori;
    //variabila statica care simuleaza trecerea zilelor ca in viata reala
    //am facut-o statica deoarece exista mai multe tipuri de gradini in curtea unui om 
    //precum gradina de flori (pe care se bazeaza proiectul), gradina de legume, de pomi(nu voi implementa in cadrul acestui proiect)
    //si ideea este ca indiferent de gradina zilele care trec sunt aceleasi pentru toate (ca sa stim cand "dau roadele =)")
    static int ziua_curenta;
public:
    //CONSTRUCTORI
    Gradina(std::vector <Floare&> flori_);
    //constructor de copiere
    Gradina(const Gradina& other);
    //GETTERS
    static int GetZiuaCurenta();

    //OPERATORI
    Gradina& operator=(const Gradina& other);

    //FUNCTII
    static void TreceZiua();
    void AdaugaFloare(const Floare& floare);
    //verificam daca in gradina mai avem flori in viata
    //daca nu avem grija sa o scoatem din vector ca si cum "ar fi murit" si sa plantam bobocii ei la loc in gradina
    void VerificaGradina();

    //DESTRUCTOR
    ~Gradina();
};



#endif /* GRADINA_H */