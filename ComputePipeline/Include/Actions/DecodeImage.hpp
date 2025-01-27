#pragma once

#include <Action.hpp>

/// Compute pipeline action which decodes an image from data stored in the previous action's output.
/// 
/// Expected input: `RawBytesOutput` storing the raw image data.
/// 
/// Output: `ImageOutput`.
class ActionDecodeImage : public Action
{
public:
    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
