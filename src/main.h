#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <windows.h>

#define INTRO_SHOW 0
#define MENU_SHOW 1
#define GAME_SHOW 2

#define GAME_FOLDER L"TrainGame"
#define SAVES_FOLDER L"saves"
#define COLLECTION_FILE L"collection.dat"
#define SETTINGS_FILE L"settings.dat"

class CGame
{
public:
    int Step;
};

#endif // MAIN_H_INCLUDED
