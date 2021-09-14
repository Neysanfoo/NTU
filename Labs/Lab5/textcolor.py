def get_color(color):
    keep_looping = True
    tries = 0
    while keep_looping:
        if tries == 3:
            return 0
        color_str = input("Enter the value of the " + color + \
            " color for message (0 to 255): ")
        color_int = int(color_str)
        if 0 <= color_int <= 255:
            return color_int
        else:
            tries += 1
            continue