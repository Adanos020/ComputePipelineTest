#include <Actions/DecompressData.hpp>

#include <ActionOutput.hpp>

#include <print>

std::optional<std::shared_ptr<ActionOutput>> ActionDecompressData::execute(const ActionOutput* previous_output)
{
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    const RawBytesOutput* raw_json_data = previous_output->as<RawBytesOutput>();
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    // TODO: implement actual data decompression here
    std::println("Decompressed the data");
    return std::make_shared<RawBytesOutput>();
}
