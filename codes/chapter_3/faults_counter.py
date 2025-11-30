from collections import deque

def fault_count(seq, frames):
    page_faults = 0
    memory = deque()
    for page in seq:
        if len(memory) == frames:
            if page in memory:
                continue
            page_faults += 1
            memory.popleft()
            memory.append(page)
        else:
            if page in memory:
                continue
            memory.append(page)
            page_faults += 1 
    return page_faults

print(fault_count([1,2,3,4,1,2,5,1,2,3,4,5], 3))
