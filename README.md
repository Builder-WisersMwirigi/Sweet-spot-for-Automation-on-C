## Sweet Spot for Automation in C

A C-language toolbox to simplify complex command-line tasks for tools like yt-dlp and ffmpeg.

MediaCurl provides simplified commands and automation scripts to make using powerful CLI tools like `yt-dlp` and `ffmpeg` as easy as spreading butter.
Eliminating the need of memorizing long, intricate command-line arguments for repetitive tasks.

## MediaCurl PRESENTS
    * Wraps complex `ffmpeg`/`yt-dlp` processes into simple commands.
    * Automates repetitive tasks into simple batch processing tasks.
    * Lightweight & Fast - written in C for minimal overhead.

## How to Build & Use
1.  Download the Zip
2.  Run the .exe
3.  Good to go.

## Example Usage
1.  Rather than calling this everytime to download a video "yt-dlp -f \"bestvideo[height<=1080]+bestaudio\" --remux-video mp4 -o \"-- simply pick 'Download Video' function
2.  Becomes simpler to convert video to audio(mp3) by using predefined 'ffmpeg' "ffmpeg -i \"%s\" -q:a 0 -map a \"%~dpn1.mp3\"

## Project Structure
