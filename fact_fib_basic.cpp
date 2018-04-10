#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

//////////////////////
// Factorial algorithm
// ///////////////////

// Recursion
int fact_recursive(int num)
{
  if(num == 0 || num == 1)
    return 1;

  return num*fact_recursive(num-1);
}

// Iterative
int fact_iterative(int num)
{
  unsigned ret = 1;

  for( int i = 1; i <= num; ++i )
    ret *= i;

  return ret;
}

// Template
template<int N>
struct fact_template
{
  static const int val = N * fact_template<N-1>::val;
};

template<>
struct fact_template<0>
{
  static const int val = 0;
};

template<>
struct fact_template<1>
{
  static const int val = 1;
};


//////////////////////
// Fibonacci algorithm
//////////////////////

// Recursion
int fib_recursive(int num)
{
  if( num == 0 || num == 1 )
    return num;

   return fib_recursive(num-1) + fib_recursive(num-2);
}

// Iterative 
int fib_iterative(int num)
{
  if( num == 0 || num == 1 )
    return num;

  auto val_prev1 = 1;
  auto val_prev2 = 1;
  auto result = 1;

  for(auto i = 3; i <= num; ++i )
  {
    result = val_prev1 + val_prev2;
    val_prev2 = val_prev1;
    val_prev1 = result;
  }

  return result;
}

// Template
template<int I>
struct fib_template
{
  static const int val = fib_template<I-1>::val + fib_template<I-2>::val;
};

template<>
struct fib_template<0>
{
  static const int val = 0;
};

template<>
struct fib_template<1>
{
  static const int val = 1;
};

///////
// Main
///////
int main()
{
  int result = 0;
  std::vector<int> fact_results, fib_results;

  fact_results.push_back( fact_recursive(7) );
  fact_results.push_back( fact_iterative(7) );
  auto tmp1 = fact_template<7>::val;
  fact_results.push_back( tmp1 );
  std::cout << tmp1 << '\n';

  fib_results.push_back( fib_recursive(12) );
  fib_results.push_back( fib_iterative(12) );
  auto tmp2 = fib_template<12>::val;
  fib_results.push_back( tmp2 );
  std::cout << tmp2 << '\n';

  auto fact_iter = std::find_if_not( fact_results.begin()
		                   , fact_results.end()
				   , [](int num)
		                     { return num == 5040; } );

  auto fib_iter = std::find_if_not( fib_results.begin()
		                  , fib_results.end()
           			  , [](int num)
		                    { return num == 144; } );

  if( fact_iter == fact_results.end() )
    std::cout << "Factorial success\n";
  else
    std::cout << "Factorial failure\n";

  if( fib_iter == fib_results.end() )
    std::cout << "Fbonacci success\n";
  else
    std::cout << "Fibonacci failure\n";

  return 0;
}
