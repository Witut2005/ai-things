
import sys
# import math
import random
import numpy as np
from typing import *
import numpy.typing as npt
# from scipy import *

class HashDict(dict):
    def __setitem__(self, key, value):
        super().__setitem__(self, key, value)
    
    def __hash__(self):
        return hash(tuple(sorted(self.items())))



class CancerCase:

    weights = {
        'event': random.uniform(0.0, 1.0),
        'age': random.uniform(0.0, 1.0),
        'menopause': random.uniform(0, 1.0),
        'size': random.uniform(0, 1.0),
        'inv_nodes': random.uniform(0, 1.0),
        'node_caps': random.uniform(0, 1.0),
        'deg_malig': random.uniform(0, 1.0),
        'breast': random.uniform(0, 1.0),
        'breast_quad': random.uniform(0, 1.0),
        'irradiat': random.uniform(0, 1.0)
    }

    values: set[HashDict[str, float]] = set({})

    def __init__(self, case):

        self.event = case[0]

        self.__data = {
            'age': None,
            'menopause': None,
            'size': None,
            'inv_nodes': None,
            'node_caps': None,
            'deg_malig': None,
            'breast': None,
            'breast_quad': None,
            'irradiat': None
        }

        for x in enumerate(self.__data.keys(), 1):
            self.__data[x[1]] = case[x[0]]
            CancerCase.values.add(HashDict([(case[x[0]], random.uniform(0, 1.0))]))

    def __str__(self):
        return f'{self.__data}'

    def get_data(self):
        return self.__data


def main(argv: List[str]):

    file = open(argv[1], 'r')

    CancerCases: npt.ArrayLike[Any] = np.array([])
    entries = file.readlines()

    for entry in entries:
        CancerCases = np.append(CancerCases, CancerCase(entry.split(',')))

    print(CancerCases[0].event)
    # print(CancerCase.values)

    return 1

if __name__ == '__main__':
    main(sys.argv)