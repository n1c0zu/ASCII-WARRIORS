//
// Created by nicol on 23/10/2024.
//


#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "core.h"
#include "menu.h"



bool first_startup=true;

int pull_times = 1000;

int secondsToMicroseconds(double seconds) {
        return seconds * 1000000.0;  // 1 second = 1,000,000 microseconds
}



void menu_print()
{

        // Display the menu
        if (first_startup == true)
        {
        printf(BHCYN"\n\n\n\n                                                          WELCOME TO\n\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.5));
                printf(BRED"       d8888  .d8888b.   .d8888b. 8888888 8888888      888       888                          d8b\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"      d88888 d88P  Y88b d88P  Y88b  888     888        888   o   888                          Y8P\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"     d88P888 Y88b.      888    888  888     888        888  d8b  888\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BWHT"    d88P 888  \"Y888b.   888         888     888        888 d888b 888  8888b.  888d888 888d888 888  .d88b.  888d888 .d8888b\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BWHT"   d88P  888     \"Y88b. 888         888     888        888d88888b888     \"88b 888P\"   888P\"   888 d88\"\"88b 888P\"   88K\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"  d88P   888       \"888 888    888  888     888        88888P Y88888 .d888888 888     888     888 888  888 888     \"Y8888b.\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL" d8888888888 Y88b  d88P Y88b  d88P  888     888        8888P   Y8888 888  888 888     888     888 Y88..88P 888          X88 \n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BRED"d88P     888  \"Y8888P\"   \"Y8888P\" 8888888 8888888      888P     Y888 \"Y888888 888     888     888  \"Y88P\"  888      88888P'\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.5));
                printf(BHCYN"\n                                              Copyright (c) 2024. All rights reserved.\n"COLOR_RESET);

                first_startup=false;
        }else
        {
                printf(BHCYN"\n\n\n\n                                                          WELCOME TO\n\n"COLOR_RESET);
                printf(BRED"       d8888  .d8888b.   .d8888b. 8888888 8888888      888       888                          d8b\n"COLOR_RESET);
                printf(BYEL"      d88888 d88P  Y88b d88P  Y88b  888     888        888   o   888                          Y8P\n"COLOR_RESET);
                printf(BYEL"     d88P888 Y88b.      888    888  888     888        888  d8b  888\n"COLOR_RESET);
                printf(BWHT"    d88P 888  \"Y888b.   888         888     888        888 d888b 888  8888b.  888d888 888d888 888  .d88b.  888d888 .d8888b\n"COLOR_RESET);
                printf(BWHT"   d88P  888     \"Y88b. 888         888     888        888d88888b888     \"88b 888P\"   888P\"   888 d88\"\"88b 888P\"   88K\n"COLOR_RESET);
                printf(BYEL"  d88P   888       \"888 888    888  888     888        88888P Y88888 .d888888 888     888     888 888  888 888     \"Y8888b.\n"COLOR_RESET);
                printf(BYEL" d8888888888 Y88b  d88P Y88b  d88P  888     888        8888P   Y8888 888  888 888     888     888 Y88..88P 888          X88 \n"COLOR_RESET);
                printf(BRED"d88P     888  \"Y8888P\"   \"Y8888P\" 8888888 8888888      888P     Y888 \"Y888888 888     888     888  \"Y88P\"  888      88888P'\n"COLOR_RESET);
                printf(BHCYN"\n                                              Copyright (c) 2024. All rights reserved.\n"COLOR_RESET);
        }
        printf("\n\n\nCurrent save file: %s\n", current_save_file);
        printf("Balance: %d \n\n\n", money); // Display total money
        printf("MAKE YOUR SELECTION\n\n");
        printf("1: PULL         5: GIVE MONEY\n");
        printf("2: PULL x10     6: SAVE GAME\n");
        printf("3: PULL x%0-4d   7: LOAD GAME\n",pull_times);
        printf("4: INVENTORY    8: QUIT\n");

}


void put_in_fullscreen() {



        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        printf(" |  __ \\| |  | |__   __|  |_   _| \\ | |                                 \n");
        printf(" | |__) | |  | |  | |       | | |  \\| |                                 \n");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        printf(BHRED"  _____  _    _ _______    _____ _   _                                  \n");
        printf(" |  __ \\| |  | |__   __|  |_   _| \\ | |                                 \n");
        printf(" | |__) | |  | |  | |       | | |  \\| |                                 \n");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(1.5));
        system("cls");
}



