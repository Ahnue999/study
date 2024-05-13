import sys

try:
    f = open("myfile.txt")
    s = f.readline()
    i = int(s.strip())
except OSError as err:
    print("OSError: ", err)
#except ValueError as err:
#    print("Couldn't convert to integer")
except Exception as err:
    print(f"Unexpected {err=}, {type(err)=}")
    raise
