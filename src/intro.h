#ifndef INTRO_H
#define INTRO_H

#include "painter.h"
#include "texture.h"


class CIntro
{
private:

    CPainter Painter;

    void Render(CTexture Texture);
public:
    void Show(CTexture Textures);
};

#endif
