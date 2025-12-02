#Day 2 part 1

# takes single ID string and returns true if ID is bad
def check_id(ident: str) -> bool:
    if len(ident) % 2 != 0:
        return False

    first_half = ident[:len(ident)//2]
    last_half = ident[len(ident)//2:]

    return first_half == last_half
    
def main():
    print("Running main script")
    
    full_input = open("./input").read()
    ranges = full_input.split(",")

    total = 0
    for j in range(len(ranges)):
        start = int(ranges[j].split("-")[0])
        stop = int(ranges[j].split("-")[1])

        for i in range(start, stop+1):
            if check_id(str(i)):
                total += i

    print("total is:")
    print(total)
    
main()

