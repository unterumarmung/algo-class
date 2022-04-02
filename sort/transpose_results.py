import pandas

data = pandas.read_csv('results/output.csv', index_col='SortName').dropna(axis='columns').transpose()

data.to_csv('results/output_transposed.csv')
