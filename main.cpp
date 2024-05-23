#include <iostream>
#include "include/Floare.h"
#include "include/Gradina.h"
#include "include/Trandafir.h"
#include "include/Bujor.h"
#include "include/FloareaSoarelui.h"


int main()
{
    //facem o gradina
    Gradina gradina;

    //initializam seed ul din cadrul functie rand() pentru a avea boboci diferiti de fiecare data
    srand(static_cast<unsigned>(time(0)));

    //facem cateva flori de plantat in gradina si care vor crea alte flori
    Floare* f1 = new Bujor("bujor",2,7,0);
    f1->AfisareInformatii(); //apelam functia din baza (clasa abstracta floare)
    std::cout << std::endl;
    std::cout << *f1 << std::endl; //aratam cum functioneaza operatorul de afisare << pentru fiecare derivata
    Floare* f2 = new Trandafir("trandafir",2,10,0);
    std::cout << *f2 << std::endl;
    Floare* f3 = new FloareaSoarelui("floarea_soarelui",2,8,0);
    std::cout << *f3 << std::endl;
    Floare* f4 = new Bujor("bujor",2,7,0,0);

    //plantam florile in gradina
    gradina.AdaugaFloare(f1);
    gradina.AdaugaFloare(f2);
    gradina.AdaugaFloare(f3);
    gradina.AdaugaFloare(f4);

    //simulam trecerea zilelor si ce se intampla in gradina
    while(Gradina::GetZiuaCurenta() != 100)
    {
        Gradina::TreceZiua();
        std::cout << Gradina::GetZiuaCurenta() << std::endl;
        gradina.VerificaGradina();
    }

    // try
    // {
    //     Trandafir& t = dynamic_cast<Trandafir&>(flori[i]);
    //     t.Atentioneaza();
    // } 
    // catch (const std::bad_cast& error){}
    // try
    // {
    //     Bujor& b = dynamic_cast<Bujor&>(flori[i]);
    //     b.PuneIngrasamant();
    // } 
    // catch (const std::bad_cast& error) {}

    return 0;
}