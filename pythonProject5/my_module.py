def inget():
    print("Enter the text (if you want to stop press <Enter> twice) ")
    lines = []
    while True:
        line = input()            # вводимо текст
        if line:                  # поки не буде 2 Enter підряд
            lines.append(line)    # записуємо рядками в список
        else:
            break
    text = '\n'.join(lines)       # з'єднуємо список в суцільний текст
    return text


def write_file():
    text = ""
    with open("input_file.txt", "a+") as in_file:     # відкриваємо файл для запису
        in_file.write(inget())                         # записуємо текст в файл з консолі
        in_file.write("\n")
    with open("input_file.txt", "r") as in_file:
        text = in_file.read()                           # зчитуємо з файла текст
    lines = text.split("\n")                            # розбиваємо текст на список рядків
    new_text = ""
    for line in lines:
        if line:
            new_text += str(len(str(line))) + " " + str(line) + "\n"   # модифікуємо текст
    with open("output.txt", "w") as out_file:
        out_file.write(new_text)                        # записуємо модифікований текст в новий файл


def display_file():
    my_file = open("input_file.txt")
    print("\nOld file:\n", *my_file)                # виводимо те, що знаходиться у вхідному файлі
    my_file.close()
    old_file = open("output.txt")
    print("New file:\n", *old_file)                 # виводимо те, що знаходиться у вихідному файлі
    old_file.close()


def dopys():
    while True:
        flag = input("Press yes if you want to add and no if you don`t:  ")
        if flag == "yes":                      # дописуємо текст якщо так вибрав "yes"
            write_file()
        if flag != "yes":
            break


def clean():
    my_file = open("input_file.txt", "w")    # очищуємо вхідний файл
    my_file.close()
    old_file = open("output.txt", "w")        # очищуємо вихідний файл
    old_file.close()
