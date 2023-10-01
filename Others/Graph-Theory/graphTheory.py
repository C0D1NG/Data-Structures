import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv
from operator import itemgetter
import networkx as nx
from networkx.algorithms import community #This part of networkx, for community detection, needs to be imported separately.
#reads the csv
stocks = pd.read_csv('STOCKDATA.csv')
#creates a correlation matrix
cor_matrix1 = stocks.iloc[:,1:].corr()
cor_matrix = stocks.corr()
#shows the first 5 rows
cor_matrix.head()
cor_matrix=np.matrix(cor_matrix)

#adjacency matrix for correlation greater than 0
size=len(cor_matrix)
adj_greater_0 = [[0]*size for i in range(size)]

for row in range( size):
    for col in range (size):
        if cor_matrix[row,col]>0:
            adj_greater_0[row][col]=1

#adjacency matrix for correlation less than 0
adj_less_0 = [[0]*size for i in range(size)]
for row in range( size):
    for col in range (size):
        if cor_matrix[row,col]<0:
            adj_less_0[row][col]=1

#adjacency matrix for correlation between -0.7 and 0.7

adj_btw_1 = [[0]*size for i in range(size)]
for row in range( size):
    for col in range (size):
        if cor_matrix[row, col]>-0.7 and cor_matrix[row, col]<0.7:
            adj_btw_1[row][col]=1



print("Grapgh for where correlations are below 0")
B= nx.from_numpy_matrix(np.array(adj_less_0))  
nx.draw(B, with_labels=True)
