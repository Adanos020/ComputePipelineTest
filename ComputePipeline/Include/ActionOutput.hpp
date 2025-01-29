#pragma once

#include <concepts>

class RawBytesOutput;
class ImageOutput;
class JsonOutput;

/// Abstract class representing an output type of a compute pipeline action.
/// Provides functions that let you access the concrete type of action output.
class ActionOutput
{
public:
    virtual ~ActionOutput() = default;
    
    template <std::derived_from<ActionOutput> TyOutput>
    const TyOutput* as() const
    {
        return dynamic_cast<const TyOutput*>(this);
    }

protected:
    ActionOutput() = default;
};

/// Stores raw data as an array of bytes.
class RawBytesOutput : public ActionOutput
{
public:
    // Raw binary data here
};

/// Stores image data as an array of colours.
struct ImageOutput : public ActionOutput
{
public:
    // Image data here
};

/// Stores a JSON object.
struct JsonOutput : public ActionOutput
{
public:
    // Json object data here
};
