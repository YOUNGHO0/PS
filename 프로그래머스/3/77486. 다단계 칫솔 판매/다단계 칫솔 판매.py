

import sys
limit_number = 15000
sys.setrecursionlimit(limit_number)

def dfs(refer,total,name,price):
    
    total[name] += price -price //10
    
    if refer[name] != '-' and price//10 !=0:
        dfs(refer,total,refer[name],price//10)
        

def solution(enroll, referral, seller, amount):
    answer = []
    total = {name:0 for name in enroll}
    refer = {}
    for i,enrol in enumerate(enroll):
        refer[enrol] = referral[i]
    
    for i,sel in enumerate(seller):
        dfs(refer,total,seller[i],amount[i]*100)
    

    return [total[e]for e in total]