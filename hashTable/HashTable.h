/*
 Name: Isaac Lowry
 Matric number: 170025555
 Module code: AC21008
*/

#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

typedef unsigned long ulint;

class HashTable {
  typedef vector <list<HashNode> > Table;
  Table *table; // size of table is stored in the Table data structure
  size_t num;   // number of entries in the HashTable;

public:
  HashTable();       // constructor, initializes table of size 1;
  HashTable(size_t); // constructor, requires size of table as arg
  ~HashTable();      // deconstructor

  size_t size(); // returns size of the hash table (number of buckets)
  size_t hash_function(ulint);  // the table's hash function
  ulint getValue(ulint);    // find and return data associated with key

  void insert(ulint,ulint); // insert data associated with key into table
  void erase(ulint);        // remove key and associated data from table

  void rehash(size_t); // sets a new size for the hash table, rehashes the hash table 

  // extend if necessary
};

HashTable::HashTable() {

  try
  {
     table = new (Table);
     table->resize(11);
     num = 0;
      
  }
  catch(std::bad_alloc& e) 
  {
      cout<<e.what()<<endl;
      throw HashTableError (OUT_OF_MEMORY);
  }

}

HashTable::HashTable (size_t size) {

  try
  {
     table = new (Table);
     table->resize(size);
     num = 0;
      
  }
  catch(std::bad_alloc& e) 
  {
      cout<<e.what()<<endl;
      throw HashTableError (OUT_OF_MEMORY);
  }

}

HashTable::~HashTable() {
  delete(table);
}

size_t HashTable::hash_function(ulint key) {
  return key % table->size();
}

void HashTable::insert(ulint key,ulint value) {
  try
  {
    getValue(key);
    throw HashTableError (DUPLICATE_KEY);
  }
  catch(HashTableError &e)
  {
    ulint index = hash_function(key);
    HashNode node;
    node.assign(key, value);
    table->at(index).push_back(node);
    num = num + 1;

    if((num / static_cast<float>(size())) > 0.9) 
    {
    rehash(2 * size());
    }
  }


}

ulint HashTable::getValue(ulint key) {

  ulint index = hash_function(key);
  list<HashNode> nodeList = table->at(index);
  list<HashNode>::iterator it;
  for  (it = nodeList.begin(); it != nodeList.end(); ++it) {
    
    if (it->getKey() == key)
    {
      return it->getValue();
    }
  }

  throw HashTableError (KEY_NOT_FOUND);



}

size_t HashTable::size() {

  return table->size();
}

void HashTable::erase(ulint key) {

   try
  {
    getValue(key);
    throw HashTableError (DUPLICATE_KEY);

  }
  catch(HashTableError &e)
  {
    ulint index = hash_function(key);
    list<HashNode> *nodeList = &table->at(index);
    list<HashNode>::iterator it;

    for  (it = nodeList->begin(); it != nodeList->end(); ++it) {

      if (it->getKey() == key)
      {
        nodeList->erase(it);
        num--;
        break;
      }

    }

  }
}

void HashTable::rehash(size_t num) {

  try
  {
    Table tmp = *table;
    table->clear();
    table->resize(num);
    vector<list<HashNode>>::iterator it;
    for  (it = tmp.begin(); it != tmp.end(); ++it) {
    
      list<HashNode> nodes = *it;
      list<HashNode>::iterator it2;
      for (it2 = nodes.begin(); it2 != nodes.end(); it2++)
      {
        insert(it2->getKey(), it2->getValue());
      }
    }
  }
    catch(bad_alloc& e) 
    {
      cout<<e.what()<<endl;
      throw HashTableError(OUT_OF_MEMORY);
    }
}



/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/

#endif
