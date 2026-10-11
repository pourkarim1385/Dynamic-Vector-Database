#pragma once
#include "Types.hpp"

struct SearchRequest {
    Vector query;
    std::size_t topK;
};

struct SearchResult {
    RecordId recordId;
    float distance;
};

struct SearchResponse {
    std::vector<SearchResult> results;
};