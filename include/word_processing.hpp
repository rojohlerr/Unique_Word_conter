#ifndef WORD_PROCESSOR_H
#define WORD_PROCESSOR_H

#include <set>
#include <string>

std::set<std::string> process_chunk(const char* start, const char* end, bool is_first_chunk, bool is_last_chunk);

#endif // WORD_PROCESSOR_H
