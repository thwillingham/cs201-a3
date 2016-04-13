import random

numberToGenerate = 1000000
maxVertexNumber = 1000
maxNumberOfSpace = 2
maxWeight = 1000

def main():
    for i in range(0, numberToGenerate):
        print(str(random.randint(0, maxVertexNumber)))
        print(" " * random.randint(0, maxNumberOfSpace))
        print(str(random.randint(0, maxVertexNumber)))
        if (random.randint(0, 1) == 0):
            print(str(random.randint(0, maxWeight)))
        print(" " * random.randint(0, maxNumberOfSpace))
        print(";")
main()
