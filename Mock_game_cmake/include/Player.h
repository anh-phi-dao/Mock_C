#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef WIN
#include <conio.h>
#endif
#include "Game.h"

extern char Yes_No;
extern char Adminstrator;
extern char Adminstrator_tester;

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


void Players_Function(struct Player_Data_Structure *p);

void Add_player_note(struct Player_Data_Structure *current_last,int ID,char *name,char *random_number,char *user_number,int count,int lucky,float lucky_rate,float time,char no_try_hard);
void Print_players_history_node(struct Player_Data_Structure *head);
void Print_player_specific_node(struct Player_Data_Structure *head,unsigned int NODE_POSISTION);
void Print_5_highest_players_node(struct Player_Data_Structure *head);
void Print_players_history_to_file(struct Player_Data_Structure *head);
void Print_player_specific_node_to_file(struct Player_Data_Structure *head,unsigned int NODE_POSISTION,FILE *file_pointer);
void Print_5_highest_players_to_file(struct Player_Data_Structure *head);
void bubble_sort_increase(float a[],int k[],int n);
char increase_check(float a[],int n);

#endif