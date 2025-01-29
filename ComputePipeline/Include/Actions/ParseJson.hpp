#pragma once

#include <Action.hpp>

/// Compute pipeline action which parses a JSON string stored in the previous action's output.
/// 
/// Expected input: `RawBytesOutput` storing the JSON string.
/// 
/// Output: `JsonOutput`.
class ActionParseJson : public Action
{
public:
    virtual std::optional<ActionOutput> execute(const std::optional<ActionOutput>& previous_output) override;
};
