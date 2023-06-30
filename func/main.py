
import sys
import time

def check_solution(wielomian: str, x: float): 
    return float(eval(wielomian.replace('x', str(x))))

def main():
    if len(sys.argv) != 2:
        print('wykorzystanie: nazwa_programu wielomian')
        sys.exit(3)

    wielomian: str = str(sys.argv[1]).replace(')(', ')*(')

    print(wielomian)

    niewiadoma: float = float(input('co pod x wariacie: '))

    najlepsze_x: float = niewiadoma


    while True:
        sol1 = check_solution(wielomian, round(najlepsze_x + 0.0001, 4))
        sol2 = check_solution(wielomian, round(najlepsze_x - 0.0001, 4))

        if check_solution(wielomian, najlepsze_x) <= sol1 and check_solution(wielomian, najlepsze_x) <= sol2:
            # print(najlepsze_x, )

            print('----------------')
            print(check_solution(wielomian, najlepsze_x))
            # print(sol1)
            # print(sol2)
            # print(najlepsze_x)
            sys.exit(1)

        najlepsze_x = round(najlepsze_x + 0.0001, 4) if sol1 < sol2 else round(najlepsze_x - 0.0001, 4)
        print(check_solution(wielomian, najlepsze_x))


if __name__ == '__main__':
    main()