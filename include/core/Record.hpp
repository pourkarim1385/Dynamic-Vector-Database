#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include "Types.hpp"

class Record {
public: 
private:
    RecordId id;
    Vector embedding;
    std::uint64_t collectionId;
    std::string metadata; 
};