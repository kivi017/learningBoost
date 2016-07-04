#include<iostream>
#include "boost/filesystem.hpp"

using namespace boost::filesystem;

int main(int argc, char* argv[]) {
  /* code */
  path p(argv[1]);

  if(exists(p))   //Checking whether p exits
  {
    if (is_regular_file(p)) {   //Quering whether p is a regular file
      std::cout<<p<<" size is "<<file_size(p)<<"\n";}

    else if(is_directory(p))    //Checking whether p is a directory
      std::cout<<p<<" is a directory."<<"\n";

    else
      std::cout<<p<<" exists, but is neither a file nor a directory"<<"\n";

  }
  else
    std::cout<<p<<" does not exist."<<"\n";

  return 0;
}
