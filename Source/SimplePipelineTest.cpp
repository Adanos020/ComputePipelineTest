#include <ActionOutput.hpp>
#include <Actions/DecodeImage.hpp>
#include <Actions/DecompressData.hpp>
#include <ComputePipeline.hpp>

#include <cassert>
#include <print>

int main() {
    auto image = ComputePipeline::load("https://www.my-cosy-domain.com/files/compressed_image.zip")
        .and_then([](ComputePipeline&& pipeline) {
            return pipeline
                .add_action<ActionDecompressData>()
                .add_action<ActionDecodeImage>()
                .execute();
        })
        .and_then([](ActionOutput&& output) {
            const ImageOutput* image_data = output.as<ImageOutput>();
            return std::optional(image_data);
        });
    
    if (image.has_value()) {
        assert(image.value() != nullptr);
        std::println("Failed to execute the pipeline");
        return 1;
    } else {
        std::println("Success!");
        return 0;
    }
}
