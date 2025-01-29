#include <ActionOutput.hpp>
#include <ComputePipeline.hpp>
#include <Actions/DecodeImage.hpp>
#include <Actions/DecompressData.hpp>
#include <Actions/LoadFromBundle.hpp>
#include <Actions/LoadFromFile.hpp>
#include <Actions/LoadFromUrl.hpp>
#include <Actions/ParseJson.hpp>

#include <memory>
#include <optional>
#include <print>

std::optional<ComputePipeline> ComputePipeline::load(std::string_view resource_uri)
{
    ComputePipeline pipeline;
    if (resource_uri.starts_with("file://")) {
        auto action = std::make_unique<ActionLoadFromFile>(resource_uri.substr(6));
        pipeline.action_queue.push(std::move(action));
    } else if (resource_uri.starts_with("http://") || resource_uri.starts_with("https://")) {
        auto action = std::make_unique<ActionLoadFromUrl>(resource_uri);
        pipeline.action_queue.push(std::move(action));
    } else if (resource_uri.starts_with("bundle://")) {
        auto action = std::make_unique<ActionLoadFromFile>(resource_uri.substr(8));
        pipeline.action_queue.push(std::move(action));
    } else {
        std::println("Error: Unrecognised URI");
        return std::nullopt;
    }
    return pipeline;
}

std::optional<ActionOutput> ComputePipeline::execute()
{
    std::optional<ActionOutput> last_action_output;
    while (!this->action_queue.empty()) {
        std::unique_ptr<Action>& action = this->action_queue.front();
        
        if (std::optional<ActionOutput> output = action->execute(last_action_output)) {
            last_action_output = std::move(output);
        } else {
            return std::nullopt;
        }
        
        this->action_queue.pop();
    }

    if (last_action_output) {
        return last_action_output;
    } else {
        return std::nullopt;
    }
}
