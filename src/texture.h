#ifndef TEXTURE_H
#define TEXTURE_H


class CTexture
{
private:
    CPainter Painter;
public:
    GLuint logo_texture;
    GLuint menu_bg_texture;

    GLuint button_normal_texture;
    GLuint button_hover_texture;
    GLuint button_active_texture;

    void LoadAllTextures();
};

#endif
