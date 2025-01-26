#pragma once

#include <Action.hpp>

#include <string_view>

class ActionParseJson : public Action {
public:
    std::string_view json_str;

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
