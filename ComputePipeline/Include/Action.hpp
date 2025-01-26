#pragma once

#include <ActionOutput.hpp>

#include <memory>
#include <optional>

class Action {
public:
    virtual ~Action() = default;

    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) = 0;
};
