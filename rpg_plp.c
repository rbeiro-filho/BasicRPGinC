#include<stdio.h>
#include<stdlib.h>

//Character structure
typedef struct Character{
    char name[50];
    char class[20];
    int health;
    int mana;
    int attack;
    int defense;
    int speed;
    int strength;
    int intelligence;
} Character;

// Functions preview
void Menu(void);
void ClearScreen(void);
void PauseScreen(void);
Character CreateCharacter(void);
// ...

// --------------------------------------------------------------

int main(void) {

    return 0;
}

// --------------------------------------------------------------

// Game menu
void Menu(void) {

}
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    getchar();
    getchar();
}
// Returns a structure with character's info
Character CreateCharacter(void) {
    
};