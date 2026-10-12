#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using CollectionId = std::uint64_t;
using VectorId = std::uint32_t;
using RecordId = std::string;
using Version = std::uint64_t;
using Vector = std::vector<float>;
using Metadata = nlohmann::json;