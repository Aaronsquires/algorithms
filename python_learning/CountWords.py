# count the number for words in a string
def countwords(string):
    if not string:
        return 0

    num_spaces = string.count(' ') + 1

    return num_spaces


if __name__ == "__main__":
    print(countwords('Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec nec erat nibh. Aenean sed malesuada nibh. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Mauris elementum bibendum tempus. Nullam eu ultricies lacus. Fusce ut massa a tellus auctor elementum sit amet viverra arcu. Quisque vel.'))
    print(countwords('Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc dapibus laoreet nisi non sollicitudin. Vivamus elementum, lacus quis accumsan accumsan.'))
    print(countwords(''))
