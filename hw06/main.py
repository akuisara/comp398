""" 
Programmer:  Qi Zhang 
Summary:     This program extracts data from Wheaton Course Schedule and creates a SVG img and another HTML page.  """

import requests
from bs4 import BeautifulSoup 

def main():
    data = {'submit_btn' : 'Search Schedule', 'schedule_beginterm':'201510'}
    url = 'https://weblprod1.wheatonma.edu/PROD/bzcrschd.P_OpenDoor'

    r = requests.post(url=url, data=data)

    doc = BeautifulSoup(r.content.decode('utf-8'))
    doc.prettify().encode('utf-8')
    # print doc.prettify().encode('utf-8')

    myString = "<?xml version='1.0' standalone='no'?>\n<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN' 'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>\n<svg version='1.1' baseProfile='full' width='100%' xmlns='http://www.w3.org/2000/svg' xmlns:xlink= 'http://www.w3.org/1999/xlink'>\n<rect width='100%' height='1000%' fill='#f0f0f0' />\n</svg>"
    svg = open("schedule.svg",'w')
    svg.write(myString)

    # tag = doc.body
    # tag['class'] = 'addClass'
    # tag['background-image'] = "url('schedule.svg')"
    # print(tag.get('class'))

    ouputFile = open("schedule.html",'w')
    ouputFile.write(str(doc))

    # for i in r.iter_content():
    #     ouputFile.write(str(i))    
    
if __name__ == '__main__':
    main()