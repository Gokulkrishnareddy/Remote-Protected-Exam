from django.db import IntegrityError
from django.contrib.auth.models import User
from django.http.response import HttpResponse
from django.shortcuts import redirect, render
import cv2 as cv
import time
from ctypes import *

###The following Python Code uses various concepts from python language 
#->django for web based development 
#->opencv and haarcascade for frontal face detection (AI-proctrated Exam)
#->integration of python and c for backend database operations 
#->time library for backend opertion 

###Other concepts Used in Pariksha 
#->Html 
#->CSS for gui
#->javascript  


lib = CDLL("./libcalci.dll")
n=lib.chck_teacher
# check=lib.checkstu
def home(request):
    return render(request,"authentication/index.html")
def check(username,password,rollno,email) :
    
    rollno=rollno+'\n'
    file_name=open("C://Users/vishnu/Desktop/pariksha/main/authentication/stdb.txt","r")
    i=0
    linenumber=0
    content = file_name.readlines()
    test=[i.split('\t', 3)[2] for i in content]
    for i in range (0,len(test)):
        if email == test[i]:
            linenumber=i
    line=content[linenumber]
    data=line.split('\t')
    i=0
    if username==data[0]:
        i+=1
    if password==data[1]:
        i+=1
    if email==data[2]:
        i+=1
    if rollno==data[3]:
        i+=1
    return i
def signin(request):
    if request.method=='POST':
        studentuser=request.POST['username']
        studentpass=request.POST['pass1']
        studentroll=request.POST['roll']
        studentemail=request.POST['emailaddress']
        #check=lib.checkstu(studentuser.encode(),studentpass.encode())
        verify=check(studentuser,studentpass,studentroll,studentemail)
        if verify==4:
            return redirect('/face')
        else:
            return render(request,'authentication/signin.html',{'error':'Please enter correct credentials'})


    return render(request,"authentication/signin.html")


def face(request):
    
  if request.method=='POST':
    t1=0
    fd=0
    t=0
    
    def t(trf,t1):
        time.sleep(0.05)
        if trf==0:
            t1+=1
        if trf==1:
            t1=0
        if (t1==50):
          return 0,t1
        else:
           return 1,t1
    
    capture = cv.VideoCapture(0)
    while True:
        isTrue ,frame = capture.read()
        gray=cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
        haar_cascade = cv.CascadeClassifier("C://Users/vishnu/Desktop/pariksha/main/haar_face.xml")
        face_rect= haar_cascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=6)
        for x,y,w,h in face_rect:
            detected_face= cv.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),4)
        if t==0:
            t+=1
            return render(request,'authentication/mcq.html')
        if(len(face_rect)==0):
            cv.imshow("Video",frame)
            fd=0
        else:
            cv.imshow("Video",detected_face)
            fd=1
        if (cv.waitKey(1) & 0xFF==ord('d')) or t1==50 :
            break
        a,t1=t(fd,t1)
        if t1==50:
                return render(request,'authentication/face.html',{'Facenot':'Your Face is not detected'})
        
    capture.release()
    cv.destroyAllWindows()
    
    return render(request,'authentication/face.html',{'stop':'Your Exam has Ended'})
  return render(request,'authentication/face.html',{'start':'Click on Start and Start your exam'})

def host(request):
    if request.method=='POST':
        hostuser=request.POST['username1']
        hostpass=request.POST['pass1']
        n=lib.chck_teacher(hostuser.encode(),hostpass.encode())
        if n==1:
             return render(request,'authentication/inve.html')
        else:
            return render(request,'authentication/host.html',{'error':'Please enter correct credentials'})
    return render(request,"authentication/host.html")
def mcq(request):
    return render(request,'authentication/mcq.html')

def inve(request):
    return render(request,'authentication/inve.html')

