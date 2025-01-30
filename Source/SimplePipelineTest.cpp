#include <ActionOutput.hpp>
#include <Actions/DecodeImage.hpp>
#include <Actions/DecompressData.hpp>
#include <ComputePipeline.hpp>

#include <cassert>
#include <print>

int main() {
    if (auto pipeline_opt = ComputePipeline::load("https://www.my-cosy-domain.com/files/compressed_image.zip")) {
        ComputePipeline& pipeline = pipeline_opt.value();
        std::optional<std::shared_ptr<ActionOutput>> output = pipeline
            .add_action<ActionDecompressData>()
            .add_action<ActionDecodeImage>()
            .execute();
        if (output) {
            const ImageOutput* image_data = (*output)->as_image();
            assert(image_data);
            std::println("Success!");
            return 0;
        } else {
            std::println("Failed to execute the pipeline");
            return 1;
        }
    } else {
        std::println("Failed to create the pipeline");
        return 1;
    }
}
