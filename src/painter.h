#ifndef PAINTER_H
#define PAINTER_H

#include <GL/gl.h>

extern int resolutionX, resolutionY;

class CPainter
{
private:
    void LoadTexture(char *filename, GLuint *target);
public:
    void CreateImage(GLuint *image, char* path);
    void DrawImage(int x, int y, int sizeX, int sizeY, GLuint image);
    void DrawImageOnCenter(GLuint image, int sizeX, int sizeY);
};

#endif
