#pragma once

#include <Action.hpp>
#include <ActionOutput.hpp>
#include <Actions/DecompressData.hpp>

#include <concepts>
#include <memory>
#include <optional>
#include <queue>
#include <string_view>
#include <type_traits>

class ComputePipeline
{
public:
    static std::optional<ComputePipeline> load(std::string_view resource_uri);

    template <std::derived_from<Action> TyAction, class... TyConstructorArgs>
        requires std::is_constructible_v<TyAction, TyConstructorArgs...>
    ComputePipeline& add_action(TyConstructorArgs... args)
    {
        auto action = std::make_unique<TyAction>(std::forward<TyConstructorArgs>(args)...);
        this->action_queue.push(std::move(action));
        return *this;
    }

    std::optional<std::shared_ptr<ActionOutput>> execute();

private:
    ComputePipeline() = default;

    std::queue<std::unique_ptr<Action>> action_queue;
};
