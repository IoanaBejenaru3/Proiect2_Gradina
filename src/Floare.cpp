#include "../include/Floare.h"


//CONSTRUCTORI

//constructor
Floare::Floare(std::string denumire_, const int numar_boboci_, const int durata_viata_, const int zi_plantare_) : denumire{denumire_}, numar_boboci{numar_boboci_}, durata_viata{durata_viata_}, zi_plantare{zi_plantare_}
{
    if(numar_boboci_ == 0)
        boboci = nullptr;
    else 
        {
            boboci = new int[numar_boboci_];
            for(int i = 0; i < numar_boboci; i++)
                boboci[i] = rand() % 10;
        }
    
}

//constructor de copiere
Floare::Floare(const Floare& other) : denumire{other.denumire}, numar_boboci{other.numar_boboci}, durata_viata{other.durata_viata},zi_plantare{other.zi_plantare}
{
    //acum trebuie sa ne asiguram ca facem copierea resurselor alocate dinamic corect
    //trebuie doar sa copiem nu sa si stergem
    //NU UITA!!! suntem in constructor de copiere, noi acum CONSTRUIM obiectul prin copiere, nimic nu trebuie sters pentru ca de fapt nu exista nimic inca in obiec
    if(other.numar_boboci == 0)
        boboci = nullptr;
    else
    {
        boboci = new int[other.numar_boboci];
        for(int i = 0; i < other.numar_boboci; i++)
            boboci[i] = other.boboci[i]; //merge sa scriem la fel ca la vectori deoarece pointerii au sprascrisa [i] si de fapt sare la adresa corecta "start + 4*i"
    }
}

//constructor de mutare
//explicatii???: cand vine vorba de constructorul de mutare ma gandesc asa: eu nu am nimic in obiectul in care vreau sa mut
//               de unde si "construirea" acestuia, asadar, mutam resursele din other in ob curent SI NU VREM SA ELIBERAM MEMORIA deoarece acum ob curent va "pointa" spre ele (resursele alocate dinamic)
//               de asta nu eliberam nimic la constructori
Floare::Floare(Floare&& other) noexcept:  denumire{other.denumire}, numar_boboci{other.numar_boboci}, durata_viata{other.durata_viata}, zi_plantare{other.zi_plantare}, boboci{other.boboci}
{
    other.denumire = "";
    other.durata_viata = 0;
    other.numar_boboci = 0;
    other.zi_plantare = 0;
    other.boboci = nullptr;
}


//GETTERS
std::string Floare::GetDenumire()
{
    return this->denumire;
}

int Floare::GetZiPlantare()
{
    return this->zi_plantare;
}

int Floare::GetDurataViata()
{
    return this->durata_viata;
}

//OPERATORI

//operator de afisare 
std::ostream& operator<<(std::ostream& os, const Floare& floare)
{
    //os << "Numele florii este " << floare.GetDenumire() << ".\n";
    floare.Descrie(os);
    return os;
}

//operator de atribuire prin copiere =
//de ce punem const? : vrem ca sa evitam copierea inutila a obiectului other
//                     vrem sa nu modificam nimic in cadrul obiectului other
Floare& Floare::operator=(const Floare &other)
{
    //are sens sa il copiem numai si numai daca other este diferit fata de obiectul curent
    //this tine o adresa de memorie si prin &other luam adresa de memorie a ob other si o verificam cu cea din this
    if(this != &other)  
    {
        //vrem sa atribuim prin COPIERE ceea ce inseamna ca nu vrem sa stergem sau sa modificam nimic in cradrul ob other (de unde si const)
        //de asemenea noi atribuim valori din other unui obiect deja INSTANTIAT ceea ce inseamna ca tot ce
        //aveam alocat dinamic trebuie eliberat pentru a evita memory leaks
        denumire = other.denumire;
        numar_boboci = other.numar_boboci;
        zi_plantare = other.zi_plantare;
        if(boboci != nullptr) //daca avem ceva alocat
            delete []boboci;
        boboci = new int[numar_boboci]; //alocam atata spatiu cat este si in other
        for(int i = 0; i < numar_boboci; i++)
            boboci[i] = other.boboci[i];
        durata_viata = other.durata_viata;
    } 
    return *this; //returnam o referinta de tip floare
}

//operrator de atribuire prin MUTARE = 
//de ce NU punem const? : in cadrul mutarii unui obiect vrem sa ne asiguram ca ob din care am preluat informatia nu o mai contine ulterior
//                        const nu ne-ar permite sa modificam nimic obiectului
Floare& Floare::operator=(Floare&& other)
{
    //acelasi principiu, are sens sa mutam numai si numai daca obiectele sunt diferite
    if(this != &other)
    {
        //prima oara ne vom ocupa de variabilele care nu sunt alocate dinamic
        denumire = other.denumire;
        other.denumire = ""; //"eliberam" ceea ce era inainte
        numar_boboci = other.numar_boboci;
        other.numar_boboci = 0;
        durata_viata = other.durata_viata;
        other.durata_viata = 0;
        zi_plantare = other.zi_plantare;
        other.zi_plantare = 0;
        //acum ne ocupam de resursele alocate dinamic din cadrul obiectului in care vrem sa mutam
        delete []boboci; //ne asiguram ca eliberam zona de memorie
        boboci = other.boboci;
        other.boboci = nullptr; //sa nu pointeze spre ac zona de memorie
    }
    //daca era cumva ac obiect pur si simplu returnam adresa de memorie a acestuia
    return *this;
}

//FUNCTII 

void Floare::AfisareInformatii() const
{
    std::cout << "Florile sunt cunoscute pentru frumusetea, culorile si parfumurile lor, avand o importanta biologica, estetica si culturala semnificativa.\n";
}

int Floare::FloriDePlantat(const int numar)
{
    int ct = 0;
    for(int i = 0; i < numar_boboci; i++)
        if(boboci[i] >= numar) ct++;
    return ct;
}

//DESTRUCTOR

Floare::~Floare()
{
    delete []boboci;
    std::cout << "~Floare\n";
}