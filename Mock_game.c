/********************************
 * @file Mock_game.c
 * @author Dao Anh Phi
 * @copyright FPT Software Âcdemy
 * @defgroup HCM_CPL_EMB_01
********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define alpha 10000
#define beta 1
#define gamma 0.1

#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define ORANGE "\033[38;5;202m"
#define PURPLE "\033[0;35m"
#define WHITE   "\033[0;37m"
#define BRIGHT_BLACK   "\033[1;30m"
#define BRIGHT_RED     "\033[1;31m"
#define BRIGHT_GREEN   "\033[1;32m"
#define BRIGHT_YELLOW  "\033[1;33m"
#define BRIGHT_BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN    "\033[1;36m"
#define BRIGHT_WHITE   "\033[1;37m"

struct Player_Data_Structure 
{
    int Player_ID;
    char name[50];
    char random_number_str[6];
    char reserve[3];
    char user_number[6];
    char reserve1[3];
    char result_number[6];
    char reserve2[3];
    char give_up;
    int number_of_play_time;
    int number_of_true;
    int previous_characters_true;
    int current_characters_true;
    float consuming_time;
    float lucky_ratio;
    struct Player_Data_Structure *link;
};
struct Player_Data_Structure p;
char Yes_No;
char Adminstrator;
char Adminstrator_tester;

void Players_Function(struct Player_Data_Structure *p);
/////////////////////
void Create_random_number_string(char *store,char *result_store);
void User_name(char *store);
void User_number(char *store);
void Check_result_number(char *store_random,char *store_user,char *store_result,int *player_count,int *player_lucky_count, int *character_true_pre,int *character_true_cur);
char Check_number_character_6_digits(char *store_value);
void  Print_skull();

/////////////////////
void Add_player_note(struct Player_Data_Structure *current_last,int ID,char *name,char *random_number,char *user_number,int count,int lucky,float lucky_rate,float time,char no_try_hard);
void Print_players_history_node(struct Player_Data_Structure *head);
void Print_player_specific_node(struct Player_Data_Structure *head,unsigned int NODE_POSISTION);
void Print_5_highest_players_node(struct Player_Data_Structure *head);
void Print_players_history_to_file(struct Player_Data_Structure *head);
void Print_player_specific_node_to_file(struct Player_Data_Structure *head,unsigned int NODE_POSISTION,FILE *file_pointer);
void Print_5_highest_players_to_file(struct Player_Data_Structure *head);
void bubble_sort_increase(float a[],int k[],int n);
char increase_check(float a[],int n);

////////////////////
void Test_Player_Funtion();
void Test_Add_note_and_test_print_player_specific_node();
void Test_Add_note_and_test_print_player_specific_node_2();

int main()
{
printf(RED "$$\\      $$\\  $$$$$$\\   $$$$$$\\  $$$$$$\\  $$$$$$\\        $$\\   $$\\ $$\\   $$\\ $$\\      $$\\ $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\  "RESET"\n");
printf(RED "$$$\\    $$$ |$$  __$$\\ $$  __$$\\ \\_$$  _|$$  __$$\\       $$$\\  $$ |$$ |  $$ |$$$\\    $$$ |$$  __$$\\ $$  _____|$$  __$$\\ "RESET"\n");
printf(RED "$$$$\\  $$$$ |$$ /  $$ |$$ /  \\__|  $$ |  $$ /  \\__|      $$$$\\ $$ |$$ |  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ |      $$ |  $$ |"RESET"\n");
printf(RED "$$\\$$\\$$ $$ |$$$$$$$$ |$$ |$$$$\\   $$ |  $$ |            $$ $$\\$$ |$$ |  $$ |$$\\$$\\$$ $$ |$$$$$$$\\ |$$$$$\\    $$$$$$$  |"RESET"\n");
printf(RED "$$ \\$$$  $$ |$$  __$$ |$$ |\\_$$ |  $$ |  $$ |            $$ \\$$$$ |$$ |  $$ |$$ \\$$$  $$ |$$  __$$\\ $$  __|   $$  __$$< "RESET"\n");
printf(RED "$$ |\\$  /$$ |$$ |  $$ |$$ |  $$ |  $$ |  $$ |  $$\\       $$ |\\$$$ |$$ |  $$ |$$ |\\$  /$$ |$$ |  $$ |$$ |      $$ |  $$ |"RESET"\n");
printf(RED "$$ | \\_/ $$ |$$ |  $$ |\\$$$$$$  |$$$$$$\\ \\$$$$$$  |      $$ | \\$$ |\\$$$$$$  |$$ | \\_/ $$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ |"RESET"\n");
printf(RED "\\__|     \\__|\\__|  \\__| \\______/ \\______| \\______/       \\__|  \\__| \\______/ \\__|     \\__|\\_______/ \\________|\\__|  \\__|"RESET);
printf("\n\n\n");

    printf(ORANGE"Are you an adminstrator (Type Y/y if you are, any characters if aren't):"RESET);
    scanf("%c",&Adminstrator);
    while(getchar()!='\n');    
    if(Adminstrator=='y'||Adminstrator=='Y')
    {
        printf(YELLOW"Do you want to run test (Type Y/y if you are, any characters if aren't) :"RESET);
        scanf("%c",&Yes_No);
        while(getchar()!='\n');
        if(Yes_No=='Y'||Yes_No=='y')
        {
            while(1)
            {
                printf(MAGENTA"There are 3 test testing function, the first one is only test the game logic\n"RESET);
                printf(MAGENTA"The second one is about linked list, print linked data to console and files, with 2 node \n"RESET);
                printf(MAGENTA"The third one is also the same, the difference is the third one has 7 node\n"RESET);
                printf(MAGENTA"Which one do you chose (chose 1 or 2 or 3, chosing different option will shut down the test mode and go to the game):"RESET);
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
                printf(YELLOW"\nDo you want to escape test mode (Type Y/y if you are, any characters if aren't):"RESET);
                scanf("%c",&Yes_No);
                while(getchar()!='\n');
                if(Yes_No=='Y'||Yes_No=='y')
                {
                    break;
                }
            }
            printf(YELLOW"\nDo you want to escape the game now? (Type Y/y if you are, any characters if aren't):"RESET); 
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
        printf(YELLOW"\nPlayer number %d wants to play? Type Y/y or N/n(If you type other characters\n the program considers it is yes\nY/N:"RESET,num);
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
        printf(YELLOW"\nDo you want to watch recently rank(Enter Y/y if you want to watch, enter any order characters if you want to exit): "RESET);
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

/**
 * @brief this funtion arrange the float array order and integer order base on float array
 * @param a the float array needs to be sort
 * @param k the int array needs to be sort base on float array
 * @param n the number of components
 * @note use this function to determine which node is printed first
**/
void bubble_sort_increase(float a[],int k[],int n)
{
    float temp;
    int temp1;
    while(increase_check(a,n)==0)// check see if the array order is true or not
    {
        for(int i=0;i<n-1;i++)
        {
            //swap the position of array if the previous
            //position is larger than the next position
            if(a[i]>a[i+1])
            {
                temp=a[i];
                temp1=k[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                k[i]=k[i+1];
                k[i+1]=temp1;
            }
            else
            {

            }
        }
    }
}

/**
 * @brief This function checks the increase order of float array
 * @param a a float array needs to be check
 * @param n the number of components
 * @retval 0/1 logic
**/
char increase_check(float a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {

        }
        else
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief This function add a node from a null link
 * @param current_last the address of the current node we want to point at
 * @note The rest of parameters are data that we want to store in that node
 * @note The start node should have a null link
**/
void Add_player_note(struct Player_Data_Structure *current_last,int ID,char *name,char *random_number,char *user_number,int count,int lucky,float lucky_rate,float time,char no_try_hard)
{
    struct Player_Data_Structure *current =current_last;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    current->link=(struct Player_Data_Structure*)malloc(sizeof(struct Player_Data_Structure));
    current=current->link;

    current->Player_ID=ID;
    strcpy(current->name, name);
    strncpy(current->random_number_str, random_number, 6);
    strncpy(current->user_number, user_number, 6);
    current->number_of_play_time=count;
    current->number_of_true=lucky;
    if(current->number_of_play_time<=0)
    {
        current->number_of_play_time=1;
    }
    current->lucky_ratio=lucky_rate;
    current->consuming_time=time;
    current->give_up=no_try_hard;
    current->link=NULL;
}

/**
 * @brief This function prints out data of every single node that exists
 * @param head the address of the first Player_Data_Structure Node
**/
void Print_players_history_node(struct Player_Data_Structure *head)
{
    struct Player_Data_Structure *current=head->link;
    printf("\nHistory profile\n\n");
    while (current!=NULL)
    {
        printf("Player name: %s\n",current->name);
        printf("Player ID:%d\n",current->Player_ID);
        printf("Number of rounds: %d\n",current->number_of_play_time);
        printf("Number of lucky rounds: %d\n",current->number_of_true);
        printf("Lucky ratio: %f\n",current->lucky_ratio);
        printf("Time consumption: %f\n\n",current->consuming_time);
        current=current->link;
    }
    
}

/**
 * @brief This function prints out the data of a specific node base on the node number we want
 * @param head the address of the first Player_Data_Structure Node
 * @param NODE_POSITION the node location we want to print out
 * @note we do not count the head as an offical node, so the next node from the head node has a NODE_POSITION=0
**/
void Print_player_specific_node(struct Player_Data_Structure *head,unsigned int NODE_POSISTION)
{
    struct Player_Data_Structure *current=head->link;
    int i=0;
    while(i<NODE_POSISTION)
    {
        if(current!=NULL)
        {
            current=current->link;
            i++;
        }
        else
        {
            break;
        }
        
    }
    if(current!=NULL)
    {
        printf("Player name: %s\n",current->name);
        printf("Player ID:%d\n",current->Player_ID);
        printf("Number of rounds: %d\n",current->number_of_play_time);
        printf("Number of lucky rounds: %d\n",current->number_of_true);
        printf("Lucky ratio: %f\n",current->lucky_ratio);
        printf("Time consumption: %f\n",current->consuming_time); 
        if(current->give_up==1)
        {
            printf("Player has given up\n");
        }
        printf("\n");
    }
}

/**
 * @brief This function prints out the data of 5 players with hightest rank depend on their lucky ratio, the number of rounds, and time consumption
 * @param head the address of the first Player_Data_Structure Node
**/
void Print_5_highest_players_node(struct Player_Data_Structure *head)
{
    struct Player_Data_Structure *current=head->link;
    int i=0;
    int *Nodes_order=(int*)malloc(sizeof(int));
    float *weight=(float*)malloc(sizeof(float));
    while(current!=NULL)
    {
        if(current->give_up==0)
        {
            weight[i]=current->lucky_ratio*alpha-current->consuming_time*beta-current->number_of_play_time*gamma;
        }
        else if(current->give_up==1)
        {
            weight[i]=current->lucky_ratio*alpha-current->consuming_time*beta-10000-current->number_of_play_time*gamma;
        }
        Nodes_order[i]=i;
        i++;
        current=current->link;
        
    }
    bubble_sort_increase(weight,Nodes_order,i);
    int u=i;
    int r=1;
    for(int i=u-1;i>u-6;i--)
    {
        printf("Rank %d:\n",r);
        if(Adminstrator=='Y'||Adminstrator=='y')
        {
            printf("Weight: %f\n",weight[i]);
            printf("Node_order: %d\n",i);
        }
        else
        {

        }
        Print_player_specific_node(head,Nodes_order[i]);
        r++;
    }
    if(Adminstrator_tester==0)
    {
        printf("\nPlayer with this data\n");
        Print_player_specific_node(head,Nodes_order[0]);
        printf(RED"is death\n"RESET);
        Print_skull();
    }
}

/**
 * @brief This function prints out data of every single node that exists into History_of_all_player.txt
 * @param head the address of the first Player_Data_Structure Node
**/
void Print_players_history_to_file(struct Player_Data_Structure *head)
{
    struct Player_Data_Structure *current=head->link;
    FILE *output_file;
    output_file=fopen("History_of_all_player.txt","w");
    while (current!=NULL)
    {
        fprintf(output_file,"Player name: %s\n",current->name);
        fprintf(output_file,"Player ID:%d\n",current->Player_ID);
        fprintf(output_file,"Number of rounds: %d\n",current->number_of_play_time);
        fprintf(output_file,"Number of lucky rounds: %d\n",current->number_of_true);
        fprintf(output_file,"Lucky ratio: %f\n",current->lucky_ratio);
        fprintf(output_file,"Time consumption: %f\n\n",current->consuming_time);
        current=current->link;
    }
    fclose(output_file);
}

/**
 * @brief This function prints out the data of a specific node base on the node number we want into a desired file
 * @param head the address of the first Player_Data_Structure Node
 * @param NODE_POSITION the node location we want to print out
 * @param file_pointer the pointer that points to a file
 * @note we do not count the head as an offical node, so the next node from the head node has a NODE_POSITION=0
**/
void Print_player_specific_node_to_file(struct Player_Data_Structure *head,unsigned int NODE_POSISTION,FILE *file_pointer)
{
    struct Player_Data_Structure *current=head->link;
    int i=0;
    while(i<NODE_POSISTION)
    {
        if(current!=NULL)
        {
            current=current->link;
            i++;
        }
        else
        {
            break;
        }
        
    }
    if(current!=NULL)
    {
        fprintf(file_pointer,"Player name: %s\n",current->name);
        fprintf(file_pointer,"Player ID:%d\n",current->Player_ID);
        fprintf(file_pointer,"Number of rounds: %d\n",current->number_of_play_time);
        fprintf(file_pointer,"Number of lucky rounds: %d\n",current->number_of_true);
        fprintf(file_pointer,"Lucky ratio: %f\n",current->lucky_ratio);
        fprintf(file_pointer,"Time consumption: %f\n\n",current->consuming_time);
         if(current->give_up==1)
        {
            fprintf(file_pointer,"Player has given up\n");
        }
        fprintf(file_pointer,"\n");        
    }
}

/**
 * @brief This function prints out the data of 5 players with hightest rank depend on their lucky ratio, the number of rounds, and time consumption into Five_highest_player.txt
 * @param head the address of the first Player_Data_Structure Node
**/
void Print_5_highest_players_to_file(struct Player_Data_Structure *head)
{
    struct Player_Data_Structure *current=head->link;
    int i=0;
    int *Nodes_order=(int*)malloc(sizeof(int));
    float *weight=(float*)malloc(sizeof(float));
    while(current!=NULL)
    {
         if(current->give_up==0)
        {
            weight[i]=current->lucky_ratio*alpha-current->consuming_time*beta-current->number_of_play_time*gamma;
        }
        else if(current->give_up==1)
        {
            weight[i]=current->lucky_ratio*alpha-current->consuming_time*beta-10000-current->number_of_play_time*gamma;
        }
        Nodes_order[i]=i;
        i++;
        current=current->link;
        
    }
    bubble_sort_increase(weight,Nodes_order,i);
    int u=i;
    int r=1;
    FILE *people_rank_file;
    people_rank_file=fopen("Five_highest_player.txt","w");
    for(int i=u-1;i>u-6;i--)
    {
        fprintf(people_rank_file,"Rank %d:\n",r);
        fprintf(people_rank_file,"Weight : %f\n",weight[i]);
        fprintf(people_rank_file,"Node orders :%d\n",Nodes_order);
        Print_player_specific_node_to_file(head,Nodes_order[i],people_rank_file);
        r++;
    }
    fclose(people_rank_file);
}

/* ******************************************************************** */

/**
 * @brief Low layer, this function is use for creating random string and create the first result string
 * @param store the address which uses for storing random number string
 * @param result_store the address which for storing the result string
**/
void Create_random_number_string(char *store,char *result_store)
{
    for(int i=0;i<6;i++)
    {
        store[i]=rand()%(10)+48;
    }
    for(int i=0;i<6;i++)
    {
        result_store[i]='_';
    }
}

/**
 * @brief Lower layer fuction, this function will collect player's name
 * @param store the address which uses for storng player's name
**/
void User_name(char *store)
{
    printf(CYAN"Enter your name : "RESET);
    fgets(store,50,stdin);
    size_t len = strlen(store);
    if (len > 0 && store[len - 1] == '\n')
    {
        store[len - 1] = '\0';
    }
   
}

/**
 * @brief Lower layer fuction, this function will collect player's number
 * @param store the address which uses for string number string that the users have entered
**/
void User_number(char *store)
{
    printf(BLUE"Enter your number:"RESET);
    scanf("%s",store);
    while (getchar() != '\n');
    size_t len = strlen(store);
    if (len > 0 && store[len - 1] == '\n')
    {
        store[len - 1] = '\0';
    }
    if(len>=6)
    {
        store[len]=0;
    }
    
}

/**
 * @brief Low layer function
 * @param store_random the address which uses for storing random number string
 * @param store_user the address which uses for string number string that the users have entered
 * @param store_result the address which for storing the result string
 * @param player_count the address which uses for storing the lucky score
 * @param player_lucky_count the address which uses for storing the number of rounds that player have taken
 * @param character_true_pre the address which uses for storing the previous number of true characters
 * @param character_true_cur the address which uses for storing the current number of true characters
**/
void Check_result_number(char *store_random,char *store_user,char *store_result,int *player_count,int *player_lucky_count, int *character_true_pre,int *character_true_cur)
{
    int u=0;
    for(int i=0;i<6;i++)
    {
        if(store_random[i]!=store_user[i])
        {
            store_result[i]='_';
        }
        else
        {
            store_result[i]=store_user[i];
            u++;
        }
    }
    (*player_count)++;
    (*character_true_cur)=u;    
    if((*character_true_cur)>(*character_true_pre))
    {
        (*player_lucky_count)++;
    }
    else if((*character_true_cur)==(*character_true_pre))
    {

    }
    else
    {
        int minus=(*character_true_pre)-(*character_true_cur);
        (*player_lucky_count)-=minus;
    }
    if((*player_lucky_count)<0)
    {
        (*player_lucky_count)=0;
    }
    (*character_true_pre)=(*character_true_cur);
    
}

/**
 * @brief Low layer function
 * @param store_value the address that contain result number that needs to be check
 * @retval the number of numbers characters in this array(check only 6 components)
**/
char Check_number_character_6_digits(char *store_value)
{
    char u=0;
    for(int i=0;i<6;i++)
    {
        if(((store_value[i]-48)>=0)&&((store_value[i]-48)<=9))
        {
            u++;
        }
    }
    return u;
}

////
/**
 * @brief High layer function, this function is the core of 
 *        player logic
 * @param p this is where the player's data is stored
**/
void Players_Function(struct Player_Data_Structure *p)
{
    /*reset all player variables, prepare for next player*/
    p->number_of_true=0;
    p->number_of_play_time=0;
    p->current_characters_true=0;
    p->previous_characters_true=0;
    p->give_up=0;
    /*get player's name*/
    User_name(p->name);
    /*Create random number*/
    Create_random_number_string(p->random_number_str,p->result_number);
    if(Adminstrator=='y'||Adminstrator=='Y')
    {
        printf("%s\n",p->random_number_str);
    }
    
    /*prepare the clock*/
    clock_t start, end;
    /*start counting time*/
    start=clock();
    /*this will loop until player can guess correct number, if player doesn't want to play,they can escape*/
    while(Check_number_character_6_digits(p->result_number)<6)
    {
        /*Exit option for player*/
        printf(YELLOW"Do you want to continue (Press N/n in order to escape, if you press any different characters, this mean that you still want to play):"RESET);
        scanf("%c",&Yes_No);
        while(getchar()!='\n');
        if(Yes_No=='N'||Yes_No=='n')
        {
            p->give_up=1;
            if(p->number_of_play_time==0)
            {
                p->number_of_play_time==1;
            }   
            break;
        }
        /*Get number from player*/
        p->give_up=0;
        User_number(p->user_number);
        /*Check number*/
        Check_result_number(p->random_number_str,p->user_number,p->result_number,&p->number_of_play_time,&p->number_of_true,&p->previous_characters_true,&p->current_characters_true);
        if(Check_number_character_6_digits(p->result_number)<=2)
        {
            printf(RED"Your result: %s\n"RESET,p->result_number);
        }
        else
        {
            printf(GREEN"Your result: %s\n"RESET,p->result_number);
        }
        p->lucky_ratio=((float)p->number_of_true)/((float)p->number_of_play_time);
        if(p->lucky_ratio<0.2)
        {
            printf(RED"Current lucky ratio : %f\n"RESET,p->lucky_ratio);
        }
        else
        {
            printf(GREEN"Current lucky ratio : %f\n"RESET,p->lucky_ratio);
        }
        if(p->number_of_play_time==7||p->number_of_play_time==50||p->number_of_play_time==100||p->number_of_play_time==1000)
        {
            Print_skull();
        }
        
       
    }
    /*end counting*/
    end=clock();
    p->consuming_time=((float)(end-start))/CLOCKS_PER_SEC;
}


void Print_skull()
{
printf(RED"                                        %%@@@@@@@@@%@@@@@@@@@                                           \n"RESET);
printf(RED"                               @@@@%*+#@@@@@@@@@@@@@@@%#%@@@@@@@@@@                                 \n"RESET);
printf(RED"                            @@@@@@@@@@%=::..-+-::::::::-=+*#%@@@@@@@@@@@ @@@                        \n"RESET);
printf(RED"                         @@@@@@@@%*:.              ....         .:+#%@@@@@@@@@                      \n"RESET);
printf(RED"                      @@@+@@@%:.             .:-*--:-==---+*=       .:--+%@@@@@@                    \n"RESET);
printf(RED"                   @@@@@@%#:::           .....                             :%@@@@@                  \n"RESET);
printf(RED"                 @@@@@@=.:.    .:=:                                         .-@@*@@                 \n"RESET);
printf(RED"               @@@@@%-:    ..+#-                                               -@#@@                \n"RESET);
printf(RED"             @@#+%@*..     =-.                                                  .=@@@@              \n"RESET);
printf(RED"            @@@@%=.                                                               .*@@              \n"RESET);
printf(RED"           @@@@-                                                                    :%@@            \n"RESET);
printf(RED"          @@%-.                                                                      .#@@@          \n"RESET);
printf(RED"        @@@*-:                                                                        .+@@@         \n"RESET);
printf(RED"       @@@*                                                                            .*@@@        \n"RESET);
printf(RED"      @@%-.                                                                             -#@@@       \n"RESET);
printf(RED"      @#.  :+..#-                                                                  .*.   .=*%@      \n"RESET);
printf(RED"     @%:   .*=.#%                                                                  .##.   .+*@@     \n"RESET);
printf(RED"    @@*.    .@+*@:                                                                  :@@##.  *%+@    \n"RESET);
printf(RED"   @@@:    .:*@+@*.                                                                 .-@=+.  .%*%@   \n"RESET);
printf(RED"   @@+    .@@@@@@=                                                               :*. .@=.   .-@@@   \n"RESET);
printf(RED"   @*     :@@@%-@+.                                 ..                           .*: .%@@.   .=*#   \n"RESET);
printf(RED"  @@-     .%@@%:@=                                  -                            .+*#.*@@:     *@@  \n"RESET);
printf(RED"  @%:     .+@@*.@=                                 -=                            .*@#.#@@:     .*@  \n"RESET);
printf(RED" @@#.      :%@%=@+.                               .#-                            .*@=.@@@.      +@@@\n"RESET);
printf(RED" @@*.      .#@%%@*... .-*%@@%#:                   :@:                            .#@::@@#       =@@@\n"RESET);
printf(RED"@@@+       :%@@+%#....-**-.*@@@+.:-==-:..         =@.              .:.  ..       +@@.-@@#       :@@@\n"RESET);
printf(RED"@@@%:      .#@%-+%:     .:*%%@@@@@@@%%*:....-:.  .+*       .*%%@@@@@@@@@@@@:    .@@%.=@@*       =@@@\n"RESET);
printf(RED"@@@#.      .#@@%@@#-...%@@@@@@@@@@@@@@@@@@@%#-....=.   .:@@@@@@@@@@@%*..%##@@@*+@@@+ +@@-      .*@@ \n"RESET);
printf(RED"@@@%:      :@@*.#:+@@*%@@@=.....#@@@@@@=##*....         ....+@@@@@@@@@+.    .-@@@@@:.*@*.      .#@@ \n"RESET);
printf(RED"@@@@=      -@@#.    ..::            ..                    .=:.     ...         :@#*..%@:       :%@@ \n"RESET);
printf(RED"@@@@@:     +@*@*               .  -#..                                          .#:*%@-       .#@@  \n"RESET);
printf(RED" @@@@@-.  :@%.        ...-=+%@@@@@@@@@@%*=-:=. ..:..          ...                  +@%.     .-@*+@  \n"RESET);
printf(RED"  @@@@*. .%@-.     .-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-. .   .+@@@@@@@@@#*-....     =@+      .%@:*   \n"RESET);
printf(RED"   @@@#..+@+.:.  :%@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.  -*%@@- -@@@@@@@@@@@@@@@@@@@@@*=..@+      :@@#%   \n"RESET);
printf(RED"     @@#.%:.*@. .:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+.  .%: .. +@@@@@@@@@@@@@@@@@@@@@@@@#@@=   .#@@@@@   \n"RESET);
printf(RED"      @@@+..#@.  .#@@@@@@@@@@@@@@@@@@@@@@@@@@@%-.  =@:    +@@@@@@@@@@@@@@@@@@@@@@@@#*@@+.+%-@@@@    \n"RESET);
printf(RED"      @@@%..#@.  .#@@@@@@@@@@@@@@@@@@@@@@@@@@-:.   -@-    +@@@@@@@@@@@@@@@@@@@@@@@#..#@@@@+#@@      \n"RESET);
printf(RED"       @@@#@@@+  :%@@@@@@@@@@@@@@@@@@@@@@@@@@#.    .#%.  .+@@@@@@@@@@@@@@@@@@@@@@@=. :-+@@@@@@      \n"RESET);
printf(RED"       @@@@#@@#. :%@@@@@@@@@@@@@@@@@@@@@@#-... :@*: =@@-  +@@@@@@@@@@@@@@@@@@@@@@@.    #@@@@@       \n"RESET);
printf(RED"       @@@%.*@%: .#@@@@@@@@@@@@@@@@#=....     -%@@@*..   .+@@@@@@@@@@@@@@@@@@@@@@*..%= .+@@@@       \n"RESET);
printf(RED"      @@@@. :@@-   #@@@@@@@@@@@@@=.         .%@@@@@*        ...#@@@@@@@@@@@@@@@@@- %=    #@@@       \n"RESET);
printf(RED"       @@*.  -@#=.   .=.  .......          .*@@@@@@@-..+@*:         ..=+****%@@@*.-@@@@: -@@@       \n"RESET);
printf(RED"      @@@=    +@@@@@@%-.         .=:-=%-.  :@@@@@@@@%:.#@@@%.                  :#@@@-    .#@@       \n"RESET);
printf(RED"   @@%@@:     .=@@#:=+*%@@@@%+.           .@@@@@@@@@@%.  .=@@@@@@@%+.       :@@@@@@+.  .*.-@@       \n"RESET);
printf(RED"     @@*                  .@@@@=         :%@@@@@@@@@@@%.    .:+-...      :@@@@@-.   =:  .%@@@       \n"RESET);
printf(RED"     @@@-                   .-*@#.       .#@@@@@@@@@@@@+.                 ..-@@.    .-#. .#@@       \n"RESET);
printf(RED"      @@@*.                              .#@@@@@@@@@@@@%.           .--      +@=     :@@#.#@@       \n"RESET);
printf(RED"       @@@@+.                             +@@@@@@@@@@@@@.   .-.     :%@-     .%*.  .--.=@%@@        \n"RESET);
printf(RED"         @@@@*.....          .-@@.        .%@@@@@@@@@@@*.   :%@+.   .#%:      :@%@#.....+%@@        \n"RESET);
printf(RED"           @@@@@@@@@@%%@@%+-.+@+           .@@@%=@@@@%.      .%#:         .=+*%@@@@@@@@@#@@         \n"RESET);
printf(RED"               @@@@*#@@@@@*#@@::   .=@-     .--. -%@*.        ::.     ..%%@@@@@@@@@@@@@@@           \n"RESET);
printf(RED"               @@@@   .#@@@%@@*-   .-+.                               =%@@@@%#++-%@@@               \n"RESET);
printf(RED"               @@@@.  .*@@-:@@@@.           ..                      :%@@%.     .-@@@                \n"RESET);
printf(RED"                @@@:  .*@@#+@@@@.   -:     ...                     .@@@@*      -@@@@                \n"RESET);
printf(RED"                @@@%- .#@@@%=@@@=...:.     .-.   :=    :.   ..   ..*@@@@#@==#..%@@@@                \n"RESET);
printf(RED"                @@@@= .#@*@@@@@@@@@%%++++++*#+#%%#%+=++*%-===%#**@@@@@@#:@@@. -#@@@                 \n"RESET);
printf(RED"                @@+-=.=@:-+:@@@- #@@@@@@@@%@@@%=+%@@@@@@@@@@@@@@@%@-.-.-%@@-.  +@@@                 \n"RESET);
printf(RED"                 @#-= .*:   .+@%#@:....#=   .%+  :#.  .*% .#@#+*..*@%#@@@@#%.  =@@                  \n"RESET);
printf(RED"                 @@@= .+@%@*..:#@@=.. +#.   .%-  :#.  .*+ .@*+-%::#@@@=*@%#-   *@@@                 \n"RESET);
printf(RED"                 @@@-  ...+@+..*%+@@@%@+.   :@:  -%   .#= .@%#%@@@%@#+@@=#=.   =@@@                 \n"RESET);
printf(RED"                 @@%.   .  =@+@@*-...%@@@@*+%@%%%%@##=*@@@@@@@#%..-@@@*.#+     =@@@                 \n"RESET);
printf(RED"                 @@*     ....-*++@@::@*:-==*@@@@@@@@@@%@@*=%#=.##%#@#..-*.     *@@                  \n"RESET);
printf(RED"                 @@.             -@@@@@*:...+@.  -%:  .*@..%*:=%@+*#  .-:      @@@                  \n"RESET);
printf(RED"                 @@.              :#%%#%@@@@@@#%@@@*++=%@@**@%=*@@*.  ..**:   -@@                   \n"RESET);
printf(RED"                 @@%.:==              .+@@*%@#%#+%@@%%#--:=%@@%=.    .:%-@=...@@@@                  \n"RESET);
printf(RED"                 @@@*.@@=              .-%@@: .-*##: .-#@%-..        .-. -. :%@@@                   \n"RESET);
printf(RED"                   @@@@@%##*.             .:=+:-#@@%%%*=.          ..:=+...#@@@@                    \n"RESET);
printf(RED"                     @@@@@@@*.                   ...            :++::+*###@@@@@                     \n"RESET);
printf(RED"                       @@@@@@*..                             .=%-..@@@@@@@@@                        \n"RESET);
printf(RED"                          @@@@@%:                           :=..+%@@@@@@@                           \n"RESET);
printf(RED"                            @@@@@%-.                          .-@@@@@%                              \n"RESET);
printf(RED"                             @@@@@@%=..              .-=*-.   :#@@@                                 \n"RESET);
printf(RED"                                 @@@@@@*:..    .:=#%#+=::..:=%@@@                                   \n"RESET);
printf(RED"                                   @@@@@@@#=+##@@@@@@%@@@@@@@@@                                     \n"RESET);
printf(RED"                                    @@@@@@%#@@@@     #%                                             \n"RESET);
}

void Test_Player_Funtion()
{
    struct Player_Data_Structure p_test;
    Players_Function(&p_test);
    printf("The data of p_test is\n:");
    printf("p_test.name= %s\np_test.number_of_play_time=%d\np_test.lucky_ratio=%f\np_test.time_consumption=%f\np_test.give_up=%d\n",p_test.name,p_test.number_of_play_time,p_test.lucky_ratio,p_test.consuming_time,p_test.give_up);
}

void Test_Add_note_and_test_print_player_specific_node()
{
    struct Player_Data_Structure *head_test;
    struct Player_Data_Structure p_test;
    head_test=(struct Player_Data_Structure*)malloc(sizeof(struct Player_Data_Structure));
    head_test->link=NULL;
    struct Player_Data_Structure *current;
    current=head_test;
    printf("Print data you want to enter\n");
    int ID;
    char name[50];
    char user_numer[6];
    char random_number[6];
    char result_number[6];
    int count;int lucky;float lucky_rate;float time;
    unsigned int Node_position;
    printf(" Enter ID you want: ");    
    scanf("%d",&ID);
    while (getchar()!='\n');
    User_name(name);
    User_number(user_numer);
    Create_random_number_string(random_number,result_number);
    printf(" Enter count you want: ");    
    scanf("%d",&count);
    while (getchar()!='\n');
    printf(" Enter lucky you want: ");    
    scanf("%d",&lucky);
    while (getchar()!='\n');
    printf(" Enter lucky_rate you want: ");    
    scanf("%f",&lucky_rate);
    while (getchar()!='\n');
    printf(" Enter time you want: ");    
    scanf("%f",&time);
    while (getchar()!='\n');
    printf("Do the players want to give up(Type Y/y(Yes) or N/n(No), any other characters wiil be assume as 'Yes'):");
    scanf("%c",&Yes_No);
    while (getchar()!='\n');
    if(Yes_No=='N'||Yes_No=='n')
    {
        p_test.give_up=0;
    }
    else
    {
        p_test.give_up=1;
    }
    Add_player_note(current,ID,name,random_number,user_numer,count,lucky,lucky_rate,time,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+1,name,random_number,user_numer,count+1,lucky+1,lucky_rate+1.0f,time+1.0f,p_test.give_up);
    printf("\nThe result of Print_players_history_node\n");
    Print_players_history_node(head_test);
    printf("\nEnter node position you want to print out : ");    
    scanf("%d",&Node_position);
    while (getchar()!='\n');
    printf("\nThe result of Print_player_Specific_node(head_test,%d)\n",Node_position,p_test.give_up);
    Print_player_specific_node(head_test,Node_position);
    printf("\nThe result of Print_5_highest_players_node");
    Print_5_highest_players_node(head_test);
}

void Test_Add_note_and_test_print_player_specific_node_2()
{
    struct Player_Data_Structure *head_test;
    struct Player_Data_Structure p_test;
    head_test=(struct Player_Data_Structure*)malloc(sizeof(struct Player_Data_Structure));
    head_test->link=NULL;
    struct Player_Data_Structure *current;
    current=head_test;
    printf("Print data you want to enter\n");
    int ID;
    char name[50];
    char user_numer[6];
    char random_number[6];
    char result_number[6];
    int count;int lucky;float lucky_rate;float time;
    unsigned int Node_position;
    printf(" Enter ID you want: ");    
    scanf("%d",&ID);
    while (getchar()!='\n');
    User_name(name);
    User_number(user_numer);
    Create_random_number_string(random_number,result_number);
    printf(" Enter count you want: ");    
    scanf("%d",&count);
    while (getchar()!='\n');
    printf(" Enter lucky you want: ");    
    scanf("%d",&lucky);
    while (getchar()!='\n');
    printf(" Enter lucky_rate you want: ");    
    scanf("%f",&lucky_rate);
    while (getchar()!='\n');
    printf(" Enter time you want: ");    
    scanf("%f",&time);
    while (getchar()!='\n');
    printf("Do the players want to give up(Type Y/y(Yes) or N/n(No), any other characters wiil be assume as 'Yes'):");
    scanf("%c",&Yes_No);
    while (getchar()!='\n');
    if(Yes_No=='N'||Yes_No=='n')
    {
        p_test.give_up=0;
    }
    else
    {
        p_test.give_up=1;
    }
    Add_player_note(current,ID,name,random_number,user_numer,count,lucky,lucky_rate,time,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+1,name,random_number,user_numer,count+1,lucky+1,lucky_rate+0.1f,time+1.0f,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+2,name,random_number,user_numer,count+1,lucky+1,lucky_rate-0.1f,time+2.0f,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+3,name,random_number,user_numer,count+1,lucky+1,lucky_rate,time+1.0f,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+4,name,random_number,user_numer,count+1,lucky+1,lucky_rate+0.2f,time+0.5f,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+5,name,random_number,user_numer,count+1,lucky+1,lucky_rate+0.25f,time+0.1f,p_test.give_up);
    current=current->link;
    Add_player_note(current,ID+6,name,random_number,user_numer,count+1,lucky+1,lucky_rate+0.125f,time,p_test.give_up);
    printf("The result of Print_players_history_node\n");
    Print_players_history_node(head_test);
    printf("Enter node position you want to print out : ");    
    scanf("%d",&Node_position);
    while (getchar()!='\n');
    printf("\nThe result of Print_player_Specific_node(head_test,%d)\n",Node_position);
    Print_player_specific_node(head_test,Node_position);
    printf("\nThe result of Print_5_highest_players_node");
    Print_5_highest_players_node(head_test);
}