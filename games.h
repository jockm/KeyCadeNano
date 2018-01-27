/*
 * games.h
 *
 *  Created on: Jan 25, 2018
 *      Author: jock
 */

#ifndef GAMES_H_

#define GAMES_H_

#include "mbed.h"
#include "GameData.h"

#include <Games/tank_jem.h>

#include "Games/15_Puzzle_Roger_Ivie.h"
#include "Games/15_Puzzle_Roger_Ivie_alt.h"
#include "Games/Addition_Problems_Paul_C._Moews.h"
#include "Games/Airplane.h"
#include "Games/Alien.h"
#include "Games/Animal_Race_Brian_Astle.h"
#include "Games/Ant.h"
#include "Games/Astro_Dodge_Hires_Revival_Studios_2008.h"
#include "Games/Astro_Dodge_Revival_Studios_2008.h"
#include "Games/BMP_Viewer_-_Hello_C8_example_Hap_2005.h"
#include "Games/BMPviewer.h"
#include "Games/Biorhythm_Jef_Winsor.h"
#include "Games/Blinky.h"
#include "Games/Blinky_Hans_Christian_Egeberg_1991.h"
#include "Games/Blinky_Hans_Christian_Egeberg_alt.h"
#include "Games/Blitz_David_Winter.h"
#include "Games/Bowling_Gooitzen_van_der_Wal.h"
#include "Games/Breakout_Brix_hack_David_Winter_1997.h"
#include "Games/Breakout_Carmelo_Cortez_1979.h"
#include "Games/Brick_Brix_hack_1990.h"
#include "Games/Brix_Andreas_Gustafsson_1990.h"
#include "Games/Car.h"
#include "Games/Cave.h"
#include "Games/Chip8_Picture.h"
#include "Games/Chip8_emulator_Logo_Garstyciuks.h"
#include "Games/Clock_Program_Bill_Fisher_1981.h"
#include "Games/Coin_Flipping_Carmelo_Cortez_1978.h"
#include "Games/Connect_4_David_Winter.h"
#include "Games/Craps_Camerlo_Cortez_1978.h"
#include "Games/Deflection_John_Fort.h"
#include "Games/Delay_Timer_Test_Matthew_Mikolay_2010.h"
#include "Games/Division_Test_Sergey_Naydenov_2010.h"
#include "Games/Dragon1.h"
#include "Games/Dragon2.h"
#include "Games/Emutest.h"
#include "Games/Field.h"
#include "Games/Figures.h"
#include "Games/Filter.h"
#include "Games/Fishie_Hap_2005.h"
#include "Games/Framed_MK1_GV_Samways_1980.h"
#include "Games/Framed_MK2_GV_Samways_1980.h"
#include "Games/Guess_David_Winter.h"
#include "Games/Guess_David_Winter_alt.h"
#include "Games/Hex_Mixt.h"
#include "Games/Hi-Lo_Jef_Winsor_1978.h"
#include "Games/Hidden_David_Winter_1996.h"
#include "Games/Hires_Maze_David_Winter_199x.h"
#include "Games/Hires_Particle_Demo_zeroZshadow_2008.h"
#include "Games/Hires_Sierpinski_Sergey_Naydenov_2010.h"
#include "Games/Hires_Stars_Sergey_Naydenov_2010.h"
#include "Games/Hires_Test_Tom_Swan_1979.h"
#include "Games/Hires_Worm_V4_RB-Revival_Studios_2007.h"
#include "Games/IBM_Logo.h"
#include "Games/Joust23.h"
#include "Games/Jumping_X_and_O_Harry_Kleinberg_1977.h"
#include "Games/Kaleid.h"
#include "Games/Kaleidoscope_Joseph_Weisbecker_1978.h"
#include "Games/Keypad_Test_Hap_2006.h"
#include "Games/Landing.h"
#include "Games/Laser.h"
#include "Games/Life_GV_Samways_1980.h"
#include "Games/LineDemo.h"
#include "Games/Lunar_Lander_Udo_Pernisz_1979.h"
#include "Games/Mastermind_FourRow_Robert_Lindley_1978.h"
#include "Games/Matches.h"
#include "Games/Maze1.h"
#include "Games/Maze2.h"
#include "Games/Maze_David_Winter_199x.h"
#include "Games/Merlin_David_Winter.h"
#include "Games/Mines.h"
#include "Games/Minimal_game_Revival_Studios_2007.h"
#include "Games/Missile_David_Winter.h"
#include "Games/Most_Dangerous_Game_Peter_Maruhnic.h"
#include "Games/Nim_Carmelo_Cortez_1978.h"
#include "Games/Paddles.h"
#include "Games/Particle_Demo_zeroZshadow_2008.h"
#include "Games/Piper.h"
#include "Games/Pong_1_player.h"
#include "Games/Pong_2_Pong_hack_David_Winter_1997.h"
#include "Games/Pong_Paul_Vervalin_1990.h"
#include "Games/Pong_alt.h"
#include "Games/Programmable_Spacefighters_Jef_Winsor.h"
#include "Games/Puzzle.h"
#include "Games/Race.h"
#include "Games/Random_Number_Test_Matthew_Mikolay_2010.h"
#include "Games/Reversi_Philip_Baltzer.h"
#include "Games/Robot.h"
#include "Games/Rocket_Joseph_Weisbecker_1978.h"
#include "Games/Rocket_Launch_Jonas_Lindstedt.h"
#include "Games/Rocket_Launcher.h"
#include "Games/Rush_Hour_Hap_2006.h"
#include "Games/Rush_Hour_Hap_2006_alt.h"
#include "Games/Russian_Roulette_Carmelo_Cortez_1978.h"
#include "Games/SCR_TEST.h"
#include "Games/SQRT_Test_Sergey_Naydenov_2010.h"
#include "Games/Sequence_Shoot_Joyce_Weisbecker.h"
#include "Games/Shooting_Stars_Philip_Baltzer_1978.h"
#include "Games/Sierpinski_Sergey_Naydenov_2010.h"
#include "Games/Slide_Joyce_Weisbecker.h"
#include "Games/Soccer.h"
#include "Games/SpaceFig.h"
#include "Games/Space_Flight.h"
#include "Games/Space_Intercept_Joseph_Weisbecker_1978.h"
#include "Games/Space_Invaders_David_Winter.h"
#include "Games/Space_Invaders_David_Winter_alt.h"
#include "Games/Spooky_Spot_Joseph_Weisbecker_1978.h"
#include "Games/Square.h"
#include "Games/Squash_David_Winter.h"
#include "Games/Stars_Sergey_Naydenov_2010.h"
#include "Games/Submarine_Carmelo_Cortez_1978.h"
#include "Games/Sum_Fun_Joyce_Weisbecker.h"
#include "Games/Syzygy_Roy_Trevino_1990.h"
#include "Games/TEST_128.h"
#include "Games/Tank.h"
#include "Games/Tapeworm_JDR_1999.h"
#include "Games/Tetris_Fran_Dachille_1991.h"
#include "Games/Tic-Tac-Toe_David_Winter.h"
#include "Games/Timebomb.h"
#include "Games/Trip8_Demo_2008_Revival_Studios.h"
#include "Games/Trip8_Hires_Demo_2008_Revival_Studios.h"
#include "Games/Tron.h"
#include "Games/UBoat.h"
#include "Games/UFO_Lutz_V_1992.h"
#include "Games/Vers_JMN_1991.h"
#include "Games/Vertical_Brix_Paul_Robson_1996.h"
#include "Games/Wall_David_Winter.h"
#include "Games/Wipe_Off_Joseph_Weisbecker.h"
#include "Games/Worm3.h"
#include "Games/Worm_V4_RB-Revival_Studios_2007.h"
#include "Games/Worms.h"
#include "Games/X-Mirror.h"
#include "Games/ZeroPong_zeroZshadow_2007.h"
#include "Games/Zero_Demo_zeroZshadow_2007.h"



const GameData games[] = {
//		 Type        IPS   FPS	Name                     U  D  L  R  C  1  2   Instructions Data         Size
//       ___________ ____  ___  ______________________ ______________________  ____________ ____________ _______________________
		{GT_CHIP8,    500,  25, "Tank Test",          "\x2\x8\x4\x6\xC\x1\x2", NULL,        game_tank,                                          sizeof(game_tank)},
		{GT_CHIP8,    500,  25, "Airplane",           "\x8\x8\x8\x8\x8\x8\x8", NULL,        Airplane_ch8,                                       sizeof(Airplane_ch8)},
		{GT_CHIP8,    500,  25, "Alien",              "\x2\x8\x3\xC\xA\xA\xA", NULL,        Alien_ch8,                                          sizeof(Alien_ch8)},
		{GT_CHIP8,    500,  25, "Ant",                "\x2\x8\x3\xC\xA\xA\xA", NULL,        Ant_ch8,                                            sizeof(Ant_ch8)},
		{GT_CHIP8,    500,  25, "Astro Dodge Hires",  "\x2\x8\x4\x6\x5\x5\x5", NULL,        Astro_Dodge_Hires_Revival_Studios_2008_ch8,         sizeof(Astro_Dodge_Hires_Revival_Studios_2008_ch8)},
		{GT_CHIP8,    500,  25, "Blinky",             "\x3\x6\x7\x8\xF\xF\xF", NULL,        Blinky_ch8,                                         sizeof(Blinky_ch8)},
		{GT_CHIP8,    500,  25, "Blitz",              "\x5\x5\x5\x5\x5\x5\x5", NULL,        Blitz_David_Winter_ch8,                             sizeof(Blitz_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, "Breakout Brix",      "\x2\x8\x4\x6\xC\x1\x2", NULL,        Breakout_Brix_hack_David_Winter_1997_ch8,           sizeof(Breakout_Brix_hack_David_Winter_1997_ch8)},
		{GT_CHIP8,    500,  25, "Brix",               "\x2\x8\x4\x6\xC\x1\x2", NULL,        Brix_Andreas_Gustafsson_1990_ch8,                   sizeof(Brix_Andreas_Gustafsson_1990_ch8)},
		{GT_CHIP8,    500,  25, "Car",                "\x2\x1\x7\x8\xC\x1\x2", NULL,        Car_ch8,                                            sizeof(Car_ch8)},
		{GT_CHIP8,    500,  25, "Cave",               "\x2\x8\x4\x6\xC\x1\x2", NULL,        Cave_ch8,                                           sizeof(Cave_ch8)},
		{GT_EOL,        0,   0,  NULL,                 NULL,                   NULL,         NULL,                                              0},

		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Dragon2_ch8,                                        sizeof(Dragon2_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Field_ch8,                                          sizeof(Field_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Figures_ch8,                                        sizeof(Figures_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Filter_ch8,                                         sizeof(Filter_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Hidden_David_Winter_1996_ch8,                       sizeof(Hidden_David_Winter_1996_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Hires_Maze_David_Winter_199x_ch8,                   sizeof(Hires_Maze_David_Winter_199x_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Hires_Worm_V4_RB_Revival_Studios_2007_ch8,          sizeof(Hires_Worm_V4_RB_Revival_Studios_2007_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Joust23_ch8,                                        sizeof(Joust23_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Landing_ch8,                                        sizeof(Landing_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Lunar_Lander_Udo_Pernisz_1979_ch8,                  sizeof(Lunar_Lander_Udo_Pernisz_1979_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Maze_David_Winter_199x_ch8,                         sizeof(Maze_David_Winter_199x_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Merlin_David_Winter_ch8,                            sizeof(Merlin_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Mines_ch8,                                          sizeof(Mines_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Missile_David_Winter_ch8,                           sizeof(Missile_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Most_Dangerous_Game_Peter_Maruhnic_ch8,             sizeof(Most_Dangerous_Game_Peter_Maruhnic_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Piper_ch8,                                          sizeof(Piper_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Pong_1_player_ch8,                                  sizeof(Pong_1_player_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Puzzle_ch8,                                         sizeof(Puzzle_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Race_ch8,                                           sizeof(Race_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Reversi_Philip_Baltzer_ch8,                         sizeof(Reversi_Philip_Baltzer_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Rocket_Launch_Jonas_Lindstedt_ch8,                  sizeof(Rocket_Launch_Jonas_Lindstedt_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Shooting_Stars_Philip_Baltzer_1978_ch8,             sizeof(Shooting_Stars_Philip_Baltzer_1978_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        SpaceFig_ch8,                                       sizeof(SpaceFig_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Space_Flight_ch8,                                   sizeof(Space_Flight_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Space_Intercept_Joseph_Weisbecker_1978_ch8,         sizeof(Space_Intercept_Joseph_Weisbecker_1978_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Space_Invaders_David_Winter_ch8,                    sizeof(Space_Invaders_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Space_Invaders_David_Winter_alt_ch8,                sizeof(Space_Invaders_David_Winter_alt_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Squash_David_Winter_ch8,                            sizeof(Squash_David_Winter_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Submarine_Carmelo_Cortez_1978_ch8,                  sizeof(Submarine_Carmelo_Cortez_1978_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Syzygy_Roy_Trevino_1990_ch8,                        sizeof(Syzygy_Roy_Trevino_1990_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Tank_ch8,                                           sizeof(Tank_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Tapeworm_JDR_1999_ch8,                              sizeof(Tapeworm_JDR_1999_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Tetris_Fran_Dachille_1991_ch8,                      sizeof(Tetris_Fran_Dachille_1991_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Tron_ch8,                                           sizeof(Tron_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        UBoat_ch8,                                          sizeof(UBoat_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        UFO_Lutz_V_1992_ch8,                                sizeof(UFO_Lutz_V_1992_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Vertical_Brix_Paul_Robson_1996_ch8,                 sizeof(Vertical_Brix_Paul_Robson_1996_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Wipe_Off_Joseph_Weisbecker_ch8,                     sizeof(Wipe_Off_Joseph_Weisbecker_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Worm3_ch8,                                          sizeof(Worm3_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Worm_V4_RB_Revival_Studios_2007_ch8,                sizeof(Worm_V4_RB_Revival_Studios_2007_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        Worms_ch8,                                          sizeof(Worms_ch8)},
		{GT_CHIP8,    500,  25, "xxxxxxxxxxxxxxxxxx", "\x2\x8\x4\x6\xc\x1\x2", NULL,        X_Mirror_ch8,                                       sizeof(X_Mirror_ch8)},
		{GT_EOL,        0,   0, NULL,                 NULL,                   NULL,         NULL,        0}
};




#endif /* GAMES_H_ */
