/*
 * games.h
 *
 *  Created on: Jan 25, GF_NONE, 2018
 *      Author: jock
 */

#ifndef GAMES_H_

#define GAMES_H_

#include "mbed.h"
#include "GameData.h"

#include <Games/tank_jem.h>

#include "Games/About.h"
#include "Games/Airplane.h"
#include "Games/Ant.h"
#include "Games/Astro_Dodge_Revival_Studios_2008.h"
#include "Games/Blinky.h"
#include "Games/Blitz_David_Winter.h"
#include "Games/Brix_Andreas_Gustafsson_1990.h"
#include "Games/Car.h"
#include "Games/Dragon2.h"
#include "Games/Filter.h"
#include "Games/Hidden_David_Winter_1996.h"
#include "Games/Joust23.h"
#include "Games/Landing.h"
#include "Games/Mines.h"
#include "Games/Piper.h"
#include "Games/Pong_1_player.h"
#include "Games/Puzzle.h"
#include "Games/Race.h"
#include "Games/Rocket_Launch_Jonas_Lindstedt.h"
#include "Games/Space_Flight.h"
#include "Games/Space_Invaders_David_Winter.h"
#include "Games/Squash_David_Winter.h"
#include "Games/Submarine_Carmelo_Cortez_1978.h"
#include "Games/Syzygy_Roy_Trevino_1990.h"
#include "Games/Tapeworm_JDR_1999.h"
#include "Games/Tetris_Fran_Dachille_1991.h"
#include "Games/UFO_Lutz_V_1992.h"
#include "Games/Wipe_Off_Joseph_Weisbecker.h"
#include "Games/Worm_V4_RB-Revival_Studios_2007.h"
#include "Games/X-Mirror.h"



const GameData games[] = {
//		 Type        IPS   FPS	Flags    Name                     U  D  L  R  C  1  2   Instructions Start   Data                                   Size
//       ___________ ____  ___  _______  ______________________ ______________________  ____________ ______  ______________________________________ _______________________
		{GT_UBASIC,     0,   0, GF_NONE, "About",              "\x2\x8\x4\x6\xC\x1\x2", NULL,        0x0200, About_bas,                             sizeof(About_bas)},
		{GT_CHIP8,    500,  25, GF_NONE, "Airplane",           "\x8\x8\x8\x8\x8\x8\x8", NULL,        0x0200, Airplane_ch8,                          sizeof(Airplane_ch8)},
//		{GT_CHIP8,   1000,  25, GF_NONE, "Ant",                "\x1\x1\x3\xC\xA\xA\xA", NULL,        0x0200, Ant_ch8,                               sizeof(Ant_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Astro Dodge",        "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Astro_Dodge_Revival_Studios_2008_ch8,  sizeof(Astro_Dodge_Revival_Studios_2008_ch8)},
		{GT_CHIP8,   1000,  25, GF_NONE, "Blinky",             "\x3\x6\x7\x8\xF\xF\xF", NULL,        0x0200, Blinky_ch8,                            sizeof(Blinky_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Blitz",              "\x5\x5\x5\x5\x5\x5\x5", NULL,        0x0200, Blitz_David_Winter_ch8,                sizeof(Blitz_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Brix",               "\x2\x8\x4\x6\xC\x1\x2", NULL,        0x0200, Brix_Andreas_Gustafsson_1990_ch8,      sizeof(Brix_Andreas_Gustafsson_1990_ch8)},
		{GT_CHIP8,   1000,  25, GF_NONE, "Car",                "\x2\x1\x7\x8\xC\x1\x2", NULL,        0x0200, Car_ch8,                               sizeof(Car_ch8)},
		{GT_CHIP8,   1000,  25, GF_NONE, "Dragon",             "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Dragon2_ch8,                           sizeof(Dragon2_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Filter",             "\x2\x8\x4\x6\xc\x1\x2", NULL,        0x0200, Filter_ch8,                            sizeof(Filter_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Hidden",             "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Hidden_David_Winter_1996_ch8,          sizeof(Hidden_David_Winter_1996_ch8)},
		{GT_CHIP8,   1000,  25, GF_NONE, "Joust",              "\x2\x8\x3\xC\xA\xA\xA", NULL,        0x0200, Joust23_ch8,                           sizeof(Joust23_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Landing",            "\x1\x2\x3\x4\x8\x8\x8", NULL,        0x0200, Landing_ch8,                           sizeof(Landing_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Mine",               "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Mines_ch8,                             sizeof(Mines_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Piper",              "\x3\x6\x7\x8\xF\x4\x1", NULL,        0x0200, Piper_ch8,                             sizeof(Piper_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Pong 1 Player",      "\x1\x4\x5\x5\x5\x5\x5", NULL,        0x0200, Pong_1_player_ch8,                     sizeof(Pong_1_player_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Puzzle",             "\x2\x8\x4\x6\xc\x1\x2", NULL,        0x0200, Puzzle_ch8,                            sizeof(Puzzle_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Race",               "\x1\x1\x7\x8\xC\x1\x2", NULL,        0x0200, Race_ch8,                              sizeof(Race_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Rocket Launch",      "\x2\x8\x4\x6\xB\xB\xB", NULL,        0x0200, Rocket_Launch_Jonas_Lindstedt_ch8,     sizeof(Rocket_Launch_Jonas_Lindstedt_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Space Flight",       "\x1\x4\x2\x2\xF\xE\xF", NULL,        0x0200, Space_Flight_ch8,                      sizeof(Space_Flight_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Space Invaders",     "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Space_Invaders_David_Winter_ch8,       sizeof(Space_Invaders_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Squash",             "\x1\x4\x5\x5\x5\x5\x5", NULL,        0x0200, Squash_David_Winter_ch8,               sizeof(Squash_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Submarine",          "\x2\x8\x4\x6\x5\x5\x5", NULL,        0x0200, Submarine_Carmelo_Cortez_1978_ch8,     sizeof(Submarine_Carmelo_Cortez_1978_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Syzygy",             "\x3\x6\x7\x8\xF\xF\xF", NULL,        0x0200, Syzygy_Roy_Trevino_1990_ch8,           sizeof(Syzygy_Roy_Trevino_1990_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Tapeworm",           "\x2\x8\x4\x6\xF\xF\xF", NULL,        0x0200, Tapeworm_JDR_1999_ch8,                 sizeof(Tapeworm_JDR_1999_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Tetris",             "\x2\x8\x5\x6\x4\x4\x7", NULL,        0x0200, Tetris_Fran_Dachille_1991_ch8,         sizeof(Tetris_Fran_Dachille_1991_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "UFO",                "\x5\x8\x4\x6\xc\x1\x2", NULL,        0x0200, UFO_Lutz_V_1992_ch8,                   sizeof(UFO_Lutz_V_1992_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Wipe Off",           "\x2\x8\x4\x6\xc\x1\x2", NULL,        0x0200, Wipe_Off_Joseph_Weisbecker_ch8,        sizeof(Wipe_Off_Joseph_Weisbecker_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "Worm",               "\x2\x8\x4\x6\xc\x1\x2", NULL,        0x0200, Worm_V4_RB_Revival_Studios_2007_ch8,   sizeof(Worm_V4_RB_Revival_Studios_2007_ch8)},
		{GT_CHIP8,    500,  25, GF_NONE, "X-Mirror",           "\x2\x8\x4\x6\xc\x1\x2", NULL,        0x0200, X_Mirror_ch8,                          sizeof(X_Mirror_ch8)},
		{GT_EOL,        0,   0, GF_NONE,  NULL,                NULL,                    NULL,        0,      0}
};



#endif /* GAMES_H_ */
