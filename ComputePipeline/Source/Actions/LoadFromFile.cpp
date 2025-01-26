#include <Actions/LoadFromFile.hpp>

#include <ActionOutput.hpp>

#include <memory>
#include <print>

ActionLoadFromFile::ActionLoadFromFile(std::filesystem::path file_path)
    : file_path(file_path)
{
}

std::optional<std::shared_ptr<ActionOutput>> ActionLoadFromFile::execute(const ActionOutput* previous_output) {
    if (previous_output) {
        // TODO: use file path from previous_output
        std::println("Loaded resource from file");
    } else {
        // TODO: use this->file_path
        std::println("Loaded resource from file: {}", this->file_path.string());
    }
    // TODO: implement actual loading of file data and return it as raw bytes.
    return std::make_unique<RawBytesOutput>();
}
