from ctypes import *
lib = CDLL("./libcalci.dll")
check=lib.checkstu
studentuser=input("Enter Your Name : ")
studentpass=input("Enter Your Password : ")
check=lib.checkstu(studentuser.encode(),studentpass.encode())
if check==48 :
    print("Correct")
else :
    print("Wrong")



