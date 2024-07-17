// -----------------------------------main.c -------------------------------------

#include "uart.h"
#include "mbox.h"

// color define for text
#define BLACK "\033[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PURPLE "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
// color define for background
#define BBLACK "\033[40m"
#define BRED "\x1b[41m"
#define BGREEN "\x1b[42m"
#define BYELLOW "\033[103m"
#define BBLUE "\x1b[44m"
#define BPURPLE "\033[105m"
#define BCYAN "\x1b[46m"
#define BWHITE "\033[107m"
// command define
#define SETCOLOR "setcolor"
#define HELP "help"
#define CLEAR "clear"
#define SHOWINFO "showinfo"
#define MAX_CMD_SIZE 100
#define OS_NAME "Dong_A2"

#define COMMANDS_SIZE 9 // for tab function
char *commands[] = {"help", "clear", "setcolor", "showinfo", "baudrate", "databit", "stopbit", "parity", "handshaking"};
char *history[100][100];
static int historyList = 0;
static int currentHistoryList = 0;
static int doubleMatch = 0;
static int doubleLock = 0;

//-------------------------------------------------------------------------------------------

char *tabHandler(char *cli_buffer, int currentMatch)
{
    int i, x;
    int numCompletions = 0;
    int lastMatchingIndex = -1;
    int partialLength = cus_strlen(cli_buffer);
    char *doubleMatch[] = {"setcolor", "showinfo"};
    for (i = 0; i < COMMANDS_SIZE; ++i)
    {
        int commandLength = 0;

        while (commands[i][commandLength] != '\0' && cli_buffer[commandLength] != '\0' && commands[i][commandLength] == cli_buffer[commandLength])
        {
            ++commandLength;
            if (cli_buffer[commandLength] == '\0')
            {
                numCompletions++;
                lastMatchingIndex = i;
            }
        }
    }

    if (numCompletions == 1 && doubleLock == 0)
    {
        return commands[lastMatchingIndex];
    }
    else if (numCompletions > 1 || doubleLock == 1) // more than 1 matches
    {
        doubleLock = 1;
        return doubleMatch[currentMatch];
    }
    // Return an empty string if no completion or multiple completions
    cli_buffer[0] = '\0';
    return "";
}

void printmacaddress(const unsigned char *mac)
{
    for (int i = 6; i >= 0; i--)
    {
        uart_dec(mac[i] % 16); // Print last digit
        uart_dec(mac[i] / 16); // Print second last digit
        if (i > 0)
        {
            uart_puts("-");
        }
    }
}
void printBoardRevision(const unsigned int *mac)
{
    if (mac = 0x00A02082)
    {
        uart_puts("Pi 3 Model B (1.2)");
    }
    else if (mac = 0x00900092)
    {
        uart_puts("Pi Zero v1.2 (1.2)");
    }
    else if (mac = 0x00000010)
    {
        uart_puts("Model B+");
    }
    else if (mac = 0x00a01041)
    {
        uart_puts("Pi 2 Model B v1.1");
    }
    else
    {
        uart_puts("Pi 4B");
    }
}
void cus_strcpy(char *dest, const char *src)
{
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int cus_strlen(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
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

int str_to_int(char *str)
{
    int res = 0;  // Initialize result
    int sign = 1; // Initialize sign as positive
    int i = 0;    // Initialize index of first digit

    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;
        i++; // Also update index of first digit
    }

    // Iterate through all digits and update the result
    for (; str[i] != '\0'; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return -1; // return -1 when non-digit character is encountered
        }
        res = res * 10 + str[i] - '0';
    }

    // Return result with sign
    return sign * res;
}

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
    else if (cus_strcmp(color, "black") == 0)
    {
        current_color = BLACK;
    }
    else
    {
        uart_puts("\u274CWarning: Invalid color, please use red, green, yellow, blue, purple, cyan, or white.\n");
    }
}

char *current_BG_color = " ";
void set_BG_color(char *color)
{
    if (cus_strcmp(color, "red") == 0)
    {
        current_color = BRED;
    }
    else if (cus_strcmp(color, "green") == 0)
    {
        current_color = BGREEN;
    }
    else if (cus_strcmp(color, "yellow") == 0)
    {
        current_color = BYELLOW;
    }
    else if (cus_strcmp(color, "blue") == 0)
    {
        current_color = BBLUE;
    }
    else if (cus_strcmp(color, "purple") == 0)
    {
        current_color = BPURPLE;
    }
    else if (cus_strcmp(color, "cyan") == 0)
    {
        current_color = BCYAN;
    }
    else if (cus_strcmp(color, "white") == 0)
    {
        current_color = BWHITE;
    }
    else if (cus_strcmp(color, "black") == 0)
    {
        current_color = BBLACK;
    }
    else
    {
        uart_puts("\u274CWarning: Invalid color, please use red, green, yellow, blue, purple, cyan, or white.\n");
    }
}

//-------------------------------------------------------------------------------------------

void cli()
{
    static char cli_buffer[MAX_CMD_SIZE];
    static int index = 0;

    // read and send back each char
    char c = uart_getc();

    if (c != '\b' && c != 95 && c != 43)
    {
        uart_sendc(c);
    }
    // put into a buffer until got new line character
    if (c != '\n' && c != '\b' && c != '\t' && c != 95 && c != 43)
    {                          // replace 127 with '\b' if using Window
        cli_buffer[index] = c; // Store into the buffer
        index++;
        // send c here to avoid tab appear
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
    //----------------------------------------------------------------------------
    else if (c == '\t') // tab function
    {
        doubleMatch = doubleMatch ^ 1;

        if (index < 7) // try to delete all of the space when tabbing
        {
            for (int i = 0; i < 7 - index; i++)
            {
                uart_puts("\b \b"); // move back input space and move back
            }
        }
        if (index >= 7) // if more than 7 index it will use the function below to delete
        {
            for (int i = 0; i <= 7 - (index - 7); i++)
            {
                uart_puts("\b \b");
            }
        }
        if (doubleLock == 1)
        {
            for (int i = 1; i < index; i++)
            {
                cli_buffer[i] = '\0';
            }
        }
        char *completedCommand = tabHandler(cli_buffer, doubleMatch);
        if (*completedCommand != '\0')
        {
            for (int i = 0; i < index; i++) // loops to delete out all output onscreen in order to replace it with completed command
            {
                uart_puts("\b \b");
            }
            uart_puts(completedCommand);
            cli_buffer[0] = '\0';
            index = cus_strlen(completedCommand);
            cus_strcpy(cli_buffer, completedCommand);
        }
    }
    //----------------------------------------------------------------------------
    if (c == 95)
    {
        if (currentHistoryList <= 0)
        {
            return;
        }
        currentHistoryList--;
        for (int i = 0; i < index; i++)
        {
            uart_puts("\b \b");
        }
        cus_strcpy(cli_buffer, history[currentHistoryList]);
        index = cus_strlen(cli_buffer);
        uart_puts(history[currentHistoryList]);
    }
    if (c == 43)
    {

        if (currentHistoryList > historyList)
        {
            return;
        }
        currentHistoryList++;
        for (int i = 0; i < index; i++)
        {
            uart_puts("\b \b");
        }
        cus_strcpy(cli_buffer, history[currentHistoryList]);
        index = cus_strlen(cli_buffer);
        uart_puts(history[currentHistoryList]);
    }
    else if (c == '\n')
    {
        doubleLock = 0;
        uart_puts("\nGot commands: ");
        uart_puts(cli_buffer);

        cus_strcpy(history[historyList], cli_buffer);
        historyList++;
        currentHistoryList = historyList;
        cli_buffer[index] = '\0';

        /* Compare with supported commands and execute
         * ........................................... */
        char *token = cus_strtok(cli_buffer, " ");
        if (*token != '\0')
        {
            if (cus_strcmp(token, SETCOLOR) == 0)
            { // if input is setcolor command
                // while (token != '\0') {
                char *flag = cus_strtok("\0", " "); // works

                uart_puts("\n");
                if (cus_strcmp(flag, "-t") == 0)
                {
                    char *color = cus_strtok("\0", " "); // Extract color name
                    char *error = cus_strtok("\0", " "); // excess checking (ERROR HANDLING)
                    if (error != 0)
                    {
                        uart_puts("\u274CInvalid command: ");
                        uart_puts(error);
                        uart_puts("\n");
                    }
                    else
                    {
                        setcolor(color);
                    }
                }
                else if (cus_strcmp(flag, "-b") == 0)
                {
                    char *color = cus_strtok("\0", " "); // Extract color name
                    set_BG_color(color);
                }
                //}
            }
            else if (cus_strcmp(token, CLEAR) == 0)
            {
                uart_puts("\033[H\033[2J");
            }
            else if (cus_strcmp(token, HELP) == 0)
            {
                char *secondToken = cus_strtok("\0", " ");
                if (secondToken != 0)
                {
                    if (cus_strcmp(secondToken, "help") == 0)
                    {
                        uart_puts("\n*-------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                          |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                        uart_puts("|  help                  | - Show brief information of 9 commands.        |\n");
                        uart_puts("|                        | - Examples:                                    |\n");
                        uart_puts("|                        |   MyOS> help                                   |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                        uart_puts("|  help <command_name>   | - Show full information of a specific command  |\n");
                        uart_puts("|                        | if user type: help <command_name>              |\n");
                        uart_puts("|                        | - Examples:                                    |\n");
                        uart_puts("|                        |   MyOS> clear <command_name>                   |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "clear") == 0)
                    {
                        uart_puts("\n*--------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                           |\n");
                        uart_puts("*--------------------------------------------------------------------------*\n");
                        uart_puts("|  clear                 | - clear screen and move the cursor to the home  |\n");
                        uart_puts("|                        | position (top-left corner).                     |\n");
                        uart_puts("|                        | - Examples:                                     |\n");
                        uart_puts("|                        |   MyOS> clear                                   |\n");
                        uart_puts("*--------------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "setcolor") == 0)
                    {
                        uart_puts("\n*-----------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                              |\n");
                        uart_puts("*-----------------------------------------------------------------------------*\n");
                        uart_puts("| setcolor               | - Set text color, and/or background color of the   |\n");
                        uart_puts("| -t <text_color>        | console to one of the following colors: black, red |\n");
                        uart_puts("| -b <background_color>  | green, yellow, blue, purple, cyan, white           |\n");
                        uart_puts("|                        | - Examples:                                        |\n");
                        uart_puts("|                        |   MyOS> setcolor -t yellow                         |\n");
                        uart_puts("|                        |   MyOS> setcolor -b yellow -t white                |\n");
                        uart_puts("*-----------------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "showinfo") == 0)
                    {
                        uart_puts("\n*--------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                           |\n");
                        uart_puts("*--------------------------------------------------------------------------*\n");
                        uart_puts("| showinfo               | - Show board revision and board MAC address in  |\n");
                        uart_puts("|                        | correct format/ meaningful information          |\n");
                        uart_puts("|                        | - Examples:                                     |\n");
                        uart_puts("|                        |   MyOS> showinfo                                |\n");
                        uart_puts("*--------------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "baudrate") == 0)
                    {
                        uart_puts("\n*----------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                       |\n");
                        uart_puts("*----------------------------------------------------------------------*\n");
                        uart_puts("| baudrate               | - Configurable UART0 Baud Rate              |\n");
                        uart_puts("|                        | - Examples:                                 |\n");
                        uart_puts("|                        |   MyOS> baudrate                            |\n");
                        uart_puts("|                        |   Enter baudrate: 115200                    |\n");
                        uart_puts("*----------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "databit") == 0)
                    {
                        uart_puts("\n*----------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                       |\n");
                        uart_puts("*----------------------------------------------------------------------*\n");
                        uart_puts("| databit                | - Support for configuring the number of     |\n");
                        uart_puts("|                        | data bits (5, 6, 7, or 8).                  |\n");
                        uart_puts("|                        | - Examples:                                 |\n");
                        uart_puts("|                        |   MyOS> databit                             |\n");
                        uart_puts("|                        |   Enter data bit (5,6,7,8): 8               |\n");
                        uart_puts("*----------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "stopbit") == 0)
                    {
                        uart_puts("\n*-----------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                        |\n");
                        uart_puts("*-----------------------------------------------------------------------*\n");
                        uart_puts("| stopbit                | - Ability to select between one or two stop  |\n");
                        uart_puts("|                        | bits.                                        |\n");
                        uart_puts("|                        | - Examples:                                  |\n");
                        uart_puts("|                        |   MyOS> stopbit                              |\n");
                        uart_puts("|                        |   Enter stop bit (1,2): 2                    |\n");
                        uart_puts("*-----------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "parity") == 0)
                    {
                        uart_puts("\n*-------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                          |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                        uart_puts("| parity                 | - Support for none, even, and odd parity       |\n");
                        uart_puts("|                        | configurations.                                |\n");
                        uart_puts("|                        | - Examples:                                    |\n");
                        uart_puts("|                        |   MyOS> parity                                 |\n");
                        uart_puts("|                        |   Enter parity choice (none, even, odd): none  |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                    }
                    else if (cus_strcmp(secondToken, "handshaking") == 0)
                    {
                        uart_puts("\n*-------------------------------------------------------------------------*\n");
                        uart_puts("| Command Name           | Usage                                          |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                        uart_puts("| handshaking            | - CTS/RTS handshaking.                         |\n");
                        uart_puts("|                        | - Examples:                                    |\n");
                        uart_puts("|                        |   MyOS> handshaking                            |\n");
                        uart_puts("|                        |   Handshaking mode (none, enable): none        |\n");
                        uart_puts("*-------------------------------------------------------------------------*\n");
                    }
                    else
                    {
                        uart_puts("error");
                    }
                }
                else
                {
                    uart_puts("\n*-----------------------------------------------------------------------------*\n");
                    uart_puts("| No. | Command Name         | Usage                                          |\n");
                    uart_puts("*-----------------------------------------------------------------------------*\n");
                    uart_puts("| 1.  | help                 | - Show brief information of all commands       |\n");
                    uart_puts("|     | help <command_name>  | - Show full information of the command         |\n");
                    uart_puts("| 2.  | clear                | - Clear screen                                 |\n");
                    uart_puts("| 3.  | setcolor             | - Set text and/or background color: red, black |\n");
                    uart_puts("|     |                      | green, yellow, blue, purple, cyan, white       |\n");
                    uart_puts("| 4.  | showinfo             | - Show board revision and MAC address          |\n");
                    uart_puts("*-----------------------------------------------------------------------------*\n");
                }
            }
            else if (cus_strcmp(token, "showinfo") == 0)
            {
                mBuf[0] = 11 * 4;       // Message Buffer Size in bytes (22 elements * 4 bytes (32 bit) each)
                mBuf[1] = MBOX_REQUEST; // Message Request Code (this is a request message)

                mBuf[2] = 0x00010002; // TAG Identifier: Get board revision
                mBuf[3] = 4;          // Value buffer size in bytes (max of request and response lengths)
                mBuf[4] = 0;          // REQUEST CODE = 0
                mBuf[5] = 0;          // clear output buffer (response data are mBuf[5])

                mBuf[6] = 0x00010003; // TAG Identifier: Get board MAC address
                mBuf[7] = 4;          // Value buffer size in bytes (max of request and response lengths)
                mBuf[8] = 0;          // REQUEST CODE = 0
                mBuf[9] = 0;          // clear output buffer (response data are mBuf[9])

                mBuf[10] = MBOX_TAG_LAST;
                // Note: Board model and Board serial may give 0 values on QEMU.
                if (mbox_call(ADDR(mBuf), MBOX_CH_PROP))
                {
                    uart_puts("\n*-----------------------------------------------*");
                    uart_puts("\n| Board Revision: ");
                    // if (cus_strcmp(mBuf[5], "0x00A02082") == 0) {
                    //     uart_puts ("Pi 3 Model B");
                    // }
                    printBoardRevision(&mBuf[5]);
                    uart_puts("            |");
                    uart_puts("\n| Board MAC Address: ");
                    printmacaddress((unsigned char *)&mBuf[9]);
                    uart_puts("       |");
                    uart_puts("\n*-----------------------------------------------*\n\n");
                }
                else
                {
                    uart_puts("Unable to query!\n");
                }
            }
            // else if (cus_strcmp(token, "baudrate") == 0)
            // {
            //     uart_puts("\nEnter baudrate: ");
            //     static char baud_buffer[10];
            //     static int baud_index = 0;
            //     static char baud_char;
            //     do
            //     {
            //         baud_char = uart_getc();
            //         uart_sendc(baud_char); // echo the character
            //         if (baud_char != '\n' && baud_char != '\r')
            //         {
            //             baud_buffer[baud_index] = baud_char;
            //             baud_index++;
            //         }
            //     } while (baud_char != '\n' && baud_char != '\r' && baud_index < sizeof(baud_buffer) - 1);
            //     baud_buffer[baud_index] = '\0';         // null-terminate the string
            //     int baudrate = str_to_int(baud_buffer); // convert string to integer
            //     uart_puts("-----------------------");
            //     // uart_puts("\nBaudrate set to: ");
            //     // uart_dec(baudrate); // print the baudrate

            //     uart_puts("\nIBRD before baudrate configuration: ");
            //     uart_hex(UART0_IBRD); // print the IBRD (it should be UART0_IBRD)
            //     uart_puts("\nFBRD before baudrate configuration: ");
            //     uart_hex(UART0_FBRD); // print the FBRD

            //     configure_baudrate(baudrate);
            //     uart_puts("\nIBRD after baudrate configuration: ");
            //     uart_hex(UART0_IBRD); // print the IBRD (it should be UART0_IBRD)
            //     uart_puts("\nFBRD after baudrate configuration: ");
            //     uart_hex(UART0_FBRD); // print the FBRD
            //     uart_puts("\n");
            //     uart_puts("-----------------------\n");

            //     for (int i = 0; i < 10; i++)
            //     { // reset buffer
            //         baud_buffer[i] = 0;
            //     }
            //     baud_index = 0;
            // }
            // else if (cus_strcmp(token, "databit") == 0)
            // {
            //     uart_puts("\nEnter data bit (5,6,7,8): ");
            //     static char databit_buffer[2]; // Increase buffer size to 2
            //     static int databit_index = 0;
            //     static char databit_char;
            //     do
            //     {
            //         databit_char = uart_getc();
            //         if (databit_char != '\n' && databit_char != '\r')
            //         {
            //             uart_sendc(databit_char); // echo the character
            //             databit_buffer[databit_index] = databit_char;
            //             databit_index++;
            //         }
            //     } while (databit_char != '\n' && databit_char != '\r' && databit_index < sizeof(databit_buffer) - 1);
            //     databit_buffer[databit_index] = '\0';     // null-terminate the string
            //     int databit = str_to_int(databit_buffer); // convert string to integer
            //     if (databit != 5 && databit != 6 && databit != 7 && databit != 8)
            //     {
            //         uart_puts("\n\u274CWarning: You entered a number other than 5, 6, 7, or 8.\n");
            //     }
            //     else
            //     {
            //         uart_puts("\nLCRH before data bit configuration: ");
            //         uart_hex(UART0_LCRH);
            //         configure_databits(databit);
            //         uart_puts("\nLCRH after data bit configuration: ");
            //         uart_hex(UART0_LCRH); // print the hex of FEN + WLEN in LCRH register
            //         uart_puts("\n");
            //         uart_puts("-----------------------\n");
            //     }
            //     for (int i = 0; i < 2; i++)
            //     { // reset buffer
            //         databit_buffer[i] = 0;
            //     }
            //     databit_index = 0;
            // }
            // else if (cus_strcmp(token, "stopbit") == 0)
            // {
            //     uart_puts("\nEnter stop bit (1,2): ");
            //     static char stopbit_buffer[2]; // Increase buffer size to 2
            //     static int stopbit_index = 0;
            //     static char stopbit_char;
            //     do
            //     {
            //         stopbit_char = uart_getc();
            //         if (stopbit_char != '\n' && stopbit_char != '\r')
            //         {
            //             uart_sendc(stopbit_char); // echo the character
            //             stopbit_buffer[stopbit_index] = stopbit_char;
            //             stopbit_index++;
            //         }
            //     } while (stopbit_char != '\n' && stopbit_char != '\r' && stopbit_index < sizeof(stopbit_buffer) - 1);
            //     stopbit_buffer[stopbit_index] = '\0';     // null-terminate the string
            //     int stopbit = str_to_int(stopbit_buffer); // convert string to integer
            //     uart_puts("\n-----------------------");
            //     // uart_puts("\nNumber of stop bit is set to: ");
            //     // uart_dec(stopbit); // print the baudrate

            //     // int IBRD, FBRD; ,&IBRD,&FBRD
            //     if (stopbit != 1 && stopbit != 2)
            //     {
            //         uart_puts("\n\u274CWarning: You entered a number other than 1 or 0.\n");
            //     }
            //     else
            //     {
            //         uart_puts("\nLCRH before stop bit configuration: ");
            //         uart_hex(UART0_LCRH);
            //         configure_stopbits(stopbit);
            //         uart_puts("\nLCRH after stop bit configuration: ");
            //         uart_hex(UART0_LCRH); // print the hex of FEN + WLEN in LCRH register
            //         uart_puts("\n");
            //         uart_puts("-----------------------\n");
            //     }
            //     for (int i = 0; i < 2; i++)
            //     { // reset buffer
            //         stopbit_buffer[i] = 0;
            //     }
            //     stopbit_index = 0;
            // }
            // else if (cus_strcmp(token, "parity") == 0)
            // {
            //     uart_puts("\nEnter parity choice (none, even, odd): ");
            //     static char parity_buffer[5]; // Increase buffer size to 2
            //     static int parity_index = 0;
            //     static char parity_char;
            //     do
            //     {
            //         parity_char = uart_getc();
            //         if (parity_char != '\n' && parity_char != '\r')
            //         {
            //             uart_sendc(parity_char); // echo the character
            //             parity_buffer[parity_index] = parity_char;
            //             parity_index++;
            //         }
            //     } while (parity_char != '\n' && parity_char != '\r' && parity_index < sizeof(parity_buffer) - 1);
            //     parity_buffer[parity_index] = '\0'; // null-terminate the string
            //     if (cus_strcmp(parity_buffer, "none") != 0 && cus_strcmp(parity_buffer, "odd") != 0 && cus_strcmp(parity_buffer, "even") != 0)
            //     {
            //         uart_puts("\n\u274CWarning: You entered a string other than 'none', 'yes', or 'no'.\n");
            //     }
            //     uart_puts("\n-----------------------");
            //     uart_puts("\nparity set to: ");
            //     uart_puts(parity_buffer); // print the choice
            //     // turn string choice into integer choice
            //     int parity_choice = 0;
            //     if (cus_strcmp(parity_buffer, "none") == 0)
            //     {
            //         parity_choice = 1;
            //     }
            //     else if (cus_strcmp(parity_buffer, "odd") == 0)
            //     {
            //         parity_choice = 2;
            //     }
            //     else
            //     {
            //         parity_choice = 3; // even
            //     }
            //     // put integer choice into the actual configure function
            //     uart_puts("\nLCRH before the parity configuration: ");
            //     uart_hex(UART0_LCRH);
            //     configure_parity(parity_choice);
            //     uart_puts("\nLCRH after the parity configuration: ");
            //     uart_hex(UART0_LCRH);
            //     uart_puts("\n");
            //     for (int i = 0; i < 2; i++)
            //     { // reset buffer
            //         parity_buffer[i] = 0;
            //     }
            //     parity_index = 0;
            // }
            // else if (cus_strcmp(token, "handshaking") == 0)
            // {
            //     uart_puts("\nEnter handshaking choice (none, enable): ");
            //     static char hs_buffer[7]; // Increase buffer size to 2
            //     static int hs_index = 0;
            //     static char hs_char;
            //     do
            //     {
            //         hs_char = uart_getc();
            //         if (hs_char != '\n' && hs_char != '\r')
            //         {
            //             uart_sendc(hs_char); // echo the character
            //             hs_buffer[hs_index] = hs_char;
            //             hs_index++;
            //         }
            //     } while (hs_char != '\n' && hs_char != '\r' && hs_index < sizeof(hs_buffer) - 1);
            //     hs_buffer[hs_index] = '\0'; // null-terminate the string
            //     if (cus_strcmp(hs_buffer, "none") != 0 && cus_strcmp(hs_buffer, "enable") != 0)
            //     {
            //         uart_puts("\n\u274CWarning: You entered a string other than 'none', 'enable'.\n");
            //     }
            //     uart_puts("\n-----------------------");
            //     uart_puts("\nHandshaking mode: ");
            //     uart_puts(hs_buffer); // print the choice
            //     // turn string choice into integer choice
            //     int hs_choice = 0;
            //     if (cus_strcmp(hs_buffer, "enable") == 0)
            //     {
            //         hs_choice = 1;
            //     }
            //     else
            //     {
            //         hs_choice = 0; // none
            //     }
            //     // put integer choice into the actual configure function
            //     configure_handshaking(hs_choice);
            //     uart_puts("\nCR after handshaking configuration: ");
            //     uart_hex(UART0_CR);
            //     uart_puts("\n");
            //     for (int i = 0; i < 7; i++)
            //     { // reset buffer
            //         hs_buffer[i] = 0;
            //     }
            //     hs_index = 0;
            // }
            else
            {
                uart_puts("\nUnknown command: ");
                uart_puts(token);
                uart_puts("\n");
            }
            // Return to command line
            for (int i = index; i >= 0; i--)
            {
                cli_buffer[i] = '\0';
            } //-------------------------
            index = 0;
            uart_puts(current_color);
            uart_puts(OS_NAME);
            uart_puts("> ");
        }
    }
}

//---------------------------------------------------------------------------------------------------

void main()
{
    // intitialize UART
    uart_init();
    // set text color
    uart_puts(current_color);    // textcolor
    uart_puts(current_BG_color); // background
    // Welcome message
    uart_puts(
        "\n######## ######## ######## ########  #######  ##         #######    #####\n"
        "##       ##       ##          ##    ##     ## ##    ##  ##     ##  ##   ## \n"
        "##       ##       ##          ##           ## ##    ##  ##     ## ##     ## \n"
        "######   ######   ######      ##     #######  ##    ##   ######## ##     ## \n"
        "##       ##       ##          ##    ##        #########        ## ##     ## \n"
        "##       ##       ##          ##    ##              ##  ##     ##  ##   ## \n"
        "######## ######## ########    ##    #########       ##   #######    ##### \n\n"
        "########     ###    ########  ########     #######   ###### \n"
        "##     ##   ## ##   ##     ## ##          ##     ## ##    ## \n"
        "##     ##  ##   ##  ##     ## ##          ##     ## ##    \n"
        "########  ##     ## ########  ######      ##     ##  ###### \n"
        "##     ## ######### ##   ##   ##          ##     ##       ## \n"
        "##     ## ##     ## ##    ##  ##          ##     ## ##    ## \n"
        "########  ##     ## ##     ## ########     #######   ###### \n\n"
        "	Developed by <HUYNH QUANG DONG> - <s3938006>\n\n");

    uart_puts("\n");
    uart_puts(OS_NAME);
    uart_puts("> ");
    // echo everything back
    while (1)
    {
        cli();
    }
}
