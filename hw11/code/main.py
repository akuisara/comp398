import re
import requests
from bs4 import BeautifulSoup 

def main():
    data = {'submit_btn' : 'Search Catalog', 'schedule_beginterm':'201510', 'subject_cat':'CONX'}
    url = 'https://weblprod1.wheatonma.edu/PROD/bzcrschd.P_OpenDoor'

    r = requests.post(url=url, data=data)

    doc = BeautifulSoup(r.content.decode('utf-8'))
    doc.prettify().encode('utf-8')

    connectionNames = re.compile(r'CONX [0-9][0-9][0-9][0-9][0-9]')
    descriptions = re.compile(r'[A-Z][a-z][a-z][a-z]?[a-z]? |(or three) course connection')
    
    connections = {}
    nameList = []
    descriptionList = []

    rows = doc.find_all('tr')
    for i in range(len(rows)):
        arow = rows[i]

        content = arow.find('td').getText().encode('utf-8').strip()
        if connectionNames.match(content):
            nameList.append(str(content).replace('\'','`'))
        if descriptions.match(content):
            descriptionList.append(str(content).replace('\'','`'))

    with open('connections.json', 'w') as outputFile:
        outputFile.write("{\"connections\": [\n")
        for i in xrange(len(nameList)):
            oneConnection = {}
            oneConnection.update({"CourseName":nameList[i]})
            print len(descriptionList)
            print len(nameList)
            oneConnection.update({"CourseDescription":descriptionList[i]})

            outputFile.write('\t'+str(oneConnection).replace('\'', '"')+'\n')
                
        outputFile.write("]}")
    
if __name__ == '__main__':
    main()