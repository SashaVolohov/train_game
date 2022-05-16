#include "painter.h"

#define STB_IMAGE_IMPLEMENTATION
#include "libs/stb_image.h"

void CPainter::LoadTexture(char *filename, GLuint *target)
{
    int width, height, cnt;
    unsigned char *data = stbi_load(filename, &width, &height, &cnt, 0);

    glGenTextures(1, target);
    glBindTexture(GL_TEXTURE_2D, *target);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);
}

void CPainter::CreateImage(GLuint *image, char* path)
{
    LoadTexture(path, image);
}

void CPainter::DrawImage(int x, int y, int sizeX, int sizeY, GLuint image)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    float background[] = {0,0, sizeX, 0, sizeX, sizeY, 0, sizeY};
    float background_texture[] = {0,0, 1,0, 1,1, 0,1};

    glVertexPointer(2, GL_FLOAT, 0, background);
    glTexCoordPointer(2, GL_FLOAT, 0, background_texture);
    glBindTexture(GL_TEXTURE_2D, image);

    glPushMatrix();
        glTranslatef(x, y, 0);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void CPainter::DrawImageOnCenter(GLuint image, int sizeX, int sizeY)
{
    int newX = resolutionX / 2 - sizeX / 2;
    int newY = resolutionY / 2 - sizeY / 2;

    DrawImage(newX, newY, sizeX, sizeY, image);
}
