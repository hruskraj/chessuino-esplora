/**
 * @file main.ino
 * @brief Main file which includes setup and loop.
 */

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include "definitions.h"

///Current state.
enum states STATE;
///Next state.
enum states NEXT_STATE;

/**
 * @brief Setup.
 * 
 * Sets MENU_NEW_GAME as current state.
 * @sa states
 */
void setup(){
  EsploraTFT.begin();
  randomSeed(analogRead(0));
  STATE = NEXT_STATE = MENU_NEW_GAME;
  menu1Init();
}
/**
 * @brief Main loop.
 * 
 * @sa states
 */
void loop(){
  switch(STATE){
    case MENU_NEW_GAME:
      if(buttonPressed(SWITCH_1)){
        NEXT_STATE = MENU_VS_PLAYER;
        menu2Init();
      }
      if(joystickIs(joystickDown)){
        NEXT_STATE = MENU_CONTROLS;
        menu1MoveSelector(NEXT_STATE);
      }
      if(joystickIs(joystickUp)){
        NEXT_STATE = MENU_ABOUT;
        menu1MoveSelector(NEXT_STATE);
      }
      break;
      
    case MENU_CONTROLS:
      if(buttonPressed(SWITCH_1)){
        NEXT_STATE = CONTROLS;
        controlsInit();
      }
      if(joystickIs(joystickDown)){
        NEXT_STATE = MENU_ABOUT;
        menu1MoveSelector(NEXT_STATE);
      }
      if(joystickIs(joystickUp)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1MoveSelector(NEXT_STATE);
      }
      break;
      
    case MENU_ABOUT:
      if(buttonPressed(SWITCH_1)){
        NEXT_STATE = ABOUT;
        aboutInit();
      }
      if(joystickIs(joystickDown)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1MoveSelector(NEXT_STATE);
      }
      if(joystickIs(joystickUp)){
        NEXT_STATE = MENU_CONTROLS;
        menu1MoveSelector(NEXT_STATE);
      }
      break;

    case MENU_VS_PLAYER:
      if(joystickIs(joystickDown)){
        NEXT_STATE = MENU_VS_AI;
        menu2MoveSelector(NEXT_STATE);
      }
      if(buttonPressed(SWITCH_1)){
        NEXT_STATE = GAME;
        gameInit();
      }
      if(joystickIs(joystickUp)){
        NEXT_STATE = MENU_VS_AI;
        menu2MoveSelector(NEXT_STATE);
      }
      if(buttonPressed(SWITCH_4)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1Init();
      }
      break;
      
    case MENU_VS_AI:
      if(joystickIs(joystickDown)){
        NEXT_STATE = MENU_VS_PLAYER;
        menu2MoveSelector(NEXT_STATE);
      }
      if(buttonPressed(SWITCH_1)){
        NEXT_STATE = GAME;
        AIInit();
        gameInit();
      }
      if(joystickIs(joystickUp)){
        NEXT_STATE = MENU_VS_PLAYER;
        menu2MoveSelector(NEXT_STATE);
      }
      if(buttonPressed(SWITCH_4)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1Init();
      }
      break;

    case CONTROLS:
      if(buttonPressed(SWITCH_4)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1Init();
      }
      break;

    case ABOUT:
      if(buttonPressed(SWITCH_4)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1Init();
      }
      break;

    case GAME:
      gameUpdate();
      if(buttonPressed(SWITCH_3)){
        NEXT_STATE = MENU_NEW_GAME;
        AIEnabled = false;
        menu1Init();
      }
      break;
      
    case END:
      if(buttonPressed(SWITCH_4)){
        NEXT_STATE = MENU_NEW_GAME;
        menu1Init();
      }
      break;
  }
  STATE = NEXT_STATE;
}
