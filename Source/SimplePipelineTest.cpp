#include <ActionOutput.hpp>
#include <Actions/DecodeImage.hpp>
#include <Actions/DecompressData.hpp>
#include <ComputePipeline.hpp>

#include <cassert>
#include <print>

int main() {
    auto pipeline = ComputePipeline::load("https://www.my-cosy-domain.com/files/compressed_image.zip");
    if (!pipeline) {
        std::println("Failed to execute the pipeline");
        return 1;
    }
    
    std::optional<std::shared_ptr<ActionOutput>> output = pipeline
        ->add_action<ActionDecompressData>()
        .add_action<ActionDecodeImage>()
        .execute();
    if (!output) {
        std::println("Failed to execute the pipeline");
        return 1;
    }
    const ImageOutput* image_data = (*output)->as_image();
    assert(image_data);

    std::println("Success!");
    
    return 0;
}
