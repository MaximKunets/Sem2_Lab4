import matplotlib.pyplot as plt
import matplotlib.style as style
import pandas as pd
import numpy as np

print("Введите, какой график хотите:\n0 - вставка элемента \n1 - поиск элемента\n2 - удаление элемента")
c = int(input())
if c == 0:
    data = pd.read_csv('./output_insert.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 1:
    data = pd.read_csv('./output_serch.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 2:
    data = pd.read_csv('./output_delete.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')

style.use('ggplot')

x = data['N'].to_numpy()
y = data['Time'].to_numpy()

plt.ylabel('Time, nanosec')
plt.xlabel('N')

plt.plot(x, y)
plt.show()
