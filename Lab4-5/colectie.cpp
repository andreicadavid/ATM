#include "colectie.h"
#include <iostream>
#include "vectordinamic.h"
using namespace std;
Collection::Collection() {
    this -> distinctelements = 0;
    this -> capacity = 75;
    this -> elements = List<int>();
    this -> occurrences = List<int>();
}

void Collection::add(TElem elem) {
    if (this->elements.search(elem) != -1) {
        int position= elements.search(elem);
        int oc = this -> occurrences.get_at(position) ;
        this -> occurrences.set_at(position, oc + 1);

    } else {
        this -> occurrences.push_backL(1);
        this -> elements.push_backL(elem);
        this -> distinctelements ++;


    }
}
bool Collection::remove(TElem elem) {
    if(search(elem)) {
        int i = this->elements.search(elem);
        this->elements.delete_at(i);
        this->occurrences.delete_at(i);
        return true;
    }
    return false;
}

bool Collection::search(TElem elem) {
    return this -> elements.search(elem);
}

int Collection::get_distinctelements() {
    return this -> elements.size();
}

int Collection::noccurrences(TElem elem) {
    int i = this -> elements.search(elem);
    return this -> occurrences.get_at(i);
}

Collection::~Collection() {

}

Node <int> *Collection::get_elements() {
    return this -> elements.getList();
}
Node<int> *Collection::get_occurences() {
    return this -> occurrences.getList();
}

int Collection::getAtEl(int i) {
    return elements.get_at(i);
}

int Collection::getAtOc(int i) {
    return occurrences.get_at(i);
}

void Collection::setoc(int i, int oc) {
    this -> occurrences.set_at(i, oc);
}
