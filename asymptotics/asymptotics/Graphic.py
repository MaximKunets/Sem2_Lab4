import matplotlib.pyplot as plt
import matplotlib.style as style
import pandas as pd
import numpy as np

print("Введите, какой график хотите:\n0 - push_back (vector)\n1 - pop_back\n2 - push_front (vector) "
      "\n3 - push_back (list)\n4 - push_front (list)")
c = int(input())
if c == 0:
    data = pd.read_csv('./output_push_back.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 1:
    data = pd.read_csv('./output_pop_back.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 2:
    data = pd.read_csv('./output_push_front.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 3:
    data = pd.read_csv('./output_push_back_list.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 4:
    data = pd.read_csv('./output_push_front_list.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')

style.use('ggplot')

x = data['N'].to_numpy()
y = data['Time'].to_numpy()

plt.ylabel('Time, nanosec')
plt.xlabel('N')

plt.plot(x, y)
plt.show()
