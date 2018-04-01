'''
Created on Mar 24, 2018

@author: 44386
'''
def convert(s, numRows):
    """
    :type s: str
    :type numRows: int
    :rtype: str
    """
    index=0
    a=['']*numRows
    for x in s:
        if index==0:
            direction=1
        if index==numRows-1:
            direction=-1
        a[index]=a[index]+x
        index=index+direction if index+direction>=0 else 0
    return ''.join(a)
s='abcdefghi'
print(convert(s,1))