int main_menu() {
    int menu_choice;
    do {
        printf("Welcome to\n"
               " _               _     _     _                _       _         \n"
               " | |             | |   | |   | |              | |     (_)        \n"
               " | |__     __ _  | |_  | |_  | |   ___   ___  | |__    _   _ __  \n"
               " | '_ \\   / _` | | __| | __| | |  / _ \\ / __| | '_ \\  | | | '_ \\ \n"
               " | |_) | | (_| | | |_  | |_  | | |  __/ \\__ \\ | | | | | | | |_) |\n"
               " |_.__/   \\__,_|  \\__|  \\__| |_|  \\___| |___/ |_| |_| |_| | .__/ \n"
               "                                                          | |    \n"
               "                                                          |_|    \n"
               "What do you want to do ?\n"
               "New game (1)\n"
               "Load game (2)\n"
               "Quit (3)\n");
        scanf("%d", &menu_choice);
    } while (menu_choice < 1 || menu_choice > 3);
    return menu_choice;
}

int mode_menu() {
    int mode_choice;
    do {
        printf("In which mode would you like to play ?\n"
               "Classic (1)\nBlind (2)\nActive (3)\n");
        scanf("%d", &mode_choice);
    } while (mode_choice < 1 || mode_choice > 3);
    return mode_choice;
}

int difficulty_menu() {
    int difficulty;
    do {
        printf("In which difficulty do you want to play ?\n"
               "Easy (1)\nMedium (2)\nHard (3)\n");
        scanf("%d", &difficulty);
    } while (difficulty < 1 || difficulty > 3);
    return difficulty;
}
