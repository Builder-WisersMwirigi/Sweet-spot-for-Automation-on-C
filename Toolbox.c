#include<stdio.h>
#include<stdlib.h>


int main(){
printf("Welcome to Download centre\n1. Download video.\n2. Download Audio.\n3. Extract Audio from Video.\n4. Fuse Video to Audio\n5. Extract Wav from Audio\n6. Exit!\n");
int x;
int y;
char url[256];
char buffer[1024];
char command[512];
FILE *fp;
for(;;){
        scanf("%d",&y);
        if (y==6){return 1;}
        if(y<1||y>6){printf("Invalid Output. Try Again\n");}
    switch (y){
        /*case 1:
            printf("Input video url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f \"bestvideo[height<=1080]+bestaudio\" --remux-video mp4 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\" --no-playlist",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Download Complete.\nBack to Main menu\n");
        break;
        case 2:
            printf("Input audio url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f bestaudio --extract-audio --audio-format mp3 --audio-quality 0 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\" --no-playlist",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Download Complete.\nBack to Main menu\n");
        break;*/
        case 3:
            printf("Input path to Video location.\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"ffmpeg -i \"%s\" -q:a 0 -map a \"%~dpn1.mp3\"",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
        break;
        case 4:
            printf("Input video url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f \"bestvideo[height<=1080]+bestaudio\" --remux-video mp4 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\" --no-playlist",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
        break;
        case 5:
            printf("Input video url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f \"bestvideo[height<=1080]+bestaudio\" --remux-video mp4 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\" --no-playlist",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
        break;
    default:printf("Sth sank");}

}


return 0;
}
