import sys

def main():
    lines = sys.stdin.read().splitlines()
    if not lines:
        return
    lines = [l.strip() for l in lines if l.strip()]
    if not lines:
        return

    perm = lines[0]
    N = int(lines[1])
    words = lines[2:2 + N]

    order = {c: i for i, c in enumerate(perm)}

    def word_key(word):
        return [order[c.lower()] + (26 if c.isupper() else 0) for c in word]

    words.sort(key=word_key)
    print('\n'.join(words))

if __name__ == '__main__':
    main()
