#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

void buildtitle() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Start to make title.
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s\n", "                            X                                            ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("        Інструкція         ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s\n", " X   **************************************** ");

    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("                           ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s", " X   ** ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
    printf("Програма для прийняття рішень.");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("     ** ");

    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("1. Написати питання.       ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s", " X   ** ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
    printf("Допомагає зважити всі аргументи. ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("  ** ");

    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("2. Написати і оцінити від 0");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s", " X   ** ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
    printf("Зменшує ризик вчинити необдумано. ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf(" ** ");

    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("       до 10 всі аргументи.");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s", " X   **");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 4));
    printf("             Created by Bohdan Klots");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("** ");

    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
    printf("3. Отримати відповідь.     ");
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 13));
    printf("%s\n", " X   **************************************** ");
    printf("%s\n", "                            X                                            ");
    // Title made.
    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
    printf("\n\n");
}


int main(void) {
    system("color E0");
    system("mode con cols=73 lines=40");
    COORD newSize = {73, 9999};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), newSize);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    buildtitle();

    repeat:

    printf("         Питання:    ");
    char question[10000];
    float positive = 0, negative = 0;
    int arg_count = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
    scanf("%[^\n]%*c", &question);
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));


    while (1 == 1) {
        printf("\n");
        printf("Напишіть 1, щоб продовжити, або 0, щоб завершити: ");
        int situation;
        char term;

        while (!scanf("%d%c", &situation, &term) || term != '\n') {
            invalid_input_1:
            rewind(stdin);
            printf("Помилка! Напишіть 1(продовжити) або 0(завершити): ");
            fflush(stdin);
        }
        if (situation != 1 && situation != 0) goto invalid_input_1;


        if (situation == 1) {

            int yn;
            printf("Це позитивний аргумент?(так-1, ні-0): ");

            while (!scanf("%d%c", &yn, &term) || term != '\n') {
                invalid_input_2:
                rewind(stdin);
                printf("Помилка! Напишіть 1(так) або 0(ні): ");
                fflush(stdin);
            }
            if (yn != 1 && yn != 0) goto invalid_input_2;


            printf("Напишіть аргумент: ");
            if (yn == 1) { SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2)); }
            else { SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4)); }
            char arg[1000];
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            fflush(stdin);
            scanf("%[^\n]%*c", &arg);
            arg_count += 1;
            SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
            SetConsoleCP(CP_UTF8);
            SetConsoleOutputCP(CP_UTF8);

            int rating = -1;

            fflush(stdin);
            printf("Оцініть важливість аргумента від 0 до 10: ");

            while (TRUE) {
                if (yn == 1) { SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2)); }
                else { SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4)); }
                if (!scanf("%d%c", &rating, &term) || term != '\n') {
                    invalid_input_3:
                    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
                    rewind(stdin);
                    printf("Будь-ласка, введіть ціле число від 0 до 10: ");
                    fflush(stdin);
                    continue;
                }
                break;
            }
            SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
            if (rating < 0 || rating > 10) goto invalid_input_3;


            if (yn == 1) { positive = positive + rating; }
            if (yn == 0) { negative = negative + rating; }
            SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
        } else {
            printf("\n\n");
            float per_posf, per_negf, sum;
            int i;
            sum = positive + negative;
            per_posf = ((positive / sum) * 100) / 2;
            per_negf = 50 - per_posf;
            int per_neg = per_negf;
            int per_pos = per_posf;
            if (per_neg % 1 >= 0.5) { per_neg += 1; }
            else { per_pos += 1; }
            if (positive == 0 && negative == 0) {
                printf("\nВибачте, замало аргумнтів =(\n\n");
            } else {
                SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
                printf("         ******************************************************");
                if (positive == 0 || negative == 0 || positive == negative) printf("*\n");
                else printf("\n");
                for (int j = 0; j <= 1; j++) {
                    printf("         **");
                    SetConsoleTextAttribute(hConsole, (WORD) ((2 << 4) | 2));
                    for (i = 1; i <= per_pos; i++) { printf("*"); }
                    SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 4));
                    for (i = 1; i <= per_neg; i++) { printf("*"); }
                    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
                    printf("**\n");
                }
                printf("         ******************************************************");
                if (positive == 0 || negative == 0 || positive == negative) printf("*\n");
                else printf("\n");
                SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
                printf("         За: %0.f%%;      Проти: %0.f%%\n", (floorf(per_posf * 200) / 100),
                       (floorf(per_negf * 200) / 100));
                printf("\n");
                if (per_negf > per_posf) {
                    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 4));
                    printf("Переважають негативні аргументи.\n\n");
                    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
                    printf("Вовк говорить 'ні' / Волк говорит 'нет'");
                    printf("\n\n");
                    printf("             ████████████████████████████████████████\n");
                    printf("             ████████████▀▀▀░░░░░░░░░░▀▀▀████████████\n");
                    printf("             █████████▀░░░░░░░░░░░░░░░░░░░▀▀█████████\n");
                    printf("             ███████▀░░░░░░░░░░░░░░░░░░░▄▄▄░░▀███████\n");
                    printf("             █████▀░░░░░░░░░░░░░░░░░░░▄████░░░░▀█████\n");
                    printf("             ████▀░░░░░░░░░░░░░░░░░▄██████▀░░░░░▀████\n");
                    printf("             ███▀░░░░░░░░░░░░░░▄▄▄██████░░░░░░░░░▀███\n");
                    printf("             ███░░░░░░░░░░░▄▄██▀▀██████░░░░░░░░░░░███\n");
                    printf("             ██░░░░░░░▄▄███████████████░░░░▄▄░░░░░░██\n");
                    printf("             ██░░░▄▄█████████████████████████░░░░░░██\n");
                    printf("             ██░▄██████████████████████████▀░░░░░░░██\n");
                    printf("             ██░░░░▄▄███████████████████▀▀░░░░░░░░▄██\n");
                    printf("             ███▄█████████████████████▀░░░░░░░░░░░███\n");
                    printf("             ████████████████████████░░░░░░░░░░░░▄███\n");
                    printf("             ███████████████████████▀░░░░░░░░░░░▄████\n");
                    printf("             ███████████████████████░░░░░░░░░░▄██████\n");
                    printf("             ██████████████████████▀░░░░░░░░▄████████\n");
                    printf("             ██████████████████████░░░░░░▄▄██████████\n");
                    printf("             ███████████████████████▄▄▄██████████████\n\n");
                }
                if (per_negf < per_posf) {
                    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 2));
                    printf("Переважають позитивні аргументи.\n\n");
                    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
                    printf("Вовк говорить 'так' / Волк говорит 'да'\n\n");
                    printf("             ░░░░░░█▄▄░░░░░░░░░░░░▄▄█░░░░░░\n");
                    printf("             ░░░░░█████▄░░░░░░░░▄█████░░░░░\n");
                    printf("             ░░░░░███████▄▄▄▄▄▄███████░░░░░\n");
                    printf("             ░░░░░██▀░░░░▀▀▀▀▀▀░░░░▀██░░░░░\n");
                    printf("             ░░░░▄█░░░░░░░░░░░░░░░░░░█▄░░░░\n");
                    printf("             ░░░░█░░░░░░░░░░░░░░░░░░░░█░░░░\n");
                    printf("             ░░░█▀░░░▄▄▄░░░░░░░░▄▄▄░░░▀█░░░\n");
                    printf("             ░░▄█░░░░▀███░░░░░░███▀░░░░█▄░░\n");
                    printf("             ░░█░▄░░░░░░░░▄░░▄░░░░░░░░▄░█░░\n");
                    printf("             ░█████▄▄░░░░░█░░█░░░░░▄▄█████░\n");
                    printf("             ▄█░░▀▀▀▀█▄░░▄█░░█░░░▄█▀▀▀▀░░█▄\n");
                    printf("             ░▀█▄░░░░░▀▄░█░░░░█░▄▀░░░░░▄█▀░\n");
                    printf("             ░░░▀█▄▄░░░█░▀████▀▄█░░░▄▄█▀░░░\n");
                    printf("             ░░░░░▀██▄░░▀█▀▀▀▀█▀░░▄██▀░░░░░\n");
                    printf("             ░░░░░░░▀██▄░░▀▀▀▀░░▄██▀░░░░░░░\n");
                    printf("             ░░░░░░░░░▀██▄░░░░▄██▀░░░░░░░░░\n");
                    printf("             ░░░░░░░░░░░▀██████▀░░░░░░░░░░░\n");
                    printf("             ░░░░░░░░░░░░░▀██▀░░░░░░░░░░░░░\n\n");
                }
                SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
                if (per_negf == per_posf) {
                    printf("Негативних і позитивних аргументів порівну.\n\n");
                    printf("Вовк не знає що робити / Волк не знает что делать\n\n");
                    printf("             ░░░░░░░▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░███▄░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░█████░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░██████▄░░░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░███████░░░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░████████▄░░░░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░██████████▄▄░░░░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░█████████████▄▄░░░░░░░░░░░░░░░░\n");
                    printf("             ░░░░░░▀██████████████████▄░░░░░░░░░░░\n");
                    printf("             ░░░░░░░▀████████████████████▄░░░░░░░░\n");
                    printf("             ░░░░░░░░░█████████████████████░░░░░░░\n");
                    printf("             ░░░░░░░░░░██████▀▀▀████████████▄░░░░░\n");
                    printf("             ░░░░░░░░░░██▀░██░░░▀████████▀███████▀\n");
                    printf("             ░░░░░░░░░░██░░██░░░░▀████████▄░▀▀▀▀░░\n");
                    printf("             ░░░░░▄▄█████▄▄█▀░░░░░▀██▄░░▀██░░░░░░░\n");
                    printf("             ░░▄██████████████▄▄░░░░██░░░██░░░░░░░\n");
                    printf("             ▄████████████████████████░░░░██░░░░░░\n");
                    printf("             ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░░░░░\n\n");
                }
            }
            break;
        }
    }

    printf("Якщо бажаєте вирішити наступне питання, напишіть 1, інакше - 0\n");
    int reaction;
    char term;
    printf("Бажаєте продовжити?(так-1, ні-0): ");
    while (!scanf("%d%c", &reaction, &term) || term != '\n') {
        invalid_input_4:
        rewind(stdin);
        printf("Помилка! Напишіть 1(так) або 0(ні): ");
        fflush(stdin);
    }
    if (reaction != 1 && reaction != 0) goto invalid_input_4;
    if (reaction == 1) {
        printf("\n");
        goto repeat;
    } else {
        printf("До побачення!");
        Sleep(4000);
    }
    return 0;
}
