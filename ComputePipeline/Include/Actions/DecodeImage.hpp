#pragma once

#include <Action.hpp>

class ActionDecodeImage : public Action {
public:
    ActionDecodeImage() = default;
    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) override;
};
