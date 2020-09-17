#ifndef CONFIG__H__
#define CONFIG__H__

#include <lib.h>

const int PLAYER_START_X         = 100;
const int PLAYER_Y               = 550;
const int PLAYER_WIDTH           = 20;
const int PLAYER_HEIGHT          = 50;
const colour PLAYER_START_COLOUR = (colour)0x661111FF;
const int PLAYER_START_SPEED     = 5;
const colour SHOT_COL            = (colour)0x662266FF;
const int SHOT_LENGTH            = 100;
const int SHOT_SPEED             = -20;
const int SHOT_START_Y           = PLAYER_Y - PLAYER_HEIGHT;

#endif