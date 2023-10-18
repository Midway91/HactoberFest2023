def fcfs_disk_scheduling(requests, start_position):
    total_head_movement = 0
    current_position = start_position

    for request in requests:
        total_head_movement += abs(current_position - request)
        current_position = request

    return total_head_movement

# Example usage
requests = [98, 183, 37, 122, 14, 124, 65, 67]
start_position = 53

total_movement = fcfs_disk_scheduling(requests, start_position)
print(f"Total head movement: {total_movement} cylinders")
