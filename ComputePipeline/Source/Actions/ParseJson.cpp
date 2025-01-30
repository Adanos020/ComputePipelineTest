#include <Actions/ParseJson.hpp>

#include <ActionOutput.hpp>

#include <print>

std::shared_ptr<ActionOutput> ActionParseJson::execute(const ActionOutput* previous_output)
{
    std::println("Parsing JSON data...");
    if (previous_output != nullptr) {
        const RawBytesOutput* raw_image_data = previous_output->as<RawBytesOutput>();
        if (raw_image_data) {
            // TODO: implement actual JSON parsing from the raw data here
            return std::make_shared<JsonOutput>();
        } else {
            std::println("Failed to get raw JSON data.");
            return nullptr;
        }
    } else {
        std::println("Raw JSON data to parse was not provided.");
        return nullptr;
    }
}
