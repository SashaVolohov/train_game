#include "painter.h"
#include "texture.h"

void CTexture::LoadAllTextures()
{
    Painter.CreateImage(&logo_texture, "textures/intro/intro.png");
    Painter.CreateImage(&menu_bg_texture, "textures/menu/bg_texture.png");

    Painter.CreateImage(&button_normal_texture, "textures/menu/buttons/normal.png");
    Painter.CreateImage(&button_hover_texture, "textures/menu/buttons/hover.png");
    Painter.CreateImage(&button_active_texture, "textures/menu/buttons/active.png");
}
