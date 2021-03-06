import math
import random
import numpy
def isprime(num):   #判断素数
    if num==2:
        return True
    else:
        for i in range(2,int(math.sqrt(num))):
            if num%i==0:
                return False
    return True

def genrandbits(w):  # w表示的2进制序列位数
    list = []
    list.append('1')  #最高位定为1
    for i in range(w - 2):
       c = numpy.random.choice(['0', '1'])
       list.append(c)
    list.append('1') # 最低位定为1
    res = int(''.join(list),2)
    return res

def genbigprime(w):         #生成w位大素数
    bigprime=genrandbits(w)
    while not isprime(bigprime):
        bigprime=genrandbits(w)
        for i in range(50):
            bigprime=bigprime+2*i
            if isprime(bigprime):
                return bigprime
            else:
                continue
    return bigprime

def gcd(a,b):               #求a,b最大公因数
    if a%b == 0:
        return b
    else :
        return gcd(b,a%b)

def gen_n(w):               #生成n
    p=1
    q=1
    while(p%4!=3):
       p=genbigprime(w)
    while(q%4!=3):
       q=genbigprime(w)
    return p*q

def finds(n):               #找到随机数s与n互素
    s=random.randint(2,int(math.sqrt(n)))
    while(gcd(s,n)!=1):
        s=random.randint(2,int(math.sqrt(n)))
    return s
def bbs(n,s):               #生成随机二进制序列
    x=pow(s,2,n)
    b=[]
    count=20
    while(count>0):
        x=pow(x,2,n)
        b.append(x%2)
        count=count-1
    return b

for i in range(10):
    n=gen_n(16)
    s=finds(n)
    bitset=bbs(n,s)
    print("生成的20位随即比特序列是: %s" %(''.join(str(x) for x in bitset)))
