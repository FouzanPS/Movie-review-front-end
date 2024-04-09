file = open("sample.txt", "r")
text = ""
ch = file.read(1)

while ch:
    text += ch
    ch = file.read(1)

token = ""
counts = {"keyword": 0, "operator": 0, "special": 0, "identifier": 0}
keywords = ["public", "static", "void", "class", "System", "out", "println", "String", "args", "int"]
operators = ["+", "-", "*", "%", "/", "="]
special = ["[", "]", ";", "{", "}", ",", ".", '"', "[]", "()", "(", ")"]
lists = {"keyword": [], "operator": [], "special": [], "identifier": []}

i = 0
while i < len(text):
    ch = text[i]

    if ch == " " or ch == "\n":
        if token:
            keyword_flag = False
            operator_flag = False
            special_flag = False
            keyword_index = 0

            while keyword_index < len(keywords):
                if token == keywords[keyword_index]:
                    counts["keyword"] += 1
                    lists["keyword"].append(token)
                    keyword_flag = True
                    break
                keyword_index += 1

            operator_index = 0
            while operator_index < len(operators):
                if token == operators[operator_index]:
                    counts["operator"] += 1
                    lists["operator"].append(token)
                    operator_flag = True
                    break
                operator_index += 1

            special_index = 0
            while special_index < len(special):
                if token == special[special_index]:
                    counts["special"] += 1
                    lists["special"].append(token)
                    special_flag = True
                    break
                special_index += 1

            if not (keyword_flag or operator_flag or special_flag):
                counts["identifier"] += 1
                lists["identifier"].append(token)
                token = ""

    else:
        token += ch

    i += 1

file.close()

print("The number of keywords are:", counts["keyword"])
print(lists["keyword"])
print("The number of operators are:", counts["operator"])
print(lists["operator"])
print("The number of special characters are:", counts["special"])
print(lists["special"])
print("The number of identifiers are:", counts["identifier"])
print(lists["identifier"])
