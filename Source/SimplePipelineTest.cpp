#include <ActionOutput.hpp>
#include <Actions/DecodeImage.hpp>
#include <Actions/DecompressData.hpp>
#include <ComputePipeline.hpp>

#include <cassert>
#include <memory>
#include <print>

int main() {
    if (auto pipeline_opt = ComputePipeline::load("https://www.my-cosy-domain.com/files/compressed_image.zip")) {
        ComputePipeline& pipeline = pipeline_opt.value();
        std::shared_ptr<ActionOutput> output = pipeline
            .add_action<ActionDecompressData>()
            .add_action<ActionDecodeImage>()
            .execute();
        if (output) {
            if (const ImageOutput* image_data = output->as<ImageOutput>()) {
                assert(image_data != nullptr);
                std::println("Success!");
                return 0;
            } else {
                std::println("Failed to execute the pipeline");
                return 1;
            }
        }
    } else {
        std::println("Failed to create the pipeline");
        return 1;
    }
}
