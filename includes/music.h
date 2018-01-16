#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include <dirent.h>
#include <windows.h>



DWORD PlayMusic(char cmd[100])
{
    //Play using powershell
   system(cmd);
}

DWORD Timeline()
{
    while(1)
    {
       Sleep(1000);
       printf("#");

    }
}



void ListMusic()
{
    DIR *dir;
    struct dirent *sd;
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Unable to read current directory\n");
        exit(1);
    }


    while( (sd=readdir(dir)) != NULL )
    {
            printf(".. %s\n", sd->d_name);
    }

    closedir(dir);
}




#endif // MUSIC_H_INCLUDED
