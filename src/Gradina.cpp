#include "../include/Gradina.h"

//STATICE

//variabila statica
int Gradina::ziua_curenta = 0;

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

/*void Gradina::AdaugaFloare(const Floare& floare)
{
    //adaugam un numar de flori in gradina
    flori.push_back(&floare);
}*/