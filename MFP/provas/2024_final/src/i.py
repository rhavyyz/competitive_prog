def i():
    i = int(input())

    lines = []

    for _ in range(i):
        lines .append(input().split(' '))
    points = dict()
   

    i = int(input()) 
    for _ in range(i):
        word, point = input().split(' ')
        points[word] = int(point)

    max_value_verse = 0
    total_sum = 0
    max_index = -1

    for index, line in enumerate(lines):
        line_value = sum([points[word] for word in line if word in points])
        
        total_sum += line_value

        if line_value >= max_value_verse:
            max_index = index
            max_value_verse = line_value

    print(f"{total_sum} {max_index + 1}")

i()
