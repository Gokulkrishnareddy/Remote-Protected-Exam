from django.urls import path
from authentication import views
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
urlpatterns = [
    path('',views.home,name="home"),
    path('signin/' ,views.signin,name="signin"),
    path('index/' ,views.home,name="index"),
    path('face/',views.face,name="face"),
    path('host/' ,views.host,name="host"),
    path('inve/' ,views.inve,name="inve"),
    path('mcq/' ,views.mcq,name="mcq"),

]

urlpatterns += staticfiles_urlpatterns()