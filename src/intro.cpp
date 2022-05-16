#include <iostream>

#include <windows.h>

#include "main.h"
#include "intro.h"

extern CGame Game;

void CIntro::Show(CTexture Textures)
{
    static float lastTime = GetTickCount() * 0.001f;
    float currentTime = GetTickCount() * 0.001f;
    if(currentTime - lastTime < 5.0f)
    {
        Render(Textures);
    }
    else Game.Step = MENU_SHOW;
    return;
}

void CIntro::Render(CTexture Texture)
{
    Painter.DrawImageOnCenter(Texture.logo_texture, 232, 343);
    return;
}
