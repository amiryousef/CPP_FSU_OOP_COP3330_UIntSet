/*
   uintset.cpp
   implementation for UIntSet
   Amir Yousef - COP3330 - FALL11 - HW4
*/

#include <cstdlib>
#include <iostream>
#include <uintset.h>

UIntSet operator + ( UIntSet& s1, UIntSet& s2 )   // returns s1 union s2
{        
s1 += s2;
return s1;
}

UIntSet operator * ( UIntSet& s1, UIntSet& s2 )   // returns s1 intersection s2
{
s1 *= s2;
return s1;
}

UIntSet operator - ( UIntSet& s1, UIntSet& s2 )   // returns s1 difference s2
{
s1 -= s2;
return s1;
}

std::ostream& operator << ( std::ostream& os, UIntSet& s )   // output operator
{    
for ( size_t i = 0; i < s.Size(); ++i )
{
os << s.size_( i ) << " ";    
}
return os;
}
    
UIntSet::UIntSet (const UIntSet& s) // copy constructor
{
intArraySize_ = s.intArraySize_;
intArray_ = new unsigned int [ intArraySize_ ];
for ( size_t i = 0; i < intArraySize_; ++i )
intArray_[ i ] = s.intArray_[ i ];
}

UIntSet::~UIntSet( )   //destructor
{
delete [ ] intArray_;
}

UIntSet& UIntSet::operator = ( const UIntSet& s )   // assignment operator        
{
if ( this != &s )
{
if ( intArraySize_ != s.intArraySize_ )
{
delete [ ] intArray_;
intArraySize_ = s.intArraySize_;
intArray_ = new unsigned int [ intArraySize_ ];
}
for ( size_t i = 0; i < intArraySize_; ++i )
intArray_[ i ] = s.intArray_[ i ];
}
return *this;
}

void UIntSet::Insert( unsigned long n )   // inserts n into set
{
intArray_ [ size_++ ] = n;
}

void UIntSet::Remove( unsigned long n )   // removes n from set
{
if( Member( n ) )
{
for( size_t i = 0; i < intArraySize_; i++ )
{
if( intArray_[ i ] == n )
{
for ( size_t j = i; j < ( intArraySize_ - 1); j++ )
intArray_ [ j ] = intArray_ [ j + 1 ];
std::cout << "deleted" << std::endl;
break;
}
}
}
else
std::cout << "not found" << std::endl;
}

void UIntSet::Clear()   // makes set empty
{
intArray_ = new unsigned int [ intArraySize_ ];
}

bool UIntSet::Member( unsigned long n ) const   // returns true iff n is in set
{
for ( size_t i = 0; i < intArraySize_; i++ )
if ( intArray_ [ i ] == n )
return true;
return false;
}

bool UIntSet::Empty() const   // true iff set is empty
{
for ( size_t i = 0; i < intArraySize_; i++ )
if ( intArray_ [ i ] != 0x00 )
return false;
return true;
}

size_t UIntSet::Size() const   // returns number of elements in set
{
return 32 * intArraySize_;
}

size_t UIntSet::Range() const   // returns upper bound of range/universe [0,ub)
{
return intArraySize_;
}

UIntSet& UIntSet::operator =  ( const UIntSet& s )   // set = s (assignment operator)
{
UIntSet newSet( this -> intArraySize_ = s.intArraySize_ );
for ( size_t i = 0; i < intArraySize_; i++ )
newSet.Insert( this -> intArray_[ i ] );
for ( size_t i = 0; i < s.intArraySize_; i++ )
newSet.Insert( s.intArray_[ i ] );
*this = newSet;
return *this;
}

UIntSet& UIntSet::operator += ( const UIntSet &s )   // set = set union s
{
UIntSet newSet( this -> intArraySize_ + s.intArraySize_ );
for ( size_t i = 0; i < intArraySize_; i++ )
newSet.Insert( this -> intArray_[ i ] );
for ( size_t i = 0; i < s.intArraySize_; i++ )
newSet.Insert( s.intArray_[ i ] );
*this = newSet;
return *this;
}

UIntSet& UIntSet::operator *= ( const UIntSet &s )   // set = set intersection s
{
UIntSet newSet( this->intArraySize_ * s.intArraySize_ );
for ( size_t i = 0; i < intArraySize_; i++ )
newSet.Insert( this -> intArray_[ i ] );
for ( size_t i = 0; i < s.intArraySize_; i++ )
newSet.Insert( s.intArray_[ i ] );
*this = newSet;
return *this;
}

UIntSet& UIntSet::operator -= ( const UIntSet &s )   // set = set difference s
{
UIntSet newSet( this -> intArraySize_ - s.intArraySize_ );
for ( size_t i = 0; i < intArraySize_; i++ )
newSet.Insert( this -> intArray_[ i ] );
for ( size_t i = 0; i < s.intArraySize_; i++ )
newSet.Insert( s.intArray_[ i ] );
*this = newSet;
return *this;
}







