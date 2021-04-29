#include <stdio.h>

int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char days[7][4] = {"sut", "sun", "mon", "tue", "wen", "thu", "fri"};
char months[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
char name_in[] = {"input.txt"};
char name_out[] = {"output.txt"};

void in(int *day_pointer, int *month_pointer, int *year_pointer) {
    FILE *fp = fopen(name_in, "w+");
    char current;
    int day, month, bool = 1;
    current = 1;
    while (current != '\n') {
        scanf("%c", &current);
        fputc(current, fp);
    }//ввод
    fseek(fp, 0, SEEK_SET);
    char arr[8];
    fgets(arr, 7, fp);
    if (arr[2] != ' ' || arr[5] != ' ') {
        bool = 0;
    }//проверка
    fseek(fp, 6, SEEK_SET);
    current = 1;
    while ((current = getc(fp)) != EOF) {
        if ((current - '0' > 9 || current - '0' < 0) && current - '0' != -38) {
            bool = 0;
            break;
        }
    }//проверка
    day = (arr[0] - '0') * 10 + arr[1] - '0';
    month = (arr[3] - '0') * 10 + arr[4] - '0';
    if (month > 12 || month < 1 || day > 31 || day < 0) {
        bool = 0;
    }//проверка
    fseek(fp, ftell(fp) - 4, SEEK_SET);
    current = (fgetc(fp) - '0') * 10 + fgetc(fp) - '0';
    *year_pointer = current;
    if (month == 2 && !((day <= 29 && (int) current % 4 == 0) || day <= 28)) {
        bool = 0;
    }//проверка
    if (month != 2 && day > date[month - 1]) {
        bool = 0;
    }//проверка
    fclose(fp);
    if (bool == 0) {
        printf("inappropriate input try again\n");
        remove(name_in);
    } else {
        int summator = 0, i = 0;
        *day_pointer = day;
        *month_pointer = month;
        FILE *out = fopen(name_out, "w+");
        FILE *in = fopen(name_in, "r");
        FILE *tmp_file = fopen("tmp_file.txt", "w+");
        fseek(in, 0, SEEK_END);
        fseek(in, ftell(in) - 3, SEEK_SET);
        current = fgetc(in);
        fseek(in, ftell(in) - 2, SEEK_SET);
        while (current == '0') {
            fprintf(tmp_file, "%c", '9');
            current = fgetc(in);
            fseek(in, ftell(in) - 2, SEEK_SET);
        }//иду до не нуля
        if (current != '1' || ftell(in) != 5) {
            fprintf(tmp_file, "%d", current - '0' - 1);
            current = fgetc(in);
            fseek(in, ftell(in) - 2, SEEK_SET);
        } else {
            fseek(in, ftell(in) - 2, SEEK_SET);
            current = fgetc(in);
        }//проверка на кратность 10
        while (ftell(in) >= 5) {
            fprintf(tmp_file, "%c", current);
            current = fgetc(in);
            fseek(in, ftell(in) - 2, SEEK_SET);
        }//полный вывод
        fclose(tmp_file);
        FILE *in_tmp = fopen("tmp_file.txt", "r");
        fseek(in_tmp, 0, SEEK_END);
        fseek(in_tmp, 0, SEEK_SET);
        current = fgetc(in_tmp);
        while (current != EOF) {
            fprintf(out, "%d", ((current - '0') * 365 + summator) % 10);
            summator = ((current - '0') * 365 + summator) / 10;
            current = fgetc(in_tmp);
        }//умножение на дни
        while (summator > 0) {
            fprintf(out, "%d", summator % 10);
            summator /= 10;
        }// доумножения на дни
        fclose(in_tmp);
        fclose(in);
        fclose(out);
        FILE *with_days = fopen("with_days.txt", "w+");
        FILE *reding_out = fopen("output.txt", "r");
        summator = day;
        for (i = 0; i < month - 1; ++i) {
            summator += date[i];
        }//посчитал дни за год
        current = 1;
        while (current != EOF) {
            current = fgetc(reding_out);
            if (current != EOF) {
                fprintf(with_days, "%d", (current - '0' + summator) % 10);
                summator = (current - '0' + summator) / 10;
            }
        }//прибавил дни за год
        while (summator > 0) {
            fprintf(with_days, "%d", +summator % 10);
            summator /= 10;
        }//доприбавил дни за год
        fclose(with_days);
        fclose(reding_out);
        remove(name_out);
        FILE *reding_with_days = fopen("tmp_file.txt", "r");
        FILE *divisible_by4 = fopen("divisible_by4.txt", "w+");
        summator = 0;
        fseek(reding_with_days, -1, SEEK_END);
        current = 1;
        while (ftell(reding_with_days) > 0) {
            current = fgetc(reding_with_days);
            if (ftell(reding_with_days) > 0) {
                fprintf(divisible_by4, "%d", (current - '0' + summator) / 4);
                summator = (current - '0' + summator) % 4 * 10;
            }
            fseek(reding_with_days, ftell(reding_with_days) - 2, SEEK_SET);
        }//поделил на 4
        current = fgetc(reding_with_days);
        fprintf(divisible_by4, "%d", (current - '0' + summator) / 4);
        fclose(reding_with_days);
        fclose(divisible_by4);
        FILE *reading_with_days = fopen("divisible_by4.txt", "r");
        FILE *divided_by4 = fopen("divided_by4_reversed.txt", "w+");
        fseek(reading_with_days, -1, SEEK_END);
        current = 1;
        while (ftell(reading_with_days) > 0) {
            current = fgetc(reading_with_days);
            if (ftell(reading_with_days) > 0) {
                fprintf(divided_by4, "%c", current);
            }
            fseek(reading_with_days, ftell(reading_with_days) - 2, SEEK_SET);
        }
        current = fgetc(reading_with_days);
        if (current != '0') {
            fprintf(divided_by4, "%c", current);
        }
        fclose(reading_with_days);
        fclose(divided_by4);
        FILE *visok = fopen("visok.txt", "w+");
        FILE *with_days_again = fopen("with_days.txt", "r");
        FILE *reversed_division = fopen("divided_by4_reversed.txt", "r");
        summator = 0;
        current = 1;
        char tmp;
        while (current != EOF) {
            current = getc(reversed_division);
            tmp = getc(with_days_again);
            if (current != EOF) {
                fprintf(visok, "%d", (current - '0' + tmp - '0' + summator) % 10);
                summator = (current - '0' + tmp - '0' + summator) / 10;
            }
        }
        do {
            if (tmp != EOF) {
                fprintf(visok, "%d", (tmp - '0' + summator) % 10);
                summator = (tmp - '0' + summator) / 10;
            }
            tmp = getc(with_days_again);
        } while (tmp != EOF);
        while (summator > 0) {
            fprintf(visok, "%d", summator % 10);
            summator /= 10;
        }
        fclose(visok);
        fclose(with_days_again);
        fclose(reversed_division);
        if (*year_pointer % 4 == 0 && *month_pointer > 2) {
            FILE *visok_again = fopen("visok.txt", "r");
            FILE *final = fopen("final.txt", "w+");
            current = fgetc(visok_again);
            fprintf(final, "%d", (current - '0' + 1) % 10);
            summator = (current - '0' + 1) / 10;
            while (current != EOF) {
                current = fgetc(visok_again);
                if (current != EOF) {
                    fprintf(final, "%d", (current - '0' + summator) % 10);
                    summator = (current - '0' + summator) / 10;
                }
            }
            while (summator > 0) {
                fprintf(final, "%d", summator % 10);
                summator /= 10;
            }
            fclose(visok_again);
            fclose(final);
            remove("visok.txt");
        } else {
            remove("final.txt");
            rename("visok.txt", "final.txt");
        }
        remove("divided_by4_reversed.txt");
        remove("divisible_by4.txt");
        remove("tmp_file.txt");
        remove("with_days.txt");
    }
}

int divisible_by7() {
    FILE *reader = fopen("final.txt", "r");
    fseek(reader, -1, SEEK_END);
    int summator = 0;
    while (ftell(reader) > 0) {
        summator = (summator * 10 + fgetc(reader) - '0') % 7;
        fseek(reader, ftell(reader) - 2, SEEK_SET);
    }
    summator = (summator * 10 + fgetc(reader) - '0') % 7;
    fclose(reader);
    return summator;
}

int main() {
    int day = 0, month = 0, year = 0;
    while (1) {
        char option = 0;
        printf("1 - input date as dd mm year\n");
        printf("2 - output date as dd month year\n");
        printf("3 - output date as dd.mm.year.\n");
        printf("4 - calculate the number of the day && day of week\n");
        printf("5 - calculate the day from CB\n");
        printf("6 - output the information\n");
        printf("7 - exit\n");
        scanf("%c", &option);
        char tmp;
        scanf("%c", &tmp);
        switch (option - '0') {
            case 1: {
                in(&day, &month, &year);
                break;
            }
            case 2: {
                FILE *fp = fopen(name_in, "r");
                if (fp == NULL) {
                    printf("u did not input a date\n");
                } else {
                    printf("%d %s ", day, months[month - 1]);
                    fseek(fp, 6, SEEK_SET);
                    char current = 1;
                    while ((current = getc(fp)) != EOF) {
                        printf("%c", current);
                    }
                }
                fclose(fp);
                break;
            }
            case 3: {
                FILE *fp = fopen(name_in, "r");
                if (fp == NULL) {
                    printf("u did not input a date\n");
                } else {
                    fseek(fp, 0, SEEK_END);
                    fseek(fp, ftell(fp) - 4, SEEK_SET);
                    char current = (char)fgetc(fp);
                    printf("%d.%d.%c%c.\n", day, month, current, fgetc(fp));
                }
                fclose(fp);
                break;
            }
            case 4: {
                FILE *fp = fopen(name_in, "r");
                if (fp == NULL) {
                    printf("u did not input a date\n");
                } else {
                    int summator = 0, i = 0;
                    for (; i < month - 1; ++i) {
                        summator += date[i];
                    }
                    summator += day;
                    if (year % 4 == 0 && month > 2) {
                        summator++;
                    }
                    printf("%d day of the year and it is %s\n", summator, days[divisible_by7()]);
                }
                fclose(fp);
                break;
            }
            case 5: {
                FILE *fp = fopen(name_in, "r");
                if (fp == NULL) {
                    printf("u did not input a date\n");
                } else {
                    FILE *reader = fopen("final.txt", "r");
                    fseek(reader, -1, SEEK_END);
                    while (ftell(reader) > 0) {
                        printf("%c", fgetc(reader));
                        fseek(reader, ftell(reader) - 2, SEEK_SET);
                    }
                    printf("%c days from CB\n", fgetc(reader));
                    fclose(reader);
                }
                fclose(fp);
                break;
            }
            case 6:
                printf("version - 3.1, author - Voiteshonok\n");
                break;
            case 7:
                remove(name_in);
                remove("final.txt");
                return 0;
            default:
                printf("inappropriate input try again\n");
        }
    }
}
