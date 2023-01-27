#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    char t[30];
    char tFormat[25] = "[%Y.%m.%d %H:%M.%S]";
    time_t time_s;
    FILE* log = fopen("log.txt", "a");
    time(&time_s);
    strftime(t, sizeof(t), tFormat, localtime(&time_s));
    fprintf(log, "%s Program started.\n", t);

    char file_values[100] = " ", file_out[100] = " ";
    double x, u;
    printf("Enter the name or path of values: ");
    scanf("%s", file_values);
    FILE* val = fopen(file_values, "r");

    if (val != NULL) {
        fread(&x, sizeof(double), 1, val);
        time(&time_s);
        strftime(t, sizeof(t), tFormat, localtime(&time_s));
        fprintf(log, "%s File '%s' have been opened x = %.2lf.\n", t, file_values, x);
        fclose(val);
    }
    else {
        printf("Cant open your file");
        time(&time_s);
        strftime(t, sizeof(t), tFormat, localtime(&time_s));
        fprintf(log, "%s Can't open file '%s'\n", t, file_values);
    }

    u = sin(x) + cos(x);
    time(&time_s);
    strftime(t, sizeof(t), tFormat, localtime(&time_s));
    fprintf(log, "%s Expression calculated. Result = %lf\n", t, u);

    printf("Enter the name of file with format(name.txt or name.bin): ");
    scanf("%s", file_out);
    FILE* out = fopen(file_out, "w");
    char* text = strstr(file_out, "txt");
    char* binar = strstr(file_out, "bin");

    if (out != NULL)
    {
        if (binar != NULL)
        {
            fwrite(&u, sizeof(double), 1, out);
        }
        else if (text != NULL)
        {
            fprintf(out, "%lf", u);
        }

        fclose(out);
        time(&time_s);
        strftime(t, sizeof(t), tFormat, localtime(&time_s));
        fprintf(log, "%s Output file \"%s\" saved.\n", t, file_out);
    }
    else
    {
        printf("Cant open your file");
        time(&time_s);
        strftime(t, sizeof(t), tFormat, localtime(&time_s));
        fprintf(log, "%s Cant open file.\n", t);
    }

    time(&time_s);
    strftime(t, sizeof(t), tFormat, localtime(&time_s));
    fprintf(log, "%s Program ended.\n", t);
    fprintf(log, "\n");
    fclose(log);

    printf("File saved.\n");

    return 0;
}