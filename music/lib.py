class Song:
    def __init__(self, title, time):
        self.title = title
        self.time = time

class Album:
    def __init__(self, name, time):
        self.songs = {}
        self.nsongs = 1
        self.name = name
        self.time = time

class Artist:
    def __init__(self, name, time):
        self.albums = {}
        self.name = name
        self.time = time
        self.nsongs = 1