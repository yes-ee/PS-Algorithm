
def print_arg(info, arg):
    print("==", info, "==")
    print(arg)

def solution(array, commands):
    answer = []
    
    for cmd in commands:
        st, ed, idx = cmd
        # print_arg("cmd", cmd)
        sorted_new_arr = sorted(array[st - 1:ed])
        # print_arg("new_arr", new_arr)
        # new_arr = sorted(new_arr)
        # print_arg("new_arr", new_arr)
        answer.append(sorted_new_arr[idx - 1])
        print_arg("answer", answer)
    
    return answer