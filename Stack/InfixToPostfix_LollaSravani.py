Operators = ['+', '-', '*', '/', '^', '(', ')']

def checkExpression(expression):
    if(expression.count('(') == expression.count(')')):
        return True
    return False

def infixToPostfix(expression):
    stack = []
    postFixExp = ''
    for character in expression:
        if character not in Operators:
            postFixExp+= character
        elif character == '(':
            stack.append('(')
        elif character==')':
            while stack and stack[-1]!= '(':
                postFixExp+=stack.pop()
            stack.pop()
        else:
            while stack and stack[-1]!= '(' and Operators.index(character) <= Operators.index(stack[-1]):
                postFixExp+=stack.pop()
            stack.append(character)
    while stack:
        postFixExp+=stack.pop()
    return postFixExp
    
expression = "((A+B)*C+D/(V+F)^E)"
print('infix expression: ',expression)
if(checkExpression(expression)):
    print('postfix expression: ',infixToPostfix(expression))
else:
    print("The given infix expression is wrong. Please check the brackets.")
                