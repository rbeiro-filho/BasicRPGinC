#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<unistd.h>
#include<time.h>

// CODE STRUCTURES

// Character 
typedef struct Character {
    char name[20];
<<<<<<< HEAD
    char body1[20];
    char body2[20];
    char body3[20];
    char class[10];
=======
    char class;             
>>>>>>> Changes
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;    
} Character;
<<<<<<< HEAD

typedef struct Enemy{
    char enemy[20];
    char body[20];
    int health;
    int attack;
    int defense;
    int speed;
} Enemy;


=======
// Enemies
typedef struct Enemie {
    char type;
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;
} Enemie;
>>>>>>> Changes
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW



void NameScreen(void);
void Menu(void);
void MainScreen(void);
void KMS(void);
void SMS(void);
void AMS(void);
void ClearScreen(void);
void PauseScreen(void);
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

void Knight(Character* P);
void Assassin(Character* P);
void Archer(Character* P);
<<<<<<< HEAD
// --------------------------------------------------------------
// ENEMY FUNCTIONS PREVIEW

void Slime(Enemy* E);
void Skeleton(Enemy* E);
void Goblin(Enemy* E);
void Demon(Enemy* E);
// --------------------------------------------------------------
// COMBAT FUNCTIONS PREVIEW

void BattleLayout(Character* P, Enemy* E);



=======
void Looter(Enemie *E);
void Hunter(Enemie *E);
void Murder(Enemie *E);
int Dice(int max);
// --------------------------------------------------------------  
>>>>>>> Changes

int main(void) {
    char select = 'Z';
    Character C;
    system("chcp 65001 > nul");
    int control = 0;


    PauseScreen();

    // Choose the player name
    do{
        NameScreen();
        scanf(" %19[^\n]", C.name);
        printf("\n\t\t\t\t\t    Are you sure? [Y/N] ");
        select = toupper(getch()); fflush(stdin);
        ClearScreen();
    }while(select != 'Y');
    // Entering Forgotten Land
    Menu();
    sleep(5);
    // Class selection
    do{
        ClearScreen();
        MainScreen();
        select = getch(); fflush(stdin);
        ClearScreen();
        switch(toupper(select)){
            case 'K':
                Knight(&C);
                KMS();
                printf("\n\t\t\t\t\tYou've choosen Knight\n");
                control = 1;
                break;
            case 'S':
                Assassin(&C);
                SMS();
                printf("\n\t\t\t\t\tYou've choosen Assassin\n");
                control = 1;
                break;
            case 'A':
                Archer(&C);
                AMS();
                printf("\n\t\t\t\t\tYou've choosen Archer\n");
                control = 1;
                break;
            default:
                printf("\n\t\t\t\t\tNot a valid option\n");
                break;
        }
        PauseScreen();
    }while(control == 0);
    




    return 0;
}
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

// Name screen
void NameScreen(void) {
    printf("\t\t\t\t\t\tYou bastard!!!\n");
    printf("\t\t\tYou must identify yourself before you entering this land\n\n\t\t\t\t\t\t");
}
// Game menu
void Menu(void) {
    printf("\t\t\t\t\tWelcome to Forgotten Land\n\n");
    printf("\t\t\t\t   The fate of this land depends on you\n");
    printf("\t\t\t\t    We wish you lucky! You'll need it!\n");
}
// Prints the home screen
void MainScreen(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0         | Archer               0         |\n" );
    printf("|                   U/ | \\P      |                   i/ | \\i      |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Speed                       20 | Speed                       65 | Speed                       80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Knight choosen home screen 
void KMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0 /P      | Assassin             0         | Archer               0         |\n" );
    printf("|                   U/ |         |                   i/ | \\i      |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Speed                       20 | Speed                       65 | Speed                       80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Assassin choosen home screen
void SMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0 /i      | Archer               0         |\n" );
    printf("|                   U/ | \\P      |                   i/ |         |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Speed                       20 | Speed                       65 | Speed                       80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Archer choosen home screen
void AMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0         | Archer               0 /D      |\n" );
    printf("|                   U/ | \\P      |                   i/ | \\i      |                   |/ |         |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Speed                       20 | Speed                       65 | Speed                       80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    printf("Press any key to continue...");
    getchar();
}
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

// Gives the knight attributes
<<<<<<< HEAD
void Knight(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "U/ | \\P");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Knight");
=======
void Knight(Character *P) {
    P->class = 1;
>>>>>>> Changes
    P->health = 65;
    P->stamina = 35;
    P->attack = 50;
    P->defense = 80;
    P->speed = 20;
}
// Gives the assassin attributes
<<<<<<< HEAD
void Assassin(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "i/ | \\i");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Assassin");
=======
void Assassin(Character *P) {
    P->class = 2;
>>>>>>> Changes
    P->health = 35;
    P->stamina = 50;
    P->attack = 80;
    P->defense = 35;
    P->speed = 65;
}
// Gives the archer attributes
<<<<<<< HEAD
void Archer(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "|/ | \\D");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Archer");
=======
void Archer(Character *P) {
    P->class = 3;
>>>>>>> Changes
    P->health = 35;
    P->stamina = 50;
    P->attack = 50;
    P->defense = 20;
    P->speed = 80;
}
<<<<<<< HEAD

// --------------------------------------------------------------
// ENEMY FUNCTIONS PREVIEW

// Gives the slime attributes
void Slime(Enemy* E) {
    strcpy(E->enemy, "Slime");
    strcpy(E->body, "\U0001F4A9");
    E->health = 20;
    E->attack = 10;
    E->defense = 10;
    E->speed = 10;
}

// Gives the skeleton attributes
void Skeleton(Enemy* E) {
    strcpy(E->enemy, "Skeleton");
    E->health = 30;
    E->attack = 15;
    E->defense = 15;
    E->speed = 15;
}

// Gives the goblin attributes
void Goblin(Enemy* E) {
    strcpy(E->enemy, "Goblin");
    E->health = 40;
    E->attack = 20;
    E->defense = 20;
    E->speed = 20;
}

// Gives the demon attributes
void Demon(Enemy* E) {
    strcpy(E->enemy, "Demon");
    E->health = 50;
    E->attack = 25;
    E->defense = 25;
    E->speed = 25;
}

void BattleLayout (Character* P, Enemy* E) {
    

    printf("                                Combat                                \n");
    printf("|%-8s                         VS                    %8s: %s|\n", P->class, E->enemy, E->body);
    printf("|-------------------------------------------------------------------|\n" );
    printf("| Health: %3d                                           Health: %3d |\n", P->health, E->health);
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("|       %s                                    %s               |\n", P->body1, E->body);
    printf("|       %s                                                     |\n", P->body2);
    printf("|       %s                                                     |\n", P->body3);
    printf("|                                                                   |\n");
    printf("|-------------------------------------------------------------------|\n" );
=======
// Gives the Looter attributes
void Looter(Enemie *E) {
    E->type = 'L';
    E->health = 33;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 18;
    E->speed = 72;
}
// Gives the Hunter attributes
void Hunter(Enemie *E) {
    E->type = 'H';
    E->health = 45;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 33;
    E->speed = 60;
}
// Gives the Murder attributes
void Murder(Enemie *E) {
    E->type = 'M';
    E->health = 60;
    E->stamina = 33;
    E->attack = 60;
    E->defense = 45;
    E->speed = 45;
>>>>>>> Changes
}
// Returns a value (min <= value <= max)
int Dice(int max) {
    int random_number;
    // Starts the seed using the clock
    srand(time(NULL));
    return random_number = rand() % (max + 1);
}