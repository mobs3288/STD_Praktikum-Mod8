#include "SLL_Circular.h"

int main()
{
   List L;
   infotype data;

   createList(L);

   // Insert 5 Data pertama
   data = newData("Word", 5, 10);
   insertAplikasi(L, data);
   printList(L);

   data = newData("Excel", 4, 20);
   insertAplikasi(L, data);
   printList(L);

   data = newData("Chrome", 8, 5);
   insertAplikasi(L, data);
   printList(L);

   data = newData("WA", 7, 10);
   insertAplikasi(L, data);
   printList(L);

   data = newData("Dota", 10, 30);
   insertAplikasi(L, data);
   printList(L);

   // Insert Data ke 6 Power Point
   data = newData("Power Point", 6, 15);
   insertAplikasi(L, data);
   printList(L);

   eksekusiMulti(L, first(L), 3, 10);
   printList(L);

   eksekusiMulti(L, first(L), 3, 10);
   printList(L);

   return 0;
}
