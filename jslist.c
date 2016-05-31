/* jslist.c
 * This little program just list the joysticks connected to the system.
 * The ouput format is "index:JoystickName".
 * It returns a non-zero value if no joystick was found; otherwise, zero.
 *
 * TODO: translate it to python for a better portability.
 */

#include <stdio.h>
#include "SDL.h"
/* in python it needs pygame */

int main(int argc, char *argv[]) {
    int num_joy, i;

    if(argc > 1) {
        printf("%s%s%s%s",
            "\nThis program lists the joysticks connected to the system.\n",
            "It returns a non-zero value if no joystick was found.\n",
            "The ouput format is:\nindex:JoystickName\n\n",
            "Usage: jslist\n\n");

        return 1;
    }

    SDL_Init(SDL_INIT_JOYSTICK);
    /* I think in python is:
       pygame.joystick.init()
     */

    num_joy = SDL_NumJoysticks();
    /* I think in python is:
       num_joy = pygame.joystick.get_count
     */

    if(num_joy < 1) {
        fputs("No joystick found!\n", stderr);
        SDL_Quit();
        /* I think in python is:
           pygame.joystick.quit()
         */

        return -1;
    }

    for(i = 0; i < num_joy; i++)
        printf("%d:%s\n", i, SDL_JoystickNameForIndex(i));
        /* I think in python is:
           for i in range(0, num_joy):
               pyPrintCmd i:pygame.joystick.Joystick(i).get_name()
         */

    SDL_Quit();
    return 0;
}

    for(i = 0; i < num_joy; i++)
        printf("%d:%s\n", i, SDL_JoystickNameForIndex(i));

    SDL_Quit();
    return 0;
}
