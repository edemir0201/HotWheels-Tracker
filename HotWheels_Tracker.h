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
int chooseCommand(void);
hotWheel **createHwArrFromFile(FILE *listFile, int *size);
hotWheel **createHwArr(int *size);
hotWheel *createHw(void);
hotWheel **addAHotWheel(hotWheel **carList, int *size);
hotWheel **destroyHotWheelArr(hotWheel **car, int *size);
void findAndDestroy(hotWheel **car, int *size);
hotWheel *destroyAHotWheel(hotWheel *oneCar);
void shiftHotWheelArray(hotWheel **carList, int *size);
FILE *createCollectFile(char *fileName, hotWheel **collection, int *arrSize);
int deleteCollectFile(char *fileName);
void promptUserHWInfo(hotWheel *car);
void printHotWheel(hotWheel *car);
void printHotWheelArr(hotWheel **carArr, int *size);



#endif
