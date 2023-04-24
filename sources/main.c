#include "../includes/sleepwipe.h"

int main(int ac, char **av)
{
    /* Uyku önleme işlemi için kullanılacak ID tanımlanıyor. */
    IOPMAssertionID assertionID;
    /* Aktivitenin nedenini tanımlayan bir CFStringRef oluşturuluyor. */
    CFStringRef reasonForActivity= CFSTR("Prevent system sleep");
    /* Uyku önleme işlemi için bir IOPMAssertionType tanımlanıyor. */
    IOReturn success = IOPMAssertionCreateWithName(kIOPMAssertionTypeNoDisplaySleep,
                                                    /* Uyku önleme seviyesi tanımlanıyor. */
                                                    kIOPMAssertionLevelOn,
                                                    /* Aktivitenin nedeni belirtiliyor. */
                                                    reasonForActivity,
                                                    /* Tanımlanan ID IOPMAssertionCreateWithName fonksiyonuna atanıyor. */
                                                    &assertionID);

    if(ac == 1)
    {
        if(success == kIOReturnSuccess)
        {
            printf("%sSince no specific parameter is given to sleepwipe, it will prevent the computer from sleeping until the program is terminated.%s\n", RED, RESET);
            CFRunLoopRun();
            success = IOPMAssertionRelease(assertionID);
        }
    }
    else if(ac == 2 || ac == 3 || ac == 4)
    {
        printf("...");
    }
    else
    {
        struct utsname unameData;
        int result = uname(&unameData);
        if (result != -1)
        {
            printf("[GNU %s, version %s]",getenv("0"), unameData.version);
            printf("These shell commands are defined by sleepwipe. Type <sleepwipe --help> to see this list.");
            printf("Type <sleepwipe --help name> to find out more about the function <name>.");

            printf("%ssleepwipe commands list:%s",GREEN, RESET);
            
        }
    }
    return success;
}