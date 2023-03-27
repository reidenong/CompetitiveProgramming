import sys

scale = {
    "A" : 1,
    "A#":"Bb",
    "Bb":"A#",
    "B" : 1,
    "C" : 1,
    "C#":"Db",
    "Db":"C#",
    "D":1,
    "D#":"Eb",
    "Eb":"D#",
    "E":1,
    "F":1,
    "F#":"Gb",
    "Gb":"F#",
    "G":1,
    "G#":"Ab",
    "Ab":"G#"
}

casecounter = 1
for line in sys.stdin:
    data = line.strip()
    data = data.split(" ")
    if scale[data[0]] == 1:
        print("Case {0}: UNIQUE".format(casecounter))
    else:
        print("Case {0}: {1} {2}".format(casecounter, scale[data[0]], data[1]))
        casecounter += 1
