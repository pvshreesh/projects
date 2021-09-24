# -*- coding: utf-8 -*-
"""
Created on Sun Mar  7 13:38:02 2021

@author: Nitin
"""

"""
import numpy as np
from sklearn.cluster import KMeans
from sklearn import metrics
shilv = np.zeros((56,9))
for i in range(1,57):
    print(i)
   # fname ='C:/Users/Nitin/Desktop/data/' + str(i) + '.xlsx'
    fname = str(i) + '.csv'
    data = np.genfromtxt(fname,delimiter = ',');
    for j in range(2,11):
        kmeans = KMeans(n_clusters=j,random_state = 0).fit(data[:0:-1])
        shilv[i-1,j-2] = metrics.silhouette_score(data[:0:-1], kmeans.labels_, metric ='euclidean')
        
fname = 'shilout.csv'
np.savetxt(fname,shilv,delimiter=',',fmt='%f')
"""
import numpy as np
import random

def add_values_in_dict(sample_dict, key, list_of_values):
    #Append multiple values to a key in the given dictionary
    if key not in sample_dict:
        sample_dict[key] = list()
    sample_dict[key].extend(list_of_values)
    return sample_dict





def samecul(a,b,cluster,arr):
    
    
    
    return 


def silvalue(ai,bi):
    maxval=max(ai,bi)
    value=(bi-ai)/maxval
    return value

def sil(i,cluster,arr,k):
    
    same_cul_dis=0
    same_cul_num=0
    diff_cul_dis=0
    diff_cul_num=0
    dis=0
    
    for j in range(len(arr)):
        if(i!=j && samecul(i,j,cluster,arr)):
            sum_sq = np.sum(np.square(arr[i] - arr[j]))
            dis = np.sqrt(sum_sq)
            same_cul_dis+=dis
            same_cul_num+=1
            
            
        if(i!=j && !samecul(i,j,cluster,arr)):
            sum_sq = np.sum(np.square(arr[i] - arr[j]))
            dis = np.sqrt(sum_sq)
            diff_cul_dis+=dis
            diff_cul_num+=1
            
    ai = same_cul_dis/same_cul_num
    bi = diff_cul_dis/same_cul_num
    value=silvalue(ai,bi)
    
    return value






for k in range(2,11):
    fname = str(k)+'.csv'
    data = np.genfromtxt(fname,delimiter = ',');
    arr = np.delete(data, -1, axis=1)
    randInd = random.sample(range(0, len(arr)), k)
    centroids = []
    for i in range(k):
        centroids.append(arr[randInd[i]])
        
    centtroids = np.array(centroids)
    distances = np.zeros((len(arr),k))
    
    while(1):
        for i in range(len(arr)):
            for j in range(k):
                sum_sq = np.sum(np.square(arr[i] - centroids[j]))
                distances[i][j] = np.sqrt(sum_sq)
              
        
        clusters = {}
        
        for i in range(len(arr)):
            minimum = min(distances[i])
            for j in range(k):
                if(distances[i][j] == minimum):
                    break
            
            #result = np.where(distances[i] == np.amin(distances[i]))
            #res = np.array(result)[indices.astype(int)]
            
            clusters = add_values_in_dict(clusters, j, [i])  #There can be multiple min distances so considering only first found one
        
        
        new_centroids = []
        for i in range(k):
            s = arr[0] - arr[0]
            for j in range(len(clusters[i])):
                s = s + arr[clusters[i][j]]
            new_centroids.append(s/len(clusters[i]))
            
        current = np.array(centroids)
        new_centroids = np.array(new_centroids)
        
        if(np.array_equal(centroids,new_centroids)):
            break
        centroids = new_centroids
    


    








