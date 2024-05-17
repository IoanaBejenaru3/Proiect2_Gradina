#include "../include/Gradina.h"
#include "../include/Trandafir.h"
#include "../include/Bujor.h"
//STATICE

//variabila statica
int Gradina::ziua_curenta = 0;
//un numar aleatoriu
int Gradina::grad_inflorire = 3;

//functia statica
void Gradina::TreceZiua()
{
    ziua_curenta++;
}


//CONSTRUCTORI
Gradina::Gradina(std::vector <Floare&> flori_) : flori{flori_} {}

//constructor de copiere
Gradina::Gradina(const Gradina& other) : flori{other.flori} {}


//GETTERS
int Gradina::GetZiuaCurenta()
{
    //nu avem cum sa punem this->ziua_curenta pentru ca fiind o variabila statica aceasta nu 
    //depinde de "obiectul this" ci de clasa intreaga
    return ziua_curenta;
}

//OPERATORI
Gradina& Gradina::operator=(const Gradina& other)  
{
    flori = other.flori;
    return *this;
}

void Gradina::AdaugaFloare(Floare& floare)
{
    flori.push_back(floare);
}
void Gradina::VerificaGradina()
{
    std::vector <int> flori_ofilite;
    int size = flori.size();
    for(int i =0; i < size; i++)
        if(Gradina::ziua_curenta - flori[i].GetZiPlantare() + 1 == flori[i].GetDurataViata())
        {
            //inseamna ca scoatem floarea din gradina deoarece e ofilita
            flori_ofilite.push_back(i); //pastram poziia si dupa vom scoate din vector
            //dupa ce am scos-o de asiguram ca bobocii ei (care au "gradul de plantare" bun adica numerele memorate in boboci) sunt plantati in gradina
            try
            {
                Trandafir& t = dynamic_cast<Trandafir&>(flori[i]);
                t.Atentioneaza();
            } 
            // catch (const std::bad_cast& error){}
            // try
            // {
            //     Bujor& t = dynamic_cast<Bujor&>(flori[i]);
                
            // } 
            // catch (const std::bad_cast& error)
        }    
}