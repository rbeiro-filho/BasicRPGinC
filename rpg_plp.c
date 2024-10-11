#include<stdio.h>
#include<stdlib.h>

// CODE STRUCTURES

typedef struct Character{
    char name[20];
    int class;             
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;    
} Character;
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

void Menu(void);
void ClearScreen(void);
void PauseScreen(void);
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

void Knight(Character* P) {
    P->class = 1;
    P->level;              
    P->health;
    P->stamina;             
    P->mana;               
    P->attack;              
    P->defense;            
    P->speed;              
    P->strength;           
    P->intelligence;
}
void Rogue(Character* P) {

}
void Archer(Character* P) {

}
void Wizard(Character* P) {

}
// --------------------------------------------------------------


int main(void) {
    int select;

    do{
        switch(select){
            case 1:{

                break;
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 0:{

                break;
            }
            default:{

                break;
            }
        }
        ClearScreen();
        PauseScreen();
    }while(select != 0);

    return 0;
}

// --------------------------------------------------------------

// Game menu
void Menu(void) {

}
// 
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    getchar();
    getchar();
}
// 