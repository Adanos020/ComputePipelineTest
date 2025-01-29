#pragma once

#include <Action.hpp>
#include <ActionOutput.hpp>
#include <Actions/DecompressData.hpp>

#include <concepts>
#include <memory>
#include <optional>
#include <queue>
#include <string_view>
#include <type_traits>

/// Represents a compute pipeline where you can define a sequence of actions, each action passing its output into
/// the next action's input.
/// 
/// Usage: in order to create a pipeline, use the `ComputePipeline::load` function which will construct a pipeline
/// object and initialise it with a load action. You can specify the next actions by calling the `add_action` member
/// function. Finally, to execute the pipeline, use the `execute` member function which will run all actions
/// sequentially, from first to last.
///
/// Example:
/// ```c++
/// // Create a pipeline and check if the initial load action is valid.
/// if (auto decode_image = ComputePipeline::load("file://images/cat.zip")) {
///     // Add actions to decompress the Zip archive and decode the image stored in it.
///     (*decode_image)
///         .add_action<ActionDecompressData>()
///         .add_action<ActionDecodeImage>();
///
///     // Run the pipeline and receive the output of the final (ActionDecodeImage) action.
///     if (auto output = decode_image->execute()) {
///         // Use the image data from the received output.
///         if (const ImageOutput* image_data = (*output)->as_image()) {
///             do_stuff_with(image_data);
///         }
///     }
/// }
/// ```
class ComputePipeline
{
public:
    /// Creates and initialises a new `ComputePipeline` with a load action set as the first action in the queue.
    /// Depending on the URI prefix ("file://", "http://", "https://", or "bundle://"), the load action will be
    /// `ActionLoadFromFile`, `ActionLoadFromUrl`, or `ActionLoadFromBundle`.
    ///
    /// Returns: Optional `ComputePipeline`. If the given URI has an unrecognised prefix, nullopt is returned.
    static std::optional<ComputePipeline> load(std::string_view resource_uri);

    /// Schedules the next action in the pipeline.
    /// 
    /// Usage: Actions are defined as classes deriving from the abstract class `Action`. Call this function by
    /// specifying a subclass of `Action` as the first template parameter. If the subclass of `Action` contains
    /// any constructors, you can pass its arguments through the arguments of this member function.
    ///
    /// Returns: Reference to self, so you can chain calls to `add_action` and `execute` in a single expression.
    template <std::derived_from<Action> TyAction, class... TyConstructorArgs>
        requires std::is_constructible_v<TyAction, TyConstructorArgs...>
    ComputePipeline& add_action(TyConstructorArgs... args)
    {
        auto action = std::make_unique<TyAction>(std::forward<TyConstructorArgs>(args)...);
        this->action_queue.push(std::move(action));
        return *this;
    }

    /// Runs and consumes all the scheduled actions sequentially, from first to last.
    ///
    /// Returns: Optional output of the last action. If any step in the pipeline fails, nullopt is returned.
    std::optional<ActionOutput> execute();

private:
    ComputePipeline() = default;

    std::queue<std::unique_ptr<Action>> action_queue;
};
