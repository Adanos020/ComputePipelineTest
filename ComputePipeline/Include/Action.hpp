#pragma once

#include <ActionOutput.hpp>

#include <memory>
#include <optional>

/// Abstract class providing an interface for a compute pipeline action.
class Action
{
public:
    virtual ~Action() = default;

    /// Runs the action, taking the `previous_output` of the preceding action in the pipeline.
    /// If `previous_output` is `nullptr`, it will be ignored.
    /// 
    /// Returns an `ActionOutput` if the `Action` has succeeded, otherwise it returns `std::nullopt`.
    virtual std::optional<std::shared_ptr<ActionOutput>> execute(const ActionOutput* previous_output) = 0;
};
