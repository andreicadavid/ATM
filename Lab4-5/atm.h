//
// Created by andre_pzeda4p on 28.03.2023.
//

#ifndef SDSEM2_ATM_H
#define SDSEM2_ATM_H
#include "tranzactie.h"
#include "colectie.h"
class Atm{
private:
    Tranzactie* tranzactii;
    Collection colectie;
    int numarTranzactii;
public:
    Atm();
    Atm(Tranzactie* tranzactii, Collection colectie, int numarTranzactii);
    Atm operator=(Atm& a);
    ~Atm();
    int get_numartranzactii();
    Tranzactie* get_alltransactions();
    Collection get_colectie();
    void set_tranzactii(Tranzactie* tranzactii);
    void set_colectie(Collection colectie);
    void set_numartranzactii(int numartranzactii);


};
#endif //SDSEM2_ATM_H
