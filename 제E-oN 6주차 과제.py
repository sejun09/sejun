from functools import reduce                # 내장함수 호출            
import operator as op
number = int(input("피자의 조각 수를 입력해주세요. :"))   #조각 수 입력 
sum = b = 0
def nCr(n, r):      #조합의 개수 구할 함수 선언 
     r = min(r, n-r)      #r과 n-r은 같기 때문에 더 작은 숫자를 사용
     n = reduce(op.mul, range(n, n-r, -1), 1)     #분자의 수 구할 식
     d = reduce(op.mul, range(1, r+1), 1)         #분모의 수 구할 식
     return n//d                #분자/분모로 조합 개수 반환

while b <= number//2:      #2의 개수에 따라 조합 함수를 반복 
    a = number - b
    sum = sum + nCr(a, b)  #반복한 조합의 수를 sum에 더하기 
    b += 1

print(sum)   #경우의 수 출력


