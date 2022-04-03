def inget():
    print("Enter the text (if you want to stop press <Enter> twice) ")
    lines = []
    while True:
        line = input()            # вводимо текст
        if line:                  # поки не буде 2 Enter підряд
            lines.append(line)    # записуємо рядками в список
        else:
            break
    return lines


def write_text():
    file_name = input("Enter name of file ") + ".bin"
    fin = open(file_name , 'ab')            # відкриваємо файл для запису в бінарній формі
    for line in inget():
        bt = (str(line) + "\n").encode()           # перетворюємо текстову інформацію в бінарну
        fin.write(bt)                               # записуємо бінарну інформацію в файл
    fin.close()
    return file_name


def read_text(fileName):
    text = ""
    with open(fileName, "rb") as fout:          # відкриваємо файл для читання в бінарній формі
        for line in fout:
            s = line.decode()                   # зчитуємо з файла інформацію й розкодовуємо її в текстову
            text += s
    lines = text.split("\n")
    my_file = open(fileName, "w")    # очищуємо файл
    my_file.close()
    for line in lines:
        if line:
            words = line.split(" ")
            hours = int(words[words.index("h") - 1])     # зчитуємо час подорожі
            min = int(words[words.index("min") - 1])
            dep_hour = int(words[words.index("time") + 1])   # зчитуємо час відравки
            dep_min = int(words[words.index("time") + 2])
            if hours < 17:                          # якщо подорож триває довше , ніж 6 годин також записуємо в файл
                if dep_hour + hours > 24:                  # вираховуємо години прибуття
                    arr_hour = dep_hour + hours - 24
                else:
                    arr_hour = dep_hour + hours
                if dep_min + min >= 60:                     # вираховуємо хвилини прибуття
                    arr_min = dep_min + min - 60
                    arr_hour += 1
                else:
                    arr_min = dep_min + min
                if 23 > arr_hour >= 6:
                    if not (23-hours < dep_hour < 23 or 6+hours > arr_hour > 6):    # якщо частина подорожі або вся подорж не проходить вночі записуємо в новий файл
                        with open(fileName, "ab") as fin:
                            bt = (line + "\n").encode()
                            fin.write(bt)
            else:
                with open(fileName, "ab") as fin:
                    bt = (line+"\n").encode()
                    fin.write(bt)


def read(fileName):
    with open(fileName, "rb") as fout:    #читаємо , і розкодувуємо інформацію з файлу
        out = fout.read()
        s = out.decode()
    print(s)


def find_dep(fileName):
    city = input("\nEnter the city: ")
    text = []
    last_buses = []
    with open(fileName, "rb") as fout:
        for line in fout:
            s = line.decode()
            text.append(s)              # записуємо інформацію з файла рядками в список
    for line in text:
        if line.find(city) != -1:        # якщо цікаве нам місто є в рядку, записуємо рядок в новий список
            last_buses.append(line)
    last_h = int(last_buses[0][last_buses[0].rfind("time") + 5]) * 10 + int(last_buses[0][last_buses[0].rfind("time") + 6])
    last_min = int(last_buses[0][last_buses[0].rfind("time") + 8]) * 10 + int(last_buses[0][last_buses[0].find("time") + 9])
    for i in range(1, len(last_buses)):
        items = last_buses[i].split()
        h = int(items[items.index("time") + 1])
        min = int(items[items.index("time") + 2])
        if h > last_h:                                              # визначаємо останній час відправки з заданого міста
            last_h = h
            last_min = min
        if h == last_h and min > last_min:
            last_min = min
    print(last_h, ":" , last_min)


def add():
    while True:
        flag = input("Press yes if you want to add and no if you don`t:  ")
        if flag == "yes":  # дописуємо текст якщо так вибрав "yes"
            write_text()
        if flag != "yes":
            break
