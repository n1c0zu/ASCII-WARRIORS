//
// Created by nicol on 28/10/2024.
//

#ifndef PARTY_H
#define PARTY_H

void print_rarity(int rar)
{
    if(rar==5)
    {
        for(int i=0;i<size[4];i++)
        {
            if(inv_ur[i]>0)
            {
                printf("[");
                printf(BHRED"%s"CRESET, ur[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_ur[i],ur_Stats[i].stats.hp,ur_Stats[i].stats.atk,ur_Stats[i].stats.res,ur_Stats[i].stats.dex,ur_Stats[i].stats.spd);
            }else if (inv_ur[i]==0){printf("[  ] x0  --- --- --- --- ---     \n");}
        }
    }else if(rar==4)
    {
        for(int i=0;i<size[3];i++)
        {
            if(inv_ssr[i]>0)
            {
                printf("[");
                printf(BHYEL"%c"CRESET, ssr[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_ssr[i],ssr_Stats[i].stats.hp,ssr_Stats[i].stats.atk,ssr_Stats[i].stats.res,ssr_Stats[i].stats.dex,ssr_Stats[i].stats.spd);
            }else if (inv_ssr[i]==0){printf("[ ] x0  --- --- --- --- ---     \n");}
        }
    }else if(rar==3)
    {
        for(int i=0;i<size[2];i++)
        {
            if(inv_sr[i]>0)
            {
                printf("[");
                printf(BHMAG"%c"CRESET, sr[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_sr[i],sr_Stats[i].stats.hp,sr_Stats[i].stats.atk,sr_Stats[i].stats.res,sr_Stats[i].stats.dex,sr_Stats[i].stats.spd);
            }else if (inv_sr[i]==0){printf("[ ] x0  --- --- --- --- ---     \n");}
        }
    }else if(rar==2)
    {
        for(int i=0;i<size[1];i++)
        {
            if(inv_r[i]>0)
            {
                printf("[");
                printf(BHCYN"%c"CRESET, r[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_r[i],r_Stats[i].stats.hp,r_Stats[i].stats.atk,r_Stats[i].stats.res,r_Stats[i].stats.dex,r_Stats[i].stats.spd);
            }else if (inv_r[i]==0){printf("[ ] x0  --- --- --- --- ---     \n");}
        }
    }else if(rar==1)
    {
        for(int i=0;i<size[0];i++)
        {
            if(inv_n[i]>0)
            {
                printf("[");
                printf(BHGRN"%c"CRESET, n[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_n[i],n_Stats[i].stats.hp,n_Stats[i].stats.atk,n_Stats[i].stats.res,n_Stats[i].stats.dex,n_Stats[i].stats.spd);
            }else if (inv_n[i]==0){printf("[ ] x0  --- --- --- --- ---     \n");}
        }
    }
    {

    }
}


void print_party()
{
    printf(BYEL"   _____                          _       _____           _         \n");
    printf("  / ____|                        | |     |  __ \\         | |        \n");
    printf(" | |    _   _ _ __ _ __ ___ _ __ | |_    | |__) |_ _ _ __| |_ _   _ \n");
    printf(" | |   | | | | '__| '__/ _ \\ '_ \\| __|   |  ___/ _` | '__| __| | | |\n");
    printf(" | |___| |_| | |  | | |  __/ | | | |_    | |  | (_| | |  | |_| |_| |\n");
    printf("  \\_____\\__,_|_|  |_|  \\___|_| |_|\\__|   |_|   \\__,_|_|   \\__|\\__, |\n");
    printf("                                                               __/ |  \n");
    printf("                                                              |___/   \n"CRESET);


    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity ==1)
        {
            printf("   [");
            printf(BHGRN"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==2)
        {
            printf("   [");
            printf(BHCYN"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==3)
        {
            printf("   [");
            printf(BHMAG"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==4)
        {
            printf("   [");
            printf(BHYEL"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity == 5)
        {
            printf("   [");
            printf(BHRED"%s"CRESET, party[i].name);
            printf("]        ");
        }else
        {
            printf("   [");
            printf(BHBLU" "CRESET);
            printf("]         ");
        }
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("HP:   %3d      ",n_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==2)
            printf("HP:   %3d      ",r_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==3)
            printf("HP:   %3d      ",sr_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==4)
            printf("HP:   %3d      ",ssr_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==5)
            printf("HP:   %3d      ",ur_Stats[party[i].position].stats.hp);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("ATK:  %3d      ",n_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==2)
            printf("ATK:  %3d      ",r_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==3)
            printf("ATK:  %3d      ",sr_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==4)
            printf("ATK:  %3d      ",ssr_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==5)
            printf("ATK:  %3d      ",ur_Stats[party[i].position].stats.atk);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("RES:  %3d      ",n_Stats[party[i].position].stats.res);
        else if(party[i].rarity==2)
            printf("RES:  %3d      ",r_Stats[party[i].position].stats.res);
        else if(party[i].rarity==3)
            printf("RES:  %3d      ",sr_Stats[party[i].position].stats.res);
        else if(party[i].rarity==4)
            printf("RES:  %3d      ",ssr_Stats[party[i].position].stats.res);
        else if(party[i].rarity==5)
            printf("RES:  %3d      ",ur_Stats[party[i].position].stats.res);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("DEX:  %3d      ",n_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==2)
            printf("DEX:  %3d      ",r_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==3)
            printf("DEX:  %3d      ",sr_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==4)
            printf("DEX:  %3d      ",ssr_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==5)
            printf("DEX:  %3d      ",ur_Stats[party[i].position].stats.dex);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("SPD:  %3d      ",n_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==2)
            printf("SPD:  %3d      ",r_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==3)
            printf("SPD:  %3d      ",sr_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==4)
            printf("SPD:  %3d      ",ssr_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==5)
            printf("SPD:  %3d      ",ur_Stats[party[i].position].stats.spd);
    }
    puts("\n");
}


void partysel()
{
    char ch_sel;
    char str_sel[3]; // Allocate space for str_sel
    int rarity, valid;

    for(int i = 0; i < 4; i++)
    {
        do {
            printf("PARTY MEMBER #%d / 4 \n\n", i + 1);

            valid = 0; // Reset valid flag for each attempt

            // Prompt for rarity
            while (true)
            {
                puts("Insert rarity (1-5, 0 to go back to title screen):");
                scanf("%d", &rarity);
                if (rarity >= 1 && rarity <= 5)
                {
                    break;
                }
                else if (rarity == 0)
                {
                    goto back;
                }
                system("cls");

                printf("PARTY MEMBER %d / 4\n\n", i + 1);
                puts("Invalid rarity");
            }
            print_rarity(rarity);

            if (rarity == 5)
            {
                puts("Insert string from selected rarity:");

                scanf("%2s", str_sel); // Limit input to avoid overflow

                // Check if str_sel matches any element in the ur array
                for (int j = 0; j < size[rarity - 1]; j++)
                {
                    if (strcmp(str_sel, ur[j]) == 0 && inv_ur[j] > 0) // Use strcmp to compare strings
                    {
                        // Check if str_sel is already used in party
                        int alreadyUsed = 0;
                        for (int k = 0; k < i; k++) // Check previous party members
                        {
                            if (strcmp(party[k].name, str_sel) == 0)
                            {
                                alreadyUsed = 1;
                                break;
                            }
                        }

                        if (alreadyUsed)
                        {
                            system("cls");
                            printf("This character is already in the party. Please try again.\n\n");
                        }
                        else
                        {
                            strncpy(party[i].name, str_sel, sizeof(party[i].name) - 1);
                            party[i].name[sizeof(party[i].name) - 1] = '\0'; // Null-terminate
                            party[i].rarity = rarity;  // Save the rarity
                            party[i].position = j;     // Save the position (j index)
                            valid = 1; // Mark as valid selection
                        }
                        break; // Exit the for-loop after checking
                    }
                }
                if (!valid)
                {
                    system("cls");
                    printf("Invalid selection. Please try again.\n\n");
                }
            }
            else
            {
                puts("Insert character from selected rarity:");
                scanf(" %c", &ch_sel); // Add a space before %c to consume newline

                // Check if ch_sel matches any element in the corresponding rarity array
                for (int j = 0; j < size[rarity - 1]; j++)
                {
                    if ((rarity == 1 && ch_sel == n[j] && inv_n[j] > 0) ||
                        (rarity == 2 && ch_sel == r[j] && inv_r[j] > 0) ||
                        (rarity == 3 && ch_sel == sr[j] && inv_sr[j] > 0) ||
                        (rarity == 4 && ch_sel == ssr[j] && inv_ssr[j] > 0))
                    {
                        // Check if ch_sel is already used in party
                        int alreadyUsed = 0;
                        for (int k = 0; k < i; k++) // Check previous party members
                        {
                            if (party[k].name[0] == ch_sel) // Assuming name[0] stores the character
                            {
                                alreadyUsed = 1;
                                break;
                            }
                        }

                        if (alreadyUsed)
                        {
                            system("cls");
                            printf("This character is already in the party. Please try again.\n\n");
                        }
                        else
                        {
                            party[i].name[0] = ch_sel;
                            party[i].name[1] = '\0'; // Null-terminate single character
                            party[i].rarity = rarity; // Save the rarity
                            party[i].position = j;    // Save the position (j index)
                            valid = 1; // Mark as valid selection
                        }
                        break; // Exit the for-loop after checking
                    }
                }
                if (!valid)
                {
                    system("cls");
                    printf("Invalid selection. Please try again.\n\n");
                }
            }
        } while (!valid); // Repeat until a valid input is found
        system("cls");
    }

    // Print out the party members, their rarities, and their positions
    print_party();
back:
}



void menu_party()
{
    char select;
    printf(BHYEL"  _____           _              _____                _   _             \n");
    printf(" |  __ \\         | |            / ____|              | | (_)            \n");
    printf(" | |__) |_ _ _ __| |_ _   _    | |     _ __ ___  __ _| |_ _  ___  _ __  \n");
    printf(" |  ___/ _` | '__| __| | | |   | |    | '__/ _ \\/ _` | __| |/ _ \\| '_ \\ \n");
    printf(" | |  | (_| | |  | |_| |_| |   | |____| | |  __/ (_| | |_| | (_) | | | |\n");
    printf(" |_|   \\__,_|_|   \\__|\\__, |    \\_____|_|  \\___|\\__,_|\\__|_|\\___/|_| |_|\n");
    printf("                       __/ |                                          \n");
    printf("                      |___/                                           \n\n\n"COLOR_RESET);
    puts("1: CREATE PARTY");
    puts("2: DISPLAY ACTIVE PARTY");

    scanf(" %c", &select);
    system("cls");

    switch(select)
    {
        case '1':
            for(int i=0;i<4;i++){
                party[i].name[0] = 'N';
                party[i].name[1] = 'a';
                party[i].name[2] = 'N';
                party[i].rarity = 0;
                party[i].position = 0;
            }
            partysel();
        break;
        case '2':
            print_party();
        break;
        default:
            puts("Invalid selection");
    }
}

#endif //PARTY_H
