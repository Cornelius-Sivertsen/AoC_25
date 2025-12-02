#Day 2 part 2

# takes single ID string and returns true if ID is bad
def check_id(ident: str) -> bool:
    id_len = len(ident)

    for i in range(1,id_len):
        if id_len % i == 0:
            chunks = chunk_id(ident,i)
            if list_equal(chunks):
                return True
    return False
    

# returns list of "chunks" or substrings of equal lenght from string
# assumes that the length is a factor of the string length
def chunk_id(ident: str, len_chunks) -> list:
    num_chunks = len(ident)//len_chunks

    chunk_list = []

    for i in range(num_chunks):
        start_chunk = i*len_chunks
        chunk_list.append(ident[start_chunk:start_chunk+len_chunks])

    return chunk_list

# Checks if all items in a list is equal
def list_equal(items: list) -> bool:
    all_equal = False
    for i in range(len(items)-1):
        if items[i] != items[i+1]:
            return False
    return True

    
def main():
    print("Running main script")

    full_input = open("./input").read()
    ranges = full_input.split(",")

    total = 0
    iters = 0 # only used to count how many IDs were processed
    for j in range(len(ranges)):
        start = int(ranges[j].split("-")[0])
        stop = int(ranges[j].split("-")[1])

        for i in range(start, stop+1):
            iters += 1
            if check_id(str(i)):
                total += i

    print("total is:")
    print(total)

    print(f"went through {iters} iterations")
    
main()

