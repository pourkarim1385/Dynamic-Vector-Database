#pragma once
#include <cstdint>
#include <vector>
#include "Record.hpp"
#include "Types.hpp"

enum class DistanceMetric {
    L2,
    Cosine,
    InnerProduct
};


class Collection {
public:
    Collection() = default;

    Collection(CollectionId id, std::string name, std::size_t dimension, DistanceMetric metric = DistanceMetric::Cosine)
        : id_(id), name_(std::move(name)), dimension_(dimension), metric_(metric) {}

    // Getters
    CollectionId getId() const noexcept { return id_; }
    const std::string& getName() const noexcept { return name_; }
    std::size_t getDimension() const noexcept { return dimension_; }
    DistanceMetric getMetric() const noexcept { return metric_; }

    // Setters
    void setId(CollectionId id) noexcept { id_ = id; }
    void setName(std::string name) { name_ = std::move(name); }
    void setDimension(std::size_t dimension) noexcept { dimension_ = dimension; }
    void setMetric(DistanceMetric metric) noexcept { metric_ = metric; }

private:
    CollectionId id_{0}; 
    std::string name_{};
    std::size_t dimension_{0};
    DistanceMetric metric_{DistanceMetric::Cosine};
    // pointer function for embedding function
};