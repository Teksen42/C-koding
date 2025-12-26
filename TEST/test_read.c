#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Opretter struct
struct event{
    char title[100], catagory[100], alcohol[100], location[100];
    int price, time;
};
typedef struct event event;

//prototyper
void get_events(event all_events[]);
void read_all_events(FILE *f, event all_events[], int length);
int count_events(event all_events[]);
int sort_time(const void *p1, const void *p2);
void print_all_events(event all_events[], int length);
void print_event(event e);
void do_task(char option, event all_events[], int length);
void scan_input(char *option);
void sort_events(event all_events[], int length);
void search_events(event all_events[], int length);
int sort_price_low_to_high(const void *p1, const void *p2);
int sort_price_high_to_low(const void *p1, const void *p2);
void sort_events_by_price(event all_events[], int length);


int main(void){
//Denne kode søger for at vi får læst events fra text fil ind i array af structs
    event all_events[500];
    int events;
    get_events(all_events);
//vi tæller hvor mange events vi fik læst ind fra filen
    int length = count_events(all_events);
//vi sorterer de indlæste events baseret på time
    qsort(all_events, length, sizeof(event),sort_time);
//vi printer den nu tidssorteret liste
    print_all_events(all_events, length);

//Denne kode udgør vores menu, som sluttes når bruger inputter "q"
    char option;
    do{
        scan_input(&option);

        do_task(option, all_events, length);

    }while(option != 'q');

    return 0;
}

//Funktionen åbner filen "Event.txt" fil og tjekker om den er åbnet korrekt
void get_events(event all_events[]){
    FILE *f = fopen("Events_database.txt", "r");
    if(f == NULL){
        printf("Failed to open file\n");
            exit(EXIT_FAILURE);
        }
    read_all_events(f, all_events, 500);
    fclose(f);
}

//Funktionen skriver alle evnets fra filen over i all_events arrayet.
void read_all_events(FILE *f, event all_events[], int length){
    char header[256];
    fgets(header,sizeof(header),f);
    for(int i = 0; i < length; i++){
        event e;
        int success = fscanf(f, "%s %s %s %s %d %d", e.title, e.catagory, e.alcohol, e.location, &e.price, &e.time);
        if(success != 6){
            break;
        }
        all_events[i] = e;
    }
}

//Funktionen tæller hvor mange events vi har ved at checke om time er nul. time er nul, hvis der ikke er scannet noget ind. 
int count_events(event all_events[]){
    int i;
    for(i = 0; i < 500; i++){
        if(all_events[i].time == 0){
            break;
        }
    }
    return i;
}

//Denne funktion sammenligner 2 events time og retunerer hvilke der er først.
int sort_time(const void *p1, const void *p2) {
    const struct event *e1 = p1;
    const struct event *e2 = p2;

    if (e1->time < e2->time) return -1;
    if (e1->time > e2->time) return 1;
    return 0;
}

//Funktionen printer alle events fra all_events arrayet.
void print_all_events(event all_events[], int length){
    for(int i = 0; i < length; i++){
        print_event(all_events[i]);
    }
}

//Funktionen printer et events
void print_event(event e){
    printf("\nTitle:     %s\n", e.title);
    printf("Catagory:  %s\n", e.catagory);
    printf("Alchohol?: %s\n", e.alcohol);
    printf("Location:  %s\n", e.location);
    printf("Price:     %dkr\n", e.price);
    printf("Time:      %d\n\n", e.time);
}

//Funktionen får input fra bruger til menu
void scan_input(char *option){
    printf("Choose from menu:\n");
    printf("s: Sort events\n");
    printf("p: Sort by price\n");
    printf("a: Search events\n");
    printf("q: Exit menu\n");
    scanf(" %c", option);
}

//Funktionen udfører det som brugeren har valgt fra menu
void do_task(char option, event all_events[], int length){
    switch(option){
        case 's':
            sort_events(all_events, length);
            break;
        case 'p':
            sort_events_by_price(all_events, length);
            break;
        case 'a':
            search_events(all_events, length);
            break;
        case 'q':
            break;
    }
}

//Funktionen printer de events, som brugere sorterer efter, både "bar" og "Bar" er gyldige input.
void sort_events(event all_events[], int length){
    printf("What catagory would you like to see?\n");
    printf("Career, Academic, Party, Gaming, Social, Culture, Sport, Tech\n");
    char sort_catagory[100];
    scanf("%s", sort_catagory);

//Hvis bruger har tastet lille input ændres første bogstav til stort. F.eks.: "sport" til "Sport"
    sort_catagory[0] = toupper((unsigned char)sort_catagory[0]);

//printer de evnents som matcher med søge kriterie
    for(int i = 0; i < length; i++){
        if(strcmp(all_events[i].catagory, sort_catagory) == 0){
            print_event(all_events[i]);
        }
    }
}

void search_events(event all_events[], int length){
    printf("What would you like to search for?\n");
    printf("Exact matches only!\n");
    char search[100];
    scanf("%s", search);

//Hvis bruger har tastet lille input ændres første bogstav til stort. F.eks.: "fredagsbar" til "Sport"
    search[0] = toupper((unsigned char)search[0]);

//printer de evnents som matcher med søge kriterie
    for(int i = 0; i < length; i++){
        if(strcmp(all_events[i].title, search) == 0){
            print_event(all_events[i]);
        }
    } 
}
int sort_price_low_to_high(const void *p1, const void *p2) {
    const struct event *e1 = p1;
    const struct event *e2 = p2;

    if (e1->price < e2->price) return -1;
    if (e1->price > e2->price) return 1;

    if (e1->time < e2->time) return -1;
    if (e1->time > e2->time) return 1;
    return 0;
}

int sort_price_high_to_low(const void *p1, const void *p2) {
    const struct event *e1 = p1;
    const struct event *e2 = p2;

    if (e1->price > e2->price) return -1;
    if (e1->price < e2->price) return 1;

    if (e1->time < e2->time) return -1;
    if (e1->time > e2->time) return 1;
    return 0;
}

void sort_events_by_price(event all_events[], int length){
    event copy_all_events[500];
    for(int i = 0; i < length; i++){
        copy_all_events[i] = all_events[i];
    }
    int sub_choice_price;
    int valid_choice = 0;

    do{ 
        printf("\n Price Menu \n");
        printf("1: Show all (Lowest price first)\n");
        printf("2: Show all (Highest price first)\n");
        printf("3: Search for specific price range\n");
        printf("Choose option: ");
        scanf("%d", &sub_choice_price);

        if(sub_choice_price == 1){
            valid_choice = 1;
            qsort(copy_all_events, length, sizeof(event),sort_price_low_to_high);
            print_all_events(copy_all_events, length);
        }else if(sub_choice_price == 2){
            valid_choice = 1;
            qsort(copy_all_events, length, sizeof(event),sort_price_high_to_low);
            print_all_events(copy_all_events, length);
        }else if(sub_choice_price == 3){
            int lowest_price;
            int highest_price;
            valid_choice = 1;

            do {
                printf("What price range of events do you want to see? \n");
                printf("Enter the lowest price you are willing to pay for\n");
                scanf("%d", &lowest_price);
                printf(" \n");
                printf("Enter the highest price you are willing to pay for\n");
                scanf("%d", &highest_price);

                if(lowest_price > highest_price){
                    printf("\nError: Your lowest price %d is higher than your highest price %d. The lowest price must be lower or the same as the highest price.", lowest_price, highest_price);
                    printf("Please try again\n");
                }

            }while(lowest_price > highest_price);

            printf("Here is the events in the price range of %d to %d\n", lowest_price, highest_price);
    
            int found = 0;
            for(int i = 0; i < length; i++){
                if(all_events[i].price >= lowest_price && all_events[i].price <= highest_price){
                    print_event(all_events[i]);
                    found = 1;
                }
            } 

            if(found == 0){
                printf("No events has been found\n");
            }

        }else{
            printf("\nError:You have chosen the wrong number\n");
            printf("Please choose 1, 2 or 3");
        }
    } while(valid_choice == 0);
}