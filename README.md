# ComputePipelineTest

This is my implementation of a coding exercise I got at a job interview.

The goal was to implement a compute pipeline in C++.

I focused on making the library easy to use and extend with additional actions.


## How to build

The simplest way is to generate build files by executing:
```sh
$ cmake .
```

And then compile:
```sh
$ cmake --build .
```

The build system will produce an executable `ComputePipelineTest` which is an example of how to use the library.

## Usage

This library is centered around the `ComputePipeline` class. It is used to create objects which process data with a sequence of `Action`s, each producing some output data stored in an `ActionOutput` object which is passed to the next `Action` as the input.

All pipelines start with a load action. There are three types of load actions currently provided by the library: `ActionLoadFromBundle`, `ActionLoadFromFile`, and `ActionLoadFromUrl`.

To create a pipeline, you have to call `ComputePipeline::load()`, passing the URI of the resource you want to load as a string argument. The type of the initial load action depends on the prefix of the URI (`bundle://`, `file://`, `http://`, or `https://`). `ComputePipeline::load()` will return an optional `ComputePipeline` object if the URI type is recognised, or `std::nullopt` otherwise.

After successfully creating a pipeline, you can schedule any number of actions by calling the `add_action()` member function on the pipeline object. This member function takes in a template argument which is the type of action, as well as function arguments which are used as constructor arguments for the action.

An action is a child of the abstract class `Action`, several of which are [provided by the library](ComputePipeline/Include/Actions/). You can implement your own action by creating a new subclass of `Action` and implementing the `execute()` pure virtual function. `Action::execute()` takes in as an argument a pointer to the previous action's `ActionOutput`, and returns an optional `ActionOutput` if the action is successful, or `std::nullopt` if it fails.

Lastly, in order to run the pipeline, all you need to do is call the `execute()` member function on the pipeline object. It will return an optional `ActionOutput` which is the output of the final action. If any one of the actions fails, the whole pipeline fails and `execute()` will return a `std::nullopt`.

Example:
```c++
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
```
