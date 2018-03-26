from geopy.geocoders import Nominatim
import pandas as pd
from xlutils.copy import copy
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import clipboard
import json
import time

geolocator = Nominatim()
browser = webdriver.Firefox()
browser.get("https://www.facebook.com")

username = browser.find_element_by_xpath('//*[@id="email"]')
password = browser.find_element_by_xpath('//*[@id="pass"]')

user_ID = 'user_id' #Please type User_ID for your facebook
username.send_keys("username") #enter your username for facebook tologin
password.send_keys("facebook")   #enter your password for facebook

browser.find_element_by_id('loginbutton').click()

appendeddf = pd.DataFrame()

while 1:
	#Please enter your facebook profile userid in the place of USER_ID
	time.sleep(2)
	#Start of level0
	browser.get('https://www.facebook.com/ajax/livemap/map/data/?level=0&video_count=500&dpr=1&__user='+ user_ID + '&__a=1&')
	pre = browser.find_element_by_tag_name("pre").text
	etc = pre[9:]
	data = pd.read_json(etc, typ='series')
	df = pd.DataFrame.from_dict(data['payload']['streams'], orient='columns')

	del df['url']
	del df['startTime']
	del df['name']
	del df['previewImage']
	del df['publisherCategory']
	del df['profilePicture']
	del df['width']
	del df['message']
	del df['messageRanges']
	del df['height']
	del df['formattedCount']
	appendeddf = appendeddf.append(df, ignore_index =True)
	#Start of level1
	browser.get('https://www.facebook.com/ajax/livemap/map/data/?level=1&video_count=500&dpr=1&__user='+ user_ID + '&__a=1&')
	pre = browser.find_element_by_tag_name("pre").text
	etc = pre[9:]
	data = pd.read_json(etc, typ='series')
	df2 = pd.DataFrame.from_dict(data['payload']['streams'], orient='columns')

	del df2['url']
	del df2['startTime']
	del df2['name']
	del df2['previewImage']
	del df2['publisherCategory']
	del df2['profilePicture']
	del df2['width']
	del df2['message']
	del df2['messageRanges']
	del df2['height']
	del df2['formattedCount']
	appendeddf = appendeddf.append(df2, ignore_index =True)
	
	#Start of level2
	browser.get('https://www.facebook.com/ajax/livemap/map/data/?level=2&video_count=500&dpr=1&__user='+ user_ID + '&__a=1&')
	
	pre = browser.find_element_by_tag_name("pre").text
	etc = pre[9:]
	data = pd.read_json(etc, typ='series')
	df3 = pd.DataFrame.from_dict(data['payload']['streams'], orient='columns')

	del df3['url']
	del df3['startTime']
	del df3['name']
	del df3['previewImage']
	del df3['publisherCategory']
	del df3['profilePicture']
	del df3['width']
	del df3['message']
	del df3['messageRanges']
	del df3['height']
	del df3['formattedCount']
	#all appended into one dataframe
	appendeddf = appendeddf.append(df3, ignore_index =True)
        temp_df = appendeddf.groupby(["videoID"])["viewerCount"].apply(list).reset_index()
	del appendeddf['viewerCount']
	appendeddf = appendeddf.merge(temp_df, how='left',on='videoID')
	appendeddf.drop_duplicates(subset='videoID', keep = 'first', inplace = True)
	print appendeddf
	time.sleep(30)
	print ("Sleeping for 30 seconds, Press Ctrl+C if you want to stop here!")
	time.sleep(30)
