let input = read_line () in
let number = int_of_string input in
let rec fact i = 
    match i with
    | 0 -> 1
    | i -> i * fact (i - 1)
in
print_endline (string_of_int (fact number))
