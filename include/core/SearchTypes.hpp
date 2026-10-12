#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <optional>
#include <functional>
#include "Types.hpp"

// Single matching record result
struct SearchResult {
    RecordId recordId{};
    float distance{0.0f};
    std::optional<std::string> document{std::nullopt};
    std::optional<Metadata> metadata{std::nullopt};
    std::optional<Vector> embedding{std::nullopt};
};

struct SearchRequest {
    // Vector queries (supports single or multi/batch queries)
    std::vector<Vector> queries{};
    std::size_t topK{10};

    // Metadata filter predicate: return true to keep the record
    std::function<bool(const Metadata&)> filter{nullptr};

    // Projection flags (matching Chroma's include parameter)
    bool includeDistances{true};
    bool includeDocuments{true};
    bool includeMetadatas{true};
    bool includeEmbeddings{false};

    SearchRequest() = default;

    // Convenience constructor for single query
    SearchRequest(Vector singleQuery, std::size_t k = 10,
                  std::function<bool(const Metadata&)> metaFilter = nullptr)
        : queries{std::move(singleQuery)}, topK(k), filter(std::move(metaFilter)) {}

    // Constructor for batch queries
    SearchRequest(std::vector<Vector> batchQueries, std::size_t k = 10,
                  std::function<bool(const Metadata&)> metaFilter = nullptr)
        : queries(std::move(batchQueries)), topK(k), filter(std::move(metaFilter)) {}
};

struct SearchResponse {
    // batchResults[i] contains the top-K SearchResults for queries[i]
    std::vector<std::vector<SearchResult>> batchResults{};

    // Convenience helper for single-query results
    const std::vector<SearchResult>& results() const {
        static const std::vector<SearchResult> emptyResults{};
        return batchResults.empty() ? emptyResults : batchResults.front();
    }
};