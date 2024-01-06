#include "serializer.h"

std::string Serializer::serializeToJson(const std::shared_ptr<Document>& document) {
    std::string jsonResult = "{ \n  \"slides\": [";

    for (const auto& slide : document->getSlides()) {
        jsonResult += serializeSlide(slide);
        jsonResult += ",";
    }
    if (jsonResult.back() == ',')
        jsonResult.pop_back();

    jsonResult += "  }]\n";
    jsonResult += "}";
    return jsonResult;
}

std::string Serializer::serializeSlide(const std::shared_ptr<Slide>& slide) {
    std::string jsonResult = "{\n    \"targets\": [";

    for (const auto& target : slide->getItems()) {
        jsonResult += serializeItem(std::dynamic_pointer_cast<Item>(target));
        jsonResult += ",";
    }

    if (jsonResult.back() == ',') {
        jsonResult.pop_back();
    }

    jsonResult += "\n    ]\n";

    return jsonResult;
}

std::string Serializer::serializeItem(const std::shared_ptr<Item> item) {
    return
        "\n"
        "      {\"kind\":\"" + item->getKind() + "\","
                            "\"top_left\":{\"x\":" + std::to_string(item->getGeometry().getTopLeft().getX()) + ",\"y\":" + std::to_string(item->getGeometry().getTopLeft().getY()) + "},"
                                                                                                                                          "\"bottom_right\":{\"x\":" + std::to_string(item->getGeometry().getBottomRight().getX()) + ",\"y\":" + std::to_string(item->getGeometry().getBottomRight().getY()) + "},"
                                                                                                                                                  "\"height\":" + std::to_string(item->getGeometry().getHeight()) + ","
                                                            "\"width\":" + std::to_string(item->getGeometry().getWidth()) + ","
                                                           "\"id\":" + std::to_string(item->getId()) +
        "}";
}
