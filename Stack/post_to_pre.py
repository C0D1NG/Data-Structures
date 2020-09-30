def chckOperator(op) : 
	if op == "+" or op == "-" or op == "/" or op == "*" : 
		return True

	return False

def postToPre(exp) :
    s = [] 
    ln = len(exp) 
    
    for i in range(ln) :  
        if (chckOperator(exp[i])) : 
            ch1 = s.pop()    
            ch2 = s.pop()
            temp = exp[i] + ch2 + ch1    
            s.append(temp)
        
        else : 
            s.append(exp[i])

    return s[-1]


exp = "AB*CD*+"
print("Prefix : ", postToPre(exp))   # Output:  +*AB*CD