#include <Actions/DecodeImage.hpp>

#include <ActionOutput.hpp>

#include <memory>
#include <print>

std::shared_ptr<ActionOutput> ActionDecodeImage::execute(const ActionOutput* previous_output)
{
    if (previous_output != nullptr) {
        if (const RawBytesOutput* raw_image_data = previous_output->as<RawBytesOutput>()) {
            std::println("Decoding the image data...");
            // TODO: implement actual image decoding from the raw data here
            return std::make_shared<ImageOutput>();
        } else {
            std::println("Failed to decode the image data.");
            return nullptr;
        }
    } else {
        std::println("Raw image data to decode was not provided.");
        return nullptr;
    }
}
