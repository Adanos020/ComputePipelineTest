#pragma once

#include <Action.hpp>

#include <string_view>

class ActionLoadFromUrl : public Action {
public:
    std::string_view url;

    ActionLoadFromUrl(std::string_view url);

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
