#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/music.h"
#include <conio.h>
#include <windows.h>
#include <dirent.h>
void ListMusic();
DWORD PlayMusic();
DWORD Timeline();

int main()
{

        printf("Welcome to SliverC v1.0 \n");
        printf("Be sure to place the binary in your music folder!\n");
        printf("=====================================\n");
        printf("Songs in current directory : \n");
        ListMusic();
        char str[80];
        int handle;
        char song[100];
        char control;

        while(1)
        {
            char cmd[100]="powershell -c (New-Object Media.SoundPlayer '";
            char cmd2[100]="').PlaySync();";
            printf("Song > ");
            fflush(stdout);
            scanf("%s", &song);

            strcat(cmd, song);
            strcat(cmd, cmd2);
            printf("[");
            HANDLE thread1, thread2, thread3;
            thread1 = CreateThread(NULL, 0, PlayMusic, cmd, 0, NULL);
            thread2 = CreateThread(NULL, 0, Timeline, "time", 0, NULL);


            DWORD result = WaitForSingleObject(thread1, INFINITE);
            char p;

            if(result==0)
            {
                printf("]\n");
                //exit(1);
                STOP:TerminateThread(thread2, 0);
            }
            else
            {
               WaitForSingleObject(thread1, INFINITE);
            }



        }



        //play mp3 function
        //system("powershell -c (New-Object Media.SoundPlayer 'test.wav').PlaySync();");
    return 0;
}
