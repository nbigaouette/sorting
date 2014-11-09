#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import glob
import re
import os
import sys

import numpy as np
import matplotlib.pyplot as plt


if len(sys.argv) == 1:
    print('Usage: plot.py path/to/build/profiling')
    sys.exit(1)

csv_files = glob.glob(os.path.join(sys.argv[1], '*.csv'))

if (len(csv_files) == 0):
    print('No csv found in ' + sys.argv[1] + '!')
    sys.exit(1)

fig = plt.figure()
ax = fig.add_subplot(111)

colors = iter(plt.cm.rainbow(np.linspace(0,1,len(csv_files))))

p = re.compile(r'profiling_(.*?)_(.*?)\.csv')
ms_to_s = 1.0 / 1000.0

for csv_file in csv_files:
    data = np.genfromtxt(csv_file, delimiter=',', skip_header=1).transpose()
    j   = data[0]
    N   = data[1]
    avg = data[2]
    std = data[3]
    m = p.search(csv_file)
    name = m.group(2)
    name = name.replace('_', ' ')
    ax.errorbar(N, avg*ms_to_s, yerr=std*ms_to_s, 
                label=name, color=next(colors), marker='o')

ax.grid(True)
ax.set_xlabel('N')
ax.set_ylabel('Timing [s]')
ax.set_xscale('log')
ax.set_yscale('log')
ax.legend(loc='best')

plt.show()
