#include <Actions/DecodeImage.hpp>

#include <ActionOutput.hpp>

#include <print>

std::optional<ActionOutput> ActionDecodeImage::execute(const std::optional<ActionOutput>& previous_output)
{
    return previous_output.and_then([](const ActionOutput& output) -> std::optional<ActionOutput> {
        const RawBytesOutput* raw_image_data = output.as<RawBytesOutput>();
        if (raw_image_data) {
            // TODO: implement actual image decoding from the raw data here
            std::println("Decoded the image data");
            return ImageOutput();
        } else {
            return std::nullopt;
        }
    });
}
