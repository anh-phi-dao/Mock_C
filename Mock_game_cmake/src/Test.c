#include "Test.h"




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