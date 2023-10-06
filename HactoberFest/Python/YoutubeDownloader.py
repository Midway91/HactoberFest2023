import pytube


url = str(input("Enter the url:\n"))

yt = pytube.YouTube(url)


while True:
    type = int(input("1.Video\n2.Audio\n"))
    if type == 1:
        stream = yt.streams.get_highest_resolution()
        break
    elif type == 2:
        stream = yt.streams.get_audio_only()
        break
    else:
        print("enter a correct option")
        continue


stream = yt.streams.get_audio_only()
stream.download()
