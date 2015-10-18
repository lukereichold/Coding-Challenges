# RubyQuiz.com Quiz #68 - Current Temperature - http://rubyquiz.com/quiz68.html
# Given a ZIP code as an argument, output the current temperature of that location.
# Example usage: 'python3 temperature.py 63026'
import sys, requests, credentials

# Pull weather data from OpenWeatherMap API
api_key = credentials.login['api_key']
BASE_REQUEST_URL = 'http://api.openweathermap.org/data/2.5/weather?zip={zip},us&units=imperial&appid={key}'

def fetch_temperature(zip_code):
	url = BASE_REQUEST_URL.format(zip=zip_code, key=api_key)
	return requests.get(url).json()['main']['temp']

zip_ = sys.argv[1]
print ("Current temperature in {zip}: {temp}°".format(zip=zip_, temp=fetch_temperature(zip_)))
