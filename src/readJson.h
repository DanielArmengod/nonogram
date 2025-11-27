//
// Created by patle on 27/11/2025.
//

#ifndef NONOGRAM_READJSON_H
#define NONOGRAM_READJSON_H

#include <string>
#include "simdjson.h"
#include <filesystem>
#include <optional>

class readJson
{
public:
    explicit readJson(const std::filesystem::path& json_path)
        : _json_path(json_path)
    {
        // All cool
    }

    std::optional<std::string> parseJson(); // Return std::nullopt if error occurs

private:
    std::filesystem::path _json_path;

};


#endif //NONOGRAM_READJSON_H