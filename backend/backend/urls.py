from django.contrib import admin
from django.urls import path
from .views import process_data

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/data', process_data, name='process_data'),

]
