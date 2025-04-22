#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader {
public:
    FileReader(const std::string& filename);
    ~FileReader();

    size_t getFileSize() const;
    const char* getData() const;

private:
    int fd_ = -1;
    size_t fileSize_ = 0;
    char* data_ = nullptr;
};

#endif // FILE_READER_H
