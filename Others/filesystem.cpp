#include "../prototypes.h"

#include <filesystem>

namespace fs = std::filesystem;

void std_filesystem()
{
  // absolute
  fs::path p = "C:cl.exe";
  std::cout << "Absolute path for " << p << " is " << fs::absolute( p ) << '\n';

  // canonical
  // weakly_canonical
  // copy
  // copy_file
  // copy_symlink
  // create_directory
  // create_directories
  // create_hard_link
  // create_sym_link
  // create_directory_symlink

  // current_path
  std::cout << "Current path is " << fs::current_path() << '\n';

  // exists
  // equivalent
  // file_size
  // hard_link_count
  // last_write_time
  // permissions
  // read_symlink
  // remove
  // remove_all
  // rename
  // resize_file
  // space
  // status
  // symlink_status
  // temp_directory_path
  // is_block_file
  // is_character_file
  // is_directory
  // is_empty
  // is_fifo
  // is_other
  // is_regular_file
  // is_socket
  // is_symlink
  // status_known

}
