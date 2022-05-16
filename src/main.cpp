#include "renderer.h"
#include "painter.h"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
   CRenderer Renderer;

   Renderer.init(hInstance, nCmdShow);

   return 0;
}
