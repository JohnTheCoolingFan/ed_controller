#include <Joystick.h>
#include <Keyboard.h>

#define BUTTON_A      2
#define BUTTON_B      3
#define BUTTON_C      4
#define BUTTON_D      5
#define BUTTON_E      6
#define BUTTON_F      7
#define SW1           8
#define SW2           9
#define VRx1          A0
#define VRy1          A1
#define VRx2          A2
#define VRy2          A3
#define POTENTIOMETER A4

// Joystick setup
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
        JOYSTICK_TYPE_MULTI_AXIS, 12, 0,
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
    pinMode(SW1,      INPUT_PULLUP);
    pinMode(SW2,      INPUT_PULLUP);

    //   Analog
    pinMode(VRx1, INPUT);
    pinMode(VRy1, INPUT);
    pinMode(VRx2, INPUT);
    pinMode(VRy2, INPUT);
    pinMode(POTENTIOMETER, INPUT);

    // Keyboard
    //Keyboard.begin();
    // Joystick
    Joystick.begin();
}

void loop() {
    /* Pressing keyboard buttons instead of joystick buttons
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
     */


    // Using joystick buttons
    // Buttons A-C
    if (!digitalRead(BUTTON_A)) {
        Joystick.pressButton(0);
    } else {
        Joystick.releaseButton(0);
    }
    if (!digitalRead(BUTTON_B)) {
        Joystick.pressButton(1);
    } else {
        Joystick.releaseButton(1);
    }
    if (!digitalRead(BUTTON_C)) {
        Joystick.pressButton(2);
    } else {
        Joystick.releaseButton(2);
    }
    if (!digitalRead(BUTTON_D)) {
        Joystick.pressButton(3);
    } else {
        Joystick.releaseButton(3);
    }


    // Joystick
    //   VRx1
    if (analogRead(VRx1) >  (512 + 128)) {
        Joystick.pressButton(4);
    } else {
        Joystick.releaseButton(4);
    }
    if (analogRead(VRx1) <  (512 - 128)) {
        Joystick.pressButton(5);
    } else {
        Joystick.releaseButton(5);
    }
    //   VRy1
    if (analogRead(VRy1) >  (512 + 128)) {
        Joystick.pressButton(6);
    } else {
        Joystick.releaseButton(6);
    }
    if (analogRead(VRy1) <  (512 - 128)) {
        Joystick.pressButton(7);
    } else {
        Joystick.releaseButton(7);
    }


    // Other Buttons
    //   E and F
    if (!digitalRead(BUTTON_E)) {
        Joystick.pressButton(8);
    } else {
        Joystick.releaseButton(8);
    }
    if (!digitalRead(BUTTON_F)) {
        Joystick.pressButton(9);
    } else {
        Joystick.releaseButton(9);
    }
    // SW1 and SW2
    if (!digitalRead(SW1)) {
        Joystick.pressButton(10);
    } else {
        Joystick.releaseButton(10);
    }
    if (!digitalRead(SW2)) {
        Joystick.pressButton(11);
    } else {
        Joystick.releaseButton(11);
    }

    //   VRx2 (Yaw or Roll)
    Joystick.setXAxis(analogRead(VRx2));
    //   VRy2 (Pitch)
    Joystick.setYAxis(analogRead(VRy2));
    //   Potentiometer (Throttle)
    Joystick.setThrottle(analogRead(POTENTIOMETER));
}
