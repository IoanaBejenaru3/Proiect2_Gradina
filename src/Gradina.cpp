#include "../include/Gradina.h"
#include "../include/Trandafir.h"
#include "../include/Bujor.h"
#include "../include/FloareaSoarelui.h"

//STATICE
//variabila statica
int Gradina::ziua_curenta = 0;
//un numar aleatoriu pe care bobocii trebuie sa il aiba minim pentru a-i replanta in gradina
int Gradina::grad_inflorire = 3;

//functia statica
void Gradina::TreceZiua()
{
    ziua_curenta++;
}

//CONSTRUCTORI
Gradina::Gradina(std::vector <Floare*> flori_) : flori{flori_} {}

//constructor de copiere
Gradina::Gradina(const Gradina& other) : flori{other.flori} {}

//constructor de mutare
Gradina::Gradina(Gradina&& other) noexcept
{
    flori = other.flori; //l am copiat in vectorul din cadrul obiectului curent
    other.flori.clear(); //am eliberat vectorul din obiectul other
}

//GETTERS
int Gradina::GetZiuaCurenta()
{
    //nu avem cum sa punem this->ziua_curenta pentru ca fiind o variabila statica aceasta nu 
    //depinde de "obiectul this" ci de clasa intreaga
    return ziua_curenta;
}

//OPERATORI
//operator de atribuire prin copiere
Gradina& Gradina::operator=(const Gradina& other)  
{
    if(this != &other )
    {   
        flori.clear(); //eliberam pointerii pe care ii aveam (clear-ul de la vector, fiind de=in STL, se ocupa deja de asta)
        flori = other.flori; 
    }
    return *this;
}

//operator de atribuire prin mutare
Gradina& Gradina::operator=(Gradina&& other)
{
    if(this != &other)
    {
        //trebuie sa mutam!
        //intai eliberam ce avem aici
        flori.clear();
        flori = other.flori;
        other.flori.clear(); 
    }
    return *this;
}

void Gradina::AdaugaFloare(Floare* floare)
{
    flori.push_back(floare);
}
void Gradina::VerificaGradina()
{
    std::vector <int> flori_ofilite;
    int size = flori.size();
    std::cout << size << std::endl;
    for(int i =0; i < size; i++) //verific doar florile care erau deja plantate nu si bobocii pe care ii plantam
        if(Gradina::ziua_curenta - flori[i]->GetZiPlantare() >= flori[i]->GetDurataViata())
        {
            //inseamna ca scoatem floarea din gradina deoarece e ofilita
            flori_ofilite.push_back(i); //pastram poziia si dupa vom scoate din vector
            //dupa ce am scos-o ne asiguram ca bobocii (care au "gradul de plantare" bun adica numerele memorate in boboci) sunt plantati in gradina
            Trandafir* t;
            Bujor* b;
            FloareaSoarelui * fs;
            int ct = flori[i]->FloriDePlantat(Gradina::grad_inflorire); //aflam cati boboci plantam
            if((t = dynamic_cast<Trandafir*>(flori[i])) != nullptr)
            {
                t->Atentioneaza();
                for(int k = 0; k < ct; k++)
                {
                    Floare* floare= new Trandafir("trandafir",rand() % 4,10,Gradina::ziua_curenta,rand() % 8);
                    flori.push_back(floare);
                }
                if(ct != 0) t->MesajPlantareBoboci();
            }
            else if((b = dynamic_cast<Bujor*>(flori[i])) != nullptr)
            {
                for(int k = 0; k < ct; k++)
                {
                    Floare* floare= new Bujor("bujor",rand() % 2,7,Gradina::ziua_curenta,0);
                    flori.push_back(floare);
                }
                 if(ct != 0) b->MesajPlantareBoboci();
            }
            else if((fs = dynamic_cast<FloareaSoarelui*>(flori[i])) != nullptr)
            {
                fs->AdunaSeminte();
                for(int k = 0; k < ct; k++)
                {
                    Floare* floare= new FloareaSoarelui("floarea_soarelui",rand() % 4,8,Gradina::ziua_curenta,rand() % 100);
                    flori.push_back(floare);
                }
                 if(ct != 0) fs->MesajPlantareBoboci();
            }
            else
                std::cout << "Nu exista o astfel de floare in gradina\n";
        }
        else
        {
            Bujor* b;
            if((b = dynamic_cast<Bujor*>(flori[i])) != nullptr)
                try
                {
                    b->PuneIngrasamant();
                }
                catch (const std::logic_error& l)
                {
                    std::cerr << "Exceptie prinsa: " << l.what();
                }
            
        }  
    //ne asiguram ca scoatem florile ofilite din gradina
    size = flori_ofilite.size();
    for(int i = 0; i < size; i++)
       flori.erase(flori.begin()+ flori_ofilite[i]);
}

//DESTRUCTOR
Gradina::~Gradina()
{
    std::cout << "~Gradina\n";
}