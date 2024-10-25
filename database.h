//
// Created by nicol on 21/10/2024.
//

#ifndef DATABASE_H // Include guard to prevent multiple inclusions
#define DATABASE_H



// Arrays of characters representing different categories for pulls
char n[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57}; // Numbers represented as ASCII values
char r[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'}; // Consonants
char sr[] = {'a', 'e', 'i', 'o', 'u', 'y', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // Lowercase vowels and uppercase letters from G
char ssr[] = {'A', 'B', 'C', 'D', 'E', 'F', 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126}; // Uppercase letters and special characters
char *ur[] = {":)", "xD", ":P", "##", "&&", "69", "::", "!?", "^^", ":D", "8-", "ww", "jk", "fr", "Ab", "00"}; // Ultra-rare combos

// Array of rarity names for pulls
char *rar[] = {"normal", "rare", "super-rare", "super-super-rare", "ultra-rare"};

// Rarity distribution variables
int n_rar = 594; // Normal rarity count
int r_rar = 300; // Rare rarity count
int sr_rar = 80; // Super-rare rarity count
int ssr_rar = 25; // Super-super-rare rarity count
int ur_rar = 1; // Ultra-rare rarity count



// Definition and initialization of the character stats arrays for different rarity levels
struct CharStats n_Stats[] = {
    {'0', {10, 5, 8, 7}},
    {'1', {9, 6, 7, 6}},
    {'2', {11, 7, 9, 5}},
    {'3', {12, 8, 6, 10}},
    {'4', {8, 5, 7, 9}},
    {'5', {7, 4, 6, 8}},
    {'6', {10, 6, 8, 7}},
    {'7', {11, 5, 9, 6}},
    {'8', {9, 7, 10, 5}},
    {'9', {12, 8, 9, 10}}
};

struct CharStats r_Stats[] = {
    {'b', {6, 4, 7, 10}},
    {'c', {7, 5, 8, 9}},
    {'d', {8, 6, 7, 9}},
    {'f', {9, 5, 6, 10}},
    {'g', {6, 4, 8, 10}},
    {'h', {7, 5, 8, 9}},
    {'j', {8, 5, 7, 9}},
    {'k', {9, 4, 9, 10}},
    {'l', {6, 4, 8, 9}},
    {'m', {7, 6, 7, 8}},
    {'n', {8, 5, 7, 9}},
    {'p', {9, 6, 8, 9}},
    {'q', {7, 5, 9, 10}},
    {'r', {8, 6, 7, 10}},
    {'s', {9, 5, 8, 9}},
    {'t', {10, 4, 7, 10}},
    {'v', {6, 5, 9, 8}},
    {'w', {7, 6, 8, 9}},
    {'x', {8, 7, 9, 10}},
    {'z', {9, 6, 7, 8}}
};

struct CharStats sr_Stats[] = {
    {'a', {5, 3, 10, 8}},
    {'e', {6, 4, 9, 8}},
    {'i', {5, 3, 10, 9}},
    {'o', {7, 4, 8, 9}},
    {'u', {6, 5, 9, 8}},
    {'y', {8, 5, 10, 8}},
    {'G', {10, 7, 6, 8}},
    {'H', {9, 8, 5, 7}},
    {'I', {8, 9, 7, 6}},
    {'J', {7, 8, 6, 9}},
    {'K', {9, 7, 6, 8}},
    {'L', {8, 9, 5, 7}},
    {'M', {10, 8, 7, 6}},
    {'N', {9, 7, 6, 9}},
    {'O', {8, 8, 5, 8}},
    {'P', {7, 9, 6, 9}},
    {'Q', {10, 7, 5, 9}},
    {'R', {9, 8, 6, 8}},
    {'S', {8, 7, 5, 10}},
    {'T', {9, 8, 6, 9}},
    {'U', {8, 9, 5, 10}},
    {'V', {7, 7, 9, 6}},
    {'W', {8, 9, 8, 7}},
    {'X', {9, 7, 9, 6}},
    {'Y', {8, 8, 10, 9}},
    {'Z', {10, 9, 7, 8}}
};

struct CharStats ssr_Stats[] = {
    {'A', {12, 10, 5, 6}},
    {'B', {11, 9, 7, 5}},
    {'C', {10, 9, 6, 7}},
    {'D', {9, 8, 5, 7}},
    {'E', {11, 9, 6, 6}},
    {'F', {10, 8, 7, 7}},
    {'!', {15, 10, 5, 5}},
    {'"', {14, 9, 6, 6}},
    {'#', {13, 8, 7, 7}},
    {'$', {12, 9, 6, 8}},
    {'%', {14, 10, 5, 9}},
    {'&', {15, 9, 7, 8}},
    {'\'', {13, 8, 6, 9}},  // Note: escaping the single quote character
    {'(', {12, 9, 7, 6}},
    {')', {11, 10, 6, 7}},
    {'*',{10,10,10,10}},
    {'+',{10,10,10,10}},
    {',',{10,10,10,10}},
    {'-',{10,10,10,10}},
    {'.',{10,10,10,10}},
    {'/',{10,10,10,10}},
    {':',{10,10,10,10}},
    {';',{10,10,10,10}},
    {'<',{10,10,10,10}},
    {'=',{10,10,10,10}},
    {'>',{10,10,10,10}},
    {'?',{10,10,10,10}},
    {'@',{10,10,10,10}},
    {'[',{10,10,10,10}},
    {'\\',{10,10,10,10}},
    {']',{10,10,10,10}},
    {'^',{10,10,10,10}},
    {'_',{10,10,10,10}},
    {'`',{10,10,10,10}},
    {'{',{10,10,10,10}},
    {'|',{10,10,10,10}},
    {'}',{10,10,10,10}},
    {'~',{10,10,10,10}},
};

struct CharStats ur_Stats[] = {
    {':', {5, 3, 8, 7}},   // Stats for ":)"
    {'x', {6, 4, 9, 6}},   // Stats for "xD"
    {'P', {7, 5, 8, 8}},   // Stats for ":P"
    {'#', {8, 6, 9, 7}},   // Stats for "##"
    {'&', {9, 5, 7, 6}},   // Stats for "&&"
    {'6', {10, 4, 8, 9}},  // Stats for "69"
    {':', {6, 4, 8, 7}},   // Stats for "::"
    {'!', {7, 5, 7, 8}},   // Stats for "!? "
    {'^', {8, 6, 9, 9}},   // Stats for "^^"
    {'D', {9, 5, 8, 7}},   // Stats for ":D"
    {'8', {10, 6, 9, 8}},  // Stats for "8-"
    {'w', {8, 5, 7, 6}},   // Stats for "ww"
    {'j', {9, 4, 8, 7}},   // Stats for "jk"
    {'f', {8, 5, 9, 8}},   // Stats for "fr"
    {'A', {10, 6, 7, 6}},  // Stats for "Ab"
    {'0', {9, 5, 8, 8}}    // Stats for "00"
};

#endif //DATABASE_H // End of include guard
