'''
Created on Mar 26, 2018

@author: 44386
'''
def intToRoman(num):
    tho=list()
    hun=list()
    ten=list()
    dig=list()
    for i in range(10):
        tho.append('M'*i)
        if i==9:
            hun.append('CM')
            ten.append('XC')
            dig.append('IX')
        elif i>=5:
            hun.append('D'+'C'*(i-5))
            ten.append('L'+'X'*(i-5))
            dig.append('V'+'I'*(i-5))
        elif i==4:
            hun.append('CD')
            ten.append('XL')
            dig.append('IV')
        else:
            hun.append('C'*i)
            ten.append('X'*i)
            dig.append('I'*i)
    return tho[num//1000]+hun[(num%1000)//100]+ten[(num%1000%100)//10]+dig[num%1000%100%10]
def romanToInt(s):
    s=list(s)
    for i in range(len(s)):
        if s[i]=='M': s[i]=1000 
        if s[i]=='D': s[i]=500 
        if s[i]=='C': s[i]=100 
        if s[i]=='L': s[i]=50 
        if s[i]=='X': s[i]=10 
        if s[i]=='V': s[i]=5 
        if s[i]=='I': s[i]=1 
    for i in range(len(s)):
        if(i+1<len(s) and s[i]<s[i+1]):
            s[i]=-s[i]
    return sum(s)
i=intToRoman(4321)
print(i)
print(romanToInt(i))