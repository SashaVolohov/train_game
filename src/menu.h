#ifndef MENU_H
#define MENU_H

#include "painter.h"
#include "texture.h"

#define START_GAME_BUTTON 0
#define LOAD_GAME_BUTTON 1
#define COLLECTION_GAME_BUTTON 2
#define SETTINGS_GAME_BUTTON 3
#define EXIT_GAME_BUTTON 4

#define MAIN_PAGE 1

typedef struct {
    int page = 0;
    char name[256];
} SButton;

class CMenu
{
private:
    CPainter Painter;
    SButton Buttons[256];

    int current_page = 1;
    int local_quit = 0;

    void AddButton(int id, int page, char *name);
    void ShowAllButtons(CTexture Texture);
    void ButtonClick(int id);
public:

    CMenu();

    int Show(CTexture Textures);
    void Render(CTexture Texture);
};

#endif
