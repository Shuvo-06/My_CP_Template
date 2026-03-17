tt = int(input())

for tc in range(1, tt + 1):
    s = input()
    t = input()

    val = [False] * 10

    def convert(expr):
        res = []
        for x in expr:
            if x.isalpha():
                res.append(f"val[{ord(x)-97}]")
            elif x == '!':
                res.append("not")
            elif x == '&':
                res.append("and")
            elif x == '|':
                res.append("or")
            else:
                res.append(x)
        return " ".join(res)

    temps = convert(s)
    tempt = convert(t)

    code_s = compile(temps, "", "eval")
    code_t = compile(tempt, "", "eval")

    ans = True

    for mask in range(1024):
        for i in range(10):
            val[i] = (mask >> i) & 1

        if eval(code_s) != eval(code_t):
            ans = False
            break

    if ans:
        print("Case ", tc, ": Equivalent", sep="")
    else:
        print("Case ", tc, ": Not Equivalent", sep="")
