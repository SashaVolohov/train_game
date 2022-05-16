#ifndef GAME_H
#define GAME_H

#include "painter.h"
#include "texture.h"


class CEngine
{
private:

    CPainter Painter;

    void Render(CTexture Texture);
public:

    CEngine();

    void Show(CTexture Textures);
};

#endif
