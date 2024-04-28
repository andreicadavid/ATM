//
// Created by andre_pzeda4p on 28.03.2023.
//
#include "inout.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "atm.h"
#include <fstream>
#include <string.h>
using namespace std;

void generate_options(int suma, Atm atm, Collection& collection) {
    int i = 0;
    while (suma > 0) {
        int el = atm.get_colectie().getAtEl(i);
        int ap = atm.get_colectie().getAtOc(i);
        if (el <= suma && ap != 0) {
            collection.add(el);
            suma = suma - el;
        } else i++;

    }
}



void savetransactions( Atm& atm){
    int id, suma;
    int n = atm.get_numartranzactii();
    Collection colectie;
    Tranzactie* pTranzactie;
    pTranzactie = atm.get_alltransactions();
    cout << "Introduceti suma: ";
    cin >> suma;
    srand(time(0));
    id = rand() % 1000;
    generate_options(suma, atm, colectie);
    int noElem = colectie.get_distinctelements();
    for(int j = 0; j < noElem - 1; j++) {
        int el = colectie.getAtEl(j);
        int oc = colectie.getAtOc(j);
        cout << el << "*" << oc << " + ";
    }
    int el = colectie.getAtEl(noElem - 1);
    int oc = colectie.getAtOc(noElem - 1);
    cout << el << "*" << oc;
    cout << endl <<  "Sunteti de acord cu aceasta modalitate ? " << endl;
    cout << " 1. DA!" << endl << " 2. NU!" << endl;
    cout << "Raspuns: ";
    int comanda;
    cin >> comanda;
    cout << endl;
    switch(comanda){
        case 1:
            pTranzactie[n].set_id(id);
            pTranzactie[n].set_suma(suma);
            pTranzactie[n].set_collection(colectie);
            n++;
            break;
        case 2:
            cout << "Ne cerem scuze!" << endl;
            break;

    }
    atm.set_numartranzactii(n);
    atm.set_tranzactii(pTranzactie);
}

void printtransactions(Atm atm){
    for(int i = 0; i < atm.get_numartranzactii() ; i++) {
        cout << "Tranzactia numarul " << i + 1 << endl;
        cout << "ID: " << atm.get_alltransactions()[i].get_id() << " ; ";
        cout << "Suma: " << atm.get_alltransactions()[i].get_suma() << " ; ";
        cout << "POSIBILITATI: ";
        Collection colectie = atm.get_alltransactions()[i].get_collection();
        for(int j = 0; j < colectie.get_distinctelements() - 1 ; j++ ) {
            cout << colectie.getAtEl(j) << "*" << colectie.getAtOc(j) << " + ";
        }
        cout << colectie.getAtEl(colectie.get_distinctelements() -1 ) << "*" << colectie.getAtOc(colectie.get_distinctelements()-1 );
        cout << endl;
    }
}
void options(){
    cout << "--------------------------------------"<<endl;
    cout << "INTRODUCETI O OPTIUNE "<< endl;
    cout << "1. EFECTUEAZA TRANZACTIE" << endl;
    cout << "2. AFISARE TRANZACTII" << endl;
    cout << "0.EXIT"<< endl;
    cout << "--------------------------------------"<<endl;
}
void citire_fisier(char* filename, Atm& atm){
    ifstream f(filename);
    while(!f.eof()){
        Collection colectie;
        int id, suma;
        f >> id >> suma;
        string s;
        f >> s;
        char*p;
        char* metoda = new char [30];
        ::strcpy(metoda, s.c_str());
        p = ::strtok(metoda, "+");
        while (p){
            int i = 0;
            int el = 0;
            int oc = 0;
            int ok = 1;
            while(i < ::strlen(p) && ok == 1){
                if(p[i] == '*'){
                    ok = 0;
                }else{
                    int m = p[i] - '0';
                    el = el*10 + m;
                }
                i++;
            }
            for(int j = i; j < ::strlen(p); j++){
                int m = p[i] - '0';
                oc = oc*10 + m;
            }
            colectie.add(el);
            colectie.setoc(colectie.get_distinctelements() - 1, oc);
            p = ::strtok(nullptr, "+");
        }
        int n = atm.get_numartranzactii();
        Tranzactie* tranzactii = atm.get_alltransactions();
        tranzactii[n].set_suma(suma);
        tranzactii[n].set_collection(colectie);
        tranzactii[n].set_id(id);
        n++;
        atm.set_numartranzactii(n);
        atm.set_tranzactii(tranzactii);
    }
}
void run_menu(Collection colectie, char * filename){
    int n  = 0;
    Tranzactie* tranzactii = new Tranzactie[20];
    bool value = true;
    Atm atm(tranzactii, colectie, n);
    citire_fisier(filename, atm);
    while(value){
        options();
        int command;
        cout << "INTRODUCETI COMANDA :";
        cin >> command ;
        switch (command) {
            case 1:
                savetransactions( atm);
                break;
            case 2:
                printtransactions(atm);
                break;
            default: {
                cout << "Goodbye!";
                value = false;
            }

        }
    }
}