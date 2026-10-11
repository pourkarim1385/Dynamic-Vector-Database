cmake_minimum_required(VERSION 3.20)
project(DynamicVectorDB VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library sources
set(DYNAMIC_VECTOR_DB_SOURCES
    src/storage/SQLiteRecordStorage.cpp
    src/index/BruteForceIndex.cpp
    src/VectorDatabase.cpp
)

add_library(dynamic_vector_db ${DYNAMIC_VECTOR_DB_SOURCES})

target_include_directories(dynamic_vector_db PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Testing (optional)
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    # Add test executables when test framework is configured
endif()

