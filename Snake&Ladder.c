#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node 
{
    int number;        
    int effect;        
    struct Node *next; 
    struct Node *prev; 
};


struct Node *createBoard() {
    struct Node *head = NULL, *tail = NULL, *temp;
    
    for (int i = 1; i <= 100; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->number = i;
        newNode->effect = 0;  
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    return head;
}


void addSnakesAndLadders(struct Node *head) {
    struct Node *temp = head;
    
    int ladders[][2] = {{4, 14}, {9, 31}, {20, 38}, {28, 84}, {40, 59}, {63, 81}, {71, 91}};
    int snakes[][2] = {{17, 7}, {54, 34}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {99, 78}};

    while (temp != NULL) {

        for (int i = 0; i < 7; i++) {
            if (temp->number == ladders[i][0]) {
                temp->effect = ladders[i][1] - ladders[i][0];  // Positive effect
            }
        }


        for (int i = 0; i < 8; i++) {
            if (temp->number == snakes[i][0]) {
                temp->effect = snakes[i][1] - snakes[i][0];  // Negative effect
            }
        }

        temp = temp->next;
    }
}


struct Node *movePlayer(struct Node *head, struct Node *player, int diceRoll) {
    printf("\nPlayer rolled: %d\n", diceRoll);


    for (int i = 0; i < diceRoll && player->next != NULL; i++) {
        player = player->next;
    }

    printf("Landed on tile: %d", player->number);

    if (player->effect != 0) {
        int newTile = player->number + player->effect;
        printf(" -> %s to tile %d\n", (player->effect > 0) ? "Ladder" : "Snake", newTile);

        while (player->number != newTile && player->next != NULL) {
            player = player->next;
        }
    } else {
        printf("\n");
    }

    return player;
}

=
void playGame(struct Node *head) {
    struct Node *player = head;  
    srand(time(0));  

    while (player->number < 100) {
        printf("\nPress Enter to roll the dice...");
        char inp;
        scanf("%c",&inp);  

        int diceRoll = (rand() % 6) + 1; 
        player = movePlayer(head, player, diceRoll);
    }

    printf("\n Player reached tile 100! You win! \n");
}


int main() {
    struct Node *board = createBoard();
    addSnakesAndLadders(board);
    playGame(board);

    return 0;
}
