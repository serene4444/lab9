#include <cassert>
#include <iostream>
using namespace std;

#include "hash_lp.h"

const int DELETED = -2;

Table::Table( )
{
   used = 0;
   for ( int i = 0; i < CAPACITY; i++ )
      table[i].key = -1;
}

void Table::insert( const RecordType& entry )
{
   bool alreadyThere;
   int index;
   
   assert( entry.key >= 0 );
   
   findIndex( entry.key, alreadyThere, index );
   if( alreadyThere )
      table[index] = entry;   
   else
   {
      assert( size( ) < CAPACITY );
      int firstDeleted = -1;
      index = hash( entry.key );
      int count = 0;
      while ( count < CAPACITY && table[index].key != -1 )
      {
         if ( table[index].key == DELETED && firstDeleted == -1 )
            firstDeleted = index;
         index = ( index + 1 ) % CAPACITY;
         count++;
      }
      if ( firstDeleted != -1 )
         index = firstDeleted;
      table[index] = entry;
      used++;
   }
}

void Table::erase( int key )
{
   bool found;
   int index;

   assert( key >= 0 );

   findIndex( key, found, index );
   if ( found )
   {
      table[index].key = DELETED;
      used--;
   }
}


int Table::hash( int key ) const
{
   return key % CAPACITY;
}

int Table::size( ) const
{
   return used;
}  

// findIndex function
//     void findIndex( int key, bool& found, int &index ) const;
// Preconditions:  key >= 0. 
// Postconditions: If a record with the indicated key is in the table, 
//    then found is true and index is set to index of the found record.
//    Otherwise, found is false and index is garbage. 

void Table::findIndex( int key, bool& found, int& i ) const
{
   int count = 0;
   
   assert( key >=0 );

   i = hash( key );
   while ( count < CAPACITY && table[i].key != -1 && table[i].key != key )
   {
      count++;
      i = (i + 1) % CAPACITY;
   }   
   found = table[i].key == key;
}

void Table::find( int key, bool& found, RecordType& result ) const
{
   int index;
   
   assert( key >=0 );
   
   findIndex( key, found, index );
   if ( found )
      result = table[index];
}


