#ifndef CONFIG__H__
#define CONFIG__H__

#include <lib.h>

// Player Configs
const colour PLAYER_START_COLOUR = (colour)0x661111FF;
const float PLAYER_START_X       = 100.;
const float PLAYER_Y             = 550.;
const float PLAYER_WIDTH         = 20.;
const float PLAYER_HEIGHT        = 50.;
const float PLAYER_START_SPEED   = 200.;

// Shot Configs
const colour SHOT_COL    = (colour)0x662266FF;
const float SHOT_LENGTH  = 100.;
const float SHOT_SPEED   = -1000.;
const float SHOT_START_Y = PLAYER_Y - PLAYER_HEIGHT;

#endif
