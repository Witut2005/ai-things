
import sys

if len(sys.argv) != 2:
    print('wykorzystanie: nazwa_programu wielomian')
    sys.exit(3)

wielomian: str = sys.argv[1]
niewiadoma: str = input('co pod x wariacie: ')

wielomian = wielomian.replace('x', niewiadoma)

print(eval(wielomian))
