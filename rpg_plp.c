#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<unistd.h>
#include<time.h>

// CODE STRUCTURES

typedef struct Character{
    char name[20];
    char body1[20];
    char body2[20];
    char body3[20];
    char class[10];
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;    
} Character;

typedef struct Enemy {
    char type[10];
    char body1[20];
    char body2[20];
    char body3[20];
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;
} Enemy;
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
// --------------------------------------------------------------
// ENEMY FUNCTIONS PREVIEW

void Looter(Enemy *E);
void Hunter(Enemy *E);
void Murder(Enemy *E);
// --------------------------------------------------------------
// COMBAT FUNCTIONS PREVIEW

//void BattleLayout(Character* P, Enemy* E);
int Dice(int max);

// --------------------------------------------------------------

int main(void) {
    int control = 0;
    char select = 'Z';
    Character C;
    system("chcp 65001 > nul");

    

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
    }while(control != 1);
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
void Knight(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "U/ | \\P");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Knight");
    P->health = 65;
    P->stamina = 35;
    P->attack = 50;
    P->defense = 80;  
    P->speed = 20;
}
// Gives the assassin attributes
void Assassin(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "i/ | \\i");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Assassin");
    P->health = 35;
    P->stamina = 50;
    P->attack = 80;
    P->defense = 35;
    P->speed = 65;
}
// Gives the archer attributes
void Archer(Character* P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "|/ | \\D");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Archer");
    P->health = 35;
    P->stamina = 50;
    P->attack = 50;
    P->defense = 20;
    P->speed = 80;
}

// --------------------------------------------------------------
// ENEMY FUNCTIONS PREVIEW

// Gives the Looter attributes
void Looter(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, " / | \\i");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Looter");
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, "U/ | \\P");
    strcpy(E->body3, "  / \\  ");
    E->health = 33;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 18;
    E->speed = 72;
}
// Gives the Hunter attributes
void Hunter(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, " / | \\D");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Hunter");
    E->health = 45;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 33;
    E->speed = 60;
}
// Gives the Murder attributes
void Murder(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, "l/ | \\l");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Murder");
    E->health = 60;
    E->stamina = 33;
    E->attack = 60;
    E->defense = 45;
    E->speed = 45;
}

void BattleLayout (Character* P, Enemy* E) {
    printf("                                Combat                                \n");
    printf("|%-8s                         VS                    %8s: %s|\n", P->class, E->type, E->body1);
    printf("|-------------------------------------------------------------------|\n" );
    printf("| Health: %3d                                           Health: %3d |\n", P->health, E->health);
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("|       %s                                    %s               |\n", P->body1, E->body1);
    printf("|       %s                                    %s               |\n", P->body2);
    printf("|       %s                                    %s               |\n", P->body3);
    printf("|                                                                   |\n");
    printf("|-------------------------------------------------------------------|\n" );
}

// Returns a value (min <= value <= max)
int Dice(int max) {
    int random_number;
    // Starts the seed using the clock
    srand(time(NULL));
    return random_number = rand() % (max + 1);
}