#pragma once

#include <Action.hpp>

#include <filesystem>

class ActionLoadFromFile : public Action {
public:
    std::filesystem::path file_path;

    ActionLoadFromFile(std::filesystem::path file_path);

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
