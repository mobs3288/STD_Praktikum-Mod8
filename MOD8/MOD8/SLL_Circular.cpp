#include "SLL_Circular.h"

void createList(List &L) {
    first(L) = nil;
}

address newElement(infotype dataBaru) {
    address P = new elmList;

    info(P).nama = dataBaru.nama;
    info(P).prioritas = dataBaru.prioritas;
    info(P).sisa_durasi = dataBaru.sisa_durasi;
    next(P) = nil;

    return P;
}

void insertFirst(List &L, address P){
    address Q = first(L);

    if (first(L) == NULL) {
        first(L) = P;
        next(P) = first(L);
    } else {
        while (next(Q) != first(L)) {
            next(P) = first(L);
            first(L) = P;
            next(Q) = first(L);
            Q = next(Q);
        };
    }
}

void insertAfter(List &L, address prec, address P) {
    if (first(L) == nil || prec == nil) {
        cout << "LIST KOSONG" << endl;
    }else if (next(prec) == first(L)) {
        next(P) = first(L);
        next(prec) = P;
    }else{
        next(P) = next(prec);
        next(prec) = P;
    }
}

void insertLast(List &L, address P) {
    address Q = first(L);

    if (first(L) == nil){
        first(L) = P;
        next(P) = first(L);
    }else{
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void insertDescending(List &L, infotype dataBaru) {
    address P = newElement(dataBaru);
    address Q = first(L);
    address Z = first(L);

    if (first(L) == nil) {
        insertFirst(L, P);
    }else {
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        if (info(P).prioritas > info(first(L)).prioritas) {
            insertFirst(L,P);
        }else if (info(P).prioritas < info(Q).prioritas) {
            insertLast(L, P);
        }else {
            while (info(P).prioritas < info(Z).prioritas) {
                Q = Z;
                Z = next(Z);
            }
            insertAfter(L, Q, P);
        }
    }
}

void deleteFirst(List &L, address &P) {
    address Q = first(L);
    P = first(L);

    if (next(first(L)) == first(L)) {
        first(L) = nil;
        next(P) = nil;
    }else {
        first(L) = next(first(L));
        next(P) = nil;
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        next(Q) = first(L);
    }
}

void deleteLast(List &L, address &P) {
    address Q = first(L);

    while (next(next(Q)) != first(L)) {
        Q = next(Q);
    }
    P = next(Q);
    next(P) = nil;
    next(Q) = first(L);
}

void deleteAfter(List &L, address prec, address &P) {
    prec = first(L);
    P = next(prec);

    if ((first(L) == nil) || (next(prec) == nil)) {
        cout << "Data Tidak Bisa Dihapus" << endl;
    }else{
        if (next(P) == nil) {
            next(prec) = nil;
        }else {
            next(prec) = next(P);
            next(P) = nil;
        }
    }
}

void deleteElm(List &L, address P) {
    address Q = next(P);

    if (P = first(L)) {
        deleteFirst(L, P);
    }else if (next(P) == first(L)) {
        deleteLast(L, P);
    }else {
        while (next(Q) != P) {
            Q = next(Q);
        }
        deleteAfter(L, Q, P);
    }
}

int eksekusi(address p, int durasi){
    infotype info;
    info(p).sisa_durasi = info(p).sisa_durasi - durasi;

    return info(p).sisa_durasi;
}

int panjangList(List L){
    address p;
    int a = 1;
    p = first(L);

    while (next(p)!= first(L)){
        a++;
        p=next(p);
    }

    return a;
}
void insertAplikasi(List &L, infotype dataBaru){
    int MAX = panjangList(L);
    address P;
    address Q = first(L);

    insertDescending(L,dataBaru);

    while(MAX > 5){
        deleteLast(L,P);
        MAX--;
    }

}

void printList(List L) {
    address P = first(L);

    if (P != nil) {
        do {
            cout << info(P).nama;
            cout << info(P).prioritas;
            cout << info(P).sisa_durasi;
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "KOSONG";
    }
    cout << endl;
}
