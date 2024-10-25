//
// Created by nicol on 25/10/2024.
//

#ifndef MENU_H
#define MENU_H



//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset

#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"



int pull_times = 1000;
bool first_startup=true;

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


void put_in_fullscreen() {  //prints a logo animation indicating that you have to put the terminal in fullscreen



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


void ascii_save() {
        printf(BHRED"   _____    __      ________ \n");
        printf("  / ____|  /\\ \\    / /  ____|\n");
        printf(" | (___   /  \\ \\  / /| |__   \n");
        printf("  \\___ \\ / /\\ \\ \\/ / |  __|  \n");
        printf("  ____) / ____ \\  /  | |____ \n");
        printf(" |_____/_/    \\_\\/   |______|\n");
        printf("                             \n");
        printf("                             \n"CRESET);
}


void ascii_load() {
        printf(BHBLU"  _      ____          _____  \n");
        printf(" | |    / __ \\   /\\   |  __ \\ \n");
        printf(" | |   | |  | | /  \\  | |  | |\n");
        printf(" | |   | |  | |/ /\\ \\ | |  | |\n");
        printf(" | |___| |__| / ____ \\| |__| |\n");
        printf(" |______\\____/_/    \\_\\_____/ \n");
        printf("                              \n");
        printf("                              \n"CRESET);
}

void ascii_inventory() {
        printf(BHCYN"  _____ _   ___      ________ _   _ _______ ____  _______     __ \n");
        printf(" |_   _| \\ | \\ \\    / /  ____| \\ | |__   __/ __ \\|  __ \\ \\   / / \n");
        printf("   | | |  \\| |\\ \\  / /| |__  |  \\| |  | | | |  | | |__) \\ \\_/ (_)\n");
        printf("   | | | . ` | \\ \\/ / |  __| | . ` |  | | | |  | |  _  / \\   /   \n");
        printf("  _| |_| |\\  |  \\  /  | |____| |\\  |  | | | |__| | | \\ \\  | |  _ \n");
        printf(" |_____|_| \\_|   \\/   |______|_| \\_|  |_|  \\____/|_|  \\_\\ |_| (_)\n");
        printf("                                                                 \n");
        printf("                                                                 \n"CRESET);
}




#endif //MENU_H
