#ifndef BUJOR_H
#define BUJOR_H
#include "Floare.h"

class Bujor : public Floare{
private:

public:
    //CONSTRUCTORI

    //OPERATORI

    //FUNCTII
    void Descrie(std::ostream& os) const override;

    //DESTRUCTOR
    ~Bujor();
};


#endif /* BUJOR_H */