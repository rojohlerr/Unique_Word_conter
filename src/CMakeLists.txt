# Collect all source files
set(SOURCE_FILES
    main.cpp
    word_processing.cpp
    file_reading.cpp
    thread_handler.cpp
    thread_pool.cpp
)

# Define the executable
add_executable(word_counter_app ${SOURCE_FILES})

# Link libraries (pthread for multithreading)
target_link_libraries(word_counter_app pthread)
