#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import glob

import numpy as np
import matplotlib.pyplot as plt


csv_files = glob.glob('*.csv')

fig = plt.figure()
ax = fig.add_subplot(111)

colors = iter(plt.cm.rainbow(np.linspace(0,1,len(csv_files))))

for csv_file in csv_files:
    data = np.genfromtxt(csv_file, delimiter=',', skip_header=1).transpose()
    j   = data[0]
    N   = data[1]
    avg = data[2]
    std = data[3]
    ax.errorbar(N, avg, yerr=std, label=csv_file, color=next(colors), marker='o')

ax.set_xlabel('N')
ax.set_ylabel('Timing [ms]')
ax.legend(loc='best')

plt.show()
