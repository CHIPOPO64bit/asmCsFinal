import regex


class Parser():
    def __init__(self, path):
        self.__path = path

        self.__out_path = "out" + path

        with open(path, "r") as f:
            self.__data = f.read()
        self.__result = ""
        self.__parse_includes()
        self.__parse_macros()
        self.__parse_function_declaration()

    def __parse_includes(self):
        pattern = "#include [<\"][A-Za-z.]+[>\"]"
        p = regex.compile(pattern)
        m = p.findall(self.__data)
        self.__result += "; headers\n"
        for include in m:
            self.__result += "; " + include + "\n"
        self.__result += "\n"

    def __parse_macros(self):
        pattern = "(#define[ ]+[\w]+[ ]+([\d]+|(\"(.+[\\]*[\n]?)+\")))"
        p = regex.compile(pattern)
        m = p.findall(self.__data)
        self.__result += "; macros\n"
        for define in m:
            line = define[0]
            end = str(define[1]).replace("\\\n", "\\n")
            if end[0] == "\"":
                self.__result += line.split()[1] + " db " + end + ", " \
                                                                  "\"$\"" + "\n"
            else:
                self.__result += line.split()[1] + " equ " + end + "d\n"
        self.__result += "\n"
#void _neg(const Number *_ptr, Number *_res);
    def __parse_function_declaration(self):
        pattern = "(void|int|char|long|(unsigned char) +[\w+]\((.[\n]?)*\);)"
        p = regex.compile(pattern)
        m = p.findall(self.__data)

        for func in m:
            print(func)
            line = func[0]
            name = line.split()[1]
            self.__result += "proc "+name+"\n"+"endp "+name


    def __parse_function_declarations(self):
        pass

    def __str__(self):
        return self.__result


def main():
    p = Parser("modulo.h")
    print(p)


if __name__ == "__main__":
    main()
