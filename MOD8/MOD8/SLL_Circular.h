#ifndef SLL_CIRCULAR_H_INCLUDED
#define SLL_CIRCULAR_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P)     (P) -> info
#define next(P)     (P) -> next
#define first(L)    ((L).first)
#define last(L)     ((L).last)
#define alokasi(P)  (P) -> alokasi
#define nil NULL

struct infotype {
    string nama;
    int prioritas;
    int sisa_durasi;
};

typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address createElemen(infotype dataBaru);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertDescending(List &L, infotype dataBaru);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElms(List &L, address P);
void printList(List L);
int panjangList(List L);
void insertAplikasi(List &L, infotype dataBaru);
int eksekusi(address P, int durasi);
void eksekusiMulti(List &L,address &current, int N, int duration);

#endif // SLL_CIRCULAR_H_INCLUDED
