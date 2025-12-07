#include <stdio.h>

#include "funcs.h"

int main(void)
{
    while (1)
    {
        printf("\nMini File Editor\n"
               "1) Create new file\n"
               "2) Append to file\n"
               "3) Read file\n"
               "4) Exit\n"
               "choose: ");

        char choice = getchar();
        while (getchar() != '\n'); // flush

        switch (choice)
        {
        case '1':
            op("w", "Create");
            break;
        case '2':
            op("a", "Append");
            break;
        case '3':
            op("r", "Read");
            break;
        case '4':
            log_action("Exiting editor");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
