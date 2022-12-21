#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sequence.hpp"
#include <functional>
#include <iostream>
#include <string>
#include "Pair.hpp"


template <class T, class K>
class HashTable
{
private:
  Sequence<Sequence<Pair<T, K>*>*>* buffer;
  int len;
public:
  HashTable(int len) : len(len)
  {
    buffer = (Sequence<Sequence< Pair<T, K>*>*>*) new ArraySequence<Sequence<Pair<T, K>*>*>();
    for (size_t i = 0; i < len; i++)
    {
      buffer->Append((Sequence<Pair<T, K>*>*) new ListSequence<Pair<T, K>*>());
    }
  }
  ~HashTable()
  {
    delete this->buffer;
  };

private:
  int getHash(T key)
  {
    std::hash<T> h;
    return h(key);
  }

public:
  void Set(T key, K value)
  {
    
    int index = getHash(key) % len;
    Sequence<Pair<T,K>*>* collisionList = buffer->Get(index);
    int flag = false;
    for (size_t i = 0; i < collisionList->GetLength(); i++)
    {
      Pair<T, K>* p = collisionList->Get(i);
      if(p->GetFirst() == key) {
        p->Set(key, value);
        return;
      }
    }
    Pair<T, K>* newRecord = new Pair<T, K>(key, value);
    collisionList->Append(newRecord);
    
  }

  K Get(T key)
  {
    int index = getHash(key) % len;
    Sequence<Pair<T,K>*>* collisionList = buffer->Get(index);
    for (size_t i = 0; i < collisionList->GetLength(); i++)
    {
      Pair<T, K>* p = collisionList->Get(i);
      if(p->GetFirst() == key) return p->GetSecond();
    }
    return NULL;
    
  }

  void PrintOut()
  {
    for (size_t i = 0; i < len; i++)
    {
      if(buffer->Get(i)->GetLength() == 0) continue;
      std::cout << "---------" << std::endl;
      for (size_t k = 0; k < buffer->Get(i)->GetLength(); k++)
      {
        std::cout << buffer->Get(i)->Get(k)->GetFirst() << " -> " << buffer->Get(i)->Get(k)->GetSecond() << std::endl;
      }
      
      // std::cout << std::endl;
      
    }
    std::cout << "---------" << std::endl;
    
  }
};
