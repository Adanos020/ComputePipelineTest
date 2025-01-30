#include <Actions/LoadFromUrl.hpp>

#include <ActionOutput.hpp>

#include <print>

ActionLoadFromUrl::ActionLoadFromUrl(std::string_view url)
    : url(url)
{
}

std::shared_ptr<ActionOutput> ActionLoadFromUrl::execute(const ActionOutput* previous_output) {
    if (previous_output != nullptr) {
        std::println("Loading resource from URL...");
        // TODO: use URL from previous_output
    } else {
        std::println("Loading resource from URL: {}...", this->url);
        // TODO: use this->url
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return std::make_shared<RawBytesOutput>();
}
