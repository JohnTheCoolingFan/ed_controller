#include <Joystick.h>
#include <Keyboard.h>

#define BUTTON_A      2
#define BUTTON_B      3
#define BUTTON_C      4
#define BUTTON_D      5
#define BUTTON_E      6
#define BUTTON_F      7
#define VRx1          A0
#define VRy1          A1
#define VRx2          A2
#define VRy2          A3
#define POTENTIOMETER A4

// Joystick setup
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
        JOYSTICK_TYPE_MULTI_AXIS, 0, 0,
        true, true, false, false, false, false,
        false, true, false, false, false);

void setup() {
    // pinMode
    //   Digital
    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    pinMode(BUTTON_C, INPUT_PULLUP);
    pinMode(BUTTON_D, INPUT_PULLUP);
    pinMode(BUTTON_E, INPUT_PULLUP);
    pinMode(BUTTON_F, INPUT_PULLUP);

    //   Analog
    pinMode(VRx1, INPUT);
    pinMode(VRy1, INPUT);
    pinMode(VRx2, INPUT);
    pinMode(VRy2, INPUT);
    pinMode(POTENTIOMETER, INPUT);

    // Keyboard
    Keyboard.begin();
    // Joystick
    Joystick.begin();
}

void loop() {
    // Buttons A-C
    if (!digitalRead(BUTTON_A)) {
    Keyboard.press('1');
    } else {
    Keyboard.release('1');
    }
    if (!digitalRead(BUTTON_B)) {
    Keyboard.press('2');
    } else {
    Keyboard.release('2');
    }
    if (!digitalRead(BUTTON_C)) {
    Keyboard.press('3');
    } else {
    Keyboard.release('3');
    }
    if (!digitalRead(BUTTON_D)) {
    Keyboard.press('4');
    } else {
    Keyboard.release('4');
    }


    // Joystick
    //   VRx1 (Left / Right arrow)
    if (analogRead(VRx1) >  (512 + 128)) {
    Keyboard.press(KEY_RIGHT_ARROW);
    } else {
    Keyboard.release(KEY_RIGHT_ARROW);
    }
    if (analogRead(VRx1) <  (512 - 128)) {
    Keyboard.press(KEY_LEFT_ARROW);
    } else {
    Keyboard.release(KEY_LEFT_ARROW);
    }
    //   VRy1 (Up / Down arrow)
    if (analogRead(VRy1) >  (512 + 128)) {
    Keyboard.press(KEY_UP_ARROW);
    } else {
    Keyboard.release(KEY_UP_ARROW);
    }
    if (analogRead(VRy1) <  (512 - 128)) {
    Keyboard.press(KEY_DOWN_ARROW);
    } else {
    Keyboard.release(KEY_DOWN_ARROW);
    }

    //   VRx2 (Yaw or Roll)
    Joystick.setXAxis(analogRead(VRx2));
    //   VRy2 (Pitch)
    Joystick.setYAxis(analogRead(VRy2));
    //   Potentiometer (Throttle)
    Joystick.setThrottle(analogRead(POTENTIOMETER));
}
