//
// Created by andre_pzeda4p on 11.04.2023.
//

#ifndef SDSEM2_VECTORDINAMIC_H
#define SDSEM2_VECTORDINAMIC_H
typedef int TElem;
class VectorDinamic{
private:
    TElem* elements;
    int capacity;
    int length;
    void resize();
public:
    VectorDinamic();
    VectorDinamic(int capacity);
    void add(TElem elem);
    void remove(int i);
    bool search(TElem elem);
    ~VectorDinamic();
    int getAt(int i);
    int* get_elements();
    void setAt(int i, TElem value);
    int get_length();
    int getPosition(TElem elem);


};
#endif //SDSEM2_VECTORDINAMIC_H
