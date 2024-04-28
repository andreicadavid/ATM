//
// Created by andre_pzeda4p on 11.04.2023.
//
#include "vectordinamic.h"

void VectorDinamic::resize() {
    TElem * newarray = new TElem [this -> capacity * 2];
    this -> capacity = this -> capacity * 2;
    for(int i = 0; i < this -> length; i++){
        newarray[i] = this -> elements[i];
    }
    delete[] this -> elements;
    this -> elements = newarray;
}

VectorDinamic::VectorDinamic(int capacity) {
    this -> elements = new TElem [capacity]();
    this -> length = 0;
    this -> capacity = capacity;
}

void VectorDinamic::add(TElem elem) {
    if (this->length == capacity - 1)
        resize();
    elements[this->length] = elem;
    this->length++;
}


void VectorDinamic::remove(int i) {
    for(int j = i; j < this -> length - 1; j ++){
        this -> elements [j] = this -> elements [j + 1];
    }
    this -> length --;

}

bool VectorDinamic::search(TElem elem) {
    int i = 0;
    while(i < this -> length){
        if(this -> elements[i] == elem){
            return true;
        }
        i ++;
    }
    return false;
}

VectorDinamic::~VectorDinamic() {

}

int *VectorDinamic::get_elements() {
    return this -> elements;
}

int VectorDinamic :: getAt(int i){
    return this -> elements[i];
}

int VectorDinamic::get_length() {
    return this -> length;
}

VectorDinamic::VectorDinamic() {

}

void VectorDinamic::setAt(int i, TElem value) {
    this -> elements[i] = value;
}

int VectorDinamic::getPosition(TElem elem) {
    for(int i = 0; i < this -> get_length(); i++){
        if(this -> elements [i] == elem) return i;
    }
}
