from lib import * 
import sys
import time
from collections import OrderedDict
import pandas as pd
import plotly.express as px
import json

def main():
    lib = {}
    f = open(sys.argv[1], "r")
    for line in f:
        l = line.strip().split(' ')
        t = str(l[1]).split(':')
        seconds = int(t[0])*60 + int(t[1])
        song = l[0]
        artist = l[2]
        album = l[3]
        track = int(l[5])
        if artist not in lib.keys():
            lib[artist] = Artist(artist, seconds)
        else:
            lib[artist].nsongs += 1
            lib[artist].time += seconds
            
        if album not in lib[artist].albums.keys():
            lib[artist].albums[album] = Album(album, seconds)
        else:
            lib[artist].albums[album].time += seconds
            lib[artist].albums[album].nsongs += 1
        lib[artist].albums[album].songs[track] = Song(song, seconds)
    l = []
    f = []
    p = ""
    for artist in OrderedDict(sorted(lib.items())):
        print(f'{artist.replace("_", " ")}: {lib[artist].nsongs}, {time.strftime("%M:%S", time.gmtime(lib[artist].time))}')
        d = f'"name": "{artist}", "#songs": "{lib[artist].nsongs}", "totaltime": "{time.strftime("%M:%S", time.gmtime(lib[artist].time))}"'
        p += "{" + d + "}"
        l.append(time.strftime("%M:%S", time.gmtime(lib[artist].time)))
        f.append(artist)
        #l.append(d)
        for album in OrderedDict(sorted(lib[artist].albums.items())):
            a = lib[artist].albums[album]
            print(f'        {album.replace("_", " ")}: {a.nsongs}, {time.strftime("%M:%S", time.gmtime(a.time))}')
            for song in OrderedDict(sorted(a.songs.items())):
                s = a.songs[song]
                print(f'                {song}. {s.title}: {time.strftime("%M:%S", time.gmtime(s.time))}')
                
    p = p.split('}')
    p = p[:-1]
    #data = json.loads(json.dumps(p))
    df = pd.DataFrame(f, index=l)
    fig = px.bar(df, y=l, x=f)
    fig.write_html('music.html')
    
if __name__ == "__main__":
    main()