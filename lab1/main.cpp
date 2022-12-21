#include "menu.cpp"
#include "HashTable.hpp"

int main() {
  // int* a = new int[4];
  // a[0] = 3;
  // a[1] = 5;
  // a[2] = 1;
  // a[3] = 4;


  // ListSequence<int>* as = new ListSequence<int>(a, 4);
  // BitonicSort<int>* bs = new BitonicSort<int>();
  // bs->Sort(as, test);
  // for (int i = 0; i < 4; i++)
  // {
  //   std::cout << as->Get(i) << '\n';
  // }
  // menu();
  HashTable<const char*, int>* ht = new HashTable<const char*, int>(5);
  // ht->Set(0, 1);
  ht->Set("aasgd", 3);
  ht->Set("ы", 1);
  ht->Set("tttttt", 4);
  ht->Set("89", 1);
  ht->PrintOut();
  ht->Set("ы", 2);
  ht->PrintOut();
  std::cout << ht->Get("89");
  delete ht;


  
  return 0;
}