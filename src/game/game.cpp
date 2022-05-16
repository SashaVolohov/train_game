#define _WIN32_WINNT 0x0A00

#include <iostream>
#include <windows.h>
#include <shlobj.h>

#define INITGUID
#include <knownfolders.h>

#include "main.h"
#include "game\game.h"

CEngine::CEngine()
{
    wchar_t* documents_path = 0;
    SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &documents_path);

    char game_folder_path[256];
    sprintf(game_folder_path, "%ls\\%ls", documents_path, GAME_FOLDER);

    CreateDirectory(game_folder_path, NULL);
}

void CEngine::Show(CTexture Textures)
{
    Render(Textures);
    return;
}

void CEngine::Render(CTexture Texture)
{
    Painter.DrawImageOnCenter(Texture.logo_texture, 232, 343);
    return;
}
