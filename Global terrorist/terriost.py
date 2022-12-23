import matplotlib.pyplot as plt
import numpy as np
from collections import Counter

def convertToint(arr):
    """
    It converts a list of lists of strings to a list of lists of integers
    """
    sub_arr = []
    for j in arr:
        temp =[]
        for k in j:
            temp.append(eval(k))
        sub_arr.append(temp)
    return sub_arr

def insert_at_index(array, index, value):
    """
    "Create a new array with the value inserted."
    The function takes in three arguments: an array, an index, and a value
    """
    new_array = array[:index] + [value] + array[index:]
    return new_array  

def getSumarray(length, num):
    """
    It takes in a list of lists and returns a list of the sums of each list
    """
    sum_arr = []
    for i in range(length):
        sum_arr.append(sum(num[i]))
    return sum_arr    

def getDuplicatearray(length, num):
    """
    It takes an array of numbers and returns an array of the number of times each number appears in the
    original array
    """
    duplicate_arr = []
    for i in range(length):
        value = num[i]
        count = 0
        for element in num:
            if element == value:
                count += 1
        if count == 1:
            duplicate_arr.append(1)
        elif count > 1:
            duplicate_arr.append(count)   
    return duplicate_arr 

def printoutbarchart(x,y):
    # Plotting a bar graph of the second_index and occurrence.
    plt.title("A graph of Duplicate Values and Serial number")
    plt.bar(x, y, color='maroon')
    plt.xlabel('Series_number')
    plt.ylabel('Duplicate')
    plt.show()  

def printouttable2(colum1, colum2):
    """
    It prints out the table of the features and the duplicate column
    """
    print("\n")
    print("\n")
    print("S/N |\tFEATURES\t|  DUPLICATE")
    print("-"*40)
    for i in range(1, len(colum1)):
        print(f"{i}   {'|'}\t{','.join(colum1[i])}   |  {colum2[i]}\t")  

def printouttable1(length, colum1, colum2, colum3,colum4):
    """
    It prints out a table with the following columns: s/n, Features, Sum, Similar ID
    The first column is the serial number of the row
    """
    print("\n")
    print("S/N  |\tFEATURES      |\tSUM   |  SIMILAR ID")
    print('-'*60)
    for i in range(1, length):
        print(f"{colum1[i]:3}  |\t{','.join(colum2[i])} | {colum3[i]:3d}   |  {colum4[i]}\t")

def getduplicateseries(duplicate, string, feature):
    """
    If the number of duplicates is greater than or equal to 1, and the string is not in the feature
    list, then add the string to the feature list
    """
    feature = []
    for i in range(len(duplicate)):   
        if duplicate[i] >= 1:
            if string[i] in feature:
                continue
            else:
                feature.append(string[i])
    return feature

def getOccurenceodseries(feature, length, string):
    """
    It takes a string and a feature, and returns the number of times the feature occurs in the string
    """
    occur = []
    for i in range(len(feature)):
        num = 0
        for j in range(length):
            if string[j] == feature[i]:
                num+=1
        occur.append(num)
    return occur

def reducethelength(index, series):
    """
    If the length of the index is not equal to the length of the series, then the index is reduced to
    the length of the series
    """
    if len(series) != len(index):
        index = index[0:len(series)]
    return index
def assignid(index_similar, duplicate_arr):
    """
    It takes in the index of the similar words and the duplicate array and returns the ids of the
    similar words. 

    The function first creates an empty array called ids. It then iterates through the index_similar
    array and adds the current and previous index to the ids array. 
    The function then creates an array called complete that is filled with -1s. It then iterates through
    the duplicate array and if the duplicate is not 1, it adds the current index of the ids array to the
    complete array. If the duplicate is 1, it adds a space to the complete array. 
    
    The function then returns the complete array.
    """
    ids = []
    for index in range(1, len(index_similar), 2):
        prev = index_similar[index-1]
        current = index_similar[index]
        ids.append(current)
        ids.append(prev)

    # Creating an array of -1s that is the same length as the duplicate_arr array.
    complete = [-1] * len(duplicate_arr) 
    current_index = 0
    for duplicate_index in range(len(duplicate_arr)):
        duplicate = duplicate_arr[duplicate_index]   
        if duplicate != 1:
            complete[duplicate_index] = ids[current_index]
            current_index += 1
        else: 
            complete[duplicate_index] = " "

    return complete



# Opening the file and assigning it to the variable file.
file = open("/Users/rufus/Desktop/C project/terroist.txt", "r", encoding="utf-8")

# Creating an empty array.
first_index = []
second_index = []
string_array = []
num_array = []
sum_array = []
array_grouping = []
duplicate_array = []
similar_id = []

# Iterating over the file and assigning each line to the variable sequence.
for sequence in file:
    sequence = sequence.rstrip()
    sequence = sequence.split("\t")
    
    first_index.append(sequence[0])
    second_index.append(sequence[1])

# Iterating over the second_index array and assigning each element to the variable sequence.
for i in range(len(second_index)):   
    string_array.append(second_index[i].split(','))
# It converts a list of lists of strings to a list of lists of integers
num_array = convertToint(string_array)
length = len(num_array)
# It takes in a list of lists and returns a list of the sums of each list
sum_array = getSumarray(length, num_array)

# Iterating over the length of the array.
for i in range(length):
    search_number = num_array[i]
    # Iterate over the array and get the indexes of the matching numbers
    for i, number in enumerate(num_array):
        if number == search_number:
            array_grouping.append(i) 

# Converting the array_grouping array to a numpy array.
similar_id = np.array(array_grouping)
duplicate_array = getDuplicatearray(length, num_array)

# Iterating over the similar_id array and getting the indexes of the matching numbers.
index_of_similar_id = [item for item, count in Counter(similar_id).items() if count > 1]
complete_id = assignid(index_of_similar_id, duplicate_array)

# Creating an empty array.
features_id = [] 
occurrence = []
# Getting the duplicate series.
features_id = getduplicateseries(duplicate_array, string_array, features_id)
occurrence = getOccurenceodseries(features_id, length, string_array)

# It prints out a table with the following columns: s/n, Features, Sum, Similar ID
# The first column is the serial number of the row
printouttable1(length, first_index, string_array, sum_array, complete_id)  
# It prints out the table of the features and the duplicate column
printouttable2(features_id, occurrence)
first_index = reducethelength(first_index, features_id)
printoutbarchart(first_index, occurrence)