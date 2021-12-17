#include "SLL_Circular.h""

int main()
{
   List L;
   createList(L);
   infotype Info;
   address p;
   int panjang;

   Info.nama = "CROME";
   Info.prioritas = 8;
   Info.sisa_durasi = 5;
   insertAplikasi(L,Info);
   cout << panjangList(L) << endl;
   printList(L);

   Info.nama="WA";
   Info.prioritas=7;
   Info.sisa_durasi=10;
   insertAplikasi(L,Info);
   cout<<panjangList(L);
   printList(L);
}
