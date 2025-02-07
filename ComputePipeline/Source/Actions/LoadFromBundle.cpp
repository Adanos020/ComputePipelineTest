#include <Actions/LoadFromBundle.hpp>

#include <ActionOutput.hpp>

#include <memory>
#include <print>

ActionLoadFromBundle::ActionLoadFromBundle(std::filesystem::path bundle_path)
    : bundle_path(bundle_path)
{
}

std::shared_ptr<ActionOutput> ActionLoadFromBundle::execute(const ActionOutput* previous_output)
{
    if (previous_output != nullptr) {
        std::println("Loading resource from bundle...");
        // TODO: use bundle path from previous_output
    } else {
        std::println("Loading resource from bundle: '{}'...", this->bundle_path.string());
        // TODO: use this->bundle_path
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return std::make_shared<RawBytesOutput>();
}
