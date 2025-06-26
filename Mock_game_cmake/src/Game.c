#include "Game.h"


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
#ifdef WIN
    printf(CYAN"Enter your name : "RESET);
    fgets(store,50,stdin);
    size_t len = strlen(store);
    if (len > 0 && store[len - 1] == '\n')
    {
        store[len - 1] = '\0';
    }
#else
    printf("Enter your name : ");
    fgets(store,50,stdin);
    size_t len = strlen(store);
    if (len > 0 && store[len - 1] == '\n')
    {
        store[len - 1] = '\0';
    }
#endif
   
}

/**
 * @brief Lower layer fuction, this function will collect player's number
 * @param store the address which uses for string number string that the users have entered
**/
void User_number(char *store)
{
#ifdef WIN
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
#else
    printf("Enter your number:");
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
#endif
    
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


void Print_skull()
{
#ifdef WIN
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
#else
    printf("                                        %%@@@@@@@@@%@@@@@@@@@                                           \n");
    printf("                               @@@@%*+#@@@@@@@@@@@@@@@%#%@@@@@@@@@@                                 \n");
    printf("                            @@@@@@@@@@%=::..-+-::::::::-=+*#%@@@@@@@@@@@ @@@                        \n");
    printf("                         @@@@@@@@%*:.              ....         .:+#%@@@@@@@@@                      \n");
    printf("                      @@@+@@@%:.             .:-*--:-==---+*=       .:--+%@@@@@@                    \n");
    printf("                   @@@@@@%#:::           .....                             :%@@@@@                  \n");
    printf("                 @@@@@@=.:.    .:=:                                         .-@@*@@                 \n");
    printf("               @@@@@%-:    ..+#-                                               -@#@@                \n");
    printf("             @@#+%@*..     =-.                                                  .=@@@@              \n");
    printf("            @@@@%=.                                                               .*@@              \n");
    printf("           @@@@-                                                                    :%@@            \n");
    printf("          @@%-.                                                                      .#@@@          \n");
    printf("        @@@*-:                                                                        .+@@@         \n");
    printf("       @@@*                                                                            .*@@@        \n");
    printf("      @@%-.                                                                             -#@@@       \n");
    printf("      @#.  :+..#-                                                                  .*.   .=*%@      \n");
    printf("     @%:   .*=.#%                                                                  .##.   .+*@@     \n");
    printf("    @@*.    .@+*@:                                                                  :@@##.  *%+@    \n");
    printf("   @@@:    .:*@+@*.                                                                 .-@=+.  .%*%@   \n");
    printf("   @@+    .@@@@@@=                                                               :*. .@=.   .-@@@   \n");
    printf("   @*     :@@@%-@+.                                 ..                           .*: .%@@.   .=*#   \n");
    printf("  @@-     .%@@%:@=                                  -                            .+*#.*@@:     *@@  \n");
    printf("  @%:     .+@@*.@=                                 -=                            .*@#.#@@:     .*@  \n");
    printf(" @@#.      :%@%=@+.                               .#-                            .*@=.@@@.      +@@@\n");
    printf(" @@*.      .#@%%@*... .-*%@@%#:                   :@:                            .#@::@@#       =@@@\n");
    printf("@@@+       :%@@+%#....-**-.*@@@+.:-==-:..         =@.              .:.  ..       +@@.-@@#       :@@@\n");
    printf("@@@%:      .#@%-+%:     .:*%%@@@@@@@%%*:....-:.  .+*       .*%%@@@@@@@@@@@@:    .@@%.=@@*       =@@@\n");
    printf("@@@#.      .#@@%@@#-...%@@@@@@@@@@@@@@@@@@@%#-....=.   .:@@@@@@@@@@@%*..%##@@@*+@@@+ +@@-      .*@@ \n");
    printf("@@@%:      :@@*.#:+@@*%@@@=.....#@@@@@@=##*....         ....+@@@@@@@@@+.    .-@@@@@:.*@*.      .#@@ \n");
    printf("@@@@=      -@@#.    ..::            ..                    .=:.     ...         :@#*..%@:       :%@@ \n");
    printf("@@@@@:     +@*@*               .  -#..                                          .#:*%@-       .#@@  \n");
    printf(" @@@@@-.  :@%.        ...-=+%@@@@@@@@@@%*=-:=. ..:..          ...                  +@%.     .-@*+@  \n");
    printf("  @@@@*. .%@-.     .-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-. .   .+@@@@@@@@@#*-....     =@+      .%@:*   \n");
    printf("   @@@#..+@+.:.  :%@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.  -*%@@- -@@@@@@@@@@@@@@@@@@@@@*=..@+      :@@#%   \n");
    printf("     @@#.%:.*@. .:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+.  .%: .. +@@@@@@@@@@@@@@@@@@@@@@@@#@@=   .#@@@@@   \n");
    printf("      @@@+..#@.  .#@@@@@@@@@@@@@@@@@@@@@@@@@@@%-.  =@:    +@@@@@@@@@@@@@@@@@@@@@@@@#*@@+.+%-@@@@    \n");
    printf("      @@@%..#@.  .#@@@@@@@@@@@@@@@@@@@@@@@@@@-:.   -@-    +@@@@@@@@@@@@@@@@@@@@@@@#..#@@@@+#@@      \n");
    printf("       @@@#@@@+  :%@@@@@@@@@@@@@@@@@@@@@@@@@@#.    .#%.  .+@@@@@@@@@@@@@@@@@@@@@@@=. :-+@@@@@@      \n");
    printf("       @@@@#@@#. :%@@@@@@@@@@@@@@@@@@@@@@#-... :@*: =@@-  +@@@@@@@@@@@@@@@@@@@@@@@.    #@@@@@       \n");
    printf("       @@@%.*@%: .#@@@@@@@@@@@@@@@@#=....     -%@@@*..   .+@@@@@@@@@@@@@@@@@@@@@@*..%= .+@@@@       \n");
    printf("      @@@@. :@@-   #@@@@@@@@@@@@@=.         .%@@@@@*        ...#@@@@@@@@@@@@@@@@@- %=    #@@@       \n");
    printf("       @@*.  -@#=.   .=.  .......          .*@@@@@@@-..+@*:         ..=+****%@@@*.-@@@@: -@@@       \n");
    printf("      @@@=    +@@@@@@%-.         .=:-=%-.  :@@@@@@@@%:.#@@@%.                  :#@@@-    .#@@       \n");
    printf("   @@%@@:     .=@@#:=+*%@@@@%+.           .@@@@@@@@@@%.  .=@@@@@@@%+.       :@@@@@@+.  .*.-@@       \n");
    printf("     @@*                  .@@@@=         :%@@@@@@@@@@@%.    .:+-...      :@@@@@-.   =:  .%@@@       \n");
    printf("     @@@-                   .-*@#.       .#@@@@@@@@@@@@+.                 ..-@@.    .-#. .#@@       \n");
    printf("      @@@*.                              .#@@@@@@@@@@@@%.           .--      +@=     :@@#.#@@       \n");
    printf("       @@@@+.                             +@@@@@@@@@@@@@.   .-.     :%@-     .%*.  .--.=@%@@        \n");
    printf("         @@@@*.....          .-@@.        .%@@@@@@@@@@@*.   :%@+.   .#%:      :@%@#.....+%@@        \n");
    printf("           @@@@@@@@@@%%@@%+-.+@+           .@@@%=@@@@%.      .%#:         .=+*%@@@@@@@@@#@@         \n");
    printf("               @@@@*#@@@@@*#@@::   .=@-     .--. -%@*.        ::.     ..%%@@@@@@@@@@@@@@@           \n");
    printf("               @@@@   .#@@@%@@*-   .-+.                               =%@@@@%#++-%@@@               \n");
    printf("               @@@@.  .*@@-:@@@@.           ..                      :%@@%.     .-@@@                \n");
    printf("                @@@:  .*@@#+@@@@.   -:     ...                     .@@@@*      -@@@@                \n");
    printf("                @@@%- .#@@@%=@@@=...:.     .-.   :=    :.   ..   ..*@@@@#@==#..%@@@@                \n");
    printf("                @@@@= .#@*@@@@@@@@@%%++++++*#+#%%#%+=++*%-===%#**@@@@@@#:@@@. -#@@@                 \n");
    printf("                @@+-=.=@:-+:@@@- #@@@@@@@@%@@@%=+%@@@@@@@@@@@@@@@%@-.-.-%@@-.  +@@@                 \n");
    printf("                 @#-= .*:   .+@%#@:....#=   .%+  :#.  .*% .#@#+*..*@%#@@@@#%.  =@@                  \n");
    printf("                 @@@= .+@%@*..:#@@=.. +#.   .%-  :#.  .*+ .@*+-%::#@@@=*@%#-   *@@@                 \n");
    printf("                 @@@-  ...+@+..*%+@@@%@+.   :@:  -%   .#= .@%#%@@@%@#+@@=#=.   =@@@                 \n");
    printf("                 @@%.   .  =@+@@*-...%@@@@*+%@%%%%@##=*@@@@@@@#%..-@@@*.#+     =@@@                 \n");
    printf("                 @@*     ....-*++@@::@*:-==*@@@@@@@@@@%@@*=%#=.##%#@#..-*.     *@@                  \n");
    printf("                 @@.             -@@@@@*:...+@.  -%:  .*@..%*:=%@+*#  .-:      @@@                  \n");
    printf("                 @@.              :#%%#%@@@@@@#%@@@*++=%@@**@%=*@@*.  ..**:   -@@                   \n");
    printf("                 @@%.:==              .+@@*%@#%#+%@@%%#--:=%@@%=.    .:%-@=...@@@@                  \n");
    printf("                 @@@*.@@=              .-%@@: .-*##: .-#@%-..        .-. -. :%@@@                   \n");
    printf("                   @@@@@%##*.             .:=+:-#@@%%%*=.          ..:=+...#@@@@                    \n");
    printf("                     @@@@@@@*.                   ...            :++::+*###@@@@@                     \n");
    printf("                       @@@@@@*..                             .=%-..@@@@@@@@@                        \n");
    printf("                          @@@@@%:                           :=..+%@@@@@@@                           \n");
    printf("                            @@@@@%-.                          .-@@@@@%                              \n");
    printf("                             @@@@@@%=..              .-=*-.   :#@@@                                 \n");
    printf("                                 @@@@@@*:..    .:=#%#+=::..:=%@@@                                   \n");
    printf("                                   @@@@@@@#=+##@@@@@@%@@@@@@@@@                                     \n");
    printf("                                    @@@@@@%#@@@@     #%                                             \n");
    #endif
}


