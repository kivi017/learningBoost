#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main(int argc, char const *argv[]) {
  /* code */
  path p(argv[1]);
  try
  {
    if(exists(p))
    {
      if(is_regular_file(p))
        std::cout<<p<<" size is "<<file_size(p)<<"\n";

      else if(is_directory(p))
      {
        std::cout <<p<< " is a directory containing" << std::endl;

        copy(directory_iterator(p), directory_iterator(), std::ostream_iterator<directory_entry>(std::cout, "\n"));
      }
      else
        std::cout <<p<< " exists, but is neither a file nor a directory " << std::endl;
    }
    else
      std::cout <<p<< " does not exist" << std::endl;

    }

    catch(const filesystem_error& ex)
    {
      std::cout <<ex.what()<< std::endl;
    }
  return 0;
}
