value = list()                                                    #입력한 숫자를 저장할 배열 선언 
locate = 0                                                        #배열의 위치를 바꿔줄 변수 
i = 1
a = int(input("입력할 숫자의 갯수를 적어주세요. :"))              #입력할 숫자의 갯수 
while i <= a:                                                     #입력한 숫자를 배열에 저장하기 위한 while문 윗줄에서 입력한 수 만큼 숫자를 저장 
   b = int(input(" %d 번째 더할 수를 입력해주세요. :" %(i)))
   value.insert(locate, b)
   i += 1
   locate +=1

def sum(value):                                                   #저장된 배열의 요소를 합하기 위한 재귀함수 
    if len(value) < 2:                                            #함수를 탈출하기 위한 조건문 
        return value.pop()
    else:
        pop = value.pop()                                         #배열에서 숫자를 하나씩 떼어내어 number에 더함 
        number = pop + sum(value)
        return number

print("입력한 수 : ", value)     
print("출력 값 : " , sum(value))
