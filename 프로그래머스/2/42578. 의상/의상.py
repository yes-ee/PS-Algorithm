DEBUG = False

def print_debug(*args):
    if not DEBUG:
        return
    print("[DEBUG]", *args, sep=' | ')

def solution(clothes):
    answer = 1
    
    # 종류별 개수 세기 -> dict
    dic = {}
    for cloth in clothes:
        name, typ = cloth
        print_debug("cloth", name, typ)
        dic[typ] = dic.get(typ, 1) + 1
        print_debug("dic", dic)
    for k in dic:
        print_debug("dic key", dic[k])
        answer *= dic[k]
        print_debug("ans", answer)
    
    return answer - 1