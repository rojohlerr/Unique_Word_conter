```
This task is to complete a C++ source code for a program that counts the number of distinct unique words in a file whose name is passed as an argument to a program. 

For example
            => given the file content "a horse and a dog" the program 
            => must output "4" (the word 'a' appears twice but only accounts for one distinct unique occurrence).
#Assumptions
The input text is guaranteed to contain only 'a'..'z' and space characters in ASCII encoding.  
You can assume that all unique words fit into memory when using the data structure of your choice.
The program should be able to handle large inputs, much larger than the amount of available RAM (e.g. 32 GiB).  
The solution should be multithreaded, use only C/C++ standard library and/or Linux syscalls.

#project Structure:

project-root/
│
├── CMakeLists.txt              # Top-level CMake configuration file
├── src/                        # Source code
│   ├── main.cpp                # Main application entry point
│   ├── word_processing.cpp     # WordProcessor implementation
│   ├── file_reading.cpp        # FileReader implementation
│   ├── thread_handler.cpp      # ThreadHandler implementation
│   ├── thread_pool.cpp         # ThreadPool class header
│   └── CMakeLists.txt          # CMake configuration file
│
├── include/                    # Header files
│   ├── word_processing.hpp      # WordProcessor class header
│   ├── file_reading.hpp        # FileReader class header
│   ├── thread_handler.hpp      # ThreadHandler class header
│   └── thread_pool.hpp         # ThreadPool class header
│
├── build/                     # Build directory (created by CMake, separate from source code)
│
├── tests/                     # Unit tests
│   ├── CMakeLists.txt         # CMake configuration for tests
│   └── ...                    # no Other test files for now
│
├── docs/                      # Documentation (e.g., README, API docs)
│   └── README.md              # Project description
│   └── ...                    # Other docs files
|
├── execute.sh                 # script file to execute the project
│
└── .git/

Usage : ./execute.sh <file_name>