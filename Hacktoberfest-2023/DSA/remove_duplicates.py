def remove_duplicates(string):
    """
        Given a string which may contain lowercase and uppercase characters. 
        The task is to remove all duplicate characters 
        from the string and find the resultant string.
    """

    new_string = ""
    for char in string:
        if char not in new_string:
            new_string += char
    return new_string
