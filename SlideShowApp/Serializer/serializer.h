#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "../PresentationElements/Item/item.h"
#include "../PresentationElements/document.h"

class Serializer
{
public:
    Serializer()=default;

public:
    std::string serializeToJson(const std::shared_ptr<Document>&);
    void deseralizeJson();

private:
    std::string serializeSlide(const std::shared_ptr<Slide>&);
    std::string serializeItem(const std::shared_ptr<Item>);

};

#endif // SERIALIZER_H
