#pragma once
#include <cstdint>
#include <vector>
#include "Record.hpp"
#include "Types.hpp"

class Collection {
public:

private:
    CollectionId id; 
    std::vector<Record> records;
    std::size_t dimension;
    // pointer function for embedding function
};