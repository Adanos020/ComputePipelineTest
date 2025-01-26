#pragma once

#include <cstdint>
#include <vector>

class RawBytesOutput;
class ImageOutput;
class JsonOutput;

class ActionOutput {
public:
    virtual const RawBytesOutput* as_raw_bytes() const { return nullptr; }
    virtual const ImageOutput* as_image() const { return nullptr; }
    virtual const JsonOutput* as_json() const { return nullptr; }
};

class RawBytesOutput : public ActionOutput {
public:
    std::vector<uint8_t> bytes;

    virtual const RawBytesOutput* as_raw_bytes() const override { return this; }
};

struct ImageOutput : public ActionOutput {
public:
    // Image data here

    virtual const ImageOutput* as_image() const override { return this; }
};

struct JsonOutput : public ActionOutput {
public:
    // Json object data here

    virtual const JsonOutput* as_json() const override { return this; }
};
