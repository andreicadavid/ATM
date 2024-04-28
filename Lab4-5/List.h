
#include "Node.h"

#ifndef CURS7_P_LIST_H
#define CURS7_P_LIST_H
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    /* definiti o reprezentare inlantuita pe elementele din lista */
    Node<T>* first;

public:
    /// constructor implicit
    List () {
        this->first=nullptr;
    }

    /// \return dimensiunea listei
    int size() const;

    ///  verifica daca lista e vida
    /// \return true, daca lista e vida, altfel returneaza false
    bool is_empty() const;

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_backL(T e);

    ///
    /// \param i - pozitia unui elem in lista , 0<=i<size()
    /// \return  elementul de pe pozitia i
    /// \raise   exceptie daca i nu e valid
    T get_at(int i) const;

    // modifica element de pe pozitia i si returneaza vechea valoare
    //arunca exceptie daca i nu e valid
    T update(int i, T e);



    // adaugare element pe o pozitie i
    //arunca exceptie daca i nu e valid
    void set_at(int i, T e);

    // sterge element de pe o pozitie i si returneaza elementul sters
    //arunca exceptie daca i nu e valid
    T delete_at(int i);

    // cauta element si returneaza prima pozitie pe care apare (sau -1)
    int search(T e)  const;
    int getLength();
    // returnare iterator
//    Iterator iterator() const;

    ///
    /// destructor
    //~List();
   Node<T>* getList();
};

template<class T>
Node<T> *List<T>::getList() {
    return first;
}

template<class T>
int List<T>::getLength() {
    if(first == nullptr){
        return 0;
    }else {
        int i = 0;
        Node<T> *last = first;
        while (last->next != nullptr) {
            last = last->next;
            i++;
        }
        return i;
    }
}

template<class T>
int List<T>::search(T e) const {
    if(first == nullptr){
        return -1;
    }else{
        int i = 0;
        Node<T>* last=first;
        while (last != nullptr){
            if(last->info == e) return i;
            last= last->next;
            i++;

        }}

    return -1;
}

template<class T>
T List<T>::update(int i, T e) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    T old_value = crt->info;
    crt->info = e;

    return old_value;
}

template<class T>
T List<T>::get_at(int i) const {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template<class T>
void List<T>::push_backL(T e) {
    Node<T>* newNode = new Node<T>(e, nullptr, nullptr);
    if(first == nullptr){
        first = newNode;
    }
    else{
        Node<T>* last=first;
        while (last->next != nullptr){
            last= last->next;
        }
        last->next = newNode;
        newNode -> prev = last;
    }

}

template<class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
int List<T>::size() const {
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}
template<class T>
void List<T>:: set_at(int i, T e){

    Node<T>* newNod = new Node<T>(e, nullptr, nullptr);
    if(i == 0){
        first -> info = e;
    }else {
        Node<T> *crt = first;
        int poz = 0;
        while (poz < i && crt != nullptr) {
            crt = crt->next;
            poz++;
        }
        if(crt != nullptr){
            crt ->info = e;
        }
    }
}

template<class T>
T List<T>::  delete_at(int i) {
    Node<T>* crt = first;
    if(i == 0){
        first = first -> next;
        return crt->info;
    }
    int poz = 0;
    while(poz < i){
        poz ++;
        crt = crt -> next;
    }
    crt ->prev -> next = crt -> next;
    crt ->next -> prev = crt -> prev;
    return crt->info;

}

#endif //CURS7_P_LIST_H
