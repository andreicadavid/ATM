//
// Created by andre_pzeda4p on 28.03.2023.
//
#include "tranzactie.h"

Tranzactie::Tranzactie() {
    this -> idTransactie = 0;
    this -> suma  = 0;
    this -> colectie = Collection();
}

Tranzactie::Tranzactie(int id, int suma, Collection colectie) {
    this -> idTransactie = id;
    this -> suma = suma;
    this -> colectie = colectie;

}

Tranzactie::~Tranzactie() {

}

Tranzactie Tranzactie::operator=(Tranzactie &t) {
    this -> suma = t.suma;
    this -> idTransactie = t.idTransactie;
    this -> colectie = t.colectie;
    return *this;
}

int Tranzactie::get_id() {
    return this -> idTransactie;
}

int Tranzactie::get_suma() {
    return this -> suma;
}

Collection Tranzactie::get_collection() {
    return this -> colectie;
}

void Tranzactie::set_id(int id) {
    this ->idTransactie = id;

}

void Tranzactie::set_suma(int suma) {
    this -> suma = suma;
}

void Tranzactie::set_collection(Collection colectie) {
    this -> colectie = colectie;
}

