// The Art of C++ / Operators
// Copyright (c) 2013-2016 Daniel Frey

#include <tao/op/operators.hpp>

#include <cassert>

struct X
  : tao::op::ordered_field< X >,
    tao::op::modable< X >,
    tao::op::ordered_field< X, int >,
    tao::op::modable< X, int >
{
  int v_;

  explicit X( const int v ) noexcept : v_( v ) {}

  X( const X& x ) noexcept : v_( x.v_ ) {}

  X& operator+=( const X& x ) noexcept { v_ += x.v_; return *this; }
  X& operator-=( const X& x ) { v_ -= x.v_; return *this; }
  X& operator*=( const X& x ) { v_ *= x.v_; return *this; }
  X& operator/=( const X& x ) { v_ /= x.v_; return *this; }
  X& operator%=( const X& x ) { v_ %= x.v_; return *this; }

  X& operator+=( const int v ) { v_ += v; return *this; }
  X& operator-=( const int v ) { v_ -= v; return *this; }
  X& operator*=( const int v ) { v_ *= v; return *this; }
  X& operator/=( const int v ) { v_ /= v; return *this; }
  X& operator%=( const int v ) { v_ %= v; return *this; }
};

bool operator==( const X& lhs, const X& rhs ) { return lhs.v_ == rhs.v_; }
bool operator<( const X& lhs, const X& rhs ) { return lhs.v_ < rhs.v_; }

bool operator==( const X& x, const int v ) { return x.v_ == v; }
bool operator<( const X& x, const int v ) { return x.v_ < v; }
bool operator>( const X& x, const int v ) { return x.v_ > v; }

int main()
{
  X x1( 1 );
  X x2( 2 );
  X x3( 3 );

  assert( x1 == x1 );
  assert( x1 != x2 );

  assert( x1 == 1 );
  assert( 2 == x2 );
  assert( x3 != 1 );
  assert( 2 != x3 );

  assert( x1 < x2 );
  assert( x1 <= x2 );
  assert( x2 <= x2 );
  assert( x3 > x2 );
  assert( x3 >= x2 );
  assert( x2 >= x2 );

  assert( x1 < 2 );
  assert( x1 <= 2 );
  assert( x2 <= 2 );
  assert( x3 > 2 );
  assert( x3 >= 2 );
  assert( x2 >= 2 );

  assert( 1 < x2 );
  assert( 1 <= x2 );
  assert( 2 <= x2 );
  assert( 3 > x2 );
  assert( 3 >= x2 );
  assert( 2 >= x2 );

  assert( x1 + x2 == x3 );
  assert( 1 + x2 == x3 );
  assert( x1 + 2 == x3 );
  assert( x2 + x1 == 3 );

  assert( x3 - x1 == x2 );
  assert( 3 - x1 == x2 );
  assert( x3 - 1 == x2 );
  assert( x1 - x3 == -2 );

  assert( x2 * x2 == 4 );
  assert( x2 * 3 == 6 );
  assert( 4 * x2 == 8 );

  assert( ( x3 + x1 ) / x2 == 2 );
  assert( ( x1 + x3 ) / 2 == x2 );

  assert( x3 % x2 == 1 );
  assert( x3 % 2 == 1 );
}
