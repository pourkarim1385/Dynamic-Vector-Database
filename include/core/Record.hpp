#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <optional>
#include "Types.hpp"

class Record {
public:
    Record() = default;

    Record(RecordId id, CollectionId collectionId, Vector embedding,
           std::optional<std::string> document = std::nullopt,
           Metadata metadata = Metadata::object(),
           Version version = 1,
           bool isDeleted = false)
        : id_(std::move(id)),
          collectionId_(collectionId),
          embedding_(std::move(embedding)),
          document_(std::move(document)),
          metadata_(std::move(metadata)),
          version_(version),
          isDeleted_(isDeleted) {}

    Record(RecordId id, CollectionId collectionId, Vector embedding,
           const nlohmann::json& documentJson,
           Metadata metadata = Metadata::object(),
           Version version = 1,
           bool isDeleted = false)
        : id_(std::move(id)),
          collectionId_(collectionId),
          embedding_(std::move(embedding)),
          document_(documentJson.dump()),
          metadata_(std::move(metadata)),
          version_(version),
          isDeleted_(isDeleted) {}

    // Getters
    const RecordId& getId() const noexcept { return id_; }
    CollectionId getCollectionId() const noexcept { return collectionId_; }
    const Vector& getEmbedding() const noexcept { return embedding_; }
    Vector& getEmbedding() noexcept { return embedding_; }
    const std::optional<std::string>& getDocument() const noexcept { return document_; }
    const Metadata& getMetadata() const noexcept { return metadata_; }
    Metadata& getMetadata() noexcept { return metadata_; }
    Version getVersion() const noexcept { return version_; }
    bool isDeleted() const noexcept { return isDeleted_; }

    std::optional<nlohmann::json> getDocumentAsJson() const {
        if (!document_.has_value()) {
            return std::nullopt;
        }
        try {
            return nlohmann::json::parse(*document_);
        } catch (...) {
            return std::nullopt;
        }
    }

    // Setters
    void setId(RecordId id) { id_ = std::move(id); }
    void setCollectionId(CollectionId collectionId) noexcept { collectionId_ = collectionId; }
    void setEmbedding(Vector embedding) { embedding_ = std::move(embedding); }
    void setDocument(std::optional<std::string> document) { document_ = std::move(document); }
    void setDocumentJson(const nlohmann::json& documentJson) { document_ = documentJson.dump(); }
    void setMetadata(Metadata metadata) { metadata_ = std::move(metadata); }
    void setVersion(Version version) noexcept { version_ = version; }
    void setIsDeleted(bool isDeleted) noexcept { isDeleted_ = isDeleted; }
    void markDeleted() noexcept { isDeleted_ = true; }

private:
    RecordId id_{};
    CollectionId collectionId_{0};
    Vector embedding_{};
    std::optional<std::string> document_{std::nullopt};
    Metadata metadata_{Metadata::object()};
    Version version_{1};
    bool isDeleted_{false};
};