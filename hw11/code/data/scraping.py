import json

def main():
    
    json_data=open('conx.json')
    data = json.load(json_data)

    graph = {}
    nodeList = []
    linksList = []

    conxList = []

    for i in data:
        conx = data[str(i)]

        areaList = []

        for j in conx:
            area = conx[str(j)]
            if not area in areaList:
                areaList.append(area)

            for k in xrange(len(area)):
                course = area[k].replace("-"," ").encode("utf-8")
                
                newNode = {}
                newNode.update({"name":course})
                if not newNode in nodeList:
                    nodeList.append(newNode)

                department = course[0:course.index(" ")]

                newNode = {}
                newNode.update({"name":department})
                if not newNode in nodeList:
                    nodeList.append(newNode)
            if not areaList in conxList:
                conxList.append(areaList)

    graph.update({"nodes":nodeList})

    for i in xrange(len(conxList)):
        conx = conxList[i]

        for j in xrange(len(conx)-1):

            for m in xrange(len(conx[j])):
                for n in xrange(len(conx[j+1])):
                    startNode = {}
                    startNode.update({"name":conx[j][m].replace("-"," ").encode("utf-8")})

                    endNode = {}
                    endNode.update({"name":conx[j+1][n].replace("-"," ").encode("utf-8")})

                    sourceLocation = nodeList.index(startNode)
                    targetLocation = nodeList.index(endNode)

                    newLink = {}
                    newLink.update({"source":sourceLocation})
                    newLink.update({"target":targetLocation})
                    linksList.append(newLink)

    graph.update({"links":linksList})

    with open('graph.json', 'w') as outputFile:
        outputFile.write(json.dumps(graph))

    json_data.close()
    

if __name__ == '__main__':
    main()