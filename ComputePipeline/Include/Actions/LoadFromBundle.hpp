#pragma once

#include <Action.hpp>

#include <filesystem>

/// Compute pipeline action which loads data from an application bundle.
/// 
/// Expected input: `RawBytesOutput` storing the path to the bundle.
/// 
/// Output: `RawBytesOutput` with the contents of the loaded bundle.
class ActionLoadFromBundle : public Action
{
public:
    std::filesystem::path bundle_path;

    ActionLoadFromBundle(std::filesystem::path bundle_path);

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
