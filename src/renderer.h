#ifndef RENDERER_H
#define RENDERER_H

#include <gl/gl.h>

#include "intro.h"
#include "menu.h"
#include "game\game.h"
#include "texture.h"

class CRenderer
{

private:
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    CIntro Intro;
    CMenu Menu;
    CEngine Engine;

    void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC);
    void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC);
    static LRESULT __stdcall WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void render(CTexture Textures);

public:
    void init(HINSTANCE hInstance, int nCmdShow);
};

#endif
