#include "../prototypes.h"

#include <utility>
#include <tuple>

template<typename Array, std::size_t... I>
auto array_to_tuple_impl( const Array &a, std::index_sequence<I...> )
{
  return std::make_tuple( a[ I ]... );
};

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto array_to_tuple( const std::array<T, N>& a )
{
  return array_to_tuple_impl( a, Indices{} );
}

struct ThrowStructure
{
  int x = 0;

  ThrowStructure() {}
  ThrowStructure( ThrowStructure&& ) { x = 27; }
  ThrowStructure( const ThrowStructure& ) { x = 29; }
};

struct NoThrowStructure
{
  int x = 0;

  NoThrowStructure() {}
  NoThrowStructure( NoThrowStructure&& ) noexcept { x = 31; }
  NoThrowStructure( const NoThrowStructure& ) noexcept { x = 33; }
};

struct DefaultExample
{
  int func() const
  {
    return 7;
  }
};

struct NotDefaultExample
{
  NotDefaultExample( const NotDefaultExample & ) {}

  int func() const
  {
    return 8;
  }
};

void std_utility()
{
  // swap
  std::vector<int> v1{ 1, 2, 3, 4 }, v2{ 5, 6, 7, 8 };

  std::swap( v1, v2 );

  if ( v1[ 0 ] == 5 && v1[ 1 ] == 6 && v1[ 2 ] == 7 && v1[ 3 ] == 8 )
    std::cout << "std::swap passed." << std::endl;
  else
    std::cout << "std::swap failed." << std::endl;

  // pair
  std::pair<int, int> pair1( 27, 29 );
  std::pair<int, int> pair2 = std::make_pair( 31, 34 );

  if( pair1.first == 27 && pair1.second == 29 && pair2.first == 31 && pair2.second == 34 )
    std::cout << "std::pair passed." << std::endl;
  else
    std::cout << "std::pair failed." << std::endl;

  // exchange
  auto original = 27;
  auto replace = std::exchange( original, 29 );
  if( replace == 27 )
    std::cout << "std::exchange #1 passed\n";
  else
    std::cout << "std::exchange #1 failed\n";

  if( original == 29 )
    std::cout << "std::exchange #2 passed\n";
  else
    std::cout << "std::exchange #2 failed\n";

  // TODO: 06/29/2019
  // tuple
  // std::make_tuple(a[I]...);

  // piecewise_construct - applciable mainly to std::pair
  std::pair<std::string, std::vector<int> > pc( std::piecewise_construct
                                              , std::forward_as_tuple( "test" )
                                              , std::forward_as_tuple( 3, 11 ) );

  if( pc.first == "test" )
  {
    std::cout << "std::piecewise_construct #1 passed\n";
  }
  else
  {
    std::cout << "std::piecewise_construct #1 failed\n";
  }

  if( pc.second.size() == 3 && pc.second[0] == 11 && pc.second[1] == 11 && pc.second[2] == 11)
  {
    std::cout << "std::piecewise_construct #2 passed\n";
  }
  else
  {
    std::cout << "std::piecewise_construct #2 failed\n";
  }

  // integer_sequence
  std::array<int, 4> array = { 1,2,3,4 };
  auto tuple_seq = array_to_tuple( array );
  static_assert( std::is_same<decltype(tuple_seq), std::tuple<int, int, int, int>>::value, "" );
  if( std::get<0>( tuple_seq ) == 1 && std::get<1>( tuple_seq ) == 2 &&
      std::get<2>( tuple_seq ) == 3 && std::get<3>( tuple_seq ) == 4 )
  {
    std::cout << "std::integer_sequence passed\n";
  }
  else
  {
    std::cout << "std::integer_sequence failed\n";
  }

  // forward

  // move
  std::string orig_str{ "Original" };
  auto new_str( std::move( orig_str ) );
  if( orig_str.empty() && new_str == "Original" )
  {
    std::cout << "std::move passed\n";
  }
  else
  {
    std::cout << "std::move failed\n";
  }

  // move_if_noexcept
  NoThrowStructure nts;
  ThrowStructure yts;
  NoThrowStructure nts1 = std::move_if_noexcept( nts );
  ThrowStructure yts1 = std::move_if_noexcept( yts );
  if( nts1.x == 31 && yts1.x == 29 )
  {
    std::cout << "std::move_if_noexcept passed\n";
  }
  else
  {
    std::cout << "std::move_if_noexcept failed\n";
  }

  // declval
  decltype(DefaultExample().func()) n1 = 11;
  decltype(std::declval<NotDefaultExample>().func()) n2 = 12;

  if( n2 == 12 )
    std::cout << "std::declval passed\n";
  else
    std::cout << "std::declval failed\n";
}
