add_library(ComputePipeline
    Source/Actions/DecodeImage.cpp
    Source/Actions/DecompressData.cpp
    Source/Actions/LoadFromBundle.cpp
    Source/Actions/LoadFromFile.cpp
    Source/Actions/LoadFromUrl.cpp
    Source/Actions/ParseJson.cpp
    Source/ComputePipeline.cpp
)
target_include_directories(ComputePipeline PUBLIC Include)
