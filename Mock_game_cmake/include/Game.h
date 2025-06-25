#ifndef GAME_H
#define GAME_H

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

void Create_random_number_string(char *store,char *result_store);
void User_name(char *store);
void User_number(char *store);
void Check_result_number(char *store_random,char *store_user,char *store_result,int *player_count,int *player_lucky_count, int *character_true_pre,int *character_true_cur);
char Check_number_character_6_digits(char *store_value);
void Print_skull();


#endif