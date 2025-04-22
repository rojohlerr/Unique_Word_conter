#include "word_processing.hpp"
#include <cctype>

std::set<std::string> process_chunk(const char* start, const char* end, bool is_first_chunk, bool is_last_chunk) {
    std::set<std::string> words;
    const char* current = start;

    // Adjust start to avoid partial words (if not first chunk)
    if (!is_first_chunk) {
        while (current < end && *current != ' ') ++current;
        while (current < end && *current == ' ') ++current;
    }

    // Adjust end to avoid partial words (if not last chunk)
    const char* chunk_end = end;
    if (!is_last_chunk) {
        chunk_end = end;
        while (chunk_end > current && *(chunk_end - 1) != ' ') --chunk_end;
    }

    // Extract words between current and chunk_end
    std::string word;
    for (const char* p = current; p < chunk_end; ++p) {
        if (*p == ' ') {
            if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        } else {
            word += *p;
        }
    }
    if (!word.empty()) words.insert(word);

    return words;
}