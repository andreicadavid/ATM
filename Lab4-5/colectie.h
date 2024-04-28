//
// Created by andre_pzeda4p on 23.03.2023.
//

#ifndef SDSEM2_COLECTIE_H
#define SDSEM2_COLECTIE_H
#include "vectordinamic.h"
#include "List.h"
typedef int TElem;

class Collection{
private:
    List<int> elements;
    List<int> occurrences;
    int distinctelements;
    int capacity;
    void redim();
public:
    Collection();
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int get_distinctelements();
    int noccurrences(TElem elem);
    ~Collection();
    Node<int>* get_elements();
    Node<int>* get_occurences();
    int getAtEl(int i);
    int getAtOc(int i);
    void setoc(int i, int oc);
};
#endif //SDSEM2_COLECTIE_H
