// This handles multiple hotWheels and stores them in a dynamically allocated
// array. It then prints the entire array and frees it before programs exits
// Stores collection in a file so that data is saved between
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HotWheels_Tracker.h"
#define BUFF 20
// this is just 4 * BUFF. It is used to read entire lines from FILE for future parsing
#define BIG_BUFF 80


// **IMPORTANT**
// FILE FORMAT FOR READING AND PRINTING
// first line only contains an integer which represents number of cars
// from there on out format is as follows:
// year collectionNumber brand model collection\n

// **ALSO IMPORTANT**
// to clear output screen depends on system:
// For LINUX/UNIX use system("clear");
// For WINDOWS/DOS use system("cls");

// MY MAIN FUNCTION
int main(void)
{
    // holds name of file that stores collection
    char collectionStorage = "collection.txt";

    // pointer to dynamically allocated array
    hotWheel **myCars = NULL;
    int *arrSize      = 0; // myCars array size

    // 0: if collection hasn't been saved in current state.
    // 1: if collection has been saved in current state.
    int isSaved;

    // 0: if user doesn't want to save the collection. (exits with state of
    //    collection at program run time)
    // 1: if user does want to save the current collection. (Overwrites
    //    previous collection)
    int doSave;
    // stores the number of the command the user chooses
    int commandNum;

    // check if user is sure they want run this command that can't be undone
    // EX: Delete a car or delete entire collection
    int doubleCheck;

    // file pointer to restore collection at program runtime
    // also stores collection when done
    FILE *collectionStorage;

    // used to determine what to erase when user chooses command to erase
    // collection
    int eraseChoice;
    // loop vars
    int i;
    int k;

    char trash[10];
    collectionStorage = fopen(myCollection, "r");
    if (collectionStorage == NULL) // this handles if no previous file was found
    {
        while (commandNum != 0)
        {
            commandNum = chooseCommand();
            switch (commandNum)
            {
                case 0:
                    // COME BACK HERE AND ADD FUNCTIONALITY FOR CLOSING PROGRAMMING
                    printf("Are you sure you wan't to exit the program?");
                    printf(" (1: Yes, 0: No)\n");
                    scanf("%d", &doubleCheck);
                    if (doubleCheck == 1)
                    {
                        printf("Would you like to save the current collection?");
                        printf(" (1: Yes, 0: No)\n");
                        scanf("%d", &doSave);
                        if (doSave == 1)
                        {
                            printf("Saving...");
                            // COME HERE AND ADD FUNCTION FOR Saving
                            printf("Done. Collection saved.\n")
                        } else
                        {
                            // start closing program here without saving
                            printf("Exiting...");
                            fclose(collectionStorage);
                            myCars = destroyHotWheelArr(myCars, arrSize);
                            printf("Done.\n");
                            return 0;
                        }
                        printf("Erasing...")
                        printf("Done. Collection erased.\n");
                    } else
                    {
                        printf("Canceled.\n")
                    }

                    break;
                case 1: // prints entire collection
                    printHotWheelArr(myCars, arrSize);
                    break;
                case 2: // Adds ONE Hot wheel
                    addAHotWheel(myCars, arrSize);
                    break;
                case 3: // Adds more than one Hot Wheel
                    // COME BACK HERE AND ADD THIS functoinality
                    break;
                case 4: // Delete a Hot Wheel
                    // come back here and add this FUNCTIONALITY
                    break;
                case 5: // Erase entire collection
                    printf("Are you sure you want to erase your Collection?");
                    printf(" (1: Yes, 0: No)\n");
                    scanf("%d", &doubleCheck);
                    if (doubleCheck == 1)
                    {
                        printf("Erasing...")
                        myCars = destroyHotWheelArr(myCars, arrSize);
                        printf("Done. Collection erased.\n");
                    } else
                    {
                        printf("Canceled.\n")
                    }
                    break;
                case 6: // Save entire collection
                    // COME BACK HERE AND ADD THIS FUNCTIONALITY

            }
        }
    } else // handle if previous file was found
    {
        // this will assume file is never empty because if previous program
        // occurance caused file to reach an empty state (user wanted
        // collection reset/cleared) then the program would delete file before
        // closing

        // reads number of cars from file
        // THIS MIGHT GET RID OF TRAILING NEWLINE CHAR. MAKE SURE TO COME BACK
        // AND CHECK THIS IS TRUE
        fscanf(collectionStorage, "%d %c", &arrSize, trash);

        myCars = createHwArrFile(collectionStorage, arrSize);


        // I JUST COPY AND PASTED THIS FROM THE IF SECTION ABOVE. MAKE SURE TO MAKE NECCESSARY CHANGES TO FUNCTIONS
        // ALSO MAKE SURE TO CHANGE THE DELETION FUNCTIONS TO CHECK IF IT LEFT AN EMPTY COLLECTION AT WHICH POINT WE WOULD DELETE THE FILE
        while (commandNum != 0)
        {
            commandNum = chooseCommand();
            switch (commandNum)
            {
                case 0:
                    // COME BACK HERE AND ADD FUNCTIONALITY FOR CLOSING PROGRAMMING
                    printf("Are you sure you wan't to exit the program?");
                    printf(" (1: Yes, 0: No)\n");
                    scanf("%d", &doubleCheck);
                    if (doubleCheck == 1)
                    {
                        printf("Would you like to save the current collection?");
                        printf(" (1: Yes, 0: No)\n");
                        scanf("%d", &doSave);
                        if (doSave == 1)
                        {
                            printf("Saving...");
                            // COME HERE AND ADD FUNCTION FOR Saving
                            printf("Done. Collection saved.\n")
                        } else
                        {
                            // start closing program here without saving
                            printf("Exiting without saving...");
                            fclose(collectionStorage);
                            myCars = destroyHotWheelArr(myCars, arrSize);
                            printf("Done.\n");
                            return 0;
                        }
                    } else
                    {
                        printf("Canceled.\n")
                    }

                    break;
                case 1: // prints entire collection
                    printHotWheelArr(myCars, arrSize);
                    break;
                case 2: // Adds ONE Hot wheel
                    addAHotWheel(myCars, arrSize);
                    break;
                case 3: // Adds more than one Hot Wheel
                    // COME BACK HERE AND ADD THIS functoinality
                    break;
                case 4: // Delete a Hot Wheel
                    findAndDestroy(myCars, arrSize);
                    // COME BACK HERE AND CHECK TO SEE IF COLLECTION IS EMPTY
                    // AND THEN DELETE FILE IF TRUE
                    break;
                case 5: // Erase entire collection
                    printf("Are you sure you want to erase your Collection?");
                    printf(" (1: Yes, 0: No)\n");
                    scanf("%d", &doubleCheck);
                    if (doubleCheck == 1)
                    {
                        printf("Erasing...")
                        myCars = destroyHotWheelArr(myCars, arrSize);
                        printf("Done. Collection erased.\n");
                    } else
                    {
                        printf("Canceled.\n")
                    }
                    break;
                case 6: // Save entire collection
                    // COME BACK HERE AND ADD THIS FUNCTIONALITY

            }
        }
    }


}
// Complications:
// Q: figure out how I want this fucntion to move into the others
// Q:Do I want to have this function call all the functoins from here?
// A: Prob not because it sounds complicated
// Q: Do I want to just print this function and then move on from there to my
//    other functions independetly?

int chooseCommand(void)
{
    int commandNum = 90;
    int i;

    displayMenu();

    i = 0;
    while (commandNum < 0 && commandNum > 6)
    {
        if (commandNum < 0 && commandNum > 6 && i != 0)
        {
            printf("Invalid Command Number! Please enter a number between 0 & 6");
        }
        commandNum = scanf("%d", &commandNum);
        ++i;
    }

    return commandNum;
}
void displayMenu(void)
{
    printf("Welcome to HW Collection!\n");
    printf("Select the function you'd like by typing its number\n");
    printf("1: Print my collection\n");
    printf("2: Add a car to my collection\n");
    printf("3: Add multiple cars to my collection\n");
    printf("4: Remove a car from my collection\n");
    printf("5: Erase my collection\n");
    printf("6: Save my collection\n");
    printf("0: Exit");
}
void promptUserHWInfo(hotWheel *car)
{
    char trash;
    int i;

    // PROMPTS USER FOR CAR DATA
    printf("Enter car brand\n");
    scanf("%s", car->brand);

    printf("Enter car model\n");
    scanf("%s", car->model);

    printf("Enter car year\n");
    // this scanf has a \n because I use an fgets afterwards and need the \n to be sucked up
    scanf("%d", &car->year);

    printf("Enter collection the car is a part of\n");
    // this reads the left over new line char
    scanf("%c\n", &trash);
    // fflush(stdout);
    // This uses fgets instead of scanf because collection names can consist of
    // more than 1 word
    fgets(car->collection, BUFF - 1, stdin);
    i = 0;
    while(i <= BUFF)
    {
        if (car->collection[i] == '\n')
        {
            car->collection[i] = '\0';
            break;
        }
        ++i;
    }

    printf("Enter the number of the car in the collection\n");
    scanf("%d", &car->collectionNumber);
}

int getNumCars(hotWheel **carList, int *arrSize)
{
    int numCars = 0;
    int i;

    for (i = 0; i < *arrSize; i++)
    {
        if (carList[i] != NULL)
        {
            numCars++;
        }
    }

    return numCars;
}

// Non-file version
// allocates the entire array and then goes through and allocates each hotWheel* with createHw
hotWheel **createHwArr(int *size)
{
    hotWheel **temp;

    temp = calloc(*size, sizeof(hotWheel *));
    if (temp == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < *size; i++)
    {
        printf("Enter info for car %d.\n", i + 1);
        printf("\n");
        temp[i] = createHw();
        if (temp[i] == NULL)
        {
            // if calloc/malloc fails to find memory, then it calls destroyHotWheelArr to free all previous dynamically allocated memory and then return NULL
            temp = destroyHotWheelArr(temp, *size);
            break;
        }
    }
    return temp;
}

// FILE VERSION
// **IMPORTANT**
// FILE FORMAT FOR READING AND PRINTING
// first line only contains an integer which represents number of cars
// from there on out format is as follows:
// year collectionNumber brand model collection\n
hotWheel **createHwArrFile(FILE listFile, int *size)
{
    hotWheel **temp;
    char year[5];
    char collectionNumberC[3];
    char lineBuffer[BIG_BUFF];
    int charCount = 0;
    int length    = 0;
    int i;
    int j;
    int k;

    temp = calloc(*size, sizeof(hotWheel *));
    if (temp == NULL)
    {
        return NULL;
    }

    for (i = 0; i < *size; i++)
    {
        // reads entire line from FILE, finds length, and swaps newline char for
        // null terminator
        fgets(lineBuffer, BIG_BUFF, listFile);
        length = strlen(lineBuffer);
        lineBuffer[length - 1] = '\0';

        // saves substrings into their appropriate struct members
        sscanf(lineBuffer, %s %s %s %s, year, collectionNumberC, temp[i]->brand, temp[i]->model);

        // finds starting index of collection substring in lineBuffer
        charCount = (strlen(year) + 1) + (strlen(collectionNumberC) + 1) - (strlen(temp[i]->brand) + 1) + (strlen(temp[i]->model) + 1);


        // charCount is the index of the string where collection string starts
        // in the lineBuffer string.
        // length is the total length of the lineBuffer string
        k = 0;
        for (j = charCount; j < length; j++)
        {
            // k goes from 0 to the length of the collection substring in
            // lineBuffer (incremented by 1 length - charCount times)
            temp[i]->collection[k++] = lineBuffer[j];
        }

        return temp;
    }
}
// THIS ALLOCATES MEMORY TO THE HW STRUCT AND INITIALIZES THE FIELDS WITH INPUT
// FROM USER
hotWheel *createHw(void)
{
    hotWheel *tempCar;
    int i;
    // this just holds a newLine character before an fgets

    // allocates memory for the struct. TempCar holds pointer to this memory
    tempCar = malloc(sizeof(hotWheel));
    if (tempCar == NULL)
    {
        return NULL;
    }


    // come back here and call promptUserHWInfo
    promptUserHWInfo(tempCar);

    return tempCar;
}

// right way to call this function is: carList = addAHotWheel(carList, size);
hotWheel **addAHotWheel(hotWheel **carList, int *size)
{
    hotWheel **newList = NULL;
    int i;
    int numCars = 0;
    // this is size after adding a hotWheel
    int newSize;
    // if carList is NULL then the collection is empty, so creates a new
    // collection of one car and returns it
    if (carList == NULL)
    {
        newList = createHwArr(1);
        return newList;
    }

    // gets actual number of cars in the collection
    numCars = getNumCars(carList, *size);

    // checks if array is big enough to add a car
    if ((numCars + 1) < *size))
    {
        // if it is big enough, then make sure the NULLs are at the end of the
        // array. Then add a car at numCars
        shiftHotWheelArray(carList, *size);
        carList[numCars] = createHw();
        return carList;
    } else
    {
        newList = calloc(numCars + 1, sizeof(hotWheel *));
        for (i = 0; i < numCars; i++)
        {
            newList[i] = carList[i];
        }

        newList[numCars] = createHw();
        *size += 1;
        free(carList);
        return newList;
    }
}

hotWheel **addHotWheels(hotWheel **carList, int *size)
{
    hotWheel **newList = NULL;
    // num cars user wants to add
    int carsToAdd;
    // num Cars currently in list
    int numCars = 0;
    // loop var
    int i;


    printf("How many cars would you like to add?\n");
    scanf("%d", &carsToAdd);

    if (carList == NULL)
    {
        newList = createHwArr(carsToAdd);
        return newList;
    } else
    {
        numCars = getNumCars(carList, *size);
        if ((numCars + carsToAdd) < *size)
        {
            shiftHotWheelArray(carList, size);

            for (i = numCars; i < carsToAdd; i++)
            {
                carList[i] = createHw();
            }

            return carList;
        } else
        {
            newList = calloc((numCars + carsToAdd), sizeof(hotWheel *));

            for (i = 0; i < numCars; i++)
            {
                newList[i] = carList[i];
            }

            for (i = numCars; i < (numCars + carsToAdd); i++)
            {
                newList[i] = createHw();
            }
            *size += carsToAdd;
            free(carList);
            return newList;
        }
    }
}
void shiftHotWheelArray(hotWheel **carList, int *size)
{
    int i;

    for (i = 0; i < *size; i++)
    {
        // if no car at this index, then shift everything towards the front 1
        // otherwise do nothing
        if (carList[i] == NULL)
        {
            // if last index is null then end because there is nothing left to
            //    shift
            // otherwise shift
            if (i == *size - 1)
            {
                break;
            } else
            {
                carList[i] = carList[i + 1];
                carList[i + 1] = NULL;
            }
        } else
        {
            continue;
        }
    }
}

hotWheel *destroyAhotWheel(hotWheel *oneCar)
{
    free(oneCar);
    return NULL;
}
// This returns a pointer just so that it can return NULL. The NULL forces me to correctly reallocate it before using pointer in future
hotWheel **destroyHotWheelArr(hotWheel **car, int *size)
{
    if (car == NULL || *size == 0)
    {
        printf("Collection is already empty, nothing to delete\n");
        return NULL;
    }

    for (int i = 0; i < *size; i++)
    {
        car[i] = destroyAhotWheel(car[i]);
    }

    free(car);
    *size = 0;
    return NULL;
}

void findAndDestroy(hotWheel **car, int *size)
{
    int i; // loop var

    // 1 or higher: if car is found
    // 0: if not found
    int isFound = 0;

    // vars to compare to members
    int year;
    int collectionNumber;
    char collection[BUFF];
    char brand[BUFF];
    char model[BUFF];

    // sucks up trailing newline
    char trash;

    if (car == NULL || car[0] == NULL || *size == 0)
    {
        printf("Collection is empty. Nothing to remove.\n");
        return;
    }
    // setting up local vars
    printf("Enter the brand of the car.\n");
    scanf("%s", brand);

    printf("Enter the model of the car.\n");
    scanf("%s", model);

    printf("Enter the car year.\n");
    scanf("%d", &year);

    printf("Enter the number of the car in the collection (collection number).\n");
    scanf("%d", &collectionNumber);

    printf("Enter the name of the collection the car is a part of.\n");
    // this reads trailing newline character in prep for following fgets() call
    scanf("%c\n", &trash);

    fgets(collection, BUFF - 1, stdin);
    i = 0;
    while(i <= BUFF)
    {
        if (car->collection[i] == '\n')
        {
            car->collection[i] = '\0';
            break;
        }
        ++i;
    }
    printf("\n");
    // done setting up local vars

    // start search
    printf("Searching...");
    isFound = 0;
    for (i = 0; i < *size; i++)
    {
        if (strcmp(car[i]->brand, brand) == 0)
        {
            if (strcmp(car[i]->model, model) == 0)
            {
                if (strcmp(car[i]->collection, collection) == 0)
                {
                    if (car[i]->year == year)
                    {
                        if (car[i]->collectionNumber == collectionNumber)
                        {
                            printf("Found.\n")
                            isFound++;

                            // If everything matches, then remove it.
                            printf("Deleting...")
                            car[i] = destroyAhotWheel(car[i]);
                            if (car[i] == NULL)
                            {
                                printf("Successfully deleted.\n");
                                shiftHotWheelArray(car, size);
                                *size -= 1;
                            } else
                            {
                                printf("Failed to delete. Try again.\n");
                            }
                        }
                    }
                }
            }
        }
    }

    if (isFound == 0)
        printf("Not found within collection.\n");
}

int deleteCollectFile(char *fileName)
{
    int deleted;
    if (remove(fileName) == 0)
    {
        deleted = 1;
        printf("Deleted succesfully.\n");
    } else
    {
        deleted = 0;
        printf("Failed to delete \"%s\".\n", fileName);
    }
    return deleted;
}
// THIS SIMPLY PRINTS A HOTWHEEL CAR
void printHotWheel(hotWheel *car)
{
    printf("\n");
    printf("Collection: %s\n", car->collection);
    printf("Collection #: %d\n", car->collectionNumber);
    printf("\n");
    printf("Car Brand: %s\n", car->brand);
    printf("Car Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
}


// prints a list of hotwheels using printHotWheel
void printHotWheelArr(hotWheel **carArr, int *size)
{
    // checks if Array (collection) is empty
    if (carArr == NULL || carArr[0] == NULL || *size == 0)
    {
        printf("Your collection is Empty!")
    } else
    {
        // prints the list
        for (int i = 0; i < *size; i++)
        {
            // prints individual hotWheel
            printHotWheel(carArr[i]);
            if (i < *size - 1)
            {
                printf("\n");
                printf("\n");
            }
        }

        printf("Done printing.");
    }
}
