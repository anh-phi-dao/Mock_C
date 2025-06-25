#include "Player.h"

char Yes_No;
char Adminstrator;
char Adminstrator_tester;

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

