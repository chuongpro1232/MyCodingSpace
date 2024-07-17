phystu = 0
phystu2 =0
chestu = 0
chestu2 =0
histu=0
histu2=0
geostu=0
geostu2=0
comstu=0
comstu2=0
phylist=[0]*19
phylist2=[0]*19
chelist=[0]*19
chelist2=[0]*19
hislist=[0]*19
hislist2=[0]*19
geolist=[0]*19
geolist2=[0]*19
comlist=[0]*19
comlist2=[0]*19

studentarray = [[0 for i in range(3)] for j in range(60)]
# asking for input
for i in range (0,60):
    studentarray[i][0] = input("What is student's name?: ")
    studentarray[i][1] = input("What is his/her first extra subjects?: ")
    studentarray[i][2] = input("What is his/her second extra subjects?: ")
    cancel=input("Do you want to continue entering name?: ")
    if cancel =="no" or cancel =="No":
        break


# counting, divide, anythings that related to subject
for i in range (0,60,1):
    for x in range (1,3):
        if studentarray[i][x]=="Physics":
            if phystu <=19:
                phylist[phystu] = studentarray[i][0]
            
            if phystu >19 and phystu <=39:
                phylist2[phystu2]=studentarray[i][0]
                phystu2+1          
            phystu += 1 #physic student counting

        if studentarray[i][x]=="Chemistry":
            if chestu <=19:
                chelist[chestu] = studentarray[i][0]
            
            if chestu >19 and phystu <=39:
                chelist2[chestu2]=studentarray[i][0]
                chestu2+1          
            chestu += 1 #chemistry student counting

        if studentarray[i][x]=="History":
            if histu <=19:
                hislist[histu] = studentarray[i][0]
            
            if histu >19 and histu <=39:
                hislist2[histu2]=studentarray[i][0]
                histu2+1          
            histu += 1 #history student counting

        if studentarray[i][x]=="Geography":
            if geostu <=19:
                geolist[geostu] = studentarray[i][0]
            
            if geostu >19 and geostu <=39:
                geolist2[geostu2]=studentarray[i][0]
                geostu2+1          
            geostu += 1#history student counting

        if studentarray[i][x]=="Computer Science":
            if comstu <=19:
                comlist[comstu] = studentarray[i][0]
            
            if comstu >19 and comstu <=39:
                comlist2[comstu2]=studentarray[i][0]
                comstu2+1          
            comstu += 1

print("The number of students in Physics class is: ", phystu,"\n")
print("The number of students in Chemistry class is: ",chestu,"\n")
print("The number of students in History class is: ",histu,"\n")
print("The number of students in Geography class is: ",geostu,"\n")
print("The number of students in Computer Science class is: ",comstu,"\n")
print(studentarray)
