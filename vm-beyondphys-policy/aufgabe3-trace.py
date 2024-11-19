import random
import argparse
from optparse import OptionParser

def generatetrace(size=10, range1=6, locality=False):
    trace = []
    valid_pages = list(range(1,range1))
    if locality:
        hot_adresses = [1, 2, 3]
        for _ in range (size):
            if random.random() < 0.7:
                trace.append(random.choice(hot_adresses))
            else:
                trace.append(random.choice(valid_pages))
    else:
        trace.append(random.choice(valid_pages))
    return trace


def main():
    parser = OptionParser()
    parser.add_option('-s', '--size', default='10',   help='size of trace',  action='store', type='int', dest='size')
    parser.add_option('-r', '--range', default='6',   help='range of pages', action='store', type='int', dest='range1')
    parser.add_option('-l', '--locality', default='False',    help='set locality',action='store', type='Boolean', dest='locality')
    (options, args) = parser.parse_args()

    trace = generatetrace(size=options.size, range1=options.range1, locality=options.locality)
    print(trace)

if __name__ == "__main__":
    main()