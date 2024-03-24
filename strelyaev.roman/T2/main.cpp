#include <iostream>
#include <list>
#include <limits>
#include <iterator>
#include "dataStruct.hpp"

using namespace strelyaev;
int main()
{
  std::list< DataStruct > data;
  using input_it = std::istream_iterator< DataStruct >;
  using output_it = std::ostream_iterator< DataStruct >;
  while (!std::cin.eof())
  {
    std::copy(input_it{std::cin}, input_it{}, std::back_inserter(data));
    if (!std::cin)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
  data.sort();
  std::copy(data.cbegin(), data.cend(), output_it{std::cout, "\n"});
}
