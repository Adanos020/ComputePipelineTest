#include <Actions/LoadFromBundle.hpp>

#include <ActionOutput.hpp>

#include <print>

ActionLoadFromBundle::ActionLoadFromBundle(std::filesystem::path bundle_path)
    : bundle_path(bundle_path)
{
}

std::optional<ActionOutput> ActionLoadFromBundle::execute(const std::optional<ActionOutput>& previous_output) {
    if (previous_output) {
        // TODO: use bundle path from previous_output
        std::println("Loaded resource from bundle");
    } else {
        // TODO: use this->bundle_path
        std::println("Loaded resource from bundle: {}", this->bundle_path.string());
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return RawBytesOutput();
}
