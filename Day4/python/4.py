
import hashlib
 
str2hash = "ckczppom"

found = False
i = 0

while found != True :
    result = hashlib.md5((str2hash + str(i)).encode()).hexdigest()
    if result.startswith("000000") :
        found = True
        print("The hexadecimal equivalent of hash is : ", end ="")
        print(result)
        print("The lowest number is : ", end ="")
        print(i)
    else :
        i = i+1