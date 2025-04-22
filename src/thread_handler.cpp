#include "thread_handler.hpp"
#include "word_processing.hpp"
#include "thread_pool.hpp"
#include <algorithm>
#include <memory>

size_t ThreadHandler::process() {
    const size_t chunk_size = 1 << 20; // 1MB chunks
    const size_t file_size = fileReader_.getFileSize();
    const char* data = fileReader_.getData();

    ThreadPool pool(std::thread::hardware_concurrency());
    std::vector<std::future<std::set<std::string>>> futures;

    // Split file into chunks and enqueue tasks
    for (size_t i = 0; i < file_size; i += chunk_size) {
        const char* chunk_start = data + i;
        const char* chunk_end = data + std::min(i + chunk_size, file_size);
        bool is_first = (i == 0);
        bool is_last = (i + chunk_size >= file_size);

        futures.emplace_back(
            pool.enqueue(process_chunk, chunk_start, chunk_end, is_first, is_last)
        );
    }

    // Merge results
    std::set<std::string> global_set;
    for (auto& future : futures) {
        auto chunk_words = future.get();
        global_set.insert(chunk_words.begin(), chunk_words.end());
    }

    return global_set.size();
}

ThreadHandler::ThreadHandler(const std::string& filename) : fileReader_(filename) {}