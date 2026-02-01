#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main(){
printf("Welcome to Download centre\n1. Download video.\n2. Download Audio.\n3. Download a playlist\n4. Extract Audio from Video.\n5. Extract Video from Video.\n6. Fuse Video to Audio\n7. Extract Wav from Audio\n8. Help!\n9. Exit!\n");
int x;
int y;
char url[256];
char buffer[1024];
char command[512];
char output[512];
char *last_dot = strrchr(url, '.');
FILE *fp;
for(;;){
        scanf("%d",&y);
        if (y==9){return 1;}
        if (y==8) { FILE *fp = fopen("read ME.txt", "r");}
        if(y<1||y>9){printf("Invalid Output. Try Again\n");}
    switch (y){
        case 1:
            printf("Input video url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f \"bestvideo[height<=1080]+bestaudio\" --remux-video mp4 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\" ",url);
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
        break;
        case 3:
            printf("Input audio url\n");
            scanf("%s",url);
            snprintf(command, sizeof(command),"yt-dlp -f bestaudio --extract-audio --audio-format mp3 --audio-quality 0 -o \"F:\\Downloads Music\\%%(title)s.%%(ext)s\" \"%s\"",url);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Download Complete.\nBack to Main menu\n");
        break;
        case 4:
            printf("Input path to Video location.\n");
            getchar();
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = 0;
                if (last_dot) {
                    snprintf(output, sizeof(output), "%.*s_extracted.mp3", (int)(last_dot - url), url);
                        } else {snprintf(output, sizeof(output), "%s_extracted.mp3", url);}
            snprintf(command, sizeof(command),"ffmpeg -i \"%s\" -q:a 0 -map a \"%s\"", url, output);
            fp=popen(command,"r");
                if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Convertion Complete.\nBack to Main menu\n");
        break;
        case 5:
            printf("Input path to Video location.\n");
            getchar();
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = 0;
            if (last_dot) {
                snprintf(output, sizeof(output), "%.*s_video_only.mp4", (int)(last_dot - url), url);}
                    else {
                snprintf(output, sizeof(output), "%s_video_only.mp4", url);}
            snprintf(command, sizeof(command),"ffmpeg -i \"%s\" -c:v copy -an \"%s\"", url, output);
            fp=popen(command,"r");
            if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Conversion Complete.\nBack to Main menu\n");
        break;
        case 6:
            printf("Input path to Video location.\n");
            getchar();
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = 0;

            printf("Input path to Audio location.\n");
            char audio_url[512];
            fgets(audio_url, sizeof(audio_url), stdin);
            audio_url[strcspn(audio_url, "\n")] = 0;
            if (last_dot) {
                snprintf(output, sizeof(output), "%.*s_merged.mp4", (int)(last_dot - url), url);}
                else {
                    snprintf(output, sizeof(output), "%s_merged.mp4", url);}
            snprintf(command, sizeof(command),"ffmpeg -i \"%s\" -i \"%s\" -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 \"%s\"", url, audio_url, output);
            fp=popen(command,"r");
            if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("Merging Complete.\nBack to Main menu\n");
        break;
        case 7:
            printf("Input path to audio/video location.\n");
            getchar();
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = 0;
            if (last_dot) {
                snprintf(output, sizeof(output), "%.*s_extracted.wav", (int)(last_dot - url), url);}
                else {
                    snprintf(output, sizeof(output), "%s_extracted.wav", url);}
            snprintf(command, sizeof(command),"ffmpeg -i \"%s\" -ac 1 -ar 16000 -vn -c:a pcm_s16le \"%s\"", url, output);
            fp=popen(command,"r");
            if (fp==NULL)break;
            while(fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("%s", buffer);}
            pclose(fp);
            printf("WAV Extraction Complete.\nBack to Main menu\n");}
        break;

}


return 0;
}
