#include "file_reading.hpp"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>

FileReader::FileReader(const std::string& filename) {
    fd_ = open(filename.c_str(), O_RDONLY);
    if (fd_ == -1) throw std::runtime_error("Failed to open file");

    struct stat sb;
    if (fstat(fd_, &sb) == -1) {
        close(fd_);
        throw std::runtime_error("Failed to get file size");
    }
    fileSize_ = sb.st_size;

    data_ = static_cast<char*>(mmap(nullptr, fileSize_, PROT_READ, MAP_PRIVATE, fd_, 0));
    if (data_ == MAP_FAILED) {
        close(fd_);
        throw std::runtime_error("Failed to mmap file");
    }
}

FileReader::~FileReader() {
    if (data_) munmap(data_, fileSize_);
    if (fd_ != -1) close(fd_);
}

size_t FileReader::getFileSize() const { return fileSize_; }
const char* FileReader::getData() const { return data_; }