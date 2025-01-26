#include <Actions/ParseJson.hpp>

#include <ActionOutput.hpp>

#include <memory>
#include <print>

std::optional<std::shared_ptr<ActionOutput>> ActionParseJson::execute(const ActionOutput* previous_output)
{
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    const RawBytesOutput* raw_json_data = previous_output->as_raw_bytes();
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    // TODO: implement actual JSON parsing from the raw data here
    std::println("Parsed JSON data");
    return std::make_shared<JsonOutput>();
}
