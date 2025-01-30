#include <Actions/DecompressData.hpp>

#include <ActionOutput.hpp>

#include <print>

std::shared_ptr<ActionOutput> ActionDecompressData::execute(const ActionOutput* previous_output)
{
    std::println("Decompressing the data...");
    if (previous_output != nullptr) {
        if (const RawBytesOutput* raw_data = previous_output->as<RawBytesOutput>()) {
            // TODO: implement actual data decompression here
            return std::make_shared<RawBytesOutput>();
        } else {
            std::println("Failed to decompress the data.");
            return nullptr;
        }
    } else {
        std::println("Raw data to decompress was not provided.");
        return nullptr;
    }
}
