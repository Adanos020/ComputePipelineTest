#include <Actions/DecodeImage.hpp>

#include <ActionOutput.hpp>

#include <print>

std::optional<std::shared_ptr<ActionOutput>> ActionDecodeImage::execute(const ActionOutput* previous_output)
{
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    const RawBytesOutput* raw_json_data = previous_output->as<RawBytesOutput>();
    if (previous_output == nullptr) {
        return std::nullopt;
    }

    // TODO: implement actual image decoding from the raw data here
    std::println("Decoded the image data");
    return std::make_shared<ImageOutput>();
}
