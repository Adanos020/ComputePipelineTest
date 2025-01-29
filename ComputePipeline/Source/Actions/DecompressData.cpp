#include <Actions/DecompressData.hpp>

#include <ActionOutput.hpp>

#include <optional>
#include <print>

std::optional<ActionOutput> ActionDecompressData::execute(const std::optional<ActionOutput>& previous_output)
{
    return previous_output.and_then([](const ActionOutput& output) -> std::optional<ActionOutput> {
        const RawBytesOutput* raw_data = output.as<RawBytesOutput>();
        if (raw_data) {
            // TODO: implement actual data decompression here
            std::println("Decompressed the data");
            return { RawBytesOutput() };
        } else {
            return std::nullopt;
        }
    });
}
