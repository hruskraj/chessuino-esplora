/**
 * @file listener.ino
 * @brief Reads input data.
 */
 
/// Array of buttons.
const int btns [4] = {SWITCH_1, SWITCH_2, SWITCH_3, SWITCH_4};
/**
 * @brief Array of button flags. 
 * 
 * Array is used to determine whether button was released since
 * the last push.
 */
bool flags [4] = {true, true, true, true};

/**
 * @brief Treshold for joystick.
 * 
 * Treshold is used to determine position of the joystick.
 * If position of the joystick is less than or equal to treshold 
 * then joystick is in the center.
 */
const int treshold = 100;

int joystickRight = 0, ///< Absolute value of the position of the joystick on x axis
    joystickLeft = 0, ///< Absolute value of the position of the joystick on x axis
    joystickUp = 0, ///< Absolute value of the position of the joystick on y axis
    joystickDown = 0; ///< Absolute value of the position of the joystick on y axis
/**
 * @brief Tests whether given button is pressed.
 * 
 * Action will occur on press not on release. Function returns
 * true only if button was released before the press.
 * @param btn button to be tested
 * @return true if pressed, otherwise false
 * @sa btns, flags
 */
bool buttonPressed(int btn){
  bool pressed = Esplora.readButton(btn) == HIGH ? false : true;
  for(byte i = 0; i < 4; ++i){
    //if it is not given button then skip
    if(btns[i] != btn)
      continue;
    //button is pressed and was released before
    if(pressed && flags[i]){
        //button is not released
        flags[i] = false;
        //button is pressed
        return true; 
      }
      else if(!pressed)
        //button was released
        flags[i] = true;
      //button is not pressed
      return false;
  }
  //given button does not exist
  return false;
}

/**
 * @brief Reads position of joystick.
 * 
 * If position is greater than treshold then according 
 * global variable is set.
 */
void readJoystick(){
  int x = Esplora.readJoystickX();
  int y = Esplora.readJoystickY();
  joystickRight = (x > treshold) ? x : 0;
  joystickLeft = (x > -1 * treshold) ? (-1 * x) : 0;
  joystickUp = (y > treshold) ? x : 0;
  joystickDown = (y > -1 * treshold) ? (-1 * x) : 0;
}
