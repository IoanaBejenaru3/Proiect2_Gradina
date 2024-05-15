#ifndef GRADINA_H
#define GRADINA_H
#include "floare.h"
#include <vector>

class Gradina{
private:
    std::vector <Floare&> flori;
    static int ziua_curenta;
public:
    static void TreceZiua();
    void AdaugaFloare(const Floare& floare, const int numar);
    //verificam daca in gradina mai avem flori in viata
    //daca nu avem grija sa o scoatem din vector ca si cum "ar fi murit" si sa plantam bobocii ei la loc in gradina
    void VerificaGradina();
};

#endif /* GRADINA_H */