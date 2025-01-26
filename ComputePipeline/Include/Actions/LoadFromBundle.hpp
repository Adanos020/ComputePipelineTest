#pragma once

#include <Action.hpp>

#include <filesystem>

class ActionLoadFromBundle : public Action {
public:
    std::filesystem::path bundle_path;

    ActionLoadFromBundle(std::filesystem::path bundle_path);

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
