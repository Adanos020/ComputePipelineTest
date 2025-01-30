#include <Actions/LoadFromFile.hpp>

#include <ActionOutput.hpp>

#include <memory>
#include <print>

ActionLoadFromFile::ActionLoadFromFile(std::filesystem::path file_path)
    : file_path(file_path)
{
}

std::shared_ptr<ActionOutput> ActionLoadFromFile::execute(const ActionOutput* previous_output) {
    if (previous_output != nullptr) {
        std::println("Loading resource from file...");
        // TODO: use file path from previous_output
    } else {
        std::println("Loading resource from file: '{}'...", this->file_path.string());
        // TODO: use this->file_path
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return std::make_shared<RawBytesOutput>();
}
