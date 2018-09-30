/*
uintset.h
header for UIntSet
Amir Yousef - COP3330 - FALL11 - HW4
*/

#ifndef UINTSET_H
#define UINTSET_H
using namespace fsu;

class UIntSet
{
public:
    
void        Insert   ( unsigned long n       );   // inserts n into set
void        Remove   ( unsigned long n       );   // removes n from set
void        Clear    (                       );   // makes set empty
bool        Member   ( unsigned long n ) const;   // returns true iff n is in set
bool        Empty    (                 ) const;   // true iff set is empty
size_t      Size     (                 ) const;   // returns number of elements in set
size_t      Range    (                 ) const;   // returns upper bound of range/universe [0,ub)

UIntSet& operator  = ( const UIntSet& s      );   // set = s (assignment operator)
UIntSet& operator += ( const UIntSet& s      );   // set = set union s
UIntSet& operator *= ( const UIntSet& s      );   // set = set intersection s
UIntSet& operator -= ( const UIntSet& s      );   // set = set difference s

size_t       size_;   // the size of the current set
fsu::BitVector bv_;   // bit vector representing set

UIntSet operator + ( const UIntSet& s1, const UIntSet& s2      );        // returns s1 union s2
UIntSet operator * ( const UIntSet& s1, const UIntSet& s2      );        // returns s1 intersection s2 
UIntSet operator - ( const UIntSet& s1, const UIntSet& s2      );        // returns s1 difference s2
std::ostream& operator << ( std::ostream& os, const UIntSet& s );        // output operator

UIntSet( 64                );   // default constructor 
~UIntSet(                  );   // destructor 
UIntSet( const UIntSet& s  );   // copy constructor     

private:
size_t intArraySize_;   // array size   
size_t *intArray_;      // array
};    

#endif

