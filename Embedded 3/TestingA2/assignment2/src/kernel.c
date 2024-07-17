// -----------------------------------main.c -------------------------------------

#include "./uart/uart0.h"

// color define
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PURPLE "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

#define MAX_CMD_SIZE 100
#define OS_NAME "Dong_A2"

//-------------------------------------------------------------------------------------------

// Custom strcmp function, to compare
int cus_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

// Custom strtok function
char *cus_strtok(char *str, const char *delim)
{
    static char *p = (char *)0;
    if (*str != '\0')
        p = str;

    if (p == (char *)0 || *p == '\0')
        return (char *)0;

    char *start = p;

    while (*p != '\0')
    {
        const char *d = delim;
        while (*d != '\0')
        {
            if (*p == *d)
            {
                *p = '\0';
                ++p;
                if (*p == '\0')
                    p = (char *)0;
                return start;
            }
            ++d;
        }
        ++p;
    }

    return start;
}

//-------------------------------------------------------------------------------------------

char *current_color = BLUE;
void setcolor(char *color)
{
    if (cus_strcmp(color, "red") == 0)
    {
        current_color = RED;
    }
    else if (cus_strcmp(color, "green") == 0)
    {
        current_color = GREEN;
    }
    else if (cus_strcmp(color, "yellow") == 0)
    {
        current_color = YELLOW;
    }
    else if (cus_strcmp(color, "blue") == 0)
    {
        current_color = BLUE;
    }
    else if (cus_strcmp(color, "purple") == 0)
    {
        current_color = PURPLE;
    }
    else if (cus_strcmp(color, "cyan") == 0)
    {
        current_color = CYAN;
    }
    else if (cus_strcmp(color, "white") == 0)
    {
        current_color = WHITE;
    }
    else
    {
        uart_puts("Invalid color. Please use red, green, yellow, blue, purple, cyan, or white.\n");
    }
}

//-------------------------------------------------------------------------------------------

void cli()
{
    static char cli_buffer[MAX_CMD_SIZE];
    static int index = 0;

    // read and send back each char
    char c = uart_getc();
    uart_sendc(c);

    // put into a buffer until got new line character
    if (c != '\n' && c != 127)
    {                          // replace 127 with '\b' if using Window
        cli_buffer[index] = c; // Store into the buffer
        index++;
    }
    // DELETE FUNCTION--------
    else if (c == 127) // replace 127 with '\b' if using Window
    {
        if (index <= 0)
        {
            // uart_puts(" "); //enable this if using Window
            return;
        }
        uart_puts("\b \b");
        index--;
        cli_buffer[index] = '\0';
    }

    else if (c == '\n')
    {
        cli_buffer[index] = '\0';

        uart_puts("Got commands: ");
        uart_puts(cli_buffer);
        uart_puts("\n");

        /* Compare with supported commands and execute
         * ........................................... */
        char *token = cus_strtok(cli_buffer, " "); // works
        if (*token != '\0')
        {
            if (cus_strcmp(token, "setcolor") == 0)
            { // if input is setcolor command
                // while (token != '\0') {
                char *flag = cus_strtok("\0", " "); // works
                uart_puts("\n");
                if (cus_strcmp(flag, "-t") == 0)
                {
                    char *color = cus_strtok("\0", " "); // Extract color name
                    setcolor(color);
                }
                //}
            }
            else if (cus_strcmp(token, "clear") == 0)
            {
                uart_puts("\033[H\033[2J");
            }

            else if (cus_strcmp(token, "help") == 0)
            {
                uart_puts("\nhelp:                     - Show brief information of all commands");
                uart_puts("\nhelp <command_name>       - Show full information of the command");
                uart_puts("\nclear                     - Clear screen (in our terminal it will scroll down to currentposition of the cursor).");
                uart_puts("\nsetcolor                  - Set text color, and/or background color of the console to one of the following colors: BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE");
                uart_puts("\n-t <text color> \n-b <background color>");
                uart_puts("\nshowinfo                  - Show board revision and board MAC address in correct format/ meaningful information\n");
            }
            else
            {
                uart_puts("Unknown command: ");
                uart_puts(token);
                uart_puts("\n");
            }

            // Return to command line
            index = 0;
            uart_puts(current_color);
            uart_puts(OS_NAME);
            uart_puts("> ");
        }
    }
}

//-------------------------------------------------------------------------------------------

void main()
{
    // intitialize UART
    uart_init();
    // set text color
    uart_puts(current_color);
    // Welcome message
    uart_puts("\n##     ## ######## ##       ##        #######\n"
              "##     ## ##       ##       ##       ##     ## \n"
              "##     ## ##       ##       ##       ##     ## \n"
              "######### ######   ##       ##       ##     ## \n"
              "##     ## ##       ##       ##       ##     ## \n"
              "##     ## ##       ##       ##       ##     ## \n"
              "##     ## ######## ######## ########  ####### \n\n"
              "	Developed by <HUYNH QUANG DONG> - <s3938006>\n\n"
              "	README: change your keyboard to English\n"
              "	README: replace 127 with '\\b' if using Window + enable uart_puts("
              ");\n");
    uart_puts("\n");
    uart_puts(OS_NAME);
    uart_puts("> ");

    // echo everything back
    while (1)
    {
        // //read each char
        // char c = uart_getc();

        // //send back twice
        // uart_sendc(c);
        // uart_sendc(c);
        cli();
    }
}