#To find Maximum in an array, Dynamic and static program
#There are two arrays- 1- an already existing array 2- An array the user creates and finds max from that array


import array



array1 = array.array('i',[10,30,40,70,20])     #Already existing array

array2= array.array('i',[])                    #Array for user to create
try:                                           #Program should not crash
	a=int(input("press 1 to get max from existing array and 2 to create an array of numbers and find out max from it "))
		                                       #giving user options
	if a==1:                                   #If user selects 1 then max of existing array i.e 70
		print("Existing array ",array1)
		print("Max of existing array ",max(array1))

	elif a==2:								    #If user selects 2 give him 3 options enter element, see max, and exit
		while True:
			op = int(input("1 To enter element in array | 2 To see max of exisiting elements | 3 to exit "))
			if op==1:
				ele = int(input("enter elem to enter ")) 
				array2.append(ele)               
				print(array2)
			elif op==2:
				if len(array2) ==0:
					print("Array is empty no max element ")
				else:
					print("Max in array is ",max(array2))
			elif op==3:
				break
			else:
				print("invalid option")

except ValueError:
	print("Please enter integer only")                 #If user inputs an alphabet or string the program should not crash
except:
	print("There's been some issue please check the data you've entered")
