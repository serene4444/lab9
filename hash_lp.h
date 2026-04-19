typedef int ItemType; 
const int CAPACITY = 31;

struct RecordType
{
       int key;
       ItemType data;
};

class Table
{
public:
   Table( );
   void insert( const RecordType& entry );
   void erase( int key );
   void find( int key, bool& found, RecordType& result ) const; 
   int size( ) const;
   void print( ) const;
private:
   // HELPER FUNCTIONS 
   int hash( int key ) const;
   void findIndex( int key, bool& found, int& i ) const;
   
   // DATA MEMBERS
   RecordType table[CAPACITY];
   int used;
};

