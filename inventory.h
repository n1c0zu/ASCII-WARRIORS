//
// Created by nicol on 22/10/2024.
//

#ifndef INVENTORY_H // Include guard to prevent multiple inclusions
#define INVENTORY_H

// Arrays to hold inventory counts for different rarity levels
// Each array corresponds to a specific rarity type and tracks the quantity of each item.

int inv_n[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Inventory for normal items (10 items)
int inv_r[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Inventory for rare items (20 items)
int inv_sr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Inventory for super-rare items (26 items)
int inv_ssr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Inventory for super-super-rare items (38 items)
int inv_ur[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Inventory for ultra-rare items (16 items)

// Global variable to keep track of the player's money
int money = 9999999;

#endif //INVENTORY_H // End of include guard
