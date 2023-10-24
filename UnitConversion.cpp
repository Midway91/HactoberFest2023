#include <stdio.h>

int main(int argc, char const *argv[])
{
    char howdoyoudo;
    int menu;
    int num, value;
    float why;
    char option;

main_menu:
    fflush(stdin);

    printf("CHOOSE THE TYPE OF UNIT YOU WANT TO CONVERT\n");
    printf("\n A. lenght\n B. time\n C. mass\n D. temperature\n E. volume\n F. Exit the program\n");
    printf("enter respective option\a \n");
    scanf("%c", &option);

    switch (option)
    {
    case 'A':
    case 'a':
        printf("choose RESPECTIVE conversion unit \n\a");
    lenght_menu:
    fflush(stdin);
        printf("1.kilometer into meter\n2. milimeter to meter\n3. meter in foot\n4. foot to centimeter\n");
        printf("5.kilometer to centimeter\n6.milimeter to kilometer\n7.foot to meter\n8.foot to inches\n0.to exit program\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in m is %d\n", value * 1000);

            goto C1;
            break;
        case 2:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in mm is %f\n", why / 1000);
            goto C1;

            break;
        case 3:

            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in foot is %f\n", value * 3.28);
            goto C1;
            break;
        case 4:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in cm is %f\n", value * 30.28);
            goto C1;

            break;
        case 5:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in cm is %d\n", value * 1000);
            goto C1;

            break;
        case 6:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in kilometer is %f\n", value / 10000);
            goto C1;

            break;
        case 7:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in meter is %f\n", value * 0.3028);
            goto C1;
            break;
        case 8:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in inches is %d\n", value * 12);
            goto C1;
            break;
        case 0: 
            goto exit;
            break;

        default:
            printf("choose only from below statement\n");
            goto lenght_menu;
            break;

        C1:
        fflush(stdin);
            printf("\n");
            printf("Enter where you want to go\n1.To lenght menu\n2.To main menu\n3.To exit program\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 2:
                goto main_menu;
                break;

            case 1:
                goto lenght_menu;
                break;
                break;
            case 3:
                goto exit;
                break;
            default:
                goto C1;
                break;
            }
            break;
        }

    case 'b':
    case 'B':
        printf("choose RESPECTIVE conversion unit \n\a");
    time_menu:
    fflush(stdin);
        printf("1. hours to seconds\n2. minutes to seconds\n3. seconds to minutes\n4. seconds to hours\n0. To exit program\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in sec is %f\n", why * 3600);

            goto c2;
            break;
        case 2:

            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in sec is %d\n", value * 60);

            goto c2;
            break;
        case 3:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in minutes is %f\n", why / 60);
            goto c2;
            break;
        case 4:
            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in hours is %f\n", why / 3600);

            goto c2;
            break;
        case 0: 
            goto exit;
            break;
        default:
            printf("choose only from below statement\n");
            goto time_menu;
            break;

        c2:
        fflush(stdin);
            printf("Enter where you want to go\n1.To time menu\n2.To main menu\n3.To exit program\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 2:
                goto main_menu;
                break;

            case 1:
                goto time_menu;
                break;
                break;
            case 3:
                goto exit;
                break;
            default:
                goto c2;
                break;
            }
            break;
        }

    case 'c':
    case 'C':
        printf("choose RESPECTIVE conversion unit \n\a");
    mass_menu:
    fflush(stdin);
        printf("1. kilogram to gram\n2. gram to kilogram\n3. kilogram to pound\n4. pound to kilogram\n5. tonne to kg\n0. to exit program\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in gm is %d\n", value * 1000);
            goto c3;

            break;
        case 2:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in kg is %f\n", why / 1000);

            goto c3;
            break;
        case 3:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in pound is %f\n", value * 2.204);
            goto c3;

            break;
        case 4:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in kg is %f\n", value * 0.4535);
            goto c3;

            break;
        case 5:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in kg is %d\n", value * 1000);
            goto c3;

            break;
        case 0: 
            goto exit;
            break;
        default:
            printf("choose only from below statement\n");
            goto mass_menu;
            break;

        c3:
        fflush(stdin);
            printf("Enter where you want to go\n1.To mass menu\n2.To main menu\n3.To exit program\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 2:
                goto main_menu;
                break;

            case 1:
                goto mass_menu;
                break;
                break;
            case 3:
                goto exit;
                break;
            default:
                goto c3;
                break;
            }

            break;
        }

    case 'd':
    case 'D':
        printf("choose RESPECTIVE conversion unit \n\a");
    temperature_menu:
    fflush(stdin);
        printf("1. celcius to kelvin\n2. celcius to fahrenheit\n3. fahrenhiet to celcius\n0. to exit program\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in k is %f\n", value + 273.15);
            goto c4;

            break;
        case 2:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in f is %f\n", (why * 9 / 5) + 32);
            goto c4;

            break;
        case 3:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in c is %f\n", (why - 32) * 5 / 9);
            goto c4;
            break;
        case 0: 
            goto exit;
            break;

        default:
            printf("choose only from below statement\n");
            goto temperature_menu;
            break;

        c4:
        fflush(stdin);
            printf("Enter where you want to go\n1.To temperature menu\n2.To main menu\n3.To exit program");
            scanf("%d", &menu);
            switch (menu)
            {
            case 2:
                goto main_menu;
                break;

            case 1:
                goto temperature_menu;
                break;
                break;
            case 3:
                goto exit;
                break;
            default:
                goto c4;
                break;
            }

            break;
        }
    case 'e':
    case 'E':
        printf("choose RESPECTIVE conversion unit \n\a");
    volume_menu:
    fflush(stdin);
        printf("1. meter^3 to feet^3\n2. cm^3 to meter^3\n3. meter^3  to liter\n0. to exit program\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in feet^3 is %f\n", why * 35.31);
            goto c5;

            break;
        case 2:

            printf("enter value\n");
            scanf("%f", &why);
            printf("you have entered your value for conversion\n");

            printf("your value in m^3 is %f\n", why / 1000000);
            goto c5;

            break;
        case 3:

            printf("enter value\n");
            scanf("%d", &value);
            printf("you have entered your value for conversion\n");

            printf("your value in liter is %d\n", value * 1000);
            goto c5;
            break;
        case 0: 
            goto exit;
            break;
        default:
            printf("choose only from below statement\n");
            goto volume_menu;
            break;

        c5:
        fflush(stdin);
            printf("Enter where you want to go\n1.To volume menu\n2.To main menu\n3.To exit program\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 2:
                goto main_menu;
                break;

            case 1:
                goto volume_menu;
                break;
            case 3:
                goto exit;
                break;
            default:
                goto c5;
                break;
            }

            break;
        }
    case 'f':
    case 'F':
        goto exit;
        break;

    default:

        printf("choose only from below menu\n");
        // scanf("%c",&howdoyoudo);
        goto main_menu;
        break;
    }
exit:
    return 0;
}