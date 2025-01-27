#pragma once

class RawBytesOutput;
class ImageOutput;
class JsonOutput;

/// Abstract class representing an output type of a compute pipeline action.
/// Provides functions that let you access the concrete type of action output.
class ActionOutput
{
public:
    /// Returns: Pointer to self as `RawBytesOutput` or `nullptr` if the actual type is different.
    virtual const RawBytesOutput* as_raw_bytes() const { return nullptr; }

    /// Returns: Pointer to self as `ImageOutput` or `nullptr` if the actual type is different.
    virtual const ImageOutput* as_image() const { return nullptr; }
    
    /// Returns: Pointer to self as `JsonOutput` or `nullptr` if the actual type is different.
    virtual const JsonOutput* as_json() const { return nullptr; }

protected:
    ActionOutput() = default;
};

/// Stores raw data as an array of bytes.
class RawBytesOutput : public ActionOutput
{
public:
    // Raw binary data here

    virtual const RawBytesOutput* as_raw_bytes() const override { return this; }
};

/// Stores image data as an array of colours.
struct ImageOutput : public ActionOutput
{
public:
    // Image data here

    virtual const ImageOutput* as_image() const override { return this; }
};

/// Stores a JSON object.
struct JsonOutput : public ActionOutput
{
public:
    // Json object data here

    virtual const JsonOutput* as_json() const override { return this; }
};
