#include "quantum.h"

#ifdef OLED_ENABLE

// Rotate OLED
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// return OLED_ROTATION_90;
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

// Draw to OLED
bool oled_task_user() {

    // Clear OLED
    oled_clear();


    // Write text to OLED
    oled_write("Winsplit", false);

 return false;
}

#endif

