//
// Created by andre_pzeda4p on 28.03.2023.
//
#include "atm.h"

Atm::Atm() {
    this -> tranzactii = new Tranzactie[20];
    this -> colectie = Collection();
    this -> numarTranzactii = 0;
}

Atm::Atm(Tranzactie *tranzactii, Collection colectie, int numarTranzactii) {
    this -> tranzactii = tranzactii;
    this -> colectie  = colectie;
    this -> numarTranzactii = numarTranzactii;
}

Atm Atm::operator=(Atm &a) {
    this -> tranzactii = a.tranzactii;
    this -> colectie = a.colectie;
    this -> numarTranzactii = a.numarTranzactii;
    return *this;
}

Atm::~Atm() {

}

Tranzactie *Atm::get_alltransactions() {
    return this -> tranzactii;
}

Collection Atm::get_colectie() {
    return this -> colectie;
}
void Atm::set_tranzactii(Tranzactie *tranzactii) {
    this -> tranzactii = tranzactii;
}

void Atm::set_colectie(Collection colectie) {
    this -> colectie = colectie;
}

int Atm::get_numartranzactii() {
    return this -> numarTranzactii;
}

void Atm::set_numartranzactii(int numartranzactii) {
    this -> numarTranzactii = numartranzactii;
}
