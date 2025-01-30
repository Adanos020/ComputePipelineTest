#pragma once

#include <Action.hpp>

#include <filesystem>

/// Compute pipeline action which loads data from a file on disk.
/// 
/// Expected input: `RawBytesOutput` storing the file path.
/// 
/// Output: `RawBytesOutput` with the contents of the loaded file.
class ActionLoadFromFile : public Action
{
public:
    std::filesystem::path file_path;

    ActionLoadFromFile(std::filesystem::path file_path);

    virtual std::shared_ptr<ActionOutput> execute(const ActionOutput* previous_output) override;
};
