//
// Created by patle on 27/11/2025.
//

#include "readJson.h"

std::optional<std::string> readJson::parseJson()
{
    try {
        simdjson::dom::parser parser;
        simdjson::dom::element const doc = parser.load(_json_path.string().c_str());
        
        // Safe approach: check each step
        auto data_result = doc["data"].get_string();
        if (data_result.error()) {
            std::cerr << "Error: 'data' field missing or not a string" << std::endl;
            return std::nullopt;
        }
        
        std::string data = std::string(data_result.value());
        return data;
    } catch (const simdjson::simdjson_error& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return std::nullopt;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return std::nullopt;
    }
}
