//
// Created by nicol on 28/10/2024.
//

#ifndef PARTY_H
#define PARTY_H

void partysel()
{
    char ch_sel;
    char str_sel[3]; // Allocate space for str_sel
    int rarity, valid;

    for(int i = 0; i < 4; i++)
    {
        do {
            printf("%d - 4 party member\n\n",i+1);

            valid = 0; // Reset valid flag for each attempt

            //Prompt for rarity
            while (true)
            {

                puts("Insert rarity (1-5):");
                scanf("%d", &rarity);
                if(rarity>=1 && rarity<=5)
                {
                    break;
                }
                system("cls");

                printf("%d - 4 party member\n\n",i+1);
                puts("Insert valid");
            }


            if (rarity == 5)
            {
                puts("Insert string from selected rarity:");
                scanf("%2s", str_sel); // Limit input to avoid overflow

                // Check if str_sel matches any element in the ur array
                for (int j = 0; j < size[rarity - 1]; j++)
                {
                    if (strcmp(str_sel, ur[j]) == 0) // Use strcmp to compare strings
                    {
                        strncpy(party[i].name, str_sel, sizeof(party[i].name) - 1);
                        party[i].name[sizeof(party[i].name) - 1] = '\0'; // Null-terminate
                        party[i].rarity = rarity;  // Save the rarity
                        party[i].position = j;     // Save the position (j index)
                        valid = 1; // Mark as valid selection
                        break;
                    }
                }
                if (!valid)
                {
                    system("cls");
                    printf("Invalid selection for %d - 4 party member. Please try again.\n\n",i+1);
                }
            }
            else
            {
                puts("Insert character from selected rarity:");
                scanf(" %c", &ch_sel); // Add a space before %c to consume newline

                // Check if ch_sel matches any element in the corresponding rarity array
                for (int j = 0; j < size[rarity - 1]; j++)
                {
                    if ((rarity == 1 && ch_sel == n[j]) ||
                        (rarity == 2 && ch_sel == r[j]) ||
                        (rarity == 3 && ch_sel == sr[j]) ||
                        (rarity == 4 && ch_sel == ssr[j]))
                    {
                        party[i].name[0] = ch_sel;
                        party[i].name[1] = '\0'; // Null-terminate single character
                        party[i].rarity = rarity; // Save the rarity
                        party[i].position = j;    // Save the position (j index)
                        valid = 1; // Mark as valid selection
                        break;
                    }
                }
                if (!valid)
                {
                    system("cls");
                    printf("Invalid selection for %d - 4 party member. Please try again.\n\n",i+1);
                }
            }
        } while (!valid); // Repeat until a valid input is found
    system("cls");
    }

    // Print out the party members, their rarities, and their positions
    for (int i = 0; i < 4; i++)
    {
        printf("Character: %s, Rarity: %d, Position: %d\n", party[i].name, party[i].rarity, party[i].position);
    }
}

void print_party()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Character: %s, Rarity: %d, Position: %d\n", party[i].name, party[i].rarity, party[i].position);
    }

}

void menu_party()
{
    char select;
    puts("1 for creating a party");
    puts("2 for displaying current party");

    scanf(" %c", &select);
    system("cls");

    switch(select)
    {
        case '1':

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
