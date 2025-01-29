#pragma once

#include <Action.hpp>

/// Compute pipeline action which decompresses the raw data from the previous action's output.
/// 
/// Expected input: `RawBytesOutput`.
/// 
/// Output: decompressed `RawBytesOutput`.
class ActionDecompressData : public Action
{
public:
    virtual std::optional<ActionOutput> execute(const std::optional<ActionOutput>& previous_output) override;
};
