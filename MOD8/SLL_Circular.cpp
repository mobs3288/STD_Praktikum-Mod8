#include "sll_circular.h"

void createList(List &L) {
    first(L) = nil;
}

infotype newData(string nama, int prioritas, int sisa_durasi) {
    infotype data;

    data.nama = nama;
    data.prioritas = prioritas;
    data.sisa_durasi = sisa_durasi;

    return data;
}

address createElemen(infotype dataBaru) {
    address P;

    P = new elmList;

    info(P).nama = dataBaru.nama;
    info(P).prioritas = dataBaru.prioritas;
    info(P).sisa_durasi = dataBaru.sisa_durasi;
    next(P) = nil;

    return P;
}

void insertFirst(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
        next(P) = first(L);
    }else{
        address Q = first(L);
        do {
            Q = next(Q);
        } while (next(Q) != first(L));
        next(P) = first(L);
        first(L) = P;
        next(Q) = first(L);
    }
}

void insertLast(List &L, address P) {
    address Q;

    if (first(L) == nil){
        first(L) = P;
        next(P) = first(L);
    }else{
        Q = first(L);

        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (first(L) == nil || Prec == nil) {
        cout << "List Kosong" << endl;
    }else if (next(Prec) == first(L)) {
        next(P) = first(L);
        next(Prec) = P;
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertDescending(List &L, infotype dataBaru) {
    address P = createElemen(dataBaru);
    address Q = first(L);
    address R = first(L);

    if (first(L) == nil) {
        insertFirst(L, P);
    }else {
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        if (info(P).prioritas > info(first(L)).prioritas) {
            insertFirst(L,P);
        } else if (info(P).prioritas < info(Q).prioritas) {
            insertLast(L, P);
        } else {
            while (info(P).prioritas < info(R).prioritas) {
                Q = R;
                R = next(R);
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

void deleteAfter(List &L, address Prec, address &P) {
    P = next(Prec);
    next(Prec) = first(L);
}

void deleteElm(List &L, address P) {
    address Q = P;

    if (P == first(L)) {
        deleteFirst(L, P);
    } else if (next(P) == first(L)) {
        deleteLast(L, P);
    } else {
        deleteAfter(L, Q, P);
    }
}

int eksekusi(address P, int durasi){
    infotype info;

    return info(P).sisa_durasi = info(P).sisa_durasi - durasi;;
}

int panjangList(List L){
    address P = first(L);
    int a = 1;

    while (next(P)!= first(L)){
        a++;
        P=next(P);
    }

    return a;
}
void insertAplikasi(List &L, infotype dataBaru){
    int MAX;
    address P;

    insertDescending(L,dataBaru);
    MAX = panjangList(L);

    while (MAX > max_app){
        deleteLast(L,P);
        MAX--;
    }

}

void eksekusiMulti(List &L, address &current, int N, int duration){
    int i = 0;

    if (current != nil) {
        do {
            info(current).sisa_durasi = eksekusi(current, duration);

            address P = current;
            current = next(current);

            if (info(P).sisa_durasi <= 0) {
                deleteElm(L, P);
            }
            i++;
        } while ( i < N);
    } else {
        cout << "Tidak ada data";
    }
    cout << endl;
}

void printList(List L) {
    address P = first(L);

    if (P != nil) {
        cout << "Jumlah data : " << panjangList(L) << endl;
        do {
            cout << "<" << info(P).nama << ", ";
            cout << info(P).prioritas << ", ";
            cout << info(P).sisa_durasi << ">" << endl;
            P = next(P);
        } while (P != first(L));
    } else {
        cout << "Tidak ada data";
    }
    cout << endl;
}

/* void createList(List &L){
    last(L) = nil;
}

void printList(List L) {
    if (last(L) == nil) {
        cout << "List Kosong" << endl;
    } else {
        address P = next(last(L));

        cout << info(P).nama << endl;
        cout << info(P).prioritas << endl;
        cout << info(P).sisa_durasi << endl;

        P = next(P);

        while (P != next(last(L))) {
            cout << info(P).nama << endl;
            cout << info(P).prioritas << endl;
            cout << info(P).sisa_durasi << endl;

            P = next(P);
        }
    }
}

void insertFirst(List &L, address P) {
    if (last(L) == nil) {
        last(L) = P;
        next(last(L)) = P;
    } else {
        next(last(L)) = P;
        next(P) = last(L);
    }
}

void insertLastNew(List &L, address P) {
    address Q;
    if (next(last(L)) == nil){
        next(last(L)) = P;
        next(P) = next(last(L));
    }else{
        Q = next(last(L));
        while (next(Q) != next(last(L))) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = next(last(L));
    }
}

Menurut saya perbedaan paling besar dari antara menggunakan first dan last adalah cara penambahan element nya baik itu pada element pertama
akhir, jika menggunakan first maka eksekusi program akan dimulai dari pertama sedangkan last dimulai dari akhir */


