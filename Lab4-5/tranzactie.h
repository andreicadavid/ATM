//
// Created by andre_pzeda4p on 28.03.2023.
//

#ifndef SDSEM2_TRANZACTIE_H
#define SDSEM2_TRANZACTIE_H
#include "colectie.h"
class Tranzactie {
private:
    int idTransactie;
    int suma;
    Collection colectie;
public:
    Tranzactie();
    Tranzactie(int id, int suma, Collection colectie);
    ~Tranzactie();
    Tranzactie operator=(Tranzactie& t);
    int get_id();
    int get_suma();
    Collection get_collection();
    void set_id(int id);
    void set_suma(int suma);
    void set_collection(Collection colectie);
};
#endif //SDSEM2_TRANZACTIE_H
