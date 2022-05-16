#include "menu.h"

#include <iostream>

#include <windows.h>

#include "main.h"
#include "menu.h"

extern CGame Game;

extern int resolutionX;
extern int resolutionY;

extern int mouseX;
extern int mouseY;

extern int clickX;
extern int clickY;

CMenu::CMenu()
{
    AddButton(START_GAME_BUTTON, MAIN_PAGE, "Начать игру");
    AddButton(LOAD_GAME_BUTTON, MAIN_PAGE, "Загрузить");
    AddButton(COLLECTION_GAME_BUTTON, MAIN_PAGE, "Коллекция");
    AddButton(SETTINGS_GAME_BUTTON, MAIN_PAGE, "Настройки");
    AddButton(EXIT_GAME_BUTTON, MAIN_PAGE, "Выход");
}

int CMenu::Show(CTexture Textures)
{
    Render(Textures);

    return local_quit;
}

void CMenu::Render(CTexture Texture)
{
    Painter.DrawImage(0, 0, resolutionX, resolutionY, Texture.menu_bg_texture);

    ShowAllButtons(Texture);

    return;
}

void CMenu::AddButton(int id, int page, char *name)
{
    sprintf(Buttons[id].name, "%s", name);
    Buttons[id].page = page;
}

void CMenu::ShowAllButtons(CTexture Texture)
{
    int Y_end_render = resolutionY - 10;

    for(int i = 255; i >= 0; i--)
    {
        if(Buttons[i].page == current_page)
        {
            if(clickX >= 10 && clickX < 310 && clickY >= Y_end_render - 50 && clickY < Y_end_render)
            {
                Painter.DrawImage(10, Y_end_render - 50, 300, 50, Texture.button_active_texture);
                ButtonClick(i);
            }
            else if(mouseX >= 10 && mouseX < 310 && mouseY >= Y_end_render - 50 && mouseY < Y_end_render)
            {
                Painter.DrawImage(10, Y_end_render - 50, 300, 50, Texture.button_hover_texture);
            }
            else Painter.DrawImage(10, Y_end_render - 50, 300, 50, Texture.button_normal_texture);
            Y_end_render -= 60;
        }
    }
}

void CMenu::ButtonClick(int id)
{

    switch(id)
    {
        case START_GAME_BUTTON:
            Game.Step = GAME_SHOW;
        break;
        case EXIT_GAME_BUTTON:
            local_quit = 1;
        break;
    }

    clickX = -1;
    clickY = -1;
}
