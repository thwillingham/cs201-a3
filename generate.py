import random
import sys

maxGeneratorNumber = int(sys.argv[1]);
maxVertexNumber = int(sys.argv[2]); 
maxNumberOfSpace = 10
maxWeight = 100

def main():
    for i in range(0, maxGeneratorNumber):
        print(str(random.randint(0, maxVertexNumber)))
        print(" " * random.randint(0, maxNumberOfSpace))
        print(str(random.randint(0, maxVertexNumber)))
        if (random.randint(0, 1) == 0):
            print(str(random.randint(0, maxWeight)))
        print(" " * random.randint(0, maxNumberOfSpace))
        print(";")
main()
