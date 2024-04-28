//
// Created by andre_pzeda4p on 5/30/2023.
//
#include <iostream>
#include "inout.h"
using namespace std;
void alimentare(Collection& colectie) {
    colectie.add(500);
    colectie.add(200);
    colectie.add(100);
    colectie.add(50);
    colectie.add(10);
    colectie.add(5);
    colectie.add(1);
}
int main() {
    Collection colectie;
    for (int i = 0; i < 10; i++) {
        alimentare(colectie);
    }
    run_menu(colectie, "C:\\Faculta\\an1sem1\\Structuri de Date\\Lab4-5\\tranzactii.txt");
    return 0;
}
