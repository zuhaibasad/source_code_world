from geopy.geocoders import Nominatim
import xlwt
from xlutils.copy import copy
from selenium import webdriver
import json
import time

browser = webdriver.Firefox()
browser.get("https://www.facebook.com")

username = browser.find_element_by_xpath('//*[@id="email"]')
password = browser.find_element_by_xpath('//*[@id="pass"]')

username.send_keys("username") #enter your username for facebook tologin
password.send_keys("password")   #enter your password for facebook

browser.find_element_by_id('loginbutton').click()

writebook = xlwt.Workbook()


geolocator = Nominatim()

style_string = "font: bold on; borders: bottom dashed"
style = xlwt.easyxf(style_string)
a=1
while 1:
	sheet1 = writebook.add_sheet('sheet'+str(a))
	sheet1.write(0,0, "VideoID", style=style)
	sheet1.write(0,1, "Latitude", style=style)
	sheet1.write(0,2, "Longitude", style=style)
	sheet1.write(0,3, "Location", style=style)
	sheet1.write(0,4, "Viewer Count", style=style)

	lent = 0
	j=1

	for x in [0,1,2]:
		#Please enter your facebook profile userid in the place of USER_ID
		time.sleep(2)
		browser.get('https://www.facebook.com/ajax/livemap/map/data/?level='+ str(x) +'&video_count=500&dpr=1&__user=100013275665525&__a=1&')
		pre = browser.find_element_by_tag_name("pre").text
		etc = pre[9:]
		parsed_json = json.loads(etc)

		lent = len(parsed_json['payload']['streams'])
		print lent,j
		i=0
		while i<lent:

			lat = parsed_json['payload']['streams'][i]['lat']
			long = parsed_json['payload']['streams'][i]['long']

			list = [lat, long]
			point = tuple(list)
			location = geolocator.reverse(point, language='en', timeout=1000)
			sheet1.write(j, 0, parsed_json['payload']['streams'][i]['videoID'] )
			sheet1.write(j, 1, lat)
			sheet1.write(j, 2, long)
			sheet1.write(j, 3, location.address)
			sheet1.write(j, 4, parsed_json['payload']['streams'][i]['viewerCount'] )
			writebook.save("output.xlsx")
			j=j+1
			i=i+1
	a =a+1
	print ("Sleeping for 30 seconds, Press Ctrl+C if you want to stop here!")
	time.sleep(30)
