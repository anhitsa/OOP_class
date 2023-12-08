#ifndef UICOMPONENT_H
#define UICOMPONENT_H

class UIComponent {
public:
    virtual void createUI() = 0;
    virtual void setBlankScreen() = 0;
};

#endif // UICOMPONENT_H
