#include "Game.h"
#include "Player.h"
#include "Test.h"

struct Player_Data_Structure p;

int main()
{
    #ifdef WIN
printf(RED "$$\\      $$\\  $$$$$$\\   $$$$$$\\  $$$$$$\\  $$$$$$\\        $$\\   $$\\ $$\\   $$\\ $$\\      $$\\ $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\  "RESET"\n");
printf(RED "$$$\\    $$$ |$$  __$$\\ $$  __$$\\ \\_$$  _|$$  __$$\\       $$$\\  $$ |$$ |  $$ |$$$\\    $$$ |$$  __$$\\ $$  _____|$$  __$$\\ "RESET"\n");
printf(RED "$$$$\\  $$$$ |$$ /  $$ |$$ /  \\__|  $$ |  $$ /  \\__|      $$$$\\ $$ |$$ |  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ |      $$ |  $$ |"RESET"\n");
printf(RED "$$\\$$\\$$ $$ |$$$$$$$$ |$$ |$$$$\\   $$ |  $$ |            $$ $$\\$$ |$$ |  $$ |$$\\$$\\$$ $$ |$$$$$$$\\ |$$$$$\\    $$$$$$$  |"RESET"\n");
printf(RED "$$ \\$$$  $$ |$$  __$$ |$$ |\\_$$ |  $$ |  $$ |            $$ \\$$$$ |$$ |  $$ |$$ \\$$$  $$ |$$  __$$\\ $$  __|   $$  __$$< "RESET"\n");
printf(RED "$$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |  $$\\       $$ |\\$$$ |$$ |  $$ |$$ |\\$  /$$ |$$ |  $$ |$$ |      $$ |  $$ |"RESET"\n");
printf(RED "$$ | \\_/ $$ |$$ |  $$ |\\$$$$$$  |$$$$$$\\ \\$$$$$$  |      $$ | \\$$ |\\$$$$$$  |$$ | \\_/ $$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ |"RESET"\n");
printf(RED "\\__|     \\__|\\__|  \\__| \\______/ \\______| \\______/       \\__|  \\__| \\______/ \\__|     \\__|\\_______/ \\________|\\__|  \\__|"RESET);
printf("\n\n\n");
    #else
    printf( "$$\\      $$\\  $$$$$$\\   $$$$$$\\  $$$$$$\\  $$$$$$\\        $$\\   $$\\ $$\\   $$\\ $$\\      $$\\ $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\ \n");
printf("$$$\\    $$$ |$$  __$$\\ $$  __$$\\ \\_$$  _|$$  __$$\\       $$$\\  $$ |$$ |  $$ |$$$\\    $$$ |$$  __$$\\ $$  _____|$$  __$$\\ \n");
printf("$$$$\\  $$$$ |$$ /  $$ |$$ /  \\__|  $$ |  $$ /  \\__|      $$$$\\ $$ |$$ |  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ |      $$ |  $$ |\n");
printf("$$\\$$\\$$ $$ |$$$$$$$$ |$$ |$$$$\\   $$ |  $$ |            $$ $$\\$$ |$$ |  $$ |$$\\$$\\$$ $$ |$$$$$$$\\ |$$$$$\\    $$$$$$$  |\n");
printf("$$ \\$$$  $$ |$$  __$$ |$$ |\\_$$ |  $$ |  $$ |            $$ \\$$$$ |$$ |  $$ |$$ \\$$$  $$ |$$  __$$\\ $$  __|   $$  __$$< \n");
printf("$$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |  $$\\       $$ |\\$$$ |$$ |  $$ |$$ |\\$  /$$ |$$ |  $$ |$$ |      $$ |  $$ |\n");
printf("$$ | \\_/ $$ |$$ |  $$ |\\$$$$$$  |$$$$$$\\ \\$$$$$$  |      $$ | \\$$ |\\$$$$$$  |$$ | \\_/ $$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ |\n");
printf("\\__|     \\__|\\__|  \\__| \\______/ \\______| \\______/       \\__|  \\__| \\______/ \\__|     \\__|\\_______/ \\________|\\__|  \\__|");
printf("\n\n\n");
    #endif

    #ifdef WIN32
    printf(ORANGE"Are you an adminstrator (Type Y/y if you are, any characters if aren't):"RESET);
    #else
    printf("Are you an adminstrator (Type Y/y if you are, any characters if aren't):");
    #endif
    scanf("%c",&Adminstrator);
    while(getchar()!='\n');    
    if(Adminstrator=='y'||Adminstrator=='Y')
    {
        #ifdef WIN
        printf(YELLOW"Do you want to run test (Type Y/y if you are, any characters if aren't) :"RESET);
        #else
        printf("Do you want to run test (Type Y/y if you are, any characters if aren't) :");
        #endif
        scanf("%c",&Yes_No);
        while(getchar()!='\n');
        if(Yes_No=='Y'||Yes_No=='y')
        {
            while(1)
            {
                #ifdef WIN
                printf(MAGENTA"There are 3 test testing function, the first one is only test the game logic\n"RESET);
                printf(MAGENTA"The second one is about linked list, print linked data to console and files, with 2 node \n"RESET);
                printf(MAGENTA"The third one is also the same, the difference is the third one has 7 node\n"RESET);
                printf(MAGENTA"Which one do you chose (chose 1 or 2 or 3, chosing different option will shut down the test mode and go to the game):"RESET);
                #else
                printf("There are 3 test testing function, the first one is only test the game logic\n");
                printf("The second one is about linked list, print linked data to console and files, with 2 node \n");
                printf("The third one is also the same, the difference is the third one has 7 node\n");
                printf("Which one do you chose (chose 1 or 2 or 3, chosing different option will shut down the test mode and go to the game):");
                #endif
                scanf("%d",&Adminstrator_tester);
                while(getchar()!='\n');
                if(Adminstrator_tester==1)
                {
                    Test_Player_Funtion();
                }
                else if(Adminstrator_tester==2)
                {
                    Test_Add_note_and_test_print_player_specific_node();
                }
                else if(Adminstrator_tester==3)
                {
                    Test_Add_note_and_test_print_player_specific_node_2();
                }
                else
                {
                    break;
                }
                #ifdef WIN
                printf(YELLOW"\nDo you want to escape test mode (Type Y/y if you are, any characters if aren't):"RESET);
                #else
                printf("\nDo you want to escape test mode (Type Y/y if you are, any characters if aren't):");
                #endif
                scanf("%c",&Yes_No);
                while(getchar()!='\n');
                if(Yes_No=='Y'||Yes_No=='y')
                {
                    break;
                }
            }
            #ifdef WIN
            printf(YELLOW"\nDo you want to escape the game now? (Type Y/y if you are, any characters if aren't):"RESET); 
            #else
            printf("\nDo you want to escape the game now? (Type Y/y if you are, any characters if aren't):"); 
            #endif
            scanf("%c",&Yes_No);
            while(getchar()!='\n');
            if(Yes_No=='Y'||Yes_No=='y')
            {
                return 0;
            }     
        }    
    }        
                 
    Adminstrator_tester=0;                                                                                                                                                                                                                                                                                                    
    struct Player_Data_Structure *head;
    head=(struct Player_Data_Structure*)malloc(sizeof(struct Player_Data_Structure));
    head->link=NULL;
    struct Player_Data_Structure *current;
    current=head;
    int ID=1;
    
    Players_Function(&p);
    Add_player_note(current,ID,p.name,p.random_number_str,p.user_number,p.number_of_play_time,p.number_of_true,p.lucky_ratio,p.consuming_time,p.give_up);
    current=current->link;
    int num=2;
    while(1)
    {
        ID++;
        #ifdef WIN
        printf(YELLOW"\nPlayer number %d wants to play? Type Y/y or N/n(If you type other characters\n the program considers it is yes\nY/N:"RESET,num);
        #else
        printf("\nPlayer number %d wants to play? Type Y/y or N/n(If you type other characters\n the program considers it is yes\nY/N:",num);
        #endif
        scanf("%c",&Yes_No);
        while (getchar() != '\n');
        if((Yes_No=='N')||(Yes_No=='n'))
        {
            break;
        }
        else
        {

        }
        Players_Function(&p);
        Add_player_note(current,ID,p.name,p.random_number_str,p.user_number,p.number_of_play_time,p.number_of_true,p.lucky_ratio,p.consuming_time,p.give_up);
        current=current->link;
        num++;
    }
    Print_players_history_node(head);
    Print_players_history_to_file(head);
    Print_5_highest_players_to_file(head);
    while(1)
    {
        #ifdef WIN
        printf(YELLOW"\nDo you want to watch recently rank(Enter Y/y if you want to watch, enter any order characters if you want to exit): "RESET);
        #else
        printf("\nDo you want to watch recently rank(Enter Y/y if you want to watch, enter any order characters if you want to exit): ");
        #endif
        scanf("%c",&Yes_No);
        while (getchar() != '\n');
        if(Yes_No=='Y'||Yes_No=='y')
        {
            printf("\nRanking list:\n");
            Print_5_highest_players_node(head);
        }
        else
        {
            printf("End program");
            break;
        }
    }
}
