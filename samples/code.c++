#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct three
{
    char data[10];
    char temp[7];
} s[30];

int main()
{
    char d1[7], d2[7] = "t";
    int i = 0, j = 1, len = 0;
    FILE *fl, *f2;

    fl = fopen("sum.txt", "r");
    f2 = fopen("out.txt", "w");

    while (fscanf(fl, "%s", s[len].data) != EOF)
        len++;

    snprintf(d1, sizeof(d1), "%d", j); // Replace sprintf(d1, "%d", j);
    strcat(d2, d1);
    strcpy(s[j].temp, d2);
    strcpy(d1, "");
    strcpy(d2, "t");

    if (!strcmp(s[3].data, "+"))
    {
        fprintf(f2, "%s=%s+%s", s[j].temp, s[i + 2].data, s[i + 4].data);
        j++;
    }
    else if (!strcmp(s[3].data, "-"))
    {
        fprintf(f2, "%s=%s-%s", s[j].temp, s[i + 2].data, s[i + 4].data);
        j++;
    }

    for (i = 4; i < len - 2; i += 2)
    {
        snprintf(d1, sizeof(d1), "%d", j); // Replace sprintf(d1, "%d", j);
        strcat(d2, d1);
        strcpy(s[j].temp, d2);
        if (!strcmp(s[i + 1].data, "+"))
        {
            fprintf(f2, "\n%s=%s+%s", s[j].temp, s[j - 1].temp, s[i + 2].data);
        }
        else if (!strcmp(s[i + 1].data, "-"))
        {
            fprintf(f2, "\n%s=%s-%s", s[j].temp, s[j - 1].temp, s[i + 2].data);
        }
        strcpy(d1, "");
        strcpy(d2, "t");
        j++;
    }

    fprintf(f2, "\n%s=%s", s[0].data, s[j - 1].temp);
    fclose(fl);
    fclose(f2);

    return 0;
}
