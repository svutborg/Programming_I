/**
*   Header for the main file of the Group picker project
*
*   To enable Debug mode uncomment the #define DEBUG line
*   To enable Random ordering on the list uncomment the #define RANDOM line
*       Random will swap indeces on the list, RAND_NUM defines the number of swaps
*       done by the randomisation.
**/

#ifndef MAIN_HEADER
#define MAIN_HEADER
    // #define DEBUG
    #define RANDOM

    #ifdef RANDOM
        #define RAND_NUM 50
    #endif // RANDOM
#endif // MAIN_HEADER
