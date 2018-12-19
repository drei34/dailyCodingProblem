'''
First, notice that the minimum number of classroom halls is the maximum number of overlapping intervals. This is the big idea - the reason why this is so is that these are the bottlenecks.
'''

def overlaps(a, b):
    start_a, end_a = a
    start_b, end_b = b
    does_overlap = not (start_a > end_b  or start_b > end_a)
    return does_overlap

def max_overlapping_slow(intervals):
    current_max = 1
    for interval in intervals:
        num_overlapping = sum(
            overlaps(interval, other_interval)
            for other_interval in intervals
            if interval is not other_interval)
        current_max = max(current_max, num_overlapping)
    return current_max

'''
The idea here is to keep finding how many intervals you currently intersect, and then each time a new one is added you update the necessary variable. 
Of we have that 
'''

def max_overlapping_fast(intervals):

    starts = sorted([start for start, end in intervals])
    ends = sorted([end for start, end in intervals])

    current_overlap = 0
    current_max = 0

    i = 0
    j = 0

    while i < len(starts) and j < len(ends):
        if starts[i] < ends[j]:
            current_overlap += 1
            current_max = max(current_max, current_overlap)
            i += 1
        else:
            current_overlap -= 1
            j += 1

    return current_max

def main():
    #intervals = [(30,75),(0,50),(60,150)]
    intervals = [(1,2),(2,3),(3,4)]

    print max_overlapping_fast(intervals)
    

if __name__ == '__main__':
    main()
