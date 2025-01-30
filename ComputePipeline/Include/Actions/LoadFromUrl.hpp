#pragma once

#include <Action.hpp>

#include <string_view>

/// Compute pipeline action which loads data from a resource at a given URL.
/// 
/// Expected input: `RawBytesOutput` storing the URL of the bundle.
/// 
/// Output: `RawBytesOutput` with the contents of the loaded resource.
class ActionLoadFromUrl : public Action
{
public:
    std::string_view url;

    ActionLoadFromUrl(std::string_view url);

    virtual std::shared_ptr<ActionOutput> execute(const ActionOutput* previous_output) override;
};
