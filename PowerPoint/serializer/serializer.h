#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "../document/document.h"
#include "../document/item.h"

#include <memory>

class Serializer
{
public:
    Serializer();
    void deseralizeJson();

public:
    std::string serializeToJson(const std::shared_ptr<Document>& document) {
        std::string jsonResult = "{ \n  \"slides\": [";

        for (const auto& slide : document->slides) {
            jsonResult += serializeSlide(slide);
            jsonResult += ",";
        }
        if (jsonResult.back() == ',')
            jsonResult.pop_back();

        jsonResult += "  }]\n";
        jsonResult += "}";
        return jsonResult;
    }

private:
    std::string serializeSlide(const std::shared_ptr<Slide>& slide) {
        std::string jsonResult = "{\n    \"targets\": [";

        for (const auto& target : slide->targets) {
            jsonResult += serializeItem(std::dynamic_pointer_cast<Item>(target));
            jsonResult += ",";
        }

        if (jsonResult.back() == ',') {
            jsonResult.pop_back();
        }

        jsonResult += "\n    ]\n";

        return jsonResult;
    }


    std::string serializeItem(const std::shared_ptr<Item> item) {
        return
            "\n"
               "      {\"kind\":\"" + item->getKind() + "\","
                                   "\"top_left\":{\"x\":" + std::to_string(item->getTopLeft().x) + ",\"y\":" + std::to_string(item->getTopLeft().y) + "},"
                                                                                                           "\"bottom_right\":{\"x\":" + std::to_string(item->getBottomRight().x) + ",\"y\":" + std::to_string(item->getBottomRight().y) + "},"
                                                                                                                 "\"height\":" + std::to_string(item->getHeight()) + ","
                                                     "\"width\":" + std::to_string(item->getWidth()) + ","
                                                    "\"id\":" + std::to_string(item->getId()) +
            "}";
    }
};

#endif // SERIALIZER_H
