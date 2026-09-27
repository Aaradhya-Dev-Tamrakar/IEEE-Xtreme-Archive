import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        a = int(tokens[0])
        b = int(tokens[1])
        print(a + b)

if __name__ == '__main__':
    main()
