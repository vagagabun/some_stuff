import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt

m_time = []
m_time_average = []
m_time_average_square = []
n = float(input())
sum_of_mtime = 0
t_average = 0
m = 0
k = 0
sigma = 0
p_max = 0
delta_t = 0


while n != 0:
    m_time.append(n)
    n = float(input())

print("Таблица с t:")
for j in range(len(m_time)):
    print(j, "   ", m_time[j])
print()

for i in range(len(m_time)):
    sum_of_mtime += m_time[i]
t_average = sum_of_mtime/len(m_time)
t_average = round(t_average, 4)


print("Таблица с t-<t>:")
for i in range(len(m_time)):
    m = m_time[i] - t_average
    m_time_average.append(m)
for j in range(len(m_time_average)):
    print(j, "   ", round(m_time_average[j], 4))
print()

print("Таблица с (t-<t>) в квадрате:")
for i in range(len(m_time_average)):
    n = m_time_average[i]**2
    m_time_average_square.append(n)
for j in range(len(m_time_average_square)):
    print(j, "   ", round(m_time_average_square[j], 4))
print()

sigma = ((1/50) * sum(m_time_average_square))**0.5
p_max = ((1)/(sigma *(2 * 3.14)**0.5))
delta_t = (max(m_time) - min(m_time))/(7)

print("<t> = ", t_average)
print("max =",  max(m_time))
print("min = ", min(m_time))
print("m_time_average_sum = ", round(sum(m_time_average), 4))
print("σ = ", sigma)
print("p_max = ", p_max)
print("delta_t = ", delta_t)

data = m_time
data.sort()
mu, std = norm.fit(data)
plt.hist(data, bins=7, density=True, alpha=0.6, color='g')
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)
plt.plot(x, p, 'k', linewidth=2)
title = "Fit results: mu = %.2f,  std = %.2f" % (mu, std)
plt.title(title)

plt.show()




