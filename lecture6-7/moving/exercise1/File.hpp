#include <stdlib.h>
#include <stdio.h>
#include <string>

class File {
public:
  File(const std::string& fileName) {
    fopen(fileName.c_str(), "w");
  }

  File(File&& other) noexcept
    : fp( std::move(other.fp) ) {
    other.fp = nullptr;
  }

  File& operator=(File&& other) noexcept {
    if (this != &other) {
      delete fp;
      fp = other.fp;
      other.fp = nullptr;
    }
    return *this;
  }

  ~File() {
    if (fp != nullptr)
      fclose(fp);
  }

  const std::string& fileName() const {
    return fileName_;
  }

private:
  FILE* fp;
  std::string fileName_;
  
};
