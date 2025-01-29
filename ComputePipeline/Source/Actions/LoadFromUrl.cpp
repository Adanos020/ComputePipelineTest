#include <Actions/LoadFromUrl.hpp>

#include <ActionOutput.hpp>

#include <print>

ActionLoadFromUrl::ActionLoadFromUrl(std::string_view url)
    : url(url)
{
}

std::optional<ActionOutput> ActionLoadFromUrl::execute(const std::optional<ActionOutput>& previous_output) {
    if (previous_output) {
        // TODO: use URL from previous_output
        std::println("Loaded resource from URL");
    } else {
        // TODO: use this->bundle_path
        std::println("Loaded resource from URL: {}", this->url);
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return RawBytesOutput();
}
