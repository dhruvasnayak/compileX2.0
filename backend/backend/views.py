import json
import requests
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt

@csrf_exempt
def process_data(request):
    if request.method == 'POST':
        try:
            data = json.loads(request.body)
            input_data = data.get('input')
            code = data.get('code')
            language = data.get('language')
            
            api_url = 'http://localhost:5000/api/compilex'

            data = {
                'code': code,
                'input': input_data,
                'language': language
            }

            response = requests.post(api_url, json=data)
            response_data = response.json()

            return JsonResponse(response_data)

        except Exception as e:
            return JsonResponse({'error': 'An error occurred'}, status=500)
