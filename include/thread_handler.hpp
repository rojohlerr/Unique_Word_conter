#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H
#include <string>
#include <set>
#include <future>
#include "file_reading.hpp"

class ThreadHandler {
public:
    explicit ThreadHandler(const std::string& filename);
    size_t process();

private:
    FileReader fileReader_;
};

#endif // THREAD_HANDLER_H
