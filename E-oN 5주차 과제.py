array = list(map(int, input("숫자를 입력하세요. : ").split()))   #입력한 숫자를 받을 배열 선언
i, j, k = map(int, input("i번째 숫자 j번째 숫자  k번째의 숫자 각 숫자를 입력하세요. : ").split())
def commands (a, i, j, k): 
    a = a[i-1 :j]
    a.sort()
    return a[k-1]
print(commands(array, i, j, k))

