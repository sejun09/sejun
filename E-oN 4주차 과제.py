a = list(map(int, input("오름차순으로 정렬할 숫자를 입력하세요: ").split()))

def bubble_sort(bubble):
    for i in range(1, len(bubble), 1):         # list에 입력된 숫자의 갯수만큼 반복
        for j in range(1, len(bubble), 1 ):    # list의 첫번 째 자리부터 list의 마지막 자리까지 1씩 더해가며 정렬
            if bubble[j-1] > bubble[j]:
                bubble[j-1], bubble[j] = bubble[j], bubble[j-1]              
    return bubble                              # 함수 값 반환
print("정렬 전 숫자",a)
print("정렬 후 정렬", bubble_sort(a))          # 정렬 후 값 출력 

