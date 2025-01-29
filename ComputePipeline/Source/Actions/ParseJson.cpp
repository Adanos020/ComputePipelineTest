#include <Actions/ParseJson.hpp>

#include <ActionOutput.hpp>

#include <print>

std::optional<ActionOutput> ActionParseJson::execute(const std::optional<ActionOutput>& previous_output)
{
    return previous_output.and_then([](const ActionOutput& output) -> std::optional<ActionOutput> {
        const RawBytesOutput* raw_image_data = output.as<RawBytesOutput>();
        if (raw_image_data) {
            // TODO: implement actual JSON parsing from the raw data here
            std::println("Parsed JSON data");
            return JsonOutput();
        } else {
            return std::nullopt;
        }
    });
}
