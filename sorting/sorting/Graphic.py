import matplotlib.pyplot as plt
import matplotlib.style as style
import pandas as pd
import numpy as np

print("Введите, какой график хотите:\n0 - сортировка выбором \n1 - сортировка Хоара")
c = int(input())
if c == 0:
    data = pd.read_csv('./output_sort_by_choice.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 1:
    data = pd.read_csv('./output_hoare_sorting.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')

style.use('ggplot')

x = data['N'].to_numpy()
y = data['Time'].to_numpy()

plt.ylabel('Time, nanosec')
plt.xlabel('N')

plt.plot(x, y)
plt.show()
