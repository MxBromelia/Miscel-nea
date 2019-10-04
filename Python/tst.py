def read_file(file):
    fo = open(file,"r")
    i=0
    while (fo.closed == False and i<10):
        string = fo.read(10)
        print(string)
        i+=1
    fo.close()
