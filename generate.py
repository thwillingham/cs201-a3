import random
import sys

maxGeneratorNumber = int(sys.argv[1]);
maxVertexNumber = int(sys.argv[2]);
maxNumberOfSpace = 10
maxWeight = 100

def main():
    for i in range(0, maxGeneratorNumber):
        print(str(random.randint(0, maxVertexNumber)))
        print(" ")
        print(str(random.randint(0, maxVertexNumber)))
        print(str(random.randint(1, maxWeight)))
        print(" ")
        print(";")
main()
