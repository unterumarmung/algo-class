import pandas
import matplotlib.pyplot as plt

data = pandas.read_csv('results/output.csv', index_col='SortName').dropna(axis='columns').transpose()

data.index = [int(x) for x in data.index]

print(data.head())

data.plot(legend=True, logy=True)

plt.savefig('results/plot.png')
