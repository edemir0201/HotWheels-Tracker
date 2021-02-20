#ifndef HOTWHEELS_HEADER1
#define HOTWHEELS_HEADER1

#define BUFF 20
// HW STRUCT
typedef struct hotWheel
{
    char collection[BUFF];
    char brand[BUFF];
    char model[BUFF];
    int year;
    int collectionNumber;
} hotWheel;

// declarations
void displayMenu(void);
hotWheel **createHwArr(int size);
hotWheel *createHw(void);
hotWheel **destroyHotWheelArr(hotWheel **car, int size);
hotWheel *destroyAhotWheel(hotWheel *oneCar);
void promptUserHWInfo(hotWheel *car);
void printHotWheel(hotWheel *car);
void printHotWheelArr(hotWheel **carArr, int size);



#endif
