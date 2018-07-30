from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import json
import time
import xlrd
import xlsxwriter

#excel file where website URL is placed from where to get email (if you preferr excel)
workbook = xlrd.open_workbook("People_Profile_Links.xls")
sheet = workbook.sheet_by_name("People Information")

writebook = xlsxwriter.Workbook('output.xls')
worksheet = writebook.add_worksheet()
bold = writebook.add_format({'bold': True})

merge_format = writebook.add_format({'bold': 1,'align': 'center','valign': 'vcenter'})

worksheet.write('A1', "Name", bold)
worksheet.write('A2', " - ", bold)

worksheet.write('B1', "Current Job", bold)
worksheet.write('B2', " - ", bold)

worksheet.write('C1', "Company & School", bold)
worksheet.write('C2', " - ", bold)

worksheet.write('D1', "Address", bold)
worksheet.write('D2', " - ", bold)

worksheet.write('E1', "Connections", bold)
worksheet.write('E2', " - ", bold)

worksheet.merge_range('F1:J1', "Experience", merge_format)
worksheet.write('F2', "Field-1", bold)
worksheet.write('G2', "Field-2", bold)
worksheet.write('H2', "Field-3", bold)
worksheet.write('I2', "Field-4", bold)
worksheet.write('J2', "Field-5", bold)

worksheet.merge_range('K1:O1', "Education", merge_format)
worksheet.write('K2', "Field-1", bold)
worksheet.write('L2', "Field-2", bold)
worksheet.write('M2', "Field-3", bold)
worksheet.write('N2', "Field-4", bold)
worksheet.write('O2', "Field-5", bold)

worksheet.write('P1', "Interests", bold)
worksheet.write('P2', " - ", bold)

browser = webdriver.Firefox()
browser.get("https://www.linkedin.com")

username = browser.find_element_by_xpath('//*[@id="login-email"]')
password = browser.find_element_by_xpath('//*[@id="login-password"]')

username.send_keys("zuhaibasad@gmail.com") #enter your username for facebook tologin
password.send_keys("zuhaibasad1")   #enter your password for facebook

browser.find_element_by_id('login-submit').click()


i = 1
next = 3
while i <= 45:
	link = sheet.cell(i,0).value
	if link:
		browser.get(link)
		browser.execute_script("window.scrollTo(0, document.body.scrollHeight)")
		time.sleep(3)
		header = browser.find_element_by_xpath("//*[@class='pv-top-card-section__information mt3 ember-view']")
		experience1 = browser.find_elements_by_xpath("//*[@class='pv-profile-section__sortable-item pv-profile-section__section-info-item relative sortable-item ember-view']")
		experience2 = browser.find_elements_by_xpath("//*[@class='pv-profile-section__card-item pv-position-entity ember-view']")
		education1 = browser.find_elements_by_xpath("//*[@class='pv-education-entity pv-profile-section__card-item ember-view']")
		education2 = browser.find_elements_by_xpath("//*[@class='pv-profile-section__sortable-card-item pv-education-entity pv-profile-section__card-item ember-view']")
		interest = browser.find_elements_by_xpath("//*[@class='pv-interest-entity pv-profile-section__card-item ember-view']")

		strhead = header.text
		prophead = strhead.split("\n")
	
		strexp = []
		stredu = []
		strint = []
		propexp = []
		propedu = []
		propint = []
		experience = experience2
		if experience1:
			experience = experience1
			if education1:
				if (experience1[0].text == education1[0].text):
					experience = experience2
			if education2:
				if (experience1[0].text == education2[0].text ):
					experience = experience2

		zz=0
		while zz < len(experience):

			strexp.append(experience[zz].text)
			propexp.append(strexp[zz].split("\n"))
			zz = zz+1
		zz=0
		if education1:
			while zz < len(education1):

				stredu.append(education1[zz].text)
				propedu.append(stredu[zz].split("\n"))
				zz = zz+1

		if education2:
			while zz < len(education2):

				stredu.append(education2[zz].text)
				propedu.append(stredu[zz].split("\n"))
				zz = zz+1
		
		zz=0
		while zz < len(interest):
			strint.append(interest[zz].text)
			propint.append(strint[zz].split("\n"))
			zz = zz+1


		####  Header       #####
		worksheet.write("A"+ str(next), prophead[0] )
		worksheet.write("B"+ str(next), prophead[1] )
		worksheet.write("C"+ str(next), prophead[2] )
		worksheet.write("D"+ str(next), prophead[3] )
		worksheet.write("E"+ str(next), prophead[4] )
		########################
	
		####  experience   #####
		j=0
		x=next
		while j<len(propexp):
			if len(propexp[j]) == 3:
				worksheet.write("F"+ str(x), propexp[j][0] )
				worksheet.write("G"+ str(x), propexp[j][2] )
			elif len(propexp[j]) < 6:
				worksheet.write("F"+ str(x), propexp[j][0] )
				worksheet.write("G"+ str(x), propexp[j][2] )
				worksheet.write("H"+ str(x), propexp[j][4] )
			elif len(propexp[j]) > 6 and len(propexp[j]) < 9:
				worksheet.write("F"+ str(x), propexp[j][0] )
				worksheet.write("G"+ str(x), propexp[j][2] )
				worksheet.write("H"+ str(x), propexp[j][4] )
				worksheet.write("I"+ str(x), propexp[j][6] )

			if len(propexp[j]) == 9:
				worksheet.write("J"+ str(x), propexp[j][8] )

			x=x+1		
			j=j+1
		########################
		cap1 = x
		#####  education  ########
		j=0
		x=next
		while j<len(propedu):
			if len(propedu[j]) < 6:
				worksheet.write("K"+ str(x), propedu[j][0] )
			elif len(propedu[j]) > 6:			
				worksheet.write("K"+ str(x), propedu[j][0] )
				worksheet.write("L"+ str(x), propedu[j][2] )
				worksheet.write("M"+ str(x), propedu[j][4] )
				worksheet.write("N"+ str(x), propedu[j][6] )

			if len(propedu[j]) > 7:
				worksheet.write("O"+ str(x), propedu[j][7] )
			x=x+1
			j=j+1
		##########################
		cap2 = x
		####  Interests ##########
		j=0
		x=next
		while j < len(propint):
			worksheet.write("P"+ str(x), propint[j][0] )
			x=x+1		
			j=j+1
		##########################
		cap3 = x
		next = max(cap1,cap2,cap3)
		print i
	i=i+1

browser.close()
writebook.close()
